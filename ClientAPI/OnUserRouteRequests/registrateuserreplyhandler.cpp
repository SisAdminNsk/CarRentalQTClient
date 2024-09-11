
#include "registrateuserreplyhandler.h"
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>

RegistrateUserReplyHandler::RegistrateUserReplyHandler(RegistrateRequest *registrateRequest, QObject *parent): BaseAPIReplyHandler(parent)
{
    this->registrateRequest = registrateRequest;
}

void RegistrateUserReplyHandler::Handle(QNetworkReply* reply){

    auto data = reply->readAll();

    if(reply->error() == QNetworkReply::NoError){
        emit this->registrateRequest->onSuccess("Регистрация успешно пройдена.");
        return;
    }

    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    if(statusCode == 400){ // возникла ошибка при регистрации

        QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
        if (jsonDoc.isNull()){
            emit this->registrateRequest->onFailure("Произошла неизвестная ошибка при регистрации");
            return;
        }

        if (jsonDoc.isObject()) {
            QJsonObject jsonObj = jsonDoc.object();
            emit this->registrateRequest->onFailure(jsonObj.value("description").toString());
            return;
        }
    }
}
