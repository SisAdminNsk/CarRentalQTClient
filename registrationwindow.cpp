#include "registrationwindow.h"
#include "ui_registrationwindow.h"
#include "RegistrationWindowDependeces/formvalidator.h"
#include <QMessageBox>

RegistrationWindow::RegistrationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegistrationWindow)
{
    setFixedSize(450,285);
    setMinimumSize(450,285);
    setMaximumSize(450,285);

    ui->setupUi(this);
    ui->registratePushButton->setEnabled(false);

    setupRegistrationForm();
}

void RegistrationWindow::setupRegistrationForm(){

    auto emailIconPixmap = QPixmap(":/Media/media/email.png");
    auto usernameIconPixmap = QPixmap(":/Media/media/usernameIcon.png");
    auto passwordIconPixmap = QPixmap(":/Media/media/passwordIcon.png");

    ui->emailIcon->setPixmap(emailIconPixmap.scaled(24,24, Qt::KeepAspectRatio));
    ui->passwordIcon->setPixmap(passwordIconPixmap.scaled(24,24,Qt::KeepAspectRatio));
    ui->confirmPasswordIcon->setPixmap(passwordIconPixmap.scaled(24,24,Qt::KeepAspectRatio));
    ui->usernameIcon->setPixmap(usernameIconPixmap.scaled(24,24,Qt::KeepAspectRatio));

    connectiWithSignals();
    setupCheckboxes();
    setupInputFields();
}

RegistrationWindow::~RegistrationWindow()
{
    delete ui;
}

void RegistrationWindow::connectiWithSignals(){

    QObject::connect(ui->registratePushButton, &QPushButton::clicked, this,
        &RegistrationWindow::onRegistratePushButtonClicked);

    QObject::connect(ui->emailLineEdit, &QLineEdit::textChanged, this, &RegistrationWindow::validateEmail);
    QObject::connect(ui->usernameLineEdit, &QLineEdit::textChanged, this, &RegistrationWindow::validateUsername);
    QObject::connect(ui->passwordLineEdit, &QLineEdit::textChanged, this, &RegistrationWindow::validatePassword);
    QObject::connect(ui->confirmPasswordLineEdit, &QLineEdit::textChanged, this, &RegistrationWindow::validateConfirmPassword);
}

void RegistrationWindow::setupInputFields(){

    this->ui->emailLineEdit->setPlaceholderText("Введите свою электронную почту");
    this->ui->usernameLineEdit->setPlaceholderText("Введите имя нового пользователя");

    this->ui->passwordLineEdit->setPlaceholderText("Придумайте новый пароль");
    this->ui->passwordLineEdit->setEchoMode(QLineEdit::Password);

    this->ui->confirmPasswordLineEdit->setPlaceholderText("Введите пароль еще раз");
    this->ui->confirmPasswordLineEdit->setEchoMode(QLineEdit::Password);

    this->ui->confirmPasswordLineEdit->setEnabled(false);
}

void RegistrationWindow::setupCheckboxes(){

    this->ui->emailCheckbox->setEnabled(false);
    this->ui->emailCheckbox->setHidden(true);

    this->ui->usernameCheckbox->setEnabled(false);
    this->ui->usernameCheckbox->setHidden(true);

    this->ui->passwordCheckbox->setEnabled(false);
    this->ui->passwordCheckbox->setHidden(true);

    this->ui->confirmPasswordCheckbox->setEnabled(false);
    this->ui->confirmPasswordCheckbox->setHidden(true);
}

void RegistrationWindow::validateEmail(){

    auto email = this->ui->emailLineEdit->text();
    bool isValid = FormValidator::isValidEmail(email);
    this->ui->emailCheckbox->setChecked(isValid);

    if(isValid){
        this->ui->emailLineEdit->setStyleSheet(checkboxValidStyleSheet);
        this->ui->emailCheckbox->setHidden(false);
    }else{
        this->ui->emailLineEdit->setStyleSheet(checkboxNotValidStyleSheet);
        this->ui->emailCheckbox->setHidden(true);
    }
}

void RegistrationWindow::validatePassword(){

    auto password = this->ui->passwordLineEdit->text();
    bool isValid = FormValidator::isValidPassword(password);
    this->ui->passwordCheckbox->setChecked(isValid);

    if(isValid){
        this->ui->passwordLineEdit->setStyleSheet(checkboxValidStyleSheet);
        this->ui->passwordCheckbox->setHidden(false);
        this->ui->confirmPasswordLineEdit->setEnabled(true);
    }else{
        this->ui->passwordLineEdit->setStyleSheet(checkboxNotValidStyleSheet);
        this->ui->passwordCheckbox->setHidden(true);
        this->ui->confirmPasswordLineEdit->setEnabled(false);
    }
}

void RegistrationWindow::validateConfirmPassword(){

    auto password = this->ui->passwordLineEdit->text();
    auto confirmPassword = this->ui->confirmPasswordLineEdit->text();

    if(confirmPassword == password){
        this->ui->confirmPasswordLineEdit->setStyleSheet(checkboxValidStyleSheet);
        this->ui->confirmPasswordCheckbox->setHidden(false);
    }else{
        this->ui->confirmPasswordLineEdit->setStyleSheet(checkboxNotValidStyleSheet);
        this->ui->confirmPasswordCheckbox->setHidden(true);
    }
}

void RegistrationWindow::validateUsername(){

    auto username = this->ui->usernameLineEdit->text();
    bool isValid = FormValidator::isValidUsername(username);
    this->ui->usernameCheckbox->setChecked(isValid);

    if(isValid){
        this->ui->usernameLineEdit->setStyleSheet(checkboxValidStyleSheet);
        this->ui->usernameCheckbox->setHidden(false);
        this->ui->usernameClue->setHidden(true);
    }else{
        this->ui->usernameLineEdit->setStyleSheet(checkboxNotValidStyleSheet);
        this->ui->usernameCheckbox->setHidden(true);
        this->ui->usernameClue->setHidden(false);
    }
}

void RegistrationWindow::onRegistratePushButtonClicked(){

    auto username = ui->usernameLineEdit->text();
    auto email = ui->emailLineEdit->text();
    auto password = ui->passwordLineEdit->text();

    this->registrateRequest = new RegistrateRequest(username, email, password);

    QObject::connect(registrateRequest, &RegistrateRequest::onFailure, this, &RegistrationWindow::onRegistrationError);
    QObject::connect(registrateRequest, &RegistrateRequest::onSuccess, this, &RegistrationWindow::onRegistrationSuccess);

    this->registrateRequest->sendRequest();
}

void RegistrationWindow::onRegistrationSuccess(const QString& message){
    QMessageBox::information(nullptr, "Регистрация", message);
}

void RegistrationWindow::onRegistrationError(const QList<QString>& message){
    //QMessageBox::information(nullptr, "Регистрация", message);
}

