
#ifndef LOGINREPLYHANDLER_H
#define LOGINREPLYHANDLER_H

#include "API/Endpoints/baseapireplyhandler.h"
#include "API/Endpoints/Users/Requests/loginrequest.h"

class LoginReplyHandler : public BaseApiReplyHandler
{
    Q_OBJECT
public:
    LoginReplyHandler(LoginRequest *loginRequest, QObject *parent = nullptr);
    virtual void Handle(QNetworkReply* rep) override;
private:
    LoginRequest *loginRequest = nullptr;
};

#endif // LOGINREPLYHANDLER_H
