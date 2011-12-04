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

namespace qUSB
{
	QLinuxUSBSerialAutoConnector::QLinuxUSBSerialAutoConnector(QString vid, QString pid, QString serial, QString manufacturer,QString product, unsigned int retryseconds)
	{
		this->manufacturer=manufacturer;
		this->serial=serial;
		this->product=product;
		this->vid=vid;
		this->pid=pid;
		this->retry=retryseconds;
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
		timer1.start(500);
		exec();
	}

	void QLinuxUSBSerialAutoConnector::ifaceManagement()
	{
		if(searchSerial())
		{
			qDebug()<<"Serial:"<<this->devFile;
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

			udev = udev_new();
			if (!udev)
			{
				//TODO msgbox There was an error when trying to create a udev object
				emit abort(UDEV_CREATION_ERROR);
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


} /* namespace qUSB */
