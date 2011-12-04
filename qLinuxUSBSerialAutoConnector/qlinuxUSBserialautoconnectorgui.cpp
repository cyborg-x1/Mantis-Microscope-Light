#include "qlinuxUSBserialautoconnectorgui.h"
#include <qdebug.h>
QLinuxUSBSerialAutoConnectorGUI::QLinuxUSBSerialAutoConnectorGUI(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
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
}

void QLinuxUSBSerialAutoConnectorGUI::setDeviceName(QString text)
{
	this->ui.label_notice->setText("Please connect: "+text);
	this->ui.groupBox_descriptors->setTitle("Searching for: "+text);
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

void QLinuxUSBSerialAutoConnectorGUI::secondsvalue(int secondsTillRetry)
{
	this->ui.progressBar_time->setValue(secondsTillRetry);
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

void QLinuxUSBSerialAutoConnectorGUI::hide()
{
		if(this->isVisible()) this->countDownSeconds.stop();
		this->QWidget::hide();
}

void QLinuxUSBSerialAutoConnectorGUI::show()
{
	if(!this->isVisible())
	{
		this->ui.progressBar_time->setValue(this->ui.progressBar_time->maximum());
		this->QWidget::show();
		this->countDownSeconds.start(1000);
	}
}
