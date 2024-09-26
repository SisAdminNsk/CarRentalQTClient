#include "carsviewmodel.h"
#include "ui_carsviewmodel.h"

CarsViewModel::CarsViewModel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CarsViewModel)
{
    ui->setupUi(this);
}

CarsViewModel::~CarsViewModel()
{
    delete ui;
}
