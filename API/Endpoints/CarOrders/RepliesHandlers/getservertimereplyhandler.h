
#ifndef GETSERVERTIMEREPLYHANDLER_H
#define GETSERVERTIMEREPLYHANDLER_H

#include "API/Endpoints/baseapireplyhandler.h"
#include "API/Endpoints/CarOrders/Requests/getservertimerequest.h"

class GetServerTimeReplyHandler : public BaseApiReplyHandler
{
    Q_OBJECT
public:
    explicit GetServerTimeReplyHandler(GetServerTimeRequest *getServerTimeRequest, QObject *parent = nullptr);
    virtual void Handle(QNetworkReply* rep) override;
private:
    GetServerTimeRequest *getServerTimeRequest;
};

#endif // GETSERVERTIMEREPLYHANDLER_H
