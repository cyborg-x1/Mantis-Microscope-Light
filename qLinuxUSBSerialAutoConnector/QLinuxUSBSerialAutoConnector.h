/*
 * QLinuxUSBSerialAutoConnector.h
 *
 *  Created on: 03.12.2011
 *      Author: cyborg-x1
 */

#ifndef QLINUXUSBSERIALAUTOCONNECTOR_H_
#define QLINUXUSBSERIALAUTOCONNECTOR_H_

#include <QThread>
#include <QTimer>
#include <QWidget>
#include <QReadWriteLock>
#include "qlinuxUSBserialautoconnectorgui.h"
#include <qdebug.h>


namespace qUSB
{

class QLinuxUSBSerialAutoConnector: public QThread
{
	Q_OBJECT

public:
	QLinuxUSBSerialAutoConnector(QString vid="", QString pid="", QString serial="", QString manufacturer="",QString product="", unsigned int retryseconds=10);
	virtual ~QLinuxUSBSerialAutoConnector();

public:
	typedef enum
	{
		USER_ABORT=-1,
		UDEV_CREATION_ERROR=-1000
	}AbortReason_t;



private:

	typedef enum
	{
		Disconnect,
		Disconnected,
		Connect,
		Connected,
		SearchSerial,
	}serialConnectionStates_t;
	QReadWriteLock lock;

	//Seconds to wait till auto retry
	unsigned int retry;

	//Target Values
	QString manufacturer;
	QString product;
	QString serial;
	QString vid;
	QString pid;

	//SerialFile
	QString devFile;


private slots:
	void ifaceManagement();
	bool searchSerial();

public:
	void run();
	QString getCurrentDevFile(){ return devFile; }


public slots:
	void serialConnect(){};
	void serialDisconnect(){};

signals:
	void serialConnectionLost();
	void serialDisconnected();
	void serialConnected();
	void serialReconnected();
	void abort(AbortReason_t reason);
};

} /* namespace qUSB */
#endif /* QLINUXUSBSERIALAUTOCONNECTOR_H_ */