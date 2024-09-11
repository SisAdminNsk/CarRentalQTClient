
#include "mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(350,220);
    w.setMinimumSize(350,220);
    w.setMaximumSize(350,220);
    w.show();
    return a.exec();
}
