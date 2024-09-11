
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QProgressDialog>

#include "ClientAPI/OnUserRouteRequests/registraterequest.h"
#include "ClientAPI/OnUserRouteRequests/loginuserrequest.h"

void MainWindow::setupLoginForm(){

    QObject::connect(ui->loginPushButton, &QPushButton::clicked, this, &MainWindow::onLoginPushButtonClicked);

    ui->usernameLineEdit->setPlaceholderText("Введите имя пользователя...");
    ui->passwordLineEdit->setPlaceholderText("Введите пароль...");
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
}

void MainWindow::onLoginRequestFinished(){
    this->movie->stop();
    this->ui->statusbar->clearMessage();
    delete loadingLabel;
}

void MainWindow::onLoginRequestStarted(){

    ui->statusbar->showMessage("Выполняется аутентификация, пожалуйста подождите...");

    loadingLabel = new QLabel(this);
    movie = new QMovie(":/Media/media/loading1.gif");
    movie->setScaledSize(QSize(22,22));
    loadingLabel->setMovie(movie);
    this->ui->statusbar->addPermanentWidget(loadingLabel);

    loadingLabel->show();
    movie->start();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupLoginForm();
}

void MainWindow::onLoginPushButtonClicked(){

    auto userLogin = ui->usernameLineEdit->text();
    auto userPassword = ui->passwordLineEdit->text();

    auto loginUserRequest = new LoginUserRequest(userLogin, userPassword,this);

    QObject::connect(loginUserRequest, &LoginUserRequest::onFailure, this, &MainWindow::onLoginError);
    QObject::connect(loginUserRequest, &LoginUserRequest::onSuccess, this, &MainWindow::onLoginSuccess);

    loginUserRequest->sendRequest();

    ui->statusbar->showMessage("Выполняется аутентификация, пожалуйста подождите ...");

    this->onLoginRequestStarted();
}

void MainWindow::onLoginError(const QString& message){

    this->onLoginRequestFinished();
    QMessageBox::information(nullptr, "Аутентификация", message);
}

void MainWindow::onLoginSuccess(const QString& message){ // переключить основное окно на окно приложения

    this->onLoginRequestFinished();
    QMessageBox::information(nullptr, "Аутентификация", message);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onRegistratePushButtonClicked() // переключить основное окно на окно регистрации
{
    registrationWindow.show();
}

