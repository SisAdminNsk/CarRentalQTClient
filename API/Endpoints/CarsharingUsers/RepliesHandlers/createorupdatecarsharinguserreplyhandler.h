
#ifndef CREATEORUPDATECARSHARINGUSERREPLYHANDLER_H
#define CREATEORUPDATECARSHARINGUSERREPLYHANDLER_H

#include "API/Endpoints/baseapireplyhandler.h"
#include "API/Endpoints/CarsharingUsers/Requests/createorupdatecarsharinguserrequest.h"

class CreateOrUpdateCarsharingUserReplyHandler : public BaseApiReplyHandler
{
    Q_OBJECT
public:
    explicit CreateOrUpdateCarsharingUserReplyHandler(
        CreateOrUpdateCarsharingUserRequest *createOrUpdateCarsharingUserRequest,
        QObject *parent = nullptr);
    virtual void Handle(QNetworkReply* reply) override;
private:
    CreateOrUpdateCarsharingUserRequest *createOrUpdateCarsharingUserRequest;
};

#endif // CREATEORUPDATECARSHARINGUSERREPLYHANDLER_H
