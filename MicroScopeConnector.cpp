/*
 * MicroScopeConnector.cpp
 *
 *  Created on: 28.10.2011
 *      Author: cyborg-x1
 */

#include "MicroScopeConnector.h"
#include <libudev.h>
#include <qdebug.h>


#ifndef NULL
	#define NULL 0
#endif

MicroScopeConnector::MicroScopeConnector()
{
	//Search for the microscope light
	//Its a FTDI with Manufacturer=www.rad-lab.net and Product=Microscope Light Serial

	struct udev *udev;
	struct udev_enumerate *enumerate;
	struct udev_list_entry *devices, *dev_list_entry;
	struct udev_device *dev;

	udev = udev_new();
	if (!udev)
	{
		//TODO msgbox
		exit(1);
	}

	QString devicefile;
	QString device_manufacturer;
	QString device_product;
	bool 	found=false;


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
		devicefile=QString::fromLatin1(udev_device_get_devnode(dev));

		//Look for the usb device
		dev = udev_device_get_parent_with_subsystem_devtype(dev, "usb",
				"usb_device");

		//If its a usb device, get the manufacturer and the product string
		if (dev)
		{
				QString device_manufacturer=QString::fromLatin1(udev_device_get_sysattr_value(dev, "manufacturer"));
				QString device_product=QString::fromLatin1(udev_device_get_sysattr_value(dev, "product"));

			if(device_manufacturer=="www.rad-lab.net" && device_product=="Microscope Light Serial")
			{
				qDebug()<<devicefile;
			}
		}
		udev_device_unref(dev);
	}
	/* Free the enumerator object */
	udev_enumerate_unref(enumerate);

	udev_unref(udev);

	if(!found)
	{
		//TODO msgbox
	}
}

MicroScopeConnector::~MicroScopeConnector()
{
	// TODO Auto-generated destructor stub
}

