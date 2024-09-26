
#ifndef GETALLCARSREPLYHANDLER_H
#define GETALLCARSREPLYHANDLER_H

#include "API/Endpoints/baseapireplyhandler.h"
#include "API/Endpoints/Cars/Requests/getallcarsrequest.h"


class GetAllCarsReplyHandler : public BaseApiReplyHandler
{
    Q_OBJECT
public:
    explicit GetAllCarsReplyHandler(GetAllCarsRequest *getAllCarsRequest, QObject *parent = nullptr);
    virtual void Handle(QNetworkReply* rep) override;
private:
    GetAllCarsRequest *getAllCarsRequest = nullptr;
};

#endif // GETALLCARSREPLYHANDLER_H
