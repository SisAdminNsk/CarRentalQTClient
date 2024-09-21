
#ifndef VERIFICATEREPLYHANDLER_H
#define VERIFICATEREPLYHANDLER_H

#include "API/Endpoints/baseapireplyhandler.h"
#include "API/Endpoints/Users/Requests/verificationrequest.h"

class VerificateReplyHandler : public BaseApiReplyHandler
{
    Q_OBJECT
public:
    VerificateReplyHandler(VerificationRequest *verificateCodeRequest, QObject *parent = nullptr);
    virtual void Handle(QNetworkReply* reply) override;
private:
    VerificationRequest *verificateCodeRequest;
    void Process400Error(QNetworkReply* reply);
};

#endif // VERIFICATEREPLYHANDLER_H
