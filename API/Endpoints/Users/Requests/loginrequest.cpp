
#include "API/Endpoints/Users/Requests/loginrequest.h"
#include "API/Endpoints/Users/RepliesHandlers/loginreplyhandler.h"

LoginRequest::LoginRequest(LoginDTO loginDTO, QObject *parent)
    : BaseApiRequest(parent),
    loginDTO(loginDTO)
{
    this->Setup(new LoginReplyHandler(this,this));
}

QNetworkReply* LoginRequest::SendApiRequest(){
   return manager->post(request, loginDTO.ToByteArray());
}

void LoginRequest::SetupRequest(){

    auto url = this->baseServerUrl.append("/v1/User/Login");

    request = QNetworkRequest(QUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
}
