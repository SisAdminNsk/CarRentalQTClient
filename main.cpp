
#include "mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(380,285);
    w.setMinimumSize(380,285);
    w.setMaximumSize(380,285);
    w.show();
    return a.exec();
}
