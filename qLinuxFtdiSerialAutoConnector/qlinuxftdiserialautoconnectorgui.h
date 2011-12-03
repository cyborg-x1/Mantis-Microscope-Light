#ifndef QLINUXFTDISERIALAUTOCONNECTORGUI_H
#define QLINUXFTDISERIALAUTOCONNECTORGUI_H

#include <QtGui/QDialog>
#include "../ui_qlinuxftdiserialautoconnectorgui.h"

class QLinuxFtdiSerialAutoConnectorGUI : public QDialog
{
    Q_OBJECT

public:
    QLinuxFtdiSerialAutoConnectorGUI(QWidget *parent = 0);
    ~QLinuxFtdiSerialAutoConnectorGUI();

private:
    Ui::QLinuxFtdiSerialAutoConnectorGUIClass ui;

public:
    Ui::QLinuxFtdiSerialAutoConnectorGUIClass* getUI();
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

#endif // QLINUXFTDISERIALAUTOCONNECTORGUI_H
