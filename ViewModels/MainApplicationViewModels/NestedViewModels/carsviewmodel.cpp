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

    ConnectWithFilterButtonsSignals();

    auto getCarsDTO = GetCarsDTO(currentPage, pageSize, ascendingSortOrder, "BaseRentalPricePerHour");
    prevFilterName = ui->cheaperFirstRadioButton->objectName();
    ui->cheaperFirstRadioButton->setChecked(true);

    getCarsRequest = new GetCarsRequest(loginResponse.Token, getCarsDTO, this);

    QObject::connect(getCarsRequest,&GetCarsRequest::OnSuccessSingal,this,&CarsViewModel::OnGettingCarsSuccess);
    QObject::connect(getCarsRequest,&GetCarsRequest::OnFailureSignal, this,&CarsViewModel::OnGettingCarsFailure);

    getCarsRequest->SendApiRequest();
}

void CarsViewModel::ConnectWithFilterButtonsSignals(){

    QObject::connect(ui->cheaperFirstRadioButton, &QRadioButton::clicked, this, &CarsViewModel::OnCheaperFirstFilterClicked);
    QObject::connect(ui->expensiveFirstRadioButton, &QRadioButton::clicked, this, &CarsViewModel::OnMoreExpensiveFirstFilterClicked);
    QObject::connect(ui->morePowerFirstRadioButton, &QRadioButton::clicked, this, &CarsViewModel::OnMostPowerFilterClicked);
    QObject::connect(ui->classLowerFirstRadioButton, &QRadioButton::clicked, this, &CarsViewModel::OnLowestClassFilterClicked);
    QObject::connect(ui->classHigherFirstRadioButton, &QRadioButton::clicked, this, &CarsViewModel::OnHigerClassFilterClicked);
}

void CarsViewModel::OnGettingsCarsStarted(){
    ui->cheaperFirstRadioButton->setEnabled(false);
    ui->expensiveFirstRadioButton->setEnabled(false);
    ui->classHigherFirstRadioButton->setEnabled(false);
    ui->classLowerFirstRadioButton->setEnabled(false);
    ui->morePowerFirstRadioButton->setEnabled(false);
    ui->showMoreButton->setEnabled(false);
}

void CarsViewModel::OnGettingsCarsFinished(){
    ui->cheaperFirstRadioButton->setEnabled(true);
    ui->expensiveFirstRadioButton->setEnabled(true);
    ui->classHigherFirstRadioButton->setEnabled(true);
    ui->classLowerFirstRadioButton->setEnabled(true);
    ui->morePowerFirstRadioButton->setEnabled(true);
    ui->showMoreButton->setEnabled(true);
}

void CarsViewModel::OnFilterClicked(
    QRadioButton* filterSelectorButton,
    const QString& sortingOrder,
    const QString& sortingByFiled)
{
    if(filterSelectorButton->objectName() != prevFilterName){
        OnGettingsCarsStarted();
        auto getCars = GetCarsDTO(currentPage, pageSize, sortingOrder, sortingByFiled);
        getCarsRequest->SetQueryString(getCars);
        getCarsRequest->SendApiRequest();
        ClearGridFromCarCards();
        this->cars.clear();
        this->currentPage = 1;
        prevFilterName = filterSelectorButton->objectName();
    }
}

void CarsViewModel::OnCheaperFirstFilterClicked(){

    OnFilterClicked(ui->cheaperFirstRadioButton,ascendingSortOrder, "BaseRentalPricePerHour");
}

void CarsViewModel::OnMoreExpensiveFirstFilterClicked(){

    OnFilterClicked(ui->expensiveFirstRadioButton, descendingSortOrder, "BaseRentalPricePerHour");
}

void CarsViewModel::OnMostPowerFilterClicked(){

    OnFilterClicked(ui->morePowerFirstRadioButton, descendingSortOrder, "Power");
}

void CarsViewModel::OnHigerClassFilterClicked(){
    OnFilterClicked(ui->classHigherFirstRadioButton, descendingSortOrder, "CarClass");
}

void CarsViewModel::OnLowestClassFilterClicked(){
    OnFilterClicked(ui->classLowerFirstRadioButton, ascendingSortOrder, "CarClass");
}

void CarsViewModel::OnGettingCarsSuccess(const GetCarsResponse& responseBody){
    ui->progressBar->reset();
    ui->progressBar->show();

    urlImageLoader = new FromURLImageLoader(ui->progressBar);
    urlImageLoader->SetTargetsForDownloadCount(responseBody.Cars.size());

    QObject::connect(urlImageLoader,&FromURLImageLoader::OnAllImagesDownloaded, this, &CarsViewModel::OnAllImagesDownloaded);

    QList<QString> urls;
    QList<CarCardViewModel*> carCards;

    for(size_t i=0;i<responseBody.Cars.size();i++){
        urls.push_back(responseBody.Cars[i].CarImageURI);
        carCards.push_back(new CarCardViewModel(responseBody.Cars[i], QSize(cardWidth, cardHeight),this));
    }

    urlImageLoader->LoadImagesWithOrderSaving(urls, carCards);
}

void CarsViewModel::OnGettingCarsFailure(const QString& errorMessage){
    QMessageBox::information(this, "Ошибка получения каталога авто", errorMessage);
    OnGettingsCarsFinished();
}

void CarsViewModel::OnAllImagesDownloaded(QList<CarCardViewModel*> carCards){

    for(size_t i=0;i<carCards.size();i++){
        AddCar(carCards[i]);
    }

    ui->progressBar->hide();
    ui->progressBar->reset();
    OnGettingsCarsFinished();
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

void CarsViewModel::ResetGridParameters(){

    currentRow = 0;
    currentColumn = 0;
    currentRowWidth = 0;
}

void CarsViewModel::resizeEvent(QResizeEvent *event){

    ResetGridParameters();

    int count = ui->gridLayout_2->count();

    for (int i = count - 1; i >= 0; --i){
        QLayoutItem *item = ui->gridLayout_2->itemAt(i);
        ui->gridLayout_2->removeItem(item);
        ui->gridLayout_2->removeWidget(item->widget());
    }

    for(size_t i=0;i<cars.size();i++){
        AddCarToGrid(cars[i]);
    }

    QWidget::resizeEvent(event);
}

void CarsViewModel::ClearGridFromCarCards(){

    ResetGridParameters();

    int count = ui->gridLayout_2->count();

    for (int i = count - 1; i >= 0; --i) {
        QLayoutItem *item = ui->gridLayout_2->itemAt(i);
        ui->gridLayout_2->removeItem( item );
        ui->gridLayout_2->removeWidget(item->widget());
        item->widget()->deleteLater();
    }
}

CarsViewModel::~CarsViewModel()
{
    delete ui;
}
