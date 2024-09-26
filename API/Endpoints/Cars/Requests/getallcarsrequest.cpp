
#include "getallcarsrequest.h"

#include "API/Endpoints/Cars/RepliesHandlers/getallcarsreplyhandler.h"

GetAllCarsRequest::GetAllCarsRequest(const QString& authorizationToken, QObject *parent)
    : BaseApiRequest{parent}
{
    this->authorizationToken = authorizationToken;

    this->Setup(new GetAllCarsReplyHandler(this, this));
}

QNetworkReply* GetAllCarsRequest::SendApiRequest(){
    return manager->get(request);
}

void GetAllCarsRequest::SetupRequest(){

    auto url = QUrl(this->baseServerUrl.append("/v1/Car/GetAllCars"));

    request = QNetworkRequest(url);

    request.setRawHeader("Authorization", "Bearer " + authorizationToken.toUtf8());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
}
