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


namespace qUSBSerial
{

class QLinuxUSBSerialAutoConnector: public QThread
{
	Q_OBJECT

public:
	QLinuxUSBSerialAutoConnector(QString vid="", QString pid="", QString serial="", QString manufacturer="",QString product="");
	virtual ~QLinuxUSBSerialAutoConnector();

public:
	/**
	 * This enum holds the abort codes transmitted from the abort signal
	 */
	typedef enum
	{
		USER_ABORT=-1,
		UDEV_CREATION_ERROR=-2,
		OPEN_DEV_FILE_FAILED=-3,
	}AbortReason_t;



private:

	/*
	 *	internal states
	 */
	typedef enum
	{
		Disconnect,
		Disconnected,
		Connect,
		Connected,
		SearchSerial,
		WaitForRetry,
	}serialConnectionStates_t;
	QReadWriteLock lock;

	//Seconds to wait till auto retry
	bool retry;
	bool abort;
	bool waitingforRetryEmitted;

	//State
	bool establish_connection;
	serialConnectionStates_t state;

	//Target Values
	QString manufacturer;
	QString product;
	QString serial;
	QString vid;
	QString pid;

	//SerialFile
	QString devFile;


private slots:
	/*
	 * Thread "main"
	 */
	void ifaceManagement();

	/*
	 * This function searches for the special serial interface
	 */
	bool searchSerial();

public:
	void run();
	QString getCurrentDevFile();


public slots:
	void serialConnect();
	void serialDisconnect();
	void retryConnect();
	void abortConnect();

signals:
	void serialConnectionLost();
	void serialDisconnected();
	void serialConnected();
	void serialReconnected();
	void abortConnect(AbortReason_t reason);
	void waitingForRetry();

};

} /* namespace qUSB */
#endif /* QLINUXUSBSERIALAUTOCONNECTOR_H_ */
