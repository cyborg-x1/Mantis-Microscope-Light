/********************************************************************************
** Form generated from reading UI file 'qlinuxUSBserialautoconnectorgui.ui'
**
** Created: Sun Dec 4 15:02:44 2011
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
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_QLinuxUSBSerialAutoConnectorGUIClass
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_descriptors;
    QGridLayout *gridLayout;
    QLabel *label_product_header_desc;
    QLabel *label_manufacturer_desc;
    QLabel *label_manufacturer;
    QLabel *label_serial_desc;
    QLabel *label_serial;
    QLabel *label_product;
    QLabel *label_notice;
    QProgressBar *progressBar_time;
    QPushButton *pushButton_abort;
    QPushButton *pushButton_retry;

    void setupUi(QDialog *QLinuxUSBSerialAutoConnectorGUIClass)
    {
        if (QLinuxUSBSerialAutoConnectorGUIClass->objectName().isEmpty())
            QLinuxUSBSerialAutoConnectorGUIClass->setObjectName(QString::fromUtf8("QLinuxUSBSerialAutoConnectorGUIClass"));
        QLinuxUSBSerialAutoConnectorGUIClass->resize(400, 255);
        QLinuxUSBSerialAutoConnectorGUIClass->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout_2 = new QGridLayout(QLinuxUSBSerialAutoConnectorGUIClass);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_descriptors = new QGroupBox(QLinuxUSBSerialAutoConnectorGUIClass);
        groupBox_descriptors->setObjectName(QString::fromUtf8("groupBox_descriptors"));
        groupBox_descriptors->setMaximumSize(QSize(600, 100));
        groupBox_descriptors->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout = new QGridLayout(groupBox_descriptors);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_product_header_desc = new QLabel(groupBox_descriptors);
        label_product_header_desc->setObjectName(QString::fromUtf8("label_product_header_desc"));
        label_product_header_desc->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout->addWidget(label_product_header_desc, 0, 0, 1, 1);

        label_manufacturer_desc = new QLabel(groupBox_descriptors);
        label_manufacturer_desc->setObjectName(QString::fromUtf8("label_manufacturer_desc"));
        label_manufacturer_desc->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout->addWidget(label_manufacturer_desc, 2, 0, 1, 1);

        label_manufacturer = new QLabel(groupBox_descriptors);
        label_manufacturer->setObjectName(QString::fromUtf8("label_manufacturer"));
        label_manufacturer->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout->addWidget(label_manufacturer, 2, 2, 1, 1);

        label_serial_desc = new QLabel(groupBox_descriptors);
        label_serial_desc->setObjectName(QString::fromUtf8("label_serial_desc"));
        label_serial_desc->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout->addWidget(label_serial_desc, 3, 0, 1, 1);

        label_serial = new QLabel(groupBox_descriptors);
        label_serial->setObjectName(QString::fromUtf8("label_serial"));
        label_serial->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout->addWidget(label_serial, 3, 2, 1, 1);

        label_product = new QLabel(groupBox_descriptors);
        label_product->setObjectName(QString::fromUtf8("label_product"));

        gridLayout->addWidget(label_product, 0, 2, 1, 1);


        gridLayout_2->addWidget(groupBox_descriptors, 0, 0, 1, 2);

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

        gridLayout_2->addWidget(label_notice, 1, 0, 1, 2);

        progressBar_time = new QProgressBar(QLinuxUSBSerialAutoConnectorGUIClass);
        progressBar_time->setObjectName(QString::fromUtf8("progressBar_time"));
        progressBar_time->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        progressBar_time->setMinimum(0);
        progressBar_time->setMaximum(10);
        progressBar_time->setValue(10);
        progressBar_time->setTextVisible(true);
        progressBar_time->setFormat(QString::fromUtf8("Auto-Retry in %vs"));

        gridLayout_2->addWidget(progressBar_time, 4, 0, 1, 2);

        pushButton_abort = new QPushButton(QLinuxUSBSerialAutoConnectorGUIClass);
        pushButton_abort->setObjectName(QString::fromUtf8("pushButton_abort"));
        pushButton_abort->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout_2->addWidget(pushButton_abort, 6, 0, 1, 2);

        pushButton_retry = new QPushButton(QLinuxUSBSerialAutoConnectorGUIClass);
        pushButton_retry->setObjectName(QString::fromUtf8("pushButton_retry"));
        pushButton_retry->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout_2->addWidget(pushButton_retry, 5, 0, 1, 2);


        retranslateUi(QLinuxUSBSerialAutoConnectorGUIClass);

        QMetaObject::connectSlotsByName(QLinuxUSBSerialAutoConnectorGUIClass);
    } // setupUi

    void retranslateUi(QDialog *QLinuxUSBSerialAutoConnectorGUIClass)
    {
        QLinuxUSBSerialAutoConnectorGUIClass->setWindowTitle(QApplication::translate("QLinuxUSBSerialAutoConnectorGUIClass", "QLinuxFtdiSerialAutoConnectorGUI", 0, QApplication::UnicodeUTF8));
        groupBox_descriptors->setTitle(QApplication::translate("QLinuxUSBSerialAutoConnectorGUIClass", "Searching for a FTDI serial device...", 0, QApplication::UnicodeUTF8));
        label_product_header_desc->setText(QApplication::translate("QLinuxUSBSerialAutoConnectorGUIClass", "Product Descriptor", 0, QApplication::UnicodeUTF8));
        label_manufacturer_desc->setText(QApplication::translate("QLinuxUSBSerialAutoConnectorGUIClass", "Manufacturer Descriptor", 0, QApplication::UnicodeUTF8));
        label_manufacturer->setText(QApplication::translate("QLinuxUSBSerialAutoConnectorGUIClass", "Not set", 0, QApplication::UnicodeUTF8));
        label_serial_desc->setText(QApplication::translate("QLinuxUSBSerialAutoConnectorGUIClass", "Serial Number", 0, QApplication::UnicodeUTF8));
        label_serial->setText(QApplication::translate("QLinuxUSBSerialAutoConnectorGUIClass", "Not set", 0, QApplication::UnicodeUTF8));
        label_product->setText(QApplication::translate("QLinuxUSBSerialAutoConnectorGUIClass", "Not set", 0, QApplication::UnicodeUTF8));
        label_notice->setText(QApplication::translate("QLinuxUSBSerialAutoConnectorGUIClass", "Please connect a FTDI device with the specifications above.", 0, QApplication::UnicodeUTF8));
        pushButton_abort->setText(QApplication::translate("QLinuxUSBSerialAutoConnectorGUIClass", "Abort", 0, QApplication::UnicodeUTF8));
        pushButton_retry->setText(QApplication::translate("QLinuxUSBSerialAutoConnectorGUIClass", "Retry", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QLinuxUSBSerialAutoConnectorGUIClass: public Ui_QLinuxUSBSerialAutoConnectorGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QLINUXUSBSERIALAUTOCONNECTORGUI_H
