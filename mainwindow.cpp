
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include "ClientAPI/OnUserRouteRequests/registraterequest.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // сверстать завтра форму под это
    auto registrateUserRequest = new RegistrateRequest("outlander","string",this);

    QObject::connect(registrateUserRequest, &RegistrateRequest::onFailure, this, &MainWindow::onRegistrationError);
    QObject::connect(registrateUserRequest, &RegistrateRequest::onSuccess, this, &MainWindow::onRegistrationSuccess);

    registrateUserRequest->sendRequest();
}

void MainWindow::onRegistrationError(const QString& message){
    QMessageBox::information(nullptr, "Регистрация", message);
}

void MainWindow::onRegistrationSuccess(const QString& message){
    QMessageBox::information(nullptr, "Регистрация", message);
}

MainWindow::~MainWindow()
{
    delete ui;
}


