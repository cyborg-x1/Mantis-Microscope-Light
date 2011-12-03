#include "qlinuxftdiserialautoconnectorgui.h"

QLinuxFtdiSerialAutoConnectorGUI::QLinuxFtdiSerialAutoConnectorGUI(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

QLinuxFtdiSerialAutoConnectorGUI::~QLinuxFtdiSerialAutoConnectorGUI()
{

}
Ui::QLinuxFtdiSerialAutoConnectorGUIClass* QLinuxFtdiSerialAutoConnectorGUI::getUI()
{
	return &this->ui;
}

void QLinuxFtdiSerialAutoConnectorGUI::setRetrySeconds(int seconds)
{
	this->ui.progressBar_time->setMaximum(seconds);
}

void QLinuxFtdiSerialAutoConnectorGUI::setDeviceName(QString text)
{
	this->ui.label_notice->setText("Please connect: "+text);
	this->ui.groupBox_descriptors->setTitle("Searching for: "+text);
}

void QLinuxFtdiSerialAutoConnectorGUI::on_pushbutton_retry_clicked()
{
	emit this->retry_click();
}

void QLinuxFtdiSerialAutoConnectorGUI::on_pushbutton_abort_clicked()
{
	emit this->abort_click();
}

void QLinuxFtdiSerialAutoConnectorGUI::secondsvalue(int secondsTillRetry)
{
	this->ui.progressBar_time->setValue(secondsTillRetry);
}
