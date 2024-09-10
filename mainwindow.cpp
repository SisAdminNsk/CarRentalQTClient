
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QJsonDocument>
#include <QArrayData>
#include <QJsonObject>
#include <QJsonArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));

    //auto registrationRequest = QNetworkRequest(QUrl("http://localhost:5096/User/RegistrateNewUser"));
    //registrationRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //QJsonObject registrationUserForm;
    //registrationUserForm["Login"] = "string";
    //registrationUserForm["Password"] = "string";

    //manager->post(registrationRequest, QJsonDocument(registrationUserForm).toJson());

    //auto loginRequest = QNetworkRequest(QUrl("http://localhost:5096/User/Login"));
    //loginRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //QJsonObject loginUserForm;
    //loginUserForm["Login"] = "string";
    //loginUserForm["Password"] = "string";

    //manager->post(loginRequest, QJsonDocument(loginUserForm).toJson());

    //auto token = "Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJVc2VySWQiOiJkZGQ1ZWE5NS1iMzE1LTRkNGItOWE5MS03Yjg1M2I1OGUwYTAiLCJodHRwOi8vc2NoZW1hcy5taWNyb3NvZnQuY29tL3dzLzIwMDgvMDYvaWRlbnRpdHkvY2xhaW1zL3JvbGUiOiJ1c2VyIiwiZXhwIjoxNzI2MDQyNDQ0fQ.5Nfy8UZdd499NuFVoxnbFST_cAt-gMSki8rD6brNbec";


    //QNetworkRequest getAllCarsRequest(QUrl("http://localhost:5096/Car/GetAllCars"));
    //getAllCarsRequest.setRawHeader("Authorization", token);

    //manager->get(getAllCarsRequest);

}

void MainWindow::replyFinished(QNetworkReply* rep)
{
    auto data = rep->readAll();

    if(rep->error() != QNetworkReply::NoError){
        qDebug() << "Error";
    }



}

MainWindow::~MainWindow()
{
    delete ui;
}


