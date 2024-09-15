
#include "registrateuserreplyhandler.h"
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>

// 1) Добавить обработку случаев 409 и 400 // в процессе
// 2) Добавить валидацию на фронтенде // сделано
// 3) Привести форму регистрации в нормальный вид // сделано
// 4) Когда отправляется код закрыть форму регистрации и открыть новую форму с отправкой кода и таймером на отправку кода
// после успешной проверки кода закрыть форму отправки кода и снова открыть форму логина


RegistrateUserReplyHandler::RegistrateUserReplyHandler(RegistrateRequest *registrateRequest, QObject *parent)
    : BaseAPIReplyHandler(parent)
{
    this->registrateRequest = registrateRequest;
}

void RegistrateUserReplyHandler::Handle(QNetworkReply* reply){

    if(reply->error() == QNetworkReply::ConnectionRefusedError){

        emit this->registrateRequest->onFailure(QList<QString>{"Сервер временно недопустен"});
        return;
    }

    if(reply->error() != QNetworkReply::NoError){

        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

        if(statusCode == 400){
            Process400Error(reply);
        }

        if(statusCode == 409){
            Process409Error(reply);
        }
    }

    emit this->registrateRequest->onSuccess("Код подтверждения регистрации отправлен на указанную почту");
}

void RegistrateUserReplyHandler::Process400Error(QNetworkReply* reply){

    throw std::runtime_error("RegistrateUserReplyHandler.Handle.Failure;"
        " occures some validation problems api has some request->response missmatches");
}

void RegistrateUserReplyHandler::Process409Error(QNetworkReply* reply){



    // сказать что пользователь с указанными данные уже зарегистрирован
}
