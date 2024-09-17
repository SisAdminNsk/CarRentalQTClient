#include "registrationwindow.h"
#include "ui_registrationwindow.h"
#include "RegistrationWindowDependeces/formvalidator.h"
#include "verificationcodewindow.h"
#include <QMessageBox>

RegistrationWindow::RegistrationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegistrationWindow)
{
    setWindowIcon(QIcon(":/Media/media/carsharingLogo.png"));

    setFixedSize(450,325);
    setMinimumSize(450,325);
    setMaximumSize(450,325);

    ui->setupUi(this);

    setupRegistrationForm();
}

void RegistrationWindow::setupRegistrationForm(){

    auto emailIconPixmap = QPixmap(":/Media/media/email.png");
    auto usernameIconPixmap = QPixmap(":/Media/media/usernameIcon.png");
    auto passwordIconPixmap = QPixmap(":/Media/media/passwordIcon.png");

    ui->emailIcon->setPixmap(emailIconPixmap.scaled(24,24, Qt::KeepAspectRatio));
    ui->passwordIcon->setPixmap(passwordIconPixmap.scaled(24,24, Qt::KeepAspectRatio));
    ui->confirmPasswordIcon->setPixmap(passwordIconPixmap.scaled(24,24, Qt::KeepAspectRatio));
    ui->usernameIcon->setPixmap(usernameIconPixmap.scaled(24,24, Qt::KeepAspectRatio));

    connectiWithSignals();
    setupCheckboxes();
    setupInputFields();
}

void RegistrationWindow::onRegistrateRequestStarted(){

    ui->registratePushButton->blockSignals(true);

    ui->statusbar->showMessage("Выполняется регистрация, пожалуйста подождите...");

    loadingLabel = new LoadingLabel(QSize(22, 22));

    ui->statusbar->addPermanentWidget(loadingLabel);

    loadingLabel->show();
}

void RegistrationWindow::onRegistrateRequestFinished(){

    ui->registratePushButton->blockSignals(false);
    ui->statusbar->clearMessage();
    delete loadingLabel;
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

    ui->emailLineEdit->setPlaceholderText("Введите свою электронную почту");
    ui->usernameLineEdit->setPlaceholderText("Введите имя нового пользователя");

    ui->passwordLineEdit->setPlaceholderText("Придумайте новый пароль");
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);

    ui->confirmPasswordLineEdit->setPlaceholderText("Введите пароль еще раз");
    ui->confirmPasswordLineEdit->setEchoMode(QLineEdit::Password);

    ui->confirmPasswordLineEdit->setEnabled(false);
}

void RegistrationWindow::setupCheckboxes(){

    ui->emailCheckbox->setEnabled(false);
    ui->emailCheckbox->setHidden(true);

    ui->usernameCheckbox->setEnabled(false);
    ui->usernameCheckbox->setHidden(true);

    ui->passwordCheckbox->setEnabled(false);
    ui->passwordCheckbox->setHidden(true);

    ui->confirmPasswordCheckbox->setEnabled(false);
    ui->confirmPasswordCheckbox->setHidden(true);
}

void RegistrationWindow::validateEmail(){

    auto email = ui->emailLineEdit->text();

    if(this->registeredEmails.contains(email)){

        ui->emailClue->setVisible(true);
        ui->emailCheckbox->setHidden(true);
        ui->emailClue->setText("Введенная почта уже зарегистрирована");
        ui->emailClue->setStyleSheet("color: red;");
        ui->emailCheckbox->setChecked(false);
        ui->emailLineEdit->setStyleSheet(checkboxNotValidStyleSheet);

        return;
    }

    bool isValid = FormValidator::isValidEmail(email);

    ui->emailCheckbox->setChecked(isValid);

    if(isValid){      
        onValidAction(ui->emailLineEdit, ui->emailClue, ui->emailCheckbox);
    }
    else{
        showDefaultEmailClue();
        onNotValidAction(ui->emailLineEdit,ui->emailClue, ui->emailCheckbox);
    }
}

void RegistrationWindow::validatePassword(){

    auto password = ui->passwordLineEdit->text();
    bool isValid = FormValidator::isValidPassword(password);
    ui->passwordCheckbox->setChecked(isValid);

    if(isValid){
        onValidAction(ui->passwordLineEdit, ui->passwordClue, ui->passwordCheckbox);
        ui->confirmPasswordLineEdit->setEnabled(true);
    }
    else{
        onNotValidAction(ui->passwordLineEdit, ui->passwordClue, ui->passwordCheckbox);
        ui->confirmPasswordLineEdit->setEnabled(false);
    }
}

void RegistrationWindow::validateConfirmPassword(){

    auto password = ui->passwordLineEdit->text();
    auto confirmPassword = ui->confirmPasswordLineEdit->text();

    if(confirmPassword == password){        
        ui->confirmPasswordLineEdit->setStyleSheet(checkboxValidStyleSheet);
        ui->confirmPasswordCheckbox->setChecked(true);
        ui->confirmPasswordCheckbox->setHidden(false);
    }
    else{
        ui->confirmPasswordLineEdit->setStyleSheet(checkboxNotValidStyleSheet);
        ui->confirmPasswordCheckbox->setChecked(false);
        ui->confirmPasswordCheckbox->setHidden(true);
    }
}

void RegistrationWindow::onNotValidAction(QLineEdit* lineEdit, QLabel* clue, QCheckBox* checkbox){

    lineEdit->setStyleSheet(checkboxNotValidStyleSheet);
    checkbox->setHidden(true);
    clue->setHidden(false);
}

void RegistrationWindow::onValidAction(QLineEdit* lineEdit, QLabel* clue, QCheckBox* checkbox){

    lineEdit->setStyleSheet(checkboxValidStyleSheet);
    checkbox->setHidden(false);
    clue->setHidden(true);
}

void RegistrationWindow::showDefaultEmailClue(){

    ui->emailClue->setText("Например: someperson@value.com");
    ui->emailClue->setStyleSheet("QLabel {font-size: 8pt;}");
}

void RegistrationWindow::showDefaultUsernameClue(){

    ui->usernameClue->setText("[ a-Z, 0-9, _ ] длина имени от 6 до 32 символов ");
    ui->usernameClue->setStyleSheet("QLabel {font-size: 8pt;}");
}

void RegistrationWindow::validateUsername(){

    auto username = ui->usernameLineEdit->text();

    if(registeredUsernames.contains(username)){

        ui->usernameClue->setVisible(true);
        ui->usernameCheckbox->setHidden(true);
        ui->usernameClue->setText("Данное имя занято");
        ui->usernameClue->setStyleSheet("color: red;");
        ui->usernameCheckbox->setChecked(false);
        ui->usernameLineEdit->setStyleSheet(checkboxNotValidStyleSheet);

        return;
    }

    bool isValid = FormValidator::isValidUsername(username);

    ui->usernameCheckbox->setChecked(isValid);

    if(isValid){
        onValidAction(ui->usernameLineEdit, ui->usernameClue, ui->usernameCheckbox);
    }
    else{
        showDefaultUsernameClue();
        onNotValidAction(ui->usernameLineEdit, ui->usernameClue, ui->usernameCheckbox);
    }
}

bool RegistrationWindow::isAllFormsValidated(){

    if(ui->usernameCheckbox->isChecked() && ui->emailCheckbox->isChecked() &&
        ui->passwordCheckbox->isChecked() && ui->confirmPasswordCheckbox->isChecked()){
        return true;
    }

    return false;
}

void RegistrationWindow::onRegistratePushButtonClicked(){

    if(isAllFormsValidated()){

        auto username = ui->usernameLineEdit->text();
        auto email = ui->emailLineEdit->text();
        auto password = ui->passwordLineEdit->text();

        registrateRequest = new RegistrateRequest(username, email, password);

        QObject::connect(registrateRequest, &RegistrateRequest::onFailure, this, &RegistrationWindow::onRegistrationError);
        QObject::connect(registrateRequest, &RegistrateRequest::onSuccess, this, &RegistrationWindow::onRegistrationSuccess);

        registrateRequest->sendRequest();
        onRegistrateRequestStarted();
    }
}

void RegistrationWindow::onRegistrationSuccess(const QString& message){

    onRegistrateRequestFinished();

    auto verificationCodeWindow = new VerificationCodeWindow(UserRegistrateDTO(
        ui->emailLineEdit->text(),
        ui->usernameLineEdit->text(),
        ui->passwordLineEdit->text()));

    close();
    verificationCodeWindow->show();

    //QMessageBox::information(nullptr, "Регистрация", message); // перейти к вводу кода подтверждения
}

void RegistrationWindow::onRegistrationError(const QMap<QString, QString>& errors){

    onRegistrateRequestFinished();

    if(errors.contains("Server")){
        QMessageBox::information(nullptr, "Регистрация", errors["Server"]);
        return;
    }


    if(errors.contains("Email")){

        ui->emailClue->setText("Введенная почта уже зарегистрирована");
        ui->emailClue->setStyleSheet("color: red;");
        ui->emailClue->setHidden(false);
        ui->emailCheckbox->setChecked(false);
        ui->emailCheckbox->setVisible(false);
        ui->emailLineEdit->setStyleSheet(checkboxNotValidStyleSheet);

        registeredEmails.insert(ui->emailLineEdit->text());
    }

    if(errors.contains("Username")){

        ui->usernameClue->setText("Введенное имя занято");
        ui->usernameClue->setStyleSheet("color: red;");
        ui->usernameClue->setHidden(false);
        ui->usernameCheckbox->setChecked(false);
        ui->usernameCheckbox->setVisible(false);
        ui->usernameLineEdit->setStyleSheet(checkboxNotValidStyleSheet);

        registeredUsernames.insert(ui->usernameLineEdit->text());
    }
}
