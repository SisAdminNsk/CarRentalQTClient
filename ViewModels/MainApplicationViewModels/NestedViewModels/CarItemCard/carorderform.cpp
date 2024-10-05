#include "carorderform.h"
#include "ui_carorderform.h"

CarOrderForm::CarOrderForm(
    const CarDTO& car,
    const CarsharingUserDTO& carsharingUser,
    const QDate& serverDate,
    QWidget *parent) :

    QMainWindow(parent),
    serverDate(serverDate),
    car(car),
    carsharingUser(carsharingUser),
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

    ui->startLeaseDatePicker->setDateRange(serverDate, QDate(2100,12,31));
    ui->endLeaseDatePicker->setDateRange(serverDate, QDate(2100,12,31));

    for (int var = 0; var < 24; ++var) {
        ui->startLeaseTimePicker->addItem(QString::number(var) + ":" + "00");
        ui->endLeaseTimePicker->addItem(QString::number(var) + ":" + "00");
    }

    connect(ui->startLeaseTimePicker, &QComboBox::currentIndexChanged, this, &CarOrderForm::OnStartOfLeaseTimeSelected);
    connect(ui->startLeaseDatePicker, &QDateEdit::dateChanged, this, &CarOrderForm::OnStartOfLeaseDateSelected);
    connect(ui->endLeaseDatePicker, &QDateEdit::dateChanged, this, &CarOrderForm::OnEndOfLeaseDateSelected);
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

void CarOrderForm::OnStartOfLeaseDateSelected(const QDate& date){
    ui->endLeaseDatePicker->setMinimumDate(date);
}

void CarOrderForm::OnEndOfLeaseDateSelected(const QDate& date){

}

void CarOrderForm::OnStartOfLeaseTimeSelected(const int currentSelectedIndex){

    ui->endLeaseTimePicker->clear();

    QMap<int,QString> indexToTime;

    for(size_t i=0;i<24;i++){
        indexToTime[i] = QString::number(i) + ":00";
    }

    if(ui->startLeaseDatePicker->dateTime() == ui->endLeaseDatePicker->dateTime()){
        for(size_t i=currentSelectedIndex; i<=23; i++){
            ui->endLeaseTimePicker->addItem(indexToTime[i]);
        }
    }
    else{
        for(size_t i=0;i<24;i++){
            ui->endLeaseTimePicker->addItem(indexToTime[i]);
        }
    }
}

void CarOrderForm::OnEndOfLeaseTimeSelected(const int currentSelectedIndex){

}

CarOrderForm::~CarOrderForm()
{
    delete ui;
}
