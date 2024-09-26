
#include "getallcarsreplyhandler.h"

#include <QJsonArray>

GetAllCarsReplyHandler::GetAllCarsReplyHandler(GetAllCarsRequest *getAllCarsRequest, QObject *parent)
    : BaseApiReplyHandler{parent},
    getAllCarsRequest(getAllCarsRequest)
{
}

void GetAllCarsReplyHandler::Handle(QNetworkReply* reply){

    auto data = reply->readAll();
    auto jsonDoc = QJsonDocument::fromJson(data);

    if(reply->error() == QNetworkReply::ConnectionRefusedError){

        emit this->getAllCarsRequest->OnFailureSignal("Сервер временно недопустен");
        return;
    }

    if(reply->error() != QNetworkReply::NoError){

        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

        emit this->getAllCarsRequest->OnFailureSignal("Код ошибки: " +
                                                               QString::fromStdString(std::to_string(statusCode)));
        return;
    }

    QList<CarDTO> body;

    auto carsDocuments = jsonDoc.array();

    for(size_t i=0;i<carsDocuments.size();i++){
        body.push_back(CarDTO(carsDocuments[i].toObject()));
    }

    emit this->getAllCarsRequest->OnSuccessSingal(body);
}

