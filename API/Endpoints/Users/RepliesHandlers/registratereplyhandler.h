
#ifndef REGISTRATEREPLYHANDLER_H
#define REGISTRATEREPLYHANDLER_H

#include "API/Endpoints/baseapireplyhandler.h"
#include "API/Endpoints/Users/Requests/registraterequest.h"

class RegistrateReplyHandler : public BaseApiReplyHandler
{
    Q_OBJECT
public:
    RegistrateReplyHandler(RegistrateRequest *registrateRequest, QObject *parent = nullptr);
    virtual void Handle(QNetworkReply* rep) override;
private:
    RegistrateRequest *registrateRequest;
    void Process400Error(QNetworkReply *reply);
    void Process409Error(QNetworkReply *reply);
};

#endif // REGISTRATEREPLYHANDLER_H
