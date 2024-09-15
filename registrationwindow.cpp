#include "registrationwindow.h"
#include "ui_registrationwindow.h"
#include "RegistrationWindowDependeces/formvalidator.h"
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

    this->ui->statusbar->addPermanentWidget(loadingLabel);

    loadingLabel->show();
}

void RegistrationWindow::onRegistrateRequestFinished(){

    ui->registratePushButton->blockSignals(false);
    this->ui->statusbar->clearMessage();
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

    if(this->registeredEmails.contains(email)){
        this->ui->emailClue->setVisible(true);
        this->ui->emailCheckbox->setHidden(true);
        this->ui->emailClue->setText("Введенная почта уже зарегистрирована");
        this->ui->emailClue->setStyleSheet("color: red;");
        this->ui->emailCheckbox->setChecked(false);
        this->ui->emailLineEdit->setStyleSheet(checkboxNotValidStyleSheet);

        return;
    }

    bool isValid = FormValidator::isValidEmail(email);

    this->ui->emailCheckbox->setChecked(isValid);

    if(isValid){      
        onValidAction(this->ui->emailLineEdit, this->ui->emailClue, this->ui->emailCheckbox);
    }
    else{
        showDefaultEmailClue();
        onNotValidAction(this->ui->emailLineEdit,this->ui->emailClue, this->ui->emailCheckbox);
    }
}

void RegistrationWindow::validatePassword(){

    auto password = this->ui->passwordLineEdit->text();
    bool isValid = FormValidator::isValidPassword(password);
    this->ui->passwordCheckbox->setChecked(isValid);

    if(isValid){
        this->ui->passwordLineEdit->setStyleSheet(checkboxValidStyleSheet);
        this->ui->passwordCheckbox->setHidden(false);
        this->ui->passwordClue->setHidden(true);
        this->ui->confirmPasswordLineEdit->setEnabled(true);
    }
    else{
        this->ui->passwordLineEdit->setStyleSheet(checkboxNotValidStyleSheet);
        this->ui->passwordCheckbox->setHidden(true);
        this->ui->passwordClue->setHidden(false);
        this->ui->confirmPasswordLineEdit->setEnabled(false);
    }
}

void RegistrationWindow::validateConfirmPassword(){

    auto password = this->ui->passwordLineEdit->text();
    auto confirmPassword = this->ui->confirmPasswordLineEdit->text();

    if(confirmPassword == password){
        this->ui->confirmPasswordLineEdit->setStyleSheet(checkboxValidStyleSheet);
        this->ui->confirmPasswordCheckbox->setChecked(true);
        this->ui->confirmPasswordCheckbox->setHidden(false);
    }
    else{
        this->ui->confirmPasswordLineEdit->setStyleSheet(checkboxNotValidStyleSheet);
        this->ui->confirmPasswordCheckbox->setChecked(false);
        this->ui->confirmPasswordCheckbox->setHidden(true);
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

    this->ui->emailClue->setText("Например: someperson@value.com");
    this->ui->emailClue->setStyleSheet("QLabel {font-size: 8pt;}");
}

void RegistrationWindow::showDefaultUsernameClue(){

    this->ui->usernameClue->setText("[ a-Z, 0-9, _ ] длина имени от 6 до 32 символов ");
    this->ui->usernameClue->setStyleSheet("QLabel {font-size: 8pt;}");
}

void RegistrationWindow::validateUsername(){

    auto username = this->ui->usernameLineEdit->text();

    if(this->registeredUsernames.contains(username)){
        this->ui->usernameClue->setVisible(true);
        this->ui->usernameCheckbox->setHidden(true);
        this->ui->usernameClue->setText("Данное имя занято");
        this->ui->usernameClue->setStyleSheet("color: red;");
        this->ui->usernameCheckbox->setChecked(false);
        this->ui->usernameLineEdit->setStyleSheet(checkboxNotValidStyleSheet);

        return;
    }

    bool isValid = FormValidator::isValidUsername(username);

    this->ui->usernameCheckbox->setChecked(isValid);

    if(isValid){
        onValidAction(this->ui->usernameLineEdit, this->ui->usernameClue, this->ui->usernameCheckbox);
    }
    else{
        showDefaultUsernameClue();
        onNotValidAction(this->ui->usernameLineEdit, this->ui->usernameClue, this->ui->usernameCheckbox);
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

        this->registrateRequest = new RegistrateRequest(username, email, password);

        QObject::connect(registrateRequest, &RegistrateRequest::onFailure, this, &RegistrationWindow::onRegistrationError);
        QObject::connect(registrateRequest, &RegistrateRequest::onSuccess, this, &RegistrationWindow::onRegistrationSuccess);

        this->registrateRequest->sendRequest();
        this->onRegistrateRequestStarted();
    }
}

void RegistrationWindow::onRegistrationSuccess(const QString& message){

    onRegistrateRequestFinished();
    QMessageBox::information(nullptr, "Регистрация", message); // перейти к вводу кода подтверждения
}

void RegistrationWindow::onRegistrationError(const QMap<QString, QString>& errors){

    onRegistrateRequestFinished();

    if(errors.contains("Email")){

        this->ui->emailClue->setText("Введенная почта уже зарегистрирована");
        this->ui->emailClue->setStyleSheet("color: red;");
        this->ui->emailClue->setHidden(false);
        this->ui->emailCheckbox->setChecked(false);
        this->ui->emailCheckbox->setVisible(false);
        this->ui->emailLineEdit->setStyleSheet(checkboxNotValidStyleSheet);

        registeredEmails.insert(this->ui->emailLineEdit->text());
    }

    if(errors.contains("Username")){

        this->ui->usernameClue->setText("Введенное имя занято");
        this->ui->usernameClue->setStyleSheet("color: red;");
        this->ui->usernameClue->setHidden(false);
        this->ui->usernameCheckbox->setChecked(false);
        this->ui->usernameCheckbox->setVisible(false);
        this->ui->usernameLineEdit->setStyleSheet(checkboxNotValidStyleSheet);

        registeredUsernames.insert(this->ui->usernameLineEdit->text());
    }
}
