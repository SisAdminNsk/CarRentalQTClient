
#include "loginuserrequest.h"
#include "ClientAPI/OnUserRouteRequests/loginuserreplyhandler.h"

LoginUserRequest::LoginUserRequest(const QString &login, const QString &password, QObject *parent)
    : BaseAPIRequest(parent)
{

    setupReplyHandler(new LoginUserReplyHandler(this, this));

    auto url = this->baseServerUrl.append("/v1/User/Login");
    loginUserRequest = QNetworkRequest(QUrl(url));
    loginUserRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    loginUserForm["Email"] = login;
    loginUserForm["Password"] = password;
}

void LoginUserRequest::sendRequest(){
    manager->post(loginUserRequest, QJsonDocument(loginUserForm).toJson());
}

