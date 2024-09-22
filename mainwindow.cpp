
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

#include "API/Endpoints/Users/Requests/loginrequest.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Setup();
}

void MainWindow::Setup(){

    setFixedSize(500,320);
    setMinimumSize(500,320);
    setMaximumSize(500,320);

    QObject::connect(ui->loginPushButton, &QPushButton::clicked, this, &MainWindow::OnLoginPushButtonClicked);
    QObject::connect(ui->newUserPushButton, &QPushButton::clicked, this, &MainWindow::OnRegistratePushButtonClicked);

    auto authenticationIconPixmap = QPixmap(":/images/Media/loginIcon.png");
    auto usernameIconPixmap = QPixmap(":/images/Media/usernameIcon.png");
    auto passwordIconPixmap = QPixmap(":/images/Media/passwordIcon.png");

    setWindowIcon(QIcon(":/images/Media/carsharingLogo.png"));

    ui->loginIcon->setPixmap(authenticationIconPixmap.scaled(37,37, Qt::KeepAspectRatio));
    ui->passwordIcon->setPixmap(passwordIconPixmap.scaled(24,24,Qt::KeepAspectRatio));
    ui->usernameIcon->setPixmap(usernameIconPixmap.scaled(24,24,Qt::KeepAspectRatio));

    ui->usernameLineEdit->setPlaceholderText("Введите вашу почту");
    ui->passwordLineEdit->setPlaceholderText("Введите ваш пароль");
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
}

void MainWindow::OnLoginPushButtonClicked(){

    auto userLogin = ui->usernameLineEdit->text();
    auto userPassword = ui->passwordLineEdit->text();

    auto loginUserRequest = new LoginRequest(LoginDTO(userLogin, userPassword), this);

    QObject::connect(loginUserRequest, &LoginRequest::OnFailureSignal, this, &MainWindow::OnLoginError);
    QObject::connect(loginUserRequest, &LoginRequest::OnSuccessSignal, this, &MainWindow::OnLoginSuccess);

    loginUserRequest->SendApiRequest();

    OnLoginRequestStarted();
}

void MainWindow::OnLoginRequestStarted(){

    ui->loginPushButton->blockSignals(true);
    ui->newUserPushButton->blockSignals(true);

    ui->statusbar->showMessage("Выполняется аутентификация, пожалуйста подождите...");

    loadingLabel = new LoadingLabel(QSize(22, 22));

    this->ui->statusbar->addPermanentWidget(loadingLabel);

    loadingLabel->show();
}

void MainWindow::OnLoginRequestFinished(){

    this->ui->statusbar->clearMessage();
    this->ui->loginPushButton->blockSignals(false);
    this->ui->newUserPushButton->blockSignals(false);

    delete loadingLabel;
}

void MainWindow::OnLoginSuccess(const QString &accessToken){

    this->OnLoginRequestFinished();

    QMessageBox::information(nullptr, "Аутентификация", accessToken);

    //mainApplicationWindow = new CarRentalClientWindow();
    //mainApplicationWindow->setWindowTitle("New Window");
    //mainApplicationWindow->show();

    this->close();
}

void MainWindow::OnLoginError(const QString &message){

    this->OnLoginRequestFinished();

    QMessageBox::information(nullptr, "Аутентификация", message);
}

void MainWindow::OnRegistratePushButtonClicked(){

    registrationForm = new RegistrationForm();
    registrationForm->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete registrationForm;
}


