#ifndef QLINUXUSBSERIALAUTOCONNECTORGUI_H
#define QLINUXUSBSERIALAUTOCONNECTORGUI_H

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

public:
    Ui::QLinuxUSBSerialAutoConnectorGUIClass* getUI();
    void setRetrySeconds(int seconds);
    void setDeviceName(QString text);

public slots:

void on_pushbutton_retry_clicked();
void on_pushbutton_abort_clicked();
void secondsvalue(int secondsTillRetry);

signals:
	void retry_click();
	void abort_click();
};

#endif // QLINUXUSBSERIALAUTOCONNECTORGUI_H
