#include "carrentalclientmainwindow.h"
#include "ui_carrentalclientmainwindow.h"

CarRentalClientMainWindow::CarRentalClientMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CarRentalClientMainWindow)
{
    ui->setupUi(this);

    this->cabinetViewModel = new CabinetViewModel();
    this->carsViewModel = new CarsViewModel();

    ui->stackedWidget->addWidget(cabinetViewModel);
    ui->stackedWidget->addWidget(carsViewModel);
    ui->stackedWidget->setCurrentWidget(cabinetViewModel);

    QObject::connect(ui->cabinetButton, &QPushButton::clicked, this, &CarRentalClientMainWindow::OnCabinetButtonClicked);
    QObject::connect(ui->carsButton, &QPushButton::clicked, this, &CarRentalClientMainWindow::OnCarsButtonClicked);
}

void CarRentalClientMainWindow::OnCabinetButtonClicked(){
    ui->stackedWidget->setCurrentWidget(cabinetViewModel);
    ui->cabinetButton->setStyleSheet("QPushButton { "
                                     "color: white; "
                                     "background-color: green; "
                                     "} ");
}

void CarRentalClientMainWindow::OnCarsButtonClicked(){
    ui->stackedWidget->setCurrentWidget(carsViewModel);
}

CarRentalClientMainWindow::~CarRentalClientMainWindow()
{
    delete ui;
}
