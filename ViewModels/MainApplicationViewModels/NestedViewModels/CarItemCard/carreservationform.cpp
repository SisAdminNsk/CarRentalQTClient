#include "carreservationform.h"
#include "ui_carreservationform.h"

CarReservationForm::CarReservationForm(
    const CarDTO& car,
    const QPixmap& carImagePixmap,
    const CarsharingUserDTO& carsharingUser,
    const QDateTime& serverDateTime,
    QWidget *parent) :

    QDialog(parent),
    car(car),
    carImagePixmap(carImagePixmap),
    carsharingUser(carsharingUser),
    serverDateTime(serverDateTime),
    ui(new Ui::CarReservationForm)
{
    ui->setupUi(this);
    Setup();
}

CarReservationForm::~CarReservationForm()
{
    delete ui;
}

void CarReservationForm::SetupApiRequest(){

}

void CarReservationForm::SetupInputWidgets(){

    ui->startLeaseDatePicker->setCalendarPopup(true);
    ui->endLeaseDatePicker->setCalendarPopup(true);

    ui->endLeaseDatePicker->setMinimumDate(serverDateTime.date());
    ui->startLeaseDatePicker->setMinimumDate(serverDateTime.date());

    for (int var = serverDateTime.time().hour(); var < 24; ++var) {
        ui->startLeaseTimePicker->addItem(QString::number(var) + ":" + "00");
        ui->endLeaseTimePicker->addItem(QString::number(var) + ":" + "00");
    }

    connect(ui->startLeaseTimePicker, &QComboBox::currentIndexChanged, this, &CarReservationForm::OnStartOfLeaseTimeSelected);
    connect(ui->startLeaseDatePicker, &QDateEdit::dateChanged, this, &CarReservationForm::OnStartOfLeaseDateSelected);
    connect(ui->endLeaseDatePicker, &QDateEdit::dateChanged, this, &CarReservationForm::OnEndOfLeaseDateSelected);
}

void CarReservationForm::FillPersonalData(){
    ui->firstnameEdit->setText(carsharingUser.Name);
    ui->surnameEdit->setText(carsharingUser.Surname);
    ui->patronymicEdit->setText(carsharingUser.Patronymic);
    ui->phoneEdit->setText(carsharingUser.Phone);

    ui->firstnameEdit->setEnabled(false);
    ui->surnameEdit->setEnabled(false);
    ui->patronymicEdit->setEnabled(false);
    ui->phoneEdit->setEnabled(false);
}

void CarReservationForm::FillCarData(){

    ui->CarImage->setPixmap(carImagePixmap.scaled(QSize(350,350), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->carName->setText(car.Brand + " " + car.Model);
    ui->carAceleration->setText(QString::number(car.CarAcceleration));
    ui->carPower->setText(QString::number(car.Power));
    ui->carClass->setText(car.CarClass);
    ui->carPrice->setText(QString::number(car.BaseRentalPricePerHour));
}

void CarReservationForm::SetupWindow(){
    setFixedHeight(400);
    setFixedWidth(700);
}

void CarReservationForm::Setup(){
    SetupWindow();
    SetupInputWidgets();
    SetupApiRequest();

    FillPersonalData();
    FillCarData();
}

void CarReservationForm::OnStartOfLeaseDateSelected(const QDate& date){

    ui->endLeaseDatePicker->setMinimumDate(date);
}

void CarReservationForm::OnEndOfLeaseDateSelected(const QDate& date){

    if(ui->startLeaseDatePicker->date() < ui->endLeaseDatePicker->date()){
        OnStartOfLeaseTimeSelected(0);
    }
    else{
        OnStartOfLeaseTimeSelected(ui->startLeaseTimePicker->currentIndex());
    }
}

void CarReservationForm::OnStartOfLeaseTimeSelected(const int currentSelectedIndex){

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

void CarReservationForm::OnEndOfLeaseTimeSelected(const int currentSelectedIndex){

}
