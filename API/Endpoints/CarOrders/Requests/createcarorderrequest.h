
#ifndef CREATECARORDERREQUEST_H
#define CREATECARORDERREQUEST_H

#include "API/Endpoints/baseapirequest.h"
#include "API/DTO/createcarorderdto.h"

class CreateCarOrderRequest : public BaseApiRequest
{
    Q_OBJECT
public:
    explicit CreateCarOrderRequest(const QString& authorizationToken, const CreateCarOrderDTO& createCarOrderDTO, QObject *parent = nullptr);
    virtual QNetworkReply* SendApiRequest() override;
    virtual void SetupRequest() override;
private:
    CreateCarOrderDTO createCarOrderDTO;
    QString authorizationToken;
signals:
    void OnSuccessSingal(const QString& message);
    void OnFailureSignal(const QString& errorMessage);
};

#endif // CREATECARORDERREQUEST_H
