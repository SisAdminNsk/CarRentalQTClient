
#include <QUrlQuery>

#include "API/Endpoints/Users/Requests/getverificationcoderequest.h"
#include "API/Endpoints/Users/RepliesHandlers/getverificationcodereplyhandler.h"

GetVerificationCodeRequest::GetVerificationCodeRequest(const QString& email, QObject *parent)
    : BaseApiRequest{parent},
    email(email)
{
    this->Setup(new GetVerificationCodeReplyHandler(this,this));
}

QNetworkReply* GetVerificationCodeRequest::SendApiRequest(){
    return manager->get(request);
}

void GetVerificationCodeRequest::SetupRequest(){

    auto url = QUrl(this->baseServerUrl.append("/v1/User/SendVerificationCodeAgain"));

    QUrlQuery query;
    query.addQueryItem("sendersEmail", email);
    url.setQuery(query);

    request = QNetworkRequest(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
}



