
#ifndef LOGINUSERREPLYHANDLER_H
#define LOGINUSERREPLYHANDLER_H

#include "ClientAPI/baseapireplyhandler.h"
#include <ClientAPI/OnUserRouteRequests/loginuserrequest.h>

class LoginUserReplyHandler : public BaseAPIReplyHandler
{
    Q_OBJECT
public:
    explicit LoginUserReplyHandler(LoginUserRequest *loginUserRequest, QObject *parent = nullptr);
    virtual void Handle(QNetworkReply* rep) override;
private:
    LoginUserRequest *loginUserRequest = nullptr;
};

#endif // LOGINUSERREPLYHANDLER_H
