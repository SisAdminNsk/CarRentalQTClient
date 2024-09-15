
#include "registraterequest.h"
#include "registrateuserreplyhandler.h"

RegistrateRequest::RegistrateRequest(const QString& username,const QString& email,const QString& password, QObject *parent)
    : BaseAPIRequest(parent)
{
    setupReplyHandler(new RegistrateUserReplyHandler(this, this));

    auto url = this->baseServerUrl.append("/v1/User/BeginRegistrateUser");
    registrationRequest = QNetworkRequest(QUrl(url));
    registrationRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    registrationUserForm["Email"] = email;
    registrationUserForm["Password"] = password;
    registrationUserForm["Username"] = username;
}

void RegistrateRequest::sendRequest(){

    manager->post(registrationRequest, QJsonDocument(registrationUserForm).toJson());
}
