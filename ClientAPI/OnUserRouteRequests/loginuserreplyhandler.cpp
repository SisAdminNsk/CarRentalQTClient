
#include "loginuserreplyhandler.h"

LoginUserReplyHandler::LoginUserReplyHandler(LoginUserRequest *loginUserRequest, QObject *parent)
    : BaseAPIReplyHandler{parent}
{
    this->loginUserRequest = loginUserRequest;
}

void LoginUserReplyHandler::Handle(QNetworkReply* reply){

    auto data = reply->readAll();
    auto jsonDoc = QJsonDocument::fromJson(data);

    if(jsonDoc.isObject()){

        auto jsonObj = jsonDoc.object();

        if(reply->error() != QNetworkReply::NoError){

            if (jsonDoc.isObject()) {
                emit this->loginUserRequest->onFailure(jsonObj.value("description").toString());
                return;
            }
        }

        emit this->loginUserRequest->onSuccess(jsonObj.value("description").toString());
        return;
    }

    emit this->loginUserRequest->onFailure("Произошла неизвестная ошибка.");
    return;
}
