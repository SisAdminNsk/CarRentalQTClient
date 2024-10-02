
#include "API/Endpoints/Cars/RepliesHandlers/getcarsreplyhandler.h"

#include <QJsonArray>

GetCarsReplyHandler::GetCarsReplyHandler(GetCarsRequest *getCarsRequest, QObject *parent)
    : BaseApiReplyHandler{parent},
    getCarsRequest(getCarsRequest)
{

}

void GetCarsReplyHandler::Handle(QNetworkReply* ApiReply){

    auto data = ApiReply->readAll();
    auto jsonDoc = QJsonDocument::fromJson(data);

    if(ApiReply->error() == QNetworkReply::ConnectionRefusedError){

        emit this->getCarsRequest->OnFailureSignal("Сервер временно недопустен");
        return;
    }

    if(ApiReply->error() != QNetworkReply::NoError){

        int statusCode = ApiReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

        emit this->getCarsRequest->OnFailureSignal("Код ошибки: " +
                                                      QString::fromStdString(std::to_string(statusCode)));
        return;
    }

    GetCarsResponse responseBody(jsonDoc.object());

    emit this->getCarsRequest->OnSuccessSingal(responseBody);

}
