
#include "API/Endpoints/Cars/Requests/getcarsrequest.h"
#include "API/Endpoints/Cars/RepliesHandlers/getcarsreplyhandler.h"

#include <QUrlQuery>

GetCarsRequest::GetCarsRequest(const QString& authorizationToken, const GetCarsDTO& getCarsDTO, QObject *parent)
    : BaseApiRequest{parent},
    authorizationToken(authorizationToken),
    getCarsDTO(getCarsDTO)
{
    this->Setup(new GetCarsReplyHandler(this,this));
}

void GetCarsRequest::SetQueryString(GetCarsDTO& getCarsDTO){
    this->getCarsDTO = getCarsDTO;
    auto query = getCarsDTO.ToUrlQuery();
    this->url.setQuery(query);
    this->request.setUrl(url);
}

QNetworkReply* GetCarsRequest::SendApiRequest(){
    return manager->get(request);
}

void GetCarsRequest::SetupRequest(){

    url = QUrl(this->baseServerUrl.append("/v1/Car/GetCars"));

    auto query = getCarsDTO.ToUrlQuery();

    url.setQuery(query);

    request = QNetworkRequest(url);

    request.setRawHeader("Authorization", "Bearer " + authorizationToken.toUtf8());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
}

