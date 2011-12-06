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
/**
 * This enum holds the abort codes transmitted from the abort signal
 */
typedef enum
{
	USER_ABORT = -1, UDEV_CREATION_ERROR = -2, OPEN_DEV_FILE_FAILED = -3, APPLY_SETTINGS_FAILED = -4,
} AbortReason_t;

/**
 * This enum holds all possible baud rate values
 */
typedef enum
{
	BAUD_0,
	BAUD_50,
	BAUD_75,
	BAUD_110,
	BAUD_134,
	BAUD_150,
	BAUD_200,
	BAUD_300,
	BAUD_600,
	BAUD_1200,
	BAUD_1800,
	BAUD_2400,
	BAUD_4800,
	BAUD_9600,
	BAUD_19200,
	BAUD_38400,
	BAUD_57600,
	BAUD_115200,
	BAUD_230400,
} baudrate_t;

/**
 * This enum holds all possible char sizes for the interface
 */
typedef enum
{
	ChrSize_5, ChrSize_6, ChrSize_7, ChrSize_8,
} ChrSize_t;

/**
 * This enum holds all possible stop bit settings
 */
typedef enum
{
	StopBits_1, StopBits_2
} stopBits_t;

/**
 * This enum holds all possilbe parity options
 */
typedef enum

{
	Parity_None, Parity_Even, Parity_Odd
} parity_t;

/**
 * This enum holds all possible hardware handshake options
 */
typedef enum
{
	HandShake_None,
	HandShake_Hardware,
	HandShake_Software,
	HandShake_HardwareAndSoftware
} handshake_t;

class QLinuxUSBSerialAutoConnector: public QThread
{
Q_OBJECT

public:

public:
	QLinuxUSBSerialAutoConnector(QString vid = "", QString pid = "",
			QString serial = "", QString manufacturer = "",
			QString product = "", baudrate_t baudrate = BAUD_9600,
			stopBits_t stopbits = StopBits_1, parity_t parity = Parity_None,
			ChrSize_t chrsize = ChrSize_8, handshake_t handshake =
					HandShake_None);
	virtual ~QLinuxUSBSerialAutoConnector();

private:

	/*
	 *	internal states
	 */
	typedef enum
	{
		Disconnect, Disconnected, Connect, Connected, SearchSerial, WaitForRetry,
	} serialConnectionStates_t;
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

	//Serial device file
	QString devFile;

	//Serial file id
	int fd;


	//Serial Settings
	baudrate_t baudrate;
	stopBits_t stopbits;
	parity_t parity;
	ChrSize_t chrsize;
	handshake_t handshake;

private slots:
	/*
	 * Thread "main"
	 */
	void ifaceManagement();

	/*
	 * This function searches for the special serial interface
	 */
	bool searchSerial();

	/**
	 * This function updates the serial settings
	 */
	bool updateSerialSettings();

	/**
	 * This function opens the interface
	 */
	bool openInterface();

	/**
	 * This function closes the interface
	 */
	void closeInterface();

public:
	void run();
	QString getCurrentDevFile();

	void setBaudrate(baudrate_t baudrate);
	void setStopBits(stopBits_t stopbits);
	void setParity(parity_t parity);
	void setCharSize(ChrSize_t chrsize);
	void setHandShake(handshake_t handshake);

public slots:
	void serialConnect();
	void serialDisconnect();
	void retryConnect();
	void abortConnect();

signals:
	void serialDisconnected();
	void serialConnected();
	void serialAbortedConnect(int);
	void waitingForRetry();
	void serialConnectionLost();

};

} /* namespace qUSB */
#endif /* QLINUXUSBSERIALAUTOCONNECTOR_H_ */
