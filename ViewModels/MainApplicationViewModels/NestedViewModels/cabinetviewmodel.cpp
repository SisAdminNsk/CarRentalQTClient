#include "cabinetviewmodel.h"
#include "ui_cabinetviewmodel.h"

CabinetViewModel::CabinetViewModel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CabinetViewModel)
{
    ui->setupUi(this);

    this->personalViewModel = new PersonalDataViewModel();
    this->activeOrdersViewModel = new ActiveOrdersViewModel();
    this->closedOrdersViewModel = new ClosedOrdersViewModel();

    ui->stackedWidget->addWidget(personalViewModel);
    ui->stackedWidget->addWidget(activeOrdersViewModel);
    ui->stackedWidget->addWidget(closedOrdersViewModel);

    QObject::connect(ui->profileDataButton, &QPushButton::clicked,this,&CabinetViewModel::OnPersonalDataButtonClicked);
    QObject::connect(ui->activeOrdersButton, &QPushButton::clicked,this,&CabinetViewModel::OnActiveOrdersButtonClicked);
    QObject::connect(ui->closedOrdersButton, &QPushButton::clicked,this,&CabinetViewModel::OnClosedOrdersButtonClicked);
}

void CabinetViewModel::OnPersonalDataButtonClicked(){
    ui->stackedWidget->setCurrentWidget(personalViewModel);
}

void CabinetViewModel::OnActiveOrdersButtonClicked(){
    ui->stackedWidget->setCurrentWidget(activeOrdersViewModel);
}

void CabinetViewModel::OnClosedOrdersButtonClicked(){
    ui->stackedWidget->setCurrentWidget(closedOrdersViewModel);
}

CabinetViewModel::~CabinetViewModel()
{
    delete ui;
}
