
#ifndef GETCARSREPLYHANDLER_H
#define GETCARSREPLYHANDLER_H

#include "API/Endpoints/baseapireplyhandler.h"
#include "API/Endpoints/Cars/Requests/getcarsrequest.h"

class GetCarsReplyHandler : public BaseApiReplyHandler
{
    Q_OBJECT
public:
    explicit GetCarsReplyHandler(GetCarsRequest *getCarsRequest, QObject *parent = nullptr);
    virtual void Handle(QNetworkReply* ApiReply) override;
private:
    GetCarsRequest *getCarsRequest = nullptr;
};

#endif // GETCARSREPLYHANDLER_H
