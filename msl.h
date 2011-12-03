#ifndef MSL_H
#define MSL_H

#include <QtGui/QWidget>
#include <QColorDialog>
#include <qdebug.h>
#include "ui_msl.h"

class msl : public QWidget
{
    Q_OBJECT
    QColorDialog *colorDialog;

	public:
		msl(QWidget *parent = 0);
		~msl();

	private:
		Ui::mslClass ui;


	void updateLEDs();

	private slots:
		void colorChanged (const QColor & color);
		void on_pushButton_Wmax_clicked();
		void on_pushButton_UVmax_clicked();
		void on_pushButton_off_clicked();
		void on_verticalSlider_rgb_valueChanged(int value);
		void on_verticalSlider_uv_valueChanged(int value);
		void on_verticalSlider_white_valueChanged(int value);
		void on_pushButton_EEPROM_clicked();
		void on_pushButton_RGB_off_clicked();
		void on_pushButton_UV_White_Tggl_clicked();
		void on_pushButton_UvWhiteOff_clicked();
		void on_pushButton_EE_Save_clicked();
		void on_pushButton_EE_Read_clicked();
		void on_pushButton_EE_currentSetting_clicked();
};

#endif // MSL_H
