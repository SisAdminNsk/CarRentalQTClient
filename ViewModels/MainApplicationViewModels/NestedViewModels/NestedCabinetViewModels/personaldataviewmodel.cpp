#include "personaldataviewmodel.h"
#include "ui_personaldataviewmodel.h"

#include "staticuserdata.h"

#include "ViewModels/Validators/personaldatavalidator.h"

PersonalDataViewModel::PersonalDataViewModel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonalDataViewModel)
{
    ui->setupUi(this);

    ui->emailEdit->setEnabled(false);

    lastProfileData.Email = DataCache::instance().getData("userEmail");
    lastProfileData.Age = 0;

    ConnectWithSignals();
}

void PersonalDataViewModel::WhenSwappedToView(){
    this->FillProfileData(lastProfileData);
}

bool PersonalDataViewModel::IsAllFormsValidated(){
    if(isValidAge && isValidName && isValidSurname && isValidPatronymic && isValidPhone){

        auto validCarhsaringUserData = CarsharingUserDTO();

        validCarhsaringUserData.Name = ui->nameEdit->text();
        validCarhsaringUserData.Surname = ui->surnameEdit->text();
        validCarhsaringUserData.Email = ui->emailEdit->text();
        validCarhsaringUserData.Patronymic = ui->patronymicEdit->text();
        validCarhsaringUserData.Age = ui->ageEdit->text().toInt();
        validCarhsaringUserData.Phone = ui->phoneEdit->text();

        lastProfileData = validCarhsaringUserData;

        isAllDataValid = true;
        return true;
    }

    isAllDataValid = false;
    return false;
}

void PersonalDataViewModel::ConnectWithSignals(){

    QObject::connect(ui->saveChangesButton, &QPushButton::clicked, this, &PersonalDataViewModel::OnSaveChangesButtonClicked);

    QObject::connect(ui->ageEdit, &QLineEdit::textChanged, this, &PersonalDataViewModel::ValidateAge);
    QObject::connect(ui->phoneEdit, &QLineEdit::textChanged, this, &PersonalDataViewModel::ValidatePhone);
    QObject::connect(ui->nameEdit, &QLineEdit::textChanged, this, &PersonalDataViewModel::ValidateName);
    QObject::connect(ui->surnameEdit, &QLineEdit::textChanged, this, &PersonalDataViewModel::ValidateSurname);
    QObject::connect(ui->patronymicEdit, &QLineEdit::textChanged, this, &PersonalDataViewModel::ValidatePatronymic);
}

void PersonalDataViewModel::OnSaveChangesButtonClicked(){
    if(IsAllFormsValidated()){

        // выполняем логику
    }
}

void PersonalDataViewModel::ValidateAge(){

    auto age = ui->ageEdit->text();

    bool isValid = PersonalDataValidator::IsValidAge(age);

    if(isValid){
        isValidAge = true;
        ui->ageClue->hide();
        ui->ageEdit->setStyleSheet(lineEditValidStyleSheet);
    }
    else{
        isValidAge = false;
        ui->ageClue->show();
        ui->ageEdit->setStyleSheet(lineEditNotValidStyleSheet);
    }
}

void PersonalDataViewModel::ValidatePhone(){

    auto phone = ui->phoneEdit->text();

    bool isValid = PersonalDataValidator::IsValidPhone(phone);

    if(isValid){
        isValidPhone = true;
        ui->phoneClue->hide();
        ui->phoneEdit->setStyleSheet(lineEditValidStyleSheet);
    }
    else{
        isValidPhone = false;
        ui->phoneClue->show();
        ui->phoneEdit->setStyleSheet(lineEditNotValidStyleSheet);
    }
}

void PersonalDataViewModel::ValidateName(){

    auto name = ui->nameEdit->text();

    bool isValid = PersonalDataValidator::IsValidInitials(name);

    if(isValid){
        isValidName = true;
        ui->nameClue->hide();
        ui->nameEdit->setStyleSheet(lineEditValidStyleSheet);
    }
    else{
        isValidName = false;
        ui->nameClue->show();
        ui->nameEdit->setStyleSheet(lineEditNotValidStyleSheet);
    }
}

void PersonalDataViewModel::ValidateSurname(){

    auto surname = ui->surnameEdit->text();

    bool isValid = PersonalDataValidator::IsValidInitials(surname);

    if(isValid){
        isValidSurname = true;
        ui->surnameClue->hide();
        ui->surnameEdit->setStyleSheet(lineEditValidStyleSheet);
    }
    else{
        isValidSurname = false;
        ui->surnameClue->show();
        ui->surnameEdit->setStyleSheet(lineEditNotValidStyleSheet);
    }
}

void PersonalDataViewModel::ValidatePatronymic(){

    auto patronymic = ui->patronymicEdit->text();

    bool isValid = PersonalDataValidator::IsValidInitials(patronymic);

    if(isValid){
        isValidPatronymic = true;
        ui->patronymicClue->hide();
        ui->patronymicEdit->setStyleSheet(lineEditValidStyleSheet);
    }
    else{
        isValidPatronymic = false;
        ui->patronymicClue->show();
        ui->patronymicEdit->setStyleSheet(lineEditNotValidStyleSheet);
    }
}

void PersonalDataViewModel::FillProfileData(const CarsharingUserDTO& carsharingUser){

    ui->ageEdit->setText(QString::fromStdString(std::to_string(carsharingUser.Age)));
    ui->emailEdit->setText(carsharingUser.Email);
    ui->phoneEdit->setText(carsharingUser.Phone);
    ui->nameEdit->setText(carsharingUser.Name);
    ui->surnameEdit->setText(carsharingUser.Surname);
    ui->patronymicEdit->setText(carsharingUser.Patronymic);

    ValidateAllForms();

    this->lastProfileData = carsharingUser;
}

void PersonalDataViewModel::ValidateAllForms(){
    ValidateAge();
    ValidateName();
    ValidateSurname();
    ValidatePatronymic();
    ValidatePhone();
}

CarsharingUserDTO PersonalDataViewModel::GetProfileData(){
    return this->lastProfileData;
}

PersonalDataViewModel::~PersonalDataViewModel()
{
    delete ui;
}
