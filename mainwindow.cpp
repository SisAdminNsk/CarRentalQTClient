
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

#include "ClientAPI/OnUserRouteRequests/registraterequest.h"
#include "ClientAPI/OnUserRouteRequests/loginuserrequest.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // сверстать завтра форму под это
    //auto registrateUserRequest = new RegistrateRequest("outlander","string",this);

    //QObject::connect(registrateUserRequest, &RegistrateRequest::onFailure, this, &MainWindow::onRegistrationError);
    //QObject::connect(registrateUserRequest, &RegistrateRequest::onSuccess, this, &MainWindow::onRegistrationSuccess);

    //registrateUserRequest->sendRequest();

    auto loginUserRequest = new LoginUserRequest("outlander","string",this);

    QObject::connect(loginUserRequest, &LoginUserRequest::onFailure, this, &MainWindow::onLoginError);
    QObject::connect(loginUserRequest, &LoginUserRequest::onSuccess, this, &MainWindow::onLoginSuccess);

    loginUserRequest->sendRequest();
    // Заблочить интерфейс

    ui->lineEdit->setPlaceholderText("Введите имя пользователя...");

    ui->lineEdit_2->setPlaceholderText("Введите пароль...");
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

void MainWindow::onRegistrationError(const QString& message){
    QMessageBox::information(nullptr, "Регистрация", message);
}

void MainWindow::onRegistrationSuccess(const QString& message){
    QMessageBox::information(nullptr, "Регистрация", message);
}

void MainWindow::onLoginError(const QString& message){
    QMessageBox::information(nullptr, "Аутентификация", message);
}

void MainWindow::onLoginSuccess(const QString& message){
    QMessageBox::information(nullptr, "Аутентификация", message);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_2_clicked()
{
    registrationWindow.show();
}

