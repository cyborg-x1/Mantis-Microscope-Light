/********************************************************************************
** Form generated from reading UI file 'msl.ui'
**
** Created: Wed Dec 7 11:16:08 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSL_H
#define UI_MSL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mslClass
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_RGBLEDs;
    QGridLayout *gridLayout_3;
    QVBoxLayout *LayoutForColorSelector;
    QPushButton *pushButton_RGB_off;
    QPushButton *pushButton_off;
    QGroupBox *groupBox_EEProm;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_EE_currentSetting;
    QTreeView *treeView;
    QPushButton *pushButton_EE_Save;
    QPushButton *pushButton_EE_Read;
    QPushButton *pushButton_EEPROM;
    QGroupBox *groupBox_UVLEDs;
    QGridLayout *gridLayout_2;
    QSpinBox *spinBox_uv;
    QSlider *verticalSlider_uv;
    QLabel *label;
    QSlider *verticalSlider_white;
    QSpinBox *spinBox_white;
    QLabel *label_2;
    QPushButton *pushButton_UvWhiteOff;
    QPushButton *pushButton_UV_White_Tggl;
    QPushButton *pushButton_Wmax;
    QPushButton *pushButton_UVmax;

    void setupUi(QWidget *mslClass)
    {
        if (mslClass->objectName().isEmpty())
            mslClass->setObjectName(QString::fromUtf8("mslClass"));
        mslClass->resize(541, 393);
        gridLayout = new QGridLayout(mslClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_RGBLEDs = new QGroupBox(mslClass);
        groupBox_RGBLEDs->setObjectName(QString::fromUtf8("groupBox_RGBLEDs"));
        gridLayout_3 = new QGridLayout(groupBox_RGBLEDs);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        LayoutForColorSelector = new QVBoxLayout();
        LayoutForColorSelector->setSpacing(6);
        LayoutForColorSelector->setObjectName(QString::fromUtf8("LayoutForColorSelector"));

        gridLayout_3->addLayout(LayoutForColorSelector, 0, 0, 1, 2);

        pushButton_RGB_off = new QPushButton(groupBox_RGBLEDs);
        pushButton_RGB_off->setObjectName(QString::fromUtf8("pushButton_RGB_off"));

        gridLayout_3->addWidget(pushButton_RGB_off, 1, 0, 1, 2);


        gridLayout->addWidget(groupBox_RGBLEDs, 0, 0, 1, 2);

        pushButton_off = new QPushButton(mslClass);
        pushButton_off->setObjectName(QString::fromUtf8("pushButton_off"));

        gridLayout->addWidget(pushButton_off, 1, 0, 1, 4);

        groupBox_EEProm = new QGroupBox(mslClass);
        groupBox_EEProm->setObjectName(QString::fromUtf8("groupBox_EEProm"));
        groupBox_EEProm->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(groupBox_EEProm);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_EE_currentSetting = new QPushButton(groupBox_EEProm);
        pushButton_EE_currentSetting->setObjectName(QString::fromUtf8("pushButton_EE_currentSetting"));

        verticalLayout->addWidget(pushButton_EE_currentSetting);

        treeView = new QTreeView(groupBox_EEProm);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        verticalLayout->addWidget(treeView);

        pushButton_EE_Save = new QPushButton(groupBox_EEProm);
        pushButton_EE_Save->setObjectName(QString::fromUtf8("pushButton_EE_Save"));

        verticalLayout->addWidget(pushButton_EE_Save);

        pushButton_EE_Read = new QPushButton(groupBox_EEProm);
        pushButton_EE_Read->setObjectName(QString::fromUtf8("pushButton_EE_Read"));

        verticalLayout->addWidget(pushButton_EE_Read);


        gridLayout->addWidget(groupBox_EEProm, 0, 5, 2, 1);

        pushButton_EEPROM = new QPushButton(mslClass);
        pushButton_EEPROM->setObjectName(QString::fromUtf8("pushButton_EEPROM"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_EEPROM->sizePolicy().hasHeightForWidth());
        pushButton_EEPROM->setSizePolicy(sizePolicy);
        pushButton_EEPROM->setMinimumSize(QSize(0, 0));
        pushButton_EEPROM->setMaximumSize(QSize(15, 16777215));

        gridLayout->addWidget(pushButton_EEPROM, 0, 4, 2, 1);

        groupBox_UVLEDs = new QGroupBox(mslClass);
        groupBox_UVLEDs->setObjectName(QString::fromUtf8("groupBox_UVLEDs"));
        gridLayout_2 = new QGridLayout(groupBox_UVLEDs);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        spinBox_uv = new QSpinBox(groupBox_UVLEDs);
        spinBox_uv->setObjectName(QString::fromUtf8("spinBox_uv"));
        spinBox_uv->setMaximum(255);

        gridLayout_2->addWidget(spinBox_uv, 2, 1, 1, 1);

        verticalSlider_uv = new QSlider(groupBox_UVLEDs);
        verticalSlider_uv->setObjectName(QString::fromUtf8("verticalSlider_uv"));
        verticalSlider_uv->setMaximum(255);
        verticalSlider_uv->setOrientation(Qt::Vertical);

        gridLayout_2->addWidget(verticalSlider_uv, 4, 1, 1, 1);

        label = new QLabel(groupBox_UVLEDs);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 1, 1, 1, 1);

        verticalSlider_white = new QSlider(groupBox_UVLEDs);
        verticalSlider_white->setObjectName(QString::fromUtf8("verticalSlider_white"));
        verticalSlider_white->setMaximum(255);
        verticalSlider_white->setOrientation(Qt::Vertical);

        gridLayout_2->addWidget(verticalSlider_white, 4, 2, 1, 1);

        spinBox_white = new QSpinBox(groupBox_UVLEDs);
        spinBox_white->setObjectName(QString::fromUtf8("spinBox_white"));
        spinBox_white->setWrapping(false);
        spinBox_white->setMaximum(255);
        spinBox_white->setValue(0);

        gridLayout_2->addWidget(spinBox_white, 2, 2, 1, 1);

        label_2 = new QLabel(groupBox_UVLEDs);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 2, 1, 1);

        pushButton_UvWhiteOff = new QPushButton(groupBox_UVLEDs);
        pushButton_UvWhiteOff->setObjectName(QString::fromUtf8("pushButton_UvWhiteOff"));

        gridLayout_2->addWidget(pushButton_UvWhiteOff, 5, 1, 1, 2);

        pushButton_UV_White_Tggl = new QPushButton(groupBox_UVLEDs);
        pushButton_UV_White_Tggl->setObjectName(QString::fromUtf8("pushButton_UV_White_Tggl"));

        gridLayout_2->addWidget(pushButton_UV_White_Tggl, 6, 1, 1, 2);

        pushButton_Wmax = new QPushButton(groupBox_UVLEDs);
        pushButton_Wmax->setObjectName(QString::fromUtf8("pushButton_Wmax"));

        gridLayout_2->addWidget(pushButton_Wmax, 3, 2, 1, 1);

        pushButton_UVmax = new QPushButton(groupBox_UVLEDs);
        pushButton_UVmax->setObjectName(QString::fromUtf8("pushButton_UVmax"));

        gridLayout_2->addWidget(pushButton_UVmax, 3, 1, 1, 1);


        gridLayout->addWidget(groupBox_UVLEDs, 0, 2, 1, 2);


        retranslateUi(mslClass);
        QObject::connect(spinBox_uv, SIGNAL(valueChanged(int)), verticalSlider_uv, SLOT(setValue(int)));
        QObject::connect(verticalSlider_uv, SIGNAL(valueChanged(int)), spinBox_uv, SLOT(setValue(int)));
        QObject::connect(verticalSlider_white, SIGNAL(valueChanged(int)), spinBox_white, SLOT(setValue(int)));
        QObject::connect(spinBox_white, SIGNAL(valueChanged(int)), verticalSlider_white, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(mslClass);
    } // setupUi

    void retranslateUi(QWidget *mslClass)
    {
        mslClass->setWindowTitle(QApplication::translate("mslClass", "MicroScope LightControl", 0, QApplication::UnicodeUTF8));
        groupBox_RGBLEDs->setTitle(QApplication::translate("mslClass", "RGB LEDs", 0, QApplication::UnicodeUTF8));
        pushButton_RGB_off->setText(QApplication::translate("mslClass", "RGB off", 0, QApplication::UnicodeUTF8));
        pushButton_off->setText(QApplication::translate("mslClass", "Off", 0, QApplication::UnicodeUTF8));
        groupBox_EEProm->setTitle(QApplication::translate("mslClass", "EEPROM", 0, QApplication::UnicodeUTF8));
        pushButton_EE_currentSetting->setText(QApplication::translate("mslClass", "To current setting", 0, QApplication::UnicodeUTF8));
        pushButton_EE_Save->setText(QApplication::translate("mslClass", "SaveToEEProm", 0, QApplication::UnicodeUTF8));
        pushButton_EE_Read->setText(QApplication::translate("mslClass", "Read EEProm", 0, QApplication::UnicodeUTF8));
        pushButton_EEPROM->setText(QApplication::translate("mslClass", "\302\273", 0, QApplication::UnicodeUTF8));
        groupBox_UVLEDs->setTitle(QApplication::translate("mslClass", "UV/WHITE LEDs", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("mslClass", "UV", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("mslClass", "WHITE", 0, QApplication::UnicodeUTF8));
        pushButton_UvWhiteOff->setText(QApplication::translate("mslClass", "off", 0, QApplication::UnicodeUTF8));
        pushButton_UV_White_Tggl->setText(QApplication::translate("mslClass", "<>", 0, QApplication::UnicodeUTF8));
        pushButton_Wmax->setText(QApplication::translate("mslClass", "max", 0, QApplication::UnicodeUTF8));
        pushButton_UVmax->setText(QApplication::translate("mslClass", "max", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class mslClass: public Ui_mslClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSL_H
