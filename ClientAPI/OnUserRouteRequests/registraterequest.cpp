
#include "registraterequest.h"
#include "registrateuserreplyhandler.h"

RegistrateRequest::RegistrateRequest(QString login, QString password, QObject *parent) : BaseAPIRequest(parent)
{
    setupReplyHandler(new RegistrateUserReplyHandler(this, this));

    auto url = this->baseServerUrl.append("/User/RegistrateNewUser");
    registrationRequest = QNetworkRequest(QUrl(url));
    registrationRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    registrationUserForm["Login"] = login;
    registrationUserForm["Password"] = password;
}

void RegistrateRequest::sendRequest(){

    manager->post(registrationRequest, QJsonDocument(registrationUserForm).toJson());
}
