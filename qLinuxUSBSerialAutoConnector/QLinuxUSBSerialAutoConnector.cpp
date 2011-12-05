/*
 * QLinuxUSBSerialAutoConnector.cpp
 *
 *  Created on: 03.12.2011
 *      Author: cyborg-x1
 */

#include "QLinuxUSBSerialAutoConnector.h"
#include <libudev.h>


#ifndef NULL //<< normally not needed eclipse just wanted to piss me off
	#define NULL 0
#endif

namespace qUSBSerial
{
	QLinuxUSBSerialAutoConnector::QLinuxUSBSerialAutoConnector(QString vid, QString pid, QString serial, QString manufacturer,QString product)
	{
		//Initialize the variables...
		this->manufacturer=manufacturer;
		this->serial=serial;
		this->product=product;
		this->vid=vid;
		this->pid=pid;
		this->retry=false;
		this->state=Disconnected;
		this->establish_connection=true;
		this->abort=false;
	}

	QLinuxUSBSerialAutoConnector::~QLinuxUSBSerialAutoConnector()
	{

		quit();
		wait();
	}

	void QLinuxUSBSerialAutoConnector::run()
	{
		QTimer timer1;
		connect(&timer1,SIGNAL(timeout()),this,SLOT(ifaceManagement()));
		timer1.start(50);
		exec();
	}

	void QLinuxUSBSerialAutoConnector::ifaceManagement()
	{
		switch(this->state)
		{
			case Disconnect:
			{
				qDebug()<<"State:Disconnect";

			}
			break;
			case Disconnected:
			{
				qDebug()<<"State:Disconnected";
				if(establish_connection==true) this->state=SearchSerial;
			}
			break;
			case Connect:
			{
				qDebug()<<"State:Connect";
				if(establish_connection==true)
				{

				}
				else
				{
					this->state=Disconnect;
				}
			}
			break;
			case Connected:
			{
				qDebug()<<"State:Connected";
				if(establish_connection==true)
				{
					QString currentDevice=devFile;
					if(searchSerial())
					{

					}
					else
					{
						this->state=WaitForRetry;
						emit serialConnectionLost();
					}
				}
				else
				{
					this->state=Disconnect;
				}
			}
			break;
			case SearchSerial:
			{
				qDebug()<<"State:SearchSerial";
				if(establish_connection==true)
				{
					bool found=this->searchSerial();
					if(found)
					{
						this->state=Connect;
					}
					else
					{
						this->state=WaitForRetry;
					}
				}
				else
				{
					this->state=Disconnected;
				}
			}
			break;
			case WaitForRetry:
			{
				qDebug()<<"State:WaitforRetry";
				//Check if we got the signal for retrying it
				this->lock.lockForWrite();
				if(this->retry==true)
				{
					this->state=SearchSerial;
					this->retry=false;
				}
				else if(this->abort==true)
				{
					this->state=Disconnect;
					this->abort=false;
				}
				else
				{
					emit waitingForRetry();
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

			bool   found=false;
			this->lock.lockForWrite();
				this->devFile="";
			this->lock.unlock();

			udev = udev_new();
			if (!udev)
			{
				//TODO msgbox There was an error when trying to create a udev object
				emit abortConnect(UDEV_CREATION_ERROR);
				qDebug()<<"UDEV ERROR!";
			}

			/* Create a list of the devices in the 'tty' subsystem. */
			enumerate = udev_enumerate_new(udev);
			udev_enumerate_add_match_subsystem(enumerate, "tty");
			udev_enumerate_scan_devices(enumerate);
			devices = udev_enumerate_get_list_entry(enumerate);


			/* Macro for searching through devices*/
			udev_list_entry_foreach(dev_list_entry, devices)
			{
				const char *path;

				path = udev_list_entry_get_name(dev_list_entry);
				dev = udev_device_new_from_syspath(udev, path);

				//Devicefile string (of the current device)
				QString deviceFile=QString::fromLatin1(udev_device_get_devnode(dev));

				//Look for the usb device
				dev = udev_device_get_parent_with_subsystem_devtype(dev, "usb",
						"usb_device");

				//If its a usb device, get the manufacturer and the product string
				if (dev)
				{
					QString device_vid=QString::fromLatin1(udev_device_get_sysattr_value(dev,"idVendor"));
			        QString device_pid=QString::fromLatin1(udev_device_get_sysattr_value(dev, "idProduct"));
					QString device_manufacturerString=QString::fromLatin1(udev_device_get_sysattr_value(dev, "manufacturer"));
					QString device_productString=QString::fromLatin1(udev_device_get_sysattr_value(dev, "product"));
					QString device_serialNumber=QString::fromLatin1(udev_device_get_sysattr_value(dev, "serial"));

					if((		       			device_vid==this->vid   || this->vid=="" 		  )&&
					   (		       			device_pid==this->pid   || this->pid==""          )&&
					   (device_manufacturerString==this->manufacturer   || this->manufacturer=="" )&&
					   (	 device_productString==this->product	    || this->product==""	  )&&
					   (	  device_serialNumber==this->serial 	    || this->serial==""		  ))
					{

						//Todo check if file can be opened...

						found=true;
						this->lock.lockForWrite();
							this->devFile=deviceFile;
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
		file=this->devFile;
		this->lock.unlock();
		return file;
	}

	void QLinuxUSBSerialAutoConnector::serialConnect()
	{
		this->lock.lockForWrite();
		this->establish_connection=true;
		this->lock.unlock();
	}

	void QLinuxUSBSerialAutoConnector::serialDisconnect()
	{
		this->lock.lockForWrite();
		this->establish_connection=false;
		this->lock.unlock();
	}

	void QLinuxUSBSerialAutoConnector::retryConnect()
	{
		this->lock.lockForWrite();
		this->retry=true;
		this->lock.unlock();
	}

	void QLinuxUSBSerialAutoConnector::abortConnect()
	{
		this->lock.lockForWrite();
		this->abort=true;
		this->lock.unlock();
	}

} /* namespace qUSB */
