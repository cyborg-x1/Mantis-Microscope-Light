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
#include <QSocketNotifier>
#include "qlinuxUSBserialautoconnectorgui.h"
#include <qdebug.h>
#include <QByteArray>
#include <inttypes.h>

namespace qUSBSerial
{
/**
 * This enum holds the abort codes transmitted from the abort signal
 */
typedef enum
{
	USER_ABORT = -1,
	UDEV_CREATION_ERROR = -2,
	OPEN_DEV_FILE_FAILED = -3,
	APPLY_SETTINGS_FAILED = -4,
	DEVICE_REMOVED = -5,
	WRONG_FILE_DESCRIPTOR = -6
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

	//Variables which need to be controlled by Mutex
	bool _retry; // One if retry signal received
	bool retry()
	{
		this->lock.lockForRead();
		bool ret=_retry;
		this->lock.unlock();
		return ret;
	}
	void clearRetry()
	{
		this->lock.lockForWrite();
			_retry=false;
		this->lock.unlock();
	}


	bool _abort; // One if abort signal received
	bool abort()
	{
		this->lock.lockForRead();
		bool ret=_abort;
		this->lock.unlock();
		return ret;
	}
	void clearAbort()
	{
		this->lock.lockForWrite();
			_abort=false;
		this->lock.unlock();
	}


	bool _open; // One when interface is open
	void setOpen(bool value)
	{
		this->lock.lockForWrite();
			_open=value;
		this->lock.unlock();
	}

	bool _serialEnabled; // One when connect signal received
	bool serialEnabled()
	{
		this->lock.lockForRead();
		bool ret=_serialEnabled;
		this->lock.unlock();
		return ret;
	}
	void clearSerialEnabled()
	{
		this->lock.lockForWrite();
			_serialEnabled=false;
		this->lock.unlock();
	}

	//Variables storing the identification settings for the serial
	QString _manufacturer;
	QString _product;
	QString _serial;
	QString _vid;
	QString _pid;






	//Storing the string of the current device file
	QString _devFile;
	void setdevFile(QString value)
	{
		this->lock.lockForWrite();
			_devFile=value;
		this->lock.unlock();
	}

	//Serial Settings
	baudrate_t _baudrate;
	stopBits_t _stopbits;
	parity_t _parity;
	ChrSize_t _chrsize;
	handshake_t _handshake;

	//Completely internal variables

	QSocketNotifier *notifier;
	bool waitingforRetryEmitted;
	serialConnectionStates_t state;
	int fd;

private slots:
	/*
	 * Thread "main"
	 */
	void ifaceManagement();

	/*
	 *	File change notifier
	 */
	void fileChanged(int fd);

private:
	/*
	 * This function searches for the special serial interface
	 */
	bool searchSerial();

	/*
	 * This function updates the serial settings
	 */
	bool updateSerialSettings();

	/*
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

	baudrate_t getBaudrate()
	{
		lock.lockForRead();
		baudrate_t ret=_baudrate;
		lock.unlock();
		return ret;
	}

	stopBits_t getStopBits()
	{
		lock.lockForRead();
		stopBits_t ret=_stopbits;
		lock.unlock();
		return ret;
	}

	parity_t getParity()
	{
		lock.lockForRead();
		parity_t ret=_parity;
		lock.unlock();
		return ret;
	}

	ChrSize_t getCharSize()
	{
		lock.lockForRead();
		ChrSize_t ret=_chrsize;
		lock.unlock();
		return ret;
	}

	handshake_t getHandShake()
	{
		lock.lockForRead();
		handshake_t ret=_handshake;
		lock.unlock();
		return ret;
	}

	bool isOpen()
	{
		this->lock.lockForRead();
		bool ret=_open;
		this->lock.unlock();
		return ret;
	}

	QString getManufacturer()
	{
		this->lock.lockForRead();
		QString ret=_manufacturer;
		this->lock.unlock();
		return ret;
	}

	QString getProduct()
	{
		this->lock.lockForRead();
		QString ret=_product;
		this->lock.unlock();
		return ret;
	}

	QString getSerial()
	{
		this->lock.lockForRead();
		QString ret=_serial;
		this->lock.unlock();
		return ret;
	}

	QString getVid()
	{
		this->lock.lockForRead();
		QString ret=_vid;
		this->lock.unlock();
		return ret;
	}

	QString getPid()
	{
		this->lock.lockForRead();
		QString ret=_pid;
		this->lock.unlock();
		return ret;
	}

	void setManufacturer(QString value)
	{
		this->lock.lockForWrite();
			_manufacturer=value;
		this->lock.unlock();
	}

	void setProduct(QString value)
	{
		this->lock.lockForWrite();
			_product=value;
		this->lock.unlock();
	}

	void setSerial(QString value)
	{
		this->lock.lockForWrite();
			_serial=value;
		this->lock.unlock();
	}

	void setVid(QString value)
	{
		this->lock.lockForWrite();
			_vid=value;
		this->lock.unlock();
	}

	void setPid(QString value)
	{
		this->lock.lockForWrite();
			_pid=value;
		this->lock.unlock();
	}

public slots:
	void serialConnect();
	void serialDisconnect();
	void retryConnect();
	void abortConnect();
	void sendByte(uint8_t byte);
	void sendArray(QByteArray array);

signals:
	void serialDisconnected();
	void serialConnected();
	void serialAbortedConnect(int);
	void waitingForRetry();
	void serialConnectionLost();
	void receivedByte(uint8_t byte);
};

} /* namespace qUSB */
#endif /* QLINUXUSBSERIALAUTOCONNECTOR_H_ */
