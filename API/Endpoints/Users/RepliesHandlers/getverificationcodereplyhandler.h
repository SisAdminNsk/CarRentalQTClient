
#ifndef GETVERIFICATIONCODEREPLYHANDLER_H
#define GETVERIFICATIONCODEREPLYHANDLER_H

#include "API/Endpoints/baseapirequest.h"

#include "API/Endpoints/Users/Requests/getverificationcoderequest.h"

class GetVerificationCodeReplyHandler : public BaseApiReplyHandler
{
public:
    explicit GetVerificationCodeReplyHandler(GetVerificationCodeRequest *getVerificationCodeRequest, QObject *parent = nullptr);
    virtual void Handle(QNetworkReply* rep) override;
private:
    GetVerificationCodeRequest *getVerificationCodeRequest = nullptr;
};

#endif // GETVERIFICATIONCODEREPLYHANDLER_H
