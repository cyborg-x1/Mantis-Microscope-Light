/********************************************************************************
** Form generated from reading UI file 'qlinuxUSBserialautoconnectorgui.ui'
**
** Created: Wed Dec 7 11:16:08 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QLINUXUSBSERIALAUTOCONNECTORGUI_H
#define UI_QLINUXUSBSERIALAUTOCONNECTORGUI_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_QLinuxUSBSerialAutoConnectorGUIClass
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label_notice;
    QProgressBar *progressBar_time;
    QPushButton *pushButton_abort;
    QPushButton *pushButton_retry;

    void setupUi(QDialog *QLinuxUSBSerialAutoConnectorGUIClass)
    {
        if (QLinuxUSBSerialAutoConnectorGUIClass->objectName().isEmpty())
            QLinuxUSBSerialAutoConnectorGUIClass->setObjectName(QString::fromUtf8("QLinuxUSBSerialAutoConnectorGUIClass"));
        QLinuxUSBSerialAutoConnectorGUIClass->resize(400, 151);
        QLinuxUSBSerialAutoConnectorGUIClass->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout_2 = new QGridLayout(QLinuxUSBSerialAutoConnectorGUIClass);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_notice = new QLabel(QLinuxUSBSerialAutoConnectorGUIClass);
        label_notice->setObjectName(QString::fromUtf8("label_notice"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label_notice->setFont(font);
        label_notice->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        label_notice->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_notice, 0, 0, 1, 2);

        progressBar_time = new QProgressBar(QLinuxUSBSerialAutoConnectorGUIClass);
        progressBar_time->setObjectName(QString::fromUtf8("progressBar_time"));
        progressBar_time->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        progressBar_time->setMinimum(0);
        progressBar_time->setMaximum(10);
        progressBar_time->setValue(10);
        progressBar_time->setTextVisible(true);
        progressBar_time->setFormat(QString::fromUtf8("Auto-Retry in %vs"));

        gridLayout_2->addWidget(progressBar_time, 3, 0, 1, 2);

        pushButton_abort = new QPushButton(QLinuxUSBSerialAutoConnectorGUIClass);
        pushButton_abort->setObjectName(QString::fromUtf8("pushButton_abort"));
        pushButton_abort->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout_2->addWidget(pushButton_abort, 5, 0, 1, 2);

        pushButton_retry = new QPushButton(QLinuxUSBSerialAutoConnectorGUIClass);
        pushButton_retry->setObjectName(QString::fromUtf8("pushButton_retry"));
        pushButton_retry->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout_2->addWidget(pushButton_retry, 4, 0, 1, 2);


        retranslateUi(QLinuxUSBSerialAutoConnectorGUIClass);

        QMetaObject::connectSlotsByName(QLinuxUSBSerialAutoConnectorGUIClass);
    } // setupUi

    void retranslateUi(QDialog *QLinuxUSBSerialAutoConnectorGUIClass)
    {
        QLinuxUSBSerialAutoConnectorGUIClass->setWindowTitle(QApplication::translate("QLinuxUSBSerialAutoConnectorGUIClass", "QLinuxFtdiSerialAutoConnectorGUI", 0, QApplication::UnicodeUTF8));
        label_notice->setText(QApplication::translate("QLinuxUSBSerialAutoConnectorGUIClass", "Please connect: USB-Serial Device", 0, QApplication::UnicodeUTF8));
        pushButton_abort->setText(QApplication::translate("QLinuxUSBSerialAutoConnectorGUIClass", "Abort", 0, QApplication::UnicodeUTF8));
        pushButton_retry->setText(QApplication::translate("QLinuxUSBSerialAutoConnectorGUIClass", "Retry", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QLinuxUSBSerialAutoConnectorGUIClass: public Ui_QLinuxUSBSerialAutoConnectorGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QLINUXUSBSERIALAUTOCONNECTORGUI_H
