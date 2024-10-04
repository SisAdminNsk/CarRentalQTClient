#include "carorderform.h"
#include "ui_carorderform.h"

CarOrderForm::CarOrderForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CarOrderForm)
{
    ui->setupUi(this);
    Setup();
}

void CarOrderForm::SetupApiRequest(){

}

void CarOrderForm::SetupInputWidgets(){
    ui->startLeaseDatePicker->setCalendarPopup(true);
    ui->endLeaseDatePicker->setCalendarPopup(true);

    ui->startLeaseDatePicker->setAccessibleName("fagag");

    for (int var = 0; var < 24; ++var) {
        ui->startLeaseTimePicker->addItem(QString::number(var) + ":" + "00");
        ui->endLeaseTimePicker->addItem(QString::number(var) + ":" + "00");
    }
}

void CarOrderForm::SetupWindow(){
    setFixedHeight(400);
    setFixedWidth(700);
}

void CarOrderForm::Setup(){
    SetupWindow();
    SetupInputWidgets();
    SetupApiRequest();
}

CarOrderForm::~CarOrderForm()
{
    delete ui;
}
