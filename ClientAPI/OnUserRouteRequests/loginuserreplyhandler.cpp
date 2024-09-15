
#include "loginuserreplyhandler.h"
#include <QSettings>

LoginUserReplyHandler::LoginUserReplyHandler(LoginUserRequest *loginUserRequest, QObject *parent)
    : BaseAPIReplyHandler{parent}
{
    this->loginUserRequest = loginUserRequest;
}

void LoginUserReplyHandler::Handle(QNetworkReply* reply){

    auto data = reply->readAll();    
    auto jsonDoc = QJsonDocument::fromJson(data);


    if(reply->error() != QNetworkReply::NoError){

        if(reply->error() == QNetworkReply::ConnectionRefusedError){
            emit this->loginUserRequest->onFailure("Сервер недоступен");
            return;
        }

        if(jsonDoc.isObject()){

            auto jsonObj = jsonDoc.object();
            emit this->loginUserRequest->onFailure(jsonObj.value("description").toString());
            return;
        }

        throw std::runtime_error("LoginUserReplyHandler.Handle.Failure;"
            " expected jsonObject is not object. Api request->response missmatch");
    }

    auto authorizationToken = data.toStdString();

    QSettings appChache;// сохраняем токен авторизации в кэше у клиента
    appChache.setValue("userToken", QString::fromStdString(authorizationToken));

    emit this->loginUserRequest->onSuccess("Вход успешно выполнен");
    return;
}
