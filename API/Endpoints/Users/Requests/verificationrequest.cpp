
#include "API/Endpoints/Users/Requests/verificationrequest.h"
#include "API/Endpoints/Users/RepliesHandlers/verificatereplyhandler.h"

#include <QUrl>
#include <QUrlQuery>

VerificationRequest::VerificationRequest(RegistrateDTO registrateDTO, QString verificationCode, QObject *parent)
    : BaseApiRequest(parent),
    registrateDTO(registrateDTO),
    verificationCode(verificationCode)
{
    Setup(new VerificateReplyHandler(this, this));
}

QNetworkReply* VerificationRequest::SendApiRequest(){
   return manager->post(request, registrateDTO.ToByteArray());
}

void VerificationRequest::SetupRequest(){

    QUrl url(this->baseServerUrl.append("/v1/User/EndRegistrateUser"));

    QUrlQuery query;
    query.addQueryItem("code", verificationCode);
    url.setQuery(query);

    request = QNetworkRequest(QUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
}

