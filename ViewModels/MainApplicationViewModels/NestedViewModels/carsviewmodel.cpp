#include "carsviewmodel.h"
#include "ui_carsviewmodel.h"

#include <API/DTO/cardto.h>
#include <QMessageBox>

CarsViewModel::CarsViewModel(const LoginResponse& loginResponse, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CarsViewModel)
{
    this->cardWidth = 350;
    this->cardHeight = 350;

    ui->setupUi(this);

    getAllCarsRequest = new GetAllCarsRequest(loginResponse.Token);

    QObject::connect(getAllCarsRequest,&GetAllCarsRequest::OnSuccessSingal,this,&CarsViewModel::OnGettingAllCarsSuccess);
    QObject::connect(getAllCarsRequest,&GetAllCarsRequest::OnFailureSignal, this,&CarsViewModel::OnGettingAllCarsFailure);
    getAllCarsRequest->SendApiRequest();
    // показать выполнения загрузки

    // тестовый код
    //for(size_t i=0;i<8;i++){
        //QString imagePath = ":/images/Media/lexus_lx450_black.jpg";
        //QString description = QString("Product %1").arg(i + 1);
        //double price = (i + 1) * 10.0;

        //auto carDto = CarDTO();
        //auto carCard = new CarCardViewModel(carDto, QSize(350,350));
        //CarCard *card = new CarCard(imagePath, description, price, QSize(400,400));
        //AddCar(carCard);
    //}
}

void CarsViewModel::OnGettingAllCarsSuccess(const QList<CarDTO> &replyBody){


    ui->progressBar->reset();
    ui->progressBar->show();

    urlImageLoader = new FromURLImageLoader(ui->progressBar);
    urlImageLoader->SetTargetsForDownloadCount(replyBody.size());

    QObject::connect(urlImageLoader,&FromURLImageLoader::OnAllImagesDownloaded, this, &CarsViewModel::OnAllImagesDownloaded);

    for(size_t i=0;i<replyBody.size();i++){
        auto carCard = new CarCardViewModel(replyBody[i], QSize(350,350));
        urlImageLoader->LoadImage(replyBody[i].CarImageURI, carCard);
    }
}

void CarsViewModel::OnAllImagesDownloaded(QList<CarCardViewModel*> carCards){

    for(size_t i=0;i<carCards.size();i++){
        AddCar(carCards[i]);
    }

    ui->progressBar->hide();
    ui->progressBar->reset();
}


void CarsViewModel::OnGettingAllCarsFailure(const QString& error){

    QMessageBox::information(this, "Ошибка получения каталога авто", error);
}

void CarsViewModel::AddCarToGrid(CarCardViewModel *carCard){

    if (currentRowWidth + cardWidth > width()) {
        currentRow++;
        currentRowWidth = 0;
        currentColumn = 0;
    }

    ui->gridLayout_2->addWidget(carCard, currentRow, currentColumn);
    currentRowWidth += cardWidth + ui->gridLayout_2->spacing();

    currentColumn++;
}

void CarsViewModel::AddCar(CarCardViewModel *carCard){

    AddCarToGrid(carCard);
    cars.push_back(carCard);
}

void CarsViewModel::resizeEvent(QResizeEvent *event){

    currentRow = 0;
    currentColumn = 0;
    currentRowWidth = 0;

    QLayoutItem *item;
    while ((item = ui->gridLayout_2->takeAt(0)) != nullptr) {
        ui->gridLayout_2->removeItem(item);
    }

    for(size_t i=0;i<cars.size();i++){
        AddCarToGrid(cars[i]);
    }

    QWidget::resizeEvent(event);
}

CarsViewModel::~CarsViewModel()
{
    delete ui;
}
