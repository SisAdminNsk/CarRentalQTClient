
#include "mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(425,285);
    w.setMinimumSize(425,285);
    w.setMaximumSize(425,285);
    w.show();
    return a.exec();
}
