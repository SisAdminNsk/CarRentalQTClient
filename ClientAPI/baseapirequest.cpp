
#include "baseapirequest.h"
#include <QFile>

#include <iostream>
#include <fstream>
#include <stdexcept>

BaseAPIRequest::BaseAPIRequest(QObject *parent)
    : QObject{parent}
{
    manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));

    tryReadServerConfigurationFromJson();
}

void BaseAPIRequest::setupReplyHandler(BaseAPIReplyHandler *replyHandler){
    this->replyHandler = replyHandler;
}

void BaseAPIRequest::tryReadServerConfigurationFromJson(){

    auto path = ":/server/serverConfiguration.json";
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly)) {

        std::string exceptionMessage = "Couldn't open the file: ";
        exceptionMessage.append(path);

        throw std::runtime_error(exceptionMessage);
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);

    if (jsonDoc.isNull()) {

        throw std::runtime_error("Failed to create JSON doc.");
    }

    QJsonObject jsonObj = jsonDoc.object();

    baseServerUrl = jsonDoc["serverBaseURL"].toString();
}

BaseAPIRequest::~BaseAPIRequest(){
    delete manager;
    delete replyHandler;
}

void BaseAPIRequest::replyFinished(QNetworkReply* reply){

    if(reply->error() == QNetworkReply::AuthenticationRequiredError){

        emit onNotAuthorize();
        return;
    }

    replyHandler->Handle(reply);
}
