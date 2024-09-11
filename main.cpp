
#include "mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(360,230);
    w.setMinimumSize(360,230);
    w.setMaximumSize(360,230);
    w.show();
    return a.exec();
}
