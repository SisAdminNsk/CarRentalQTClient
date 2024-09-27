
#ifndef GETCARSHARINGUSERREPLYHANDLER_H
#define GETCARSHARINGUSERREPLYHANDLER_H

#include "API/Endpoints/baseapireplyhandler.h"
#include "API/Endpoints/CarsharingUsers/Requests/getcarsharinguserrequest.h"

class GetCarsharingUserReplyHandler : public BaseApiReplyHandler
{
    Q_OBJECT
public:
    explicit GetCarsharingUserReplyHandler(GetCarsharingUserRequest *getCarsharingUserRequest, QObject *parent = nullptr);
    virtual void Handle(QNetworkReply* rep) override;
private:
    GetCarsharingUserRequest *getCarsharingUserRequest = nullptr;
};

#endif // GETCARSHARINGUSERREPLYHANDLER_H
