
#include "API/Endpoints/CarOrders/Requests/getservertimerequest.h"
#include "API/Endpoints/CarOrders/RepliesHandlers/getservertimereplyhandler.h"
#include <QUrlQuery>

GetServerTimeRequest::GetServerTimeRequest(const QString& authorizationToken, int dateTimeOffset, QObject *parent)
    : BaseApiRequest{parent},
    dateTimeOffset(dateTimeOffset),
    authorizationToken(authorizationToken)
{
    this->Setup(new GetServerTimeReplyHandler(this,this));
}

QNetworkReply* GetServerTimeRequest::SendApiRequest(){
    return manager->get(request);
}

void GetServerTimeRequest::SetupRequest(){

    url = QUrl(this->baseServerUrl.append("/v1/CarBooking/GetServerDateTime"));

    QUrlQuery query;
    query.addQueryItem("hoursOffset", QString::number(dateTimeOffset));

    url.setQuery(query);

    request = QNetworkRequest(url);

    request.setRawHeader("Authorization", "Bearer " + authorizationToken.toUtf8());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
}

void GetServerTimeRequest::SetQueryString(int dateTimeOffset){
    this->dateTimeOffset = dateTimeOffset;
    QUrlQuery query;
    query.addQueryItem("hoursOffset", QString::number(dateTimeOffset));
    this->url.setQuery(query);
    this->request.setUrl(url);
}

