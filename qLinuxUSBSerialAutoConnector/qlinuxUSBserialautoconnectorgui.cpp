#include "qlinuxUSBserialautoconnectorgui.h"
#include <qdebug.h>
QLinuxUSBSerialAutoConnectorGUI::QLinuxUSBSerialAutoConnectorGUI(QWidget *parent, unsigned int SecondsTillAutoRetry, QString DeviceName)
    : QDialog(parent)
{
	ui.setupUi(this);
	this->ui.progressBar_time->setMaximum(SecondsTillAutoRetry);
	this->ui.progressBar_time->setValue(SecondsTillAutoRetry);
	this->ui.label_notice->setText("Please connect: "+DeviceName);
	connect(&this->countDownSeconds,SIGNAL(timeout()),this,SLOT(countdown()));
}

QLinuxUSBSerialAutoConnectorGUI::~QLinuxUSBSerialAutoConnectorGUI()
{}

Ui::QLinuxUSBSerialAutoConnectorGUIClass* QLinuxUSBSerialAutoConnectorGUI::getUI()
{
	return &this->ui;
}

void QLinuxUSBSerialAutoConnectorGUI::setRetrySeconds(int seconds)
{
	this->ui.progressBar_time->setMaximum(seconds);
	this->ui.progressBar_time->setValue(seconds);
}

void QLinuxUSBSerialAutoConnectorGUI::setDeviceName(QString text)
{
	this->ui.label_notice->setText("Please connect: "+text);
}

void QLinuxUSBSerialAutoConnectorGUI::on_pushButton_retry_clicked()
{
	this->countDownSeconds.stop();
	emit this->retry();
}

void QLinuxUSBSerialAutoConnectorGUI::on_pushButton_abort_clicked()
{
	this->countDownSeconds.stop();
	emit this->abort();
}

void QLinuxUSBSerialAutoConnectorGUI::countdown()
{
	if(this->ui.progressBar_time->value()>0)
	{
		this->ui.progressBar_time->setValue(this->ui.progressBar_time->value()-1);
	}
	else
	{
		this->ui.progressBar_time->setValue(-1);
		this->countDownSeconds.stop();
		emit this->retry();
	}
}
