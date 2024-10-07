
#include "API/Endpoints/CarOrders/Requests/createcarorderrequest.h"
#include "API/Endpoints/CarOrders/RepliesHandlers/createcarorderreplyhandler.h"

CreateCarOrderRequest::CreateCarOrderRequest(const QString& authorizationToken, const CreateCarOrderDTO& createCarOrderDTO, QObject *parent)
    : BaseApiRequest{parent},
    createCarOrderDTO(createCarOrderDTO),
    authorizationToken(authorizationToken)
{
    this->Setup(new CreateCarOrderReplyHandler(this,this));
}

QNetworkReply* CreateCarOrderRequest::SendApiRequest(){
    return manager->post(request, createCarOrderDTO.ToByteArray());
}

void CreateCarOrderRequest::SetupRequest(){

    auto url = QUrl(this->baseServerUrl.append("/v1/CarBooking/CreateCarOrder"));

    request = QNetworkRequest(url);

    request.setRawHeader("Authorization", "Bearer " + authorizationToken.toUtf8());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
}



