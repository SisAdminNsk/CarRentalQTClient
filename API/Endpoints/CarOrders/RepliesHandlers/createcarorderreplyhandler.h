
#ifndef CREATECARORDERREPLYHANDLER_H
#define CREATECARORDERREPLYHANDLER_H

#include "API/Endpoints/baseapireplyhandler.h"
#include "API/Endpoints/CarOrders/Requests/createcarorderrequest.h"

class CreateCarOrderReplyHandler : public BaseApiReplyHandler
{
    Q_OBJECT
public:
    explicit CreateCarOrderReplyHandler(CreateCarOrderRequest* createCarOrderRequest, QObject *parent = nullptr);
    virtual void Handle(QNetworkReply* reply) override;
private:
    CreateCarOrderRequest* createCarOrderRequest = nullptr;
};

#endif // CREATECARORDERREPLYHANDLER_H
