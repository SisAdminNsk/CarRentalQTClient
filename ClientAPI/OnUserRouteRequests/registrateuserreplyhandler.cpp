
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

    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    if(reply->error() == QNetworkReply::NoError){
        emit this->registrateRequest->onSuccess("Регистрация успешно пройдена.");
        return;
    }

    if(statusCode == 400){ // возникла ошибка при регистрации

        QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
        if (jsonDoc.isNull()){
            emit this->registrateRequest->onFailure("Произошла неизвестная при регистрации");
            return;
        }

        if (jsonDoc.isObject()) {
            QJsonObject jsonObj = jsonDoc.object();
            emit this->registrateRequest->onFailure(jsonObj.value("description").toString());
            return;
        }
    }
}
