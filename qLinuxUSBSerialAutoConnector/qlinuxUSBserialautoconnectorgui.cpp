#include "qlinuxUSBserialautoconnectorgui.h"

QLinuxUSBSerialAutoConnectorGUI::QLinuxUSBSerialAutoConnectorGUI(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
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

void QLinuxUSBSerialAutoConnectorGUI::on_pushbutton_retry_clicked()
{
	emit this->retry_click();
}

void QLinuxUSBSerialAutoConnectorGUI::on_pushbutton_abort_clicked()
{
	emit this->abort_click();
}

void QLinuxUSBSerialAutoConnectorGUI::secondsvalue(int secondsTillRetry)
{
	this->ui.progressBar_time->setValue(secondsTillRetry);
}
