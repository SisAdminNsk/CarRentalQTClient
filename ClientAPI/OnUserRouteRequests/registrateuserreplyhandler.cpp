
#include "registrateuserreplyhandler.h"
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>

// 1) Добавить обработку случаев 409 и 400
// 2) Добавить валидацию на фронтенде
// 3) Привести форму регистрации в нормальный вид
// 4) Когда отправляется код закрыть форму регистрации и открыть новую форму с отправкой кода и таймером на отправку кода
// после успешной проверки кода закрыть форму отправки кода и снова открыть форму логина


RegistrateUserReplyHandler::RegistrateUserReplyHandler(RegistrateRequest *registrateRequest, QObject *parent)
    : BaseAPIReplyHandler(parent)
{
    this->registrateRequest = registrateRequest;
}

void RegistrateUserReplyHandler::Handle(QNetworkReply* reply){

    auto data = reply->readAll();

    if(reply->error() != QNetworkReply::NoError){

        // необходимо обработать случай 409 и случай 400



        auto errorString = reply->errorString();
        auto jsonDoc = QJsonDocument::fromJson(errorString.toUtf8());
        auto errors = jsonDoc.object().value("errors").toArray();

        for (int i = 0; i < errors.size(); ++i) {
            if(errors[i].toString() == "Email"){

            }

            if(errors[i].toString() == "Password"){

            }
        }
    }

    if(reply->error() == QNetworkReply::NoError){

        QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
        auto jsonObj = jsonDoc.object();

        emit this->registrateRequest->onSuccess(jsonObj.value("message").toString());
        return;
    }

    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    if(statusCode == 400){ // возникла ошибка при регистрации

        QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
        if (jsonDoc.isNull()){
            //emit this->registrateRequest->onFailure("Произошла неизвестная ошибка при регистрации");
            //return;
        }

        if (jsonDoc.isArray()) {

            auto arr = jsonDoc.array();

            for(size_t i=0;i<arr.size();i++){

                if(arr[i].isObject()){
                    QJsonObject jsonObj = arr[i].toObject();
                    //emit this->registrateRequest->onFailure(jsonObj.value("description").toString());
                    //return;
                }
            }
        }

        //emit this->registrateRequest->onFailure("Произошла неизвестная ошибка при регистрации");
        return;
    }
}
