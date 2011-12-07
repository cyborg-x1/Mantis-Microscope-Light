/*
 * QLinuxUSBSerialAutoConnector.cpp
 */
#include "../ui_qlinuxUSBserialautoconnectorgui.h"
#include "QLinuxUSBSerialAutoConnector.h"

#include <libudev.h>
#include <errno.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/ioctl.h>
#include <sys/termios.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/fcntl.h>


namespace qUSBSerial
{
QLinuxUSBSerialAutoConnector::QLinuxUSBSerialAutoConnector(QString vid,
		QString pid, QString serial, QString manufacturer, QString product,
		baudrate_t baudrate, stopBits_t stopbits, parity_t parity,
		ChrSize_t chrsize, handshake_t handshake)
{
	//Initialize the variables...
	this->manufacturer = manufacturer;
	this->serial = serial;
	this->product = product;
	this->vid = vid;
	this->pid = pid;
	this->state = Disconnected;
	this->establish_connection=false;
	this->abort = false;
	this->retry = false;
	this->baudrate = baudrate;
	this->stopbits = stopbits;
	this->parity = parity;
	this->chrsize = chrsize;
	this->handshake = handshake;
	this->fd=-1;
}

QLinuxUSBSerialAutoConnector::~QLinuxUSBSerialAutoConnector()
{
	quit();
	wait();
}

void QLinuxUSBSerialAutoConnector::run()
{
	this->lock.lockForWrite();
		this->waitingforRetryEmitted = false;
	this->lock.unlock();
	QTimer timer1;
	connect(&timer1, SIGNAL(timeout()), this, SLOT(ifaceManagement()));
	timer1.start(500);
	exec();
}

void QLinuxUSBSerialAutoConnector::ifaceManagement()
{
	switch (this->state)
	{
	case Disconnect:
	{
		qDebug() << "State:Disconnect";
		this->closeInterface();
		this->state=Disconnected;
		this->establish_connection=false;
		emit this->serialDisconnect();
	}
		break;
	case Disconnected:
	{
		qDebug() << "State:Disconnected";
		if (establish_connection == true) this->state = SearchSerial;
	}
		break;
	case Connect:
	{
		qDebug() << "State:Connect";
		if (establish_connection == true)
		{
			   fd=open(devFile.toLatin1(), O_RDWR | O_NDELAY);
			   if (fd<0)
			   {
				   this->state=Disconnect;
				   this->fd=-1;
				   emit serialAbortedConnect(OPEN_DEV_FILE_FAILED);
			   }
			   else
			   {
				   tcflush(fd, TCIOFLUSH);

				   if(updateSerialSettings())
				   {
					   this->state=Disconnect;
					   close(this->fd);
					   this->fd=-1;
					   emit serialAbortedConnect(APPLY_SETTINGS_FAILED);
				   }
				   else
				   {
					   this->state=Connected;
					   emit serialConnected();
				   }
			   }
		}
		else
		{
			this->state = Disconnect;
		}
	}
		break;
	case Connected:
	{
		qDebug() << "State:Connected";
		if (establish_connection == true)
		{
			QString currentDevice = devFile;
			if (!searchSerial())
			{
				this->state = WaitForRetry;
				emit serialConnectionLost();
			}
		}
		else
		{
			this->state = Disconnect;
		}
	}
		break;
	case SearchSerial:
	{
		qDebug() << "State:SearchSerial";
		if (establish_connection == true)
		{
			bool found = this->searchSerial();
			if (found)
			{
				this->state = Connect;
			}
			else
			{
				this->state = WaitForRetry;
			}
		}
		else
		{
			this->state = Disconnected;
		}
	}
		break;
	case WaitForRetry:
	{

		//We only send WaitingForRetry on entry.
		if (!waitingforRetryEmitted)
		{
			qDebug() << "State:WaitforRetry";
			this->waitingforRetryEmitted = true;
			emit waitingForRetry();
		}
		//Check if we got the signal for retrying it
		this->lock.lockForWrite();
		if (this->retry == true)
		{
			this->waitingforRetryEmitted = false;
			this->state = SearchSerial;
			this->retry = false;
		}
		else if (this->abort == true)
		{
			this->waitingforRetryEmitted = false;
			this->state = Disconnect;
			this->abort = false;
		}
		this->lock.unlock();
	}
		break;
	}
}

bool QLinuxUSBSerialAutoConnector::searchSerial()
{

	//Search for a suitable device
	struct udev *udev;
	struct udev_enumerate *enumerate;
	struct udev_list_entry *devices, *dev_list_entry;
	struct udev_device *dev;

	bool found = false;
	this->lock.lockForWrite();
	this->devFile = "";
	this->lock.unlock();

	udev = udev_new();
	if (!udev)
	{
		//TODO msgbox There was an error when trying to create a udev object
		emit serialAbortedConnect(UDEV_CREATION_ERROR);
		qDebug() << "UDEV ERROR!";
	}

	/* Create a list of the devices in the 'tty' subsystem. */
	enumerate = udev_enumerate_new(udev);
	udev_enumerate_add_match_subsystem(enumerate, "tty");
	udev_enumerate_scan_devices(enumerate);
	devices = udev_enumerate_get_list_entry(enumerate);

	/* Macro for searching through devices*/udev_list_entry_foreach(dev_list_entry, devices)
	{
		const char *path;

		path = udev_list_entry_get_name(dev_list_entry);
		dev = udev_device_new_from_syspath(udev, path);

		//Devicefile string (of the current device)
		QString deviceFile = QString::fromLatin1(udev_device_get_devnode(dev));

		//Look for the usb device
		dev = udev_device_get_parent_with_subsystem_devtype(dev, "usb",
				"usb_device");

		//If its a usb device, get the manufacturer and the product string
		if (dev)
		{
			QString device_vid = QString::fromLatin1(
					udev_device_get_sysattr_value(dev, "idVendor"));
			QString device_pid = QString::fromLatin1(
					udev_device_get_sysattr_value(dev, "idProduct"));
			QString device_manufacturerString = QString::fromLatin1(
					udev_device_get_sysattr_value(dev, "manufacturer"));
			QString device_productString = QString::fromLatin1(
					udev_device_get_sysattr_value(dev, "product"));
			QString device_serialNumber = QString::fromLatin1(
					udev_device_get_sysattr_value(dev, "serial"));

			if ((device_vid == this->vid || this->vid == "")
					&& (device_pid == this->pid || this->pid == "")
					&& (device_manufacturerString == this->manufacturer
							|| this->manufacturer == "")
					&& (device_productString == this->product
							|| this->product == "")
					&& (device_serialNumber == this->serial
							|| this->serial == ""))
			{

				//Todo check if file can be opened...

				found = true;
				this->lock.lockForWrite();
				this->devFile = deviceFile;
				this->lock.unlock();
				break;
			}
		}
		udev_device_unref(dev);
	}

	//free enumerator object
	udev_enumerate_unref(enumerate);

	udev_unref(udev);

	return found;
}

QString QLinuxUSBSerialAutoConnector::getCurrentDevFile()
{
	QString file;
	this->lock.lockForRead();
	file = this->devFile;
	this->lock.unlock();
	return file;
}

void QLinuxUSBSerialAutoConnector::serialConnect()
{
	this->lock.lockForWrite();
	this->establish_connection = true;
	this->lock.unlock();
}

void QLinuxUSBSerialAutoConnector::serialDisconnect()
{
	this->lock.lockForWrite();
	this->establish_connection = false;
	this->lock.unlock();
}

void QLinuxUSBSerialAutoConnector::retryConnect()
{
	this->lock.lockForWrite();
	if(waitingforRetryEmitted==true)this->retry = true;
	this->lock.unlock();
}

void QLinuxUSBSerialAutoConnector::abortConnect()
{
	this->lock.lockForWrite();
	if(waitingforRetryEmitted)this->abort = true;
	this->lock.unlock();
}

bool QLinuxUSBSerialAutoConnector::updateSerialSettings()
{
	/* This function features some code from minicom 2.0.0, src/sysdep1.c
	 * copied from cutecom, THANKS :-)
	 */

	if(fd<0)
	{
		return 0;
	}

	struct termios newtio;
	speed_t br;

	lock.lockForRead();
	switch (this->baudrate)
	{
	case BAUD_0:
		br = B0;
		break;
	case BAUD_50:
		br = B50;
		break;
	case BAUD_75:
		br = B75;
		break;
	case BAUD_110:
		br = B110;
		break;
	case BAUD_134:
		br = B134;
		break;
	case BAUD_150:
		br = B150;
		break;
	case BAUD_200:
		br = B200;
		break;
	case BAUD_300:
		br = B300;
		break;
	case BAUD_600:
		br = B600;
		break;
	case BAUD_1200:
		br = B1200;
		break;
	case BAUD_1800:
		br = B1800;
		break;
	case BAUD_2400:
		br = B2400;
		break;
	case BAUD_4800:
		br = B4800;
		break;
	case BAUD_9600:
		br = B9600;
		break;
	case BAUD_19200:
		br = B19200;
		break;
	case BAUD_38400:
		br = B38400;
		break;
	case BAUD_57600:
		br = B57600;
		break;
	case BAUD_115200:
		br = B115200;
		break;
	case BAUD_230400:
		br = B230400;
		break;
	}
	this->lock.unlock();
	cfsetospeed(&newtio, br);
	cfsetispeed(&newtio, br);

	this->lock.lockForRead();
	switch (this->chrsize)
	{
	case ChrSize_5:
		newtio.c_cflag = (newtio.c_cflag & ~CSIZE) | CS5;
		break;
	case ChrSize_6:
		newtio.c_cflag = (newtio.c_cflag & ~CSIZE) | CS6;
		break;
	case ChrSize_7:
		newtio.c_cflag = (newtio.c_cflag & ~CSIZE) | CS7;
		break;
	case ChrSize_8:
	default:
		newtio.c_cflag = (newtio.c_cflag & ~CSIZE) | CS8;
		break;
	}
	this->lock.unlock();
	newtio.c_cflag |= CLOCAL | CREAD;

	this->lock.lockForRead();
	if (this->parity == Parity_Even)
	{
		newtio.c_cflag |= PARENB;
	}
	else if (parity == Parity_Odd)
	{
		newtio.c_cflag |= (PARENB | PARODD);
	}
	else //Parity none
	{
		newtio.c_cflag &= ~(PARENB | PARODD);
	}
	this->lock.unlock();

	this->lock.lockForRead();
	if (this->stopbits == StopBits_2)
	{
		newtio.c_cflag |= CSTOPB;
	}
	else
	{
		newtio.c_cflag &= ~CSTOPB;
	}
	this->lock.unlock();

	newtio.c_iflag = IGNBRK;

	newtio.c_cflag &= ~CRTSCTS;

	this->lock.lockForRead();
	//software handshake
	if (this->handshake == HandShake_HardwareAndSoftware
			|| this->handshake == HandShake_Software)
	{
		newtio.c_iflag |= IXON | IXOFF;
	}
	else
	{
		newtio.c_iflag &= ~(IXON | IXOFF | IXANY);
	}
	this->lock.unlock();

	newtio.c_lflag = 0;
	newtio.c_oflag = 0;

	newtio.c_cc[VTIME] = 1;
	newtio.c_cc[VMIN] = 60;

	if (tcsetattr(this->fd, TCSANOW, &newtio) != 0)
	{
		qDebug() << "tcsetattr() 1 failed";
		return 1;
	}

	int mcs = 0;
	ioctl(fd, TIOCMGET, &mcs);
	mcs |= TIOCM_RTS;
	ioctl(fd, TIOCMSET, &mcs);

	if (tcgetattr(fd, &newtio) != 0)
	{
		qDebug() << "tcgetattr() 2 failed";
		return 2;
	}

	this->lock.lockForRead();
	//hardware handshake
	if (this->handshake == HandShake_HardwareAndSoftware
			|| this->handshake == HandShake_Hardware)
	{
		newtio.c_cflag |= CRTSCTS;
	}
	else
	{
		newtio.c_cflag &= ~CRTSCTS;
	}
	this->lock.unlock();
	if (tcsetattr(fd, TCSANOW, &newtio) != 0)
	{
		qDebug() << "tcsetattr() 3 failed";
		return 3;
	}

	return 0;
}

void QLinuxUSBSerialAutoConnector::setBaudrate(baudrate_t baudrate)
{
	this->lock.lockForWrite();
	this->baudrate = baudrate;
	updateSerialSettings();
	this->lock.unlock();
}

void QLinuxUSBSerialAutoConnector::setStopBits(stopBits_t stopbits)
{
	this->lock.lockForWrite();
	this->stopbits = stopbits;
	updateSerialSettings();
	this->lock.unlock();
}

void QLinuxUSBSerialAutoConnector::setParity(parity_t parity)
{
	this->lock.lockForWrite();
	this->parity = parity;
	updateSerialSettings();
	this->lock.unlock();
}

void QLinuxUSBSerialAutoConnector::setCharSize(ChrSize_t chrsize)
{
	this->lock.lockForWrite();
	this->chrsize = chrsize;
	updateSerialSettings();
	this->lock.unlock();
}

void QLinuxUSBSerialAutoConnector::setHandShake(handshake_t handshake)
{
	this->lock.lockForWrite();
	this->handshake = handshake;
	updateSerialSettings();
	this->lock.unlock();
}

void QLinuxUSBSerialAutoConnector::closeInterface()
{
	close(this->fd);
	this->fd=-1;
}

} /* namespace qUSB */
