#include "personaldataviewmodel.h"
#include "ui_personaldataviewmodel.h"

PersonalDataViewModel::PersonalDataViewModel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonalDataViewModel)
{
    ui->setupUi(this);

    ui->emailEdit->setEnabled(false);
}

PersonalDataViewModel::~PersonalDataViewModel()
{
    delete ui;
}
