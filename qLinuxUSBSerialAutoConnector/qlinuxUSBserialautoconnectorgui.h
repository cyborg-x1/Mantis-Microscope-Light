#ifndef QLINUXUSBSERIALAUTOCONNECTORGUI_H
#define QLINUXUSBSERIALAUTOCONNECTORGUI_H

#include <QTimer>
#include <QtGui/QDialog>
#include "../ui_qlinuxUSBserialautoconnectorgui.h"

class QLinuxUSBSerialAutoConnectorGUI : public QDialog
{
    Q_OBJECT

public:
    QLinuxUSBSerialAutoConnectorGUI(QWidget *parent = 0);
    ~QLinuxUSBSerialAutoConnectorGUI();

private:
    Ui::QLinuxUSBSerialAutoConnectorGUIClass ui;
    QTimer countDownSeconds;


public:
    Ui::QLinuxUSBSerialAutoConnectorGUIClass* getUI();
    void setRetrySeconds(int seconds);
    void setDeviceName(QString text);
    void hide();
    void show();

private slots:
	void countdown();
	void on_pushButton_retry_clicked();
	void on_pushButton_abort_clicked();

public slots:
void secondsvalue(int secondsTillRetry);


signals:
	void retry();
	void abort();
};

#endif // QLINUXUSBSERIALAUTOCONNECTORGUI_H
