#ifndef QLINUXUSBSERIALAUTOCONNECTORGUI_H
#define QLINUXUSBSERIALAUTOCONNECTORGUI_H

#include <QTimer>
#include <QtGui/QDialog>
#include <QMessageBox>
#include "../ui_qlinuxUSBserialautoconnectorgui.h"


class QLinuxUSBSerialAutoConnectorGUI : public QDialog
{
    Q_OBJECT

public:
    QLinuxUSBSerialAutoConnectorGUI(QWidget *parent = 0, unsigned int SecondsTillAutoRetry=10, QString DeviceName="USB Serial Adapter");
    ~QLinuxUSBSerialAutoConnectorGUI();

private:
    Ui::QLinuxUSBSerialAutoConnectorGUIClass ui;
    QTimer countDownSeconds;


public:
    Ui::QLinuxUSBSerialAutoConnectorGUIClass* getUI();
    void setRetrySeconds(int seconds);
    void setDeviceName(QString text);
    int exec()
    {
    	countDownSeconds.start(1000);
    	return QDialog::exec();
    }

private slots:
	void countdown();
	void on_pushButton_retry_clicked();
	void on_pushButton_abort_clicked();

public slots:

signals:
	void retry();
	void abort();
};

#endif // QLINUXUSBSERIALAUTOCONNECTORGUI_H
