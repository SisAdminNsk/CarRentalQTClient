
#ifndef REGISTRATEUSERREPLYHANDLER_H
#define REGISTRATEUSERREPLYHANDLER_H

#include "ClientAPI/baseapireplyhandler.h"
#include "ClientAPI/OnUserRouteRequests/registraterequest.h"

class RegistrateUserReplyHandler : public BaseAPIReplyHandler
{
    Q_OBJECT
public:
    explicit RegistrateUserReplyHandler(RegistrateRequest *registrateRequest, QObject *parent = nullptr);

    virtual void Handle(QNetworkReply* rep) override;
private:
    RegistrateRequest *registrateRequest = nullptr;
};

#endif // REGISTRATEUSERREPLYHANDLER_H