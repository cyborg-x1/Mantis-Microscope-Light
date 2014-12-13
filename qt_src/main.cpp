#include "msl.h"
#include "ui_msl.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    msl w;
    w.show();
    return a.exec();
}
