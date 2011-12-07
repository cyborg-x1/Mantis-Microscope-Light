#include "msl.h"

msl::msl(QWidget *parent) :
		QWidget(parent), serialConnection()
{
	ui.setupUi(this);
	//Create QColorDialog
	this->colorDialog = new QColorDialog(this);
	this->colorDialog->setWindowFlags(Qt::Widget);

	//Remove buttons and dialog
	this->colorDialog->setOptions(
			QColorDialog::DontUseNativeDialog | QColorDialog::NoButtons);
	//SetColor
	this->colorDialog->setCurrentColor(QColor(Qt::black));
	this->ui.LayoutForColorSelector->addWidget(colorDialog);

	//Connect the colorChanged signal
	connect(this->colorDialog, SIGNAL(currentColorChanged(QColor)), this,
			SLOT(colorChanged(QColor)));

	//Hide the EEProm settings-box
	this->ui.groupBox_EEProm->hide();

	//Disable the GUI as long as there is no connection to the serial
	this->setDisabled(1);

	//Connect the signals
	connect(&this->serialConnection,
                        SIGNAL(serialAbortedConnect(int)), this,
                        SLOT(serialConnectionAbort(int)));

	connect(&this->serialConnection, SIGNAL(waitingForRetry()), this,
			SLOT(serialWaitingForRetry()));
	connect(&this->serialConnection, SIGNAL(serialConnected()), this,
			SLOT(serialConnected()));
	connect(this, SIGNAL(retry()), &this->serialConnection,
			SLOT(retryConnect()));

	connect(this, SIGNAL(sendArray(QByteArray)),&this->serialConnection,SLOT(sendArray(QByteArray)));

	//Start serial connection thread
	serialConnection.start();
	serialConnection.setStopBits(qUSBSerial::StopBits_2);

	//Connect to Microscope Light
	serialConnection.serialConnect();
}

msl::~msl()
{

}

void msl::colorChanged(const QColor & color)
{
	//Get RGB values of the current color
	int r, g, b, h, s, v;

	color.getRgb(&r, &g, &b);
	color.getHsv(&h, &s, &v);

	updateLEDs();
}

void msl::on_pushButton_Wmax_clicked()
{
	this->ui.verticalSlider_white->setValue(255);
}

void msl::on_pushButton_UVmax_clicked()
{
	this->ui.verticalSlider_uv->setValue(255);
}

void msl::on_pushButton_off_clicked()
{

	this->colorDialog->setCurrentColor(QColor::fromHsv(0, 0, 0));
	this->ui.verticalSlider_uv->setValue(0);
	this->ui.verticalSlider_white->setValue(0);
}

void msl::on_verticalSlider_uv_valueChanged(int value)
{
	if (value)
		this->ui.verticalSlider_white->setValue(0);
	updateLEDs();
}

void msl::on_verticalSlider_white_valueChanged(int value)
{
	if (value)
		this->ui.verticalSlider_uv->setValue(0);
	updateLEDs();
}

void msl::on_pushButton_EEPROM_clicked()
{
	if (this->ui.groupBox_EEProm->isHidden())
	{
		ushort a = 0x00AB; // "<<" Symbol
		this->ui.groupBox_EEProm->setHidden(0);
		this->ui.pushButton_EEPROM->setText(QString::fromUtf16(&a, 1));
	}
	else
	{
		ushort a = 0x00BB; //   ">>" Symbol
		this->ui.groupBox_EEProm->setHidden(1);
		this->ui.pushButton_EEPROM->setText(QString::fromUtf16(&a, 1));
	}
}

void msl::on_pushButton_RGB_off_clicked()
{
	int h, s, v;
	this->colorDialog->currentColor().getHsv(&h, &s, &v);
	this->colorDialog->setCurrentColor(QColor::fromHsv(h, s, 0));
}

void msl::updateLEDs()
{
	//qDebug() << "Updating LEDs!";
	QByteArray array;
	array.push_back('W');
	array.push_back((char)0x0);
	array.push_back((char)this->ui.verticalSlider_uv->value());
	array.push_back((char)this->ui.verticalSlider_white->value());
	array.push_back(this->colorDialog->currentColor().red());
	array.push_back(this->colorDialog->currentColor().green());
	array.push_back(this->colorDialog->currentColor().blue());
	unsigned char checksum=0;
	for(QByteArray::iterator it = array.begin(); it != array.end(); ++it)
	{
		checksum+=*it;
	}
	array.push_back(checksum);
	emit sendArray(array);
}

void msl::on_pushButton_UV_White_Tggl_clicked()
{
	if (this->ui.verticalSlider_uv->value())
	{
		this->ui.verticalSlider_white->setValue(
				this->ui.verticalSlider_uv->value());
	}
	else
	{
		this->ui.verticalSlider_uv->setValue(
				this->ui.verticalSlider_white->value());
	}
}

void msl::on_pushButton_UvWhiteOff_clicked()
{
	this->ui.verticalSlider_white->setValue(0);
	this->ui.verticalSlider_uv->setValue(0);
}

void msl::on_pushButton_EE_Save_clicked()
{

}

void msl::on_pushButton_EE_Read_clicked()
{

}

void msl::on_pushButton_EE_currentSetting_clicked()
{

}

void msl::serialConnected()
{
	this->setEnabled(1);
}

void msl::serialWaitingForRetry()
{
	this->setDisabled(1);
	QLinuxUSBSerialAutoConnectorGUI retryGUI(this, 10);
	qDebug() << "receivedWatingForRetry";
	int ret = retryGUI.exec();
	if (ret)
	{
		emit retry();
	}
	else
	{
		exit(1);
	}
}

void msl::serialConnectionAbort(int reason)
{
	QMessageBox msgbox;
	msgbox.setStandardButtons(QMessageBox::Retry | QMessageBox::Abort);
	msgbox.setWindowTitle("Retry to connect?");
	msgbox.setIcon(QMessageBox::Critical);
	switch (reason)
	{
	case qUSBSerial::USER_ABORT:
		//Should not happen here...
		break;
	case qUSBSerial::APPLY_SETTINGS_FAILED:
		msgbox.setText("Could not apply settings to serial!");
		break;
	case qUSBSerial::OPEN_DEV_FILE_FAILED:
		msgbox.setText("Could not open device! Do you have the rights to use the serial interface?");
		break;
	case qUSBSerial::UDEV_CREATION_ERROR:
		msgbox.setText("Error in udev handling. Could not create udev object.");
		break;
	}
	int ret=msgbox.exec();
	if(ret==QMessageBox::Retry)
	{
		serialConnection.serialConnect();
	}
	else
	{
		exit(1);
	}


}

