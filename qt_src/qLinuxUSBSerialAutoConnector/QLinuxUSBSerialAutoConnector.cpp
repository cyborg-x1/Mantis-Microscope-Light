/*
 * QLinuxUSBSerialAutoConnector.cpp
 */
#include "ui_qlinuxUSBserialautoconnectorgui.h"
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
	this->_manufacturer = manufacturer;
	this->_serial = serial;
	this->_product = product;
	this->_vid = vid;
	this->_pid = pid;
	this->state = Disconnected;
	this->_serialEnabled = false;
	this->_abort = false;
	this->_retry = false;
	this->_baudrate = baudrate;
	this->_stopbits = stopbits;
	this->_parity = parity;
	this->_chrsize = chrsize;
	this->_handshake = handshake;
	this->fd = -1;
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
		this->state = Disconnected;
		this->closeInterface();
		setOpen(0);
		this->clearSerialEnabled();
		emit this->serialDisconnect();
	}
		break;
	case Disconnected:
	{
		qDebug() << "State:Disconnected";
		if (serialEnabled() == true)
			this->state = SearchSerial;
	}
		break;
	case Connect:
	{
		qDebug() << "State:Connect";
		if (serialEnabled() == true)
		{
			fd = open(getCurrentDevFile().toLatin1(), O_RDWR | O_NDELAY);
			if (fd < 0)
			{
				this->state = Disconnect;
				this->fd = -1;
				emit serialAbortedConnect(OPEN_DEV_FILE_FAILED);
			}
			else
			{
				tcflush(fd, TCIOFLUSH);

				if (updateSerialSettings())
				{
					this->state = Disconnect;
					close(this->fd);
					this->fd = -1;
					emit serialAbortedConnect(APPLY_SETTINGS_FAILED);
				}
				else
				{
					notifier = new QSocketNotifier(this->fd,
							QSocketNotifier::Read);

					this->state = Connected;
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
		if (serialEnabled() == true)
		{
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
		if (serialEnabled() == true)
		{
			if (this->searchSerial())
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
		if (this->retry() == true)
		{
			this->waitingforRetryEmitted = false;
			this->state = SearchSerial;
			clearRetry();
		}
		else if (abort() == true)
		{
			this->waitingforRetryEmitted = false;
			this->state = Disconnect;
			clearAbort();
		}
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
	this->_devFile = "";
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

			if ((device_vid == this->_vid || this->_vid == "")
					&& (device_pid == this->_pid || this->_pid == "")
					&& (device_manufacturerString == this->_manufacturer
							|| this->_manufacturer == "")
					&& (device_productString == this->_product
							|| this->_product == "")
					&& (device_serialNumber == this->_serial
							|| this->_serial == ""))
			{

				//Todo check if file can be opened...

				found = true;
				this->lock.lockForWrite();
				this->_devFile = deviceFile;
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
	file = this->_devFile;
	this->lock.unlock();
	return file;
}

void QLinuxUSBSerialAutoConnector::serialConnect()
{
	this->lock.lockForWrite();
	this->_serialEnabled = true;
	this->lock.unlock();
}

void QLinuxUSBSerialAutoConnector::serialDisconnect()
{
	this->lock.lockForWrite();
	this->_serialEnabled = false;
	this->lock.unlock();
}

void QLinuxUSBSerialAutoConnector::retryConnect()
{
	this->lock.lockForWrite();
	if (waitingforRetryEmitted == true)
		this->_retry = true;
	this->lock.unlock();
}

void QLinuxUSBSerialAutoConnector::abortConnect()
{
	this->lock.lockForWrite();
	if (waitingforRetryEmitted)
		this->_abort = true;
	this->lock.unlock();
}

bool QLinuxUSBSerialAutoConnector::updateSerialSettings()
{
	/* This function features some code from minicom 2.0.0, src/sysdep1.c
	 * copied from cutecom, THANKS :-)
	 */
	if (fd < 0)
	{
		return 0;
	}

	struct termios newtio;
	speed_t br;

	switch (getBaudrate())
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
	cfsetospeed(&newtio, br);
	cfsetispeed(&newtio, br);

	switch (getCharSize())
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

	newtio.c_cflag |= CLOCAL | CREAD;

	if (getParity() == Parity_Even)
	{
		newtio.c_cflag |= PARENB;
	}
	else if (getParity() == Parity_Odd)
	{
		newtio.c_cflag |= (PARENB | PARODD);
	}
	else //Parity none
	{
		newtio.c_cflag &= ~(PARENB | PARODD);
	}

	if (getStopBits() == StopBits_2)
	{
		newtio.c_cflag |= CSTOPB;
	}
	else
	{
		newtio.c_cflag &= ~CSTOPB;
	}

	newtio.c_iflag = IGNBRK;

	newtio.c_cflag &= ~CRTSCTS;

	//software handshake
	if (getHandShake() == HandShake_HardwareAndSoftware
			|| getHandShake() == HandShake_Software)
	{
		newtio.c_iflag |= IXON | IXOFF;
	}
	else
	{
		newtio.c_iflag &= ~(IXON | IXOFF | IXANY);
	}

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

	//hardware handshake
	if (getHandShake() == HandShake_HardwareAndSoftware
			|| getHandShake() == HandShake_Hardware)
	{
		newtio.c_cflag |= CRTSCTS;
	}
	else
	{
		newtio.c_cflag &= ~CRTSCTS;
	}
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
	this->_baudrate = baudrate;
	updateSerialSettings();
	this->lock.unlock();
}

void QLinuxUSBSerialAutoConnector::setStopBits(stopBits_t stopbits)
{
	this->lock.lockForWrite();
	this->_stopbits = stopbits;
	updateSerialSettings();
	this->lock.unlock();
}

void QLinuxUSBSerialAutoConnector::setParity(parity_t parity)
{
	this->lock.lockForWrite();
	this->_parity = parity;
	updateSerialSettings();
	this->lock.unlock();
}

void QLinuxUSBSerialAutoConnector::setCharSize(ChrSize_t chrsize)
{
	this->lock.lockForWrite();
	this->_chrsize = chrsize;
	updateSerialSettings();
	this->lock.unlock();
}

void QLinuxUSBSerialAutoConnector::setHandShake(handshake_t handshake)
{
	this->lock.lockForWrite();
	this->_handshake = handshake;
	updateSerialSettings();
	this->lock.unlock();
}

void QLinuxUSBSerialAutoConnector::closeInterface()
{
	close(this->fd);
	this->fd = -1;
}

void QLinuxUSBSerialAutoConnector::sendByte(uint8_t byte)
{
	if(1||isOpen())
	{
		 int res=::write(fd, &byte, 1);
		   if (res<1)
		   {

		   }
	}
}

void QLinuxUSBSerialAutoConnector::sendArray(QByteArray array)
{
	if(1||isOpen())
	{
		for(QByteArray::ConstIterator it = array.begin(); it!=array.end(); it++)
		{
			this->sendByte(*it);
		}
	}
}

void QLinuxUSBSerialAutoConnector::fileChanged(int fd)
{
	//Check if file descriptor is the same
	if (fd != this->fd)
	{
		emit serialAbortedConnect(WRONG_FILE_DESCRIPTOR);
	}

	uint8_t buf[255];
	int bytesRead = ::read(fd, buf, 255);

	if (bytesRead < 0) //read nothing
	{
		return;
	}
	else if (bytesRead == 0) //device removed
	{
		emit serialAbortedConnect(DEVICE_REMOVED);
	}
	else
	{
		//TODO
	}
}

} /* namespace qUSB */
