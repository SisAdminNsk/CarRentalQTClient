#include "carrentalclientwindow.h"
#include "ui_carrentalclientwindow.h"

CarRentalClientWindow::CarRentalClientWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CarRentalClientWindow)
{
    ui->setupUi(this);
}

CarRentalClientWindow::~CarRentalClientWindow()
{
    delete ui;
}
