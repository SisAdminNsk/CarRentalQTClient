
#include "mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(450,285);
    w.setMinimumSize(450,285);
    w.setMaximumSize(450,285);
    w.show();
    return a.exec();
}
