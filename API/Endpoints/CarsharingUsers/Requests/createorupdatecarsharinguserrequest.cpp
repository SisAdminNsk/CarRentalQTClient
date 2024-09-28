
#include "createorupdatecarsharinguserrequest.h"
#include "API/Endpoints/CarsharingUsers/RepliesHandlers/createorupdatecarsharinguserreplyhandler.h"

CreateOrUpdateCarsharingUserRequest::CreateOrUpdateCarsharingUserRequest(
    const LoginResponse& loginResponse,
    const CreateOrUpdateCarsharingUserRequestBody& carsharingUser,
    QObject *parent)
    : BaseApiRequest{parent},
    carsharingUser(carsharingUser),
    loginResponse(loginResponse)
{
    Setup(new CreateOrUpdateCarsharingUserReplyHandler(this,this));
}

QNetworkReply* CreateOrUpdateCarsharingUserRequest::SendApiRequest(){
    return manager->post(request, carsharingUser.ToByteArray());
}

void CreateOrUpdateCarsharingUserRequest::SetupRequest(){

    auto url = QUrl(this->baseServerUrl.append("/v1/CarsharingUser/CreateOrUpdateCarsharingUser"));

    request = QNetworkRequest(url);

    request.setRawHeader("Authorization", "Bearer " + loginResponse.Token.toUtf8());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
}

