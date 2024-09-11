
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QProgressDialog>

#include "ClientAPI/OnUserRouteRequests/registraterequest.h"
#include "ClientAPI/OnUserRouteRequests/loginuserrequest.h"

void MainWindow::setupLoginForm(){

    QObject::connect(ui->loginPushButton, &QPushButton::clicked, this, &MainWindow::onLoginPushButtonClicked);
    QObject::connect(ui->newUserPushButton, &QPushButton::clicked, this, &MainWindow::onRegistratePushButtonClicked);

    ui->usernameLineEdit->setPlaceholderText("Введите имя пользователя...");
    ui->passwordLineEdit->setPlaceholderText("Введите пароль...");
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
}

void MainWindow::onLoginRequestFinished(){

    this->ui->statusbar->clearMessage();
    this->ui->loginPushButton->blockSignals(false);
    this->ui->newUserPushButton->blockSignals(false);

    delete loadingLabel;
}

void MainWindow::onLoginRequestStarted(){

    ui->loginPushButton->blockSignals(true);
    ui->newUserPushButton->blockSignals(true);

    ui->statusbar->showMessage("Выполняется аутентификация, пожалуйста подождите...");

    loadingLabel = new LoadingLabel(QSize(22, 22));

    this->ui->statusbar->addPermanentWidget(loadingLabel);

    loadingLabel->show();
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

    this->onLoginRequestStarted();
}

void MainWindow::onLoginError(const QString& message){

    this->onLoginRequestFinished();

    QMessageBox::information(nullptr, "Аутентификация", message);
}

void MainWindow::onLoginSuccess(const QString& message){ // переключить основное окно на окно приложения

    this->onLoginRequestFinished();

    QMessageBox::information(nullptr, "Аутентификация", message);

    mainApplicationWindow = new CarRentalClientWindow();
    mainApplicationWindow->setWindowTitle("New Window");
    mainApplicationWindow->show();

    this->close();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mainApplicationWindow;
}

void MainWindow::onRegistratePushButtonClicked() // переключить основное окно на окно регистрации
{

}

