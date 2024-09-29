#include "carcardviewmodel.h"
#include "ui_carcardviewmodel.h"

#include <QPalette>
#include <QPixmap>

CarCardViewModel::CarCardViewModel(const CarDTO& carDto, const QSize& cardSize, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CarCardViewModel),
    cardSize(cardSize),
    carDto(carDto)
{
    ui->setupUi(this);

    InitializeCarData();
    setFixedSize(cardSize);
}

void CarCardViewModel::InitializeCarData(){
    ui->carModelName->setText(carDto.Model);
    ui->carBrandName->setText(carDto.Brand);
    ui->carClass->setText(carDto.CarClass);       
    ui->carPower->setText(QString::fromStdString(std::to_string(carDto.Power)));
    ui->rentalPrice->setText(QString::number(carDto.BaseRentalPricePerHour, 'f', 2));
    ui->carAcseleration->setText(QString::number(carDto.CarAcceleration, 'f', 1));
}

void CarCardViewModel::SetImageFromPixmap(const QPixmap& pixmap){
    ui->carImage->setPixmap(
        pixmap.scaled(QSize(cardSize.width() * 0.8, cardSize.height() * 0.8),
        Qt::KeepAspectRatio,
        Qt::SmoothTransformation));
}

CarCardViewModel::~CarCardViewModel()
{
    delete ui;
}
