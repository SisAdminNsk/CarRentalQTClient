
#include "API/Endpoints/Users/Requests/registraterequest.h"
#include "API/Endpoints/Users/RepliesHandlers/registratereplyhandler.h"

RegistrateRequest::RegistrateRequest(RegistrateDTO registrateDTO, QObject *parent)
    : BaseApiRequest{parent},
    registrateDTO(registrateDTO)
{
    this->Setup(new RegistrateReplyHandler(this,this));
}

QNetworkReply* RegistrateRequest::SendApiRequest(){
   return manager->post(request, registrateDTO.ToByteArray());
}


void RegistrateRequest::SetupRequest(){

    auto url = this->baseServerUrl.append("/v1/User/BeginRegistrateUser");

    request = QNetworkRequest(QUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
}
