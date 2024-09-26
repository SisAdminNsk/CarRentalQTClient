
#ifndef GETALLCARSREQUEST_H
#define GETALLCARSREQUEST_H

#include "API/Endpoints/baseapirequest.h"

#include "API/DTO/cardto.h"

class GetAllCarsRequest : public BaseApiRequest
{
    Q_OBJECT
public:
    explicit GetAllCarsRequest(const QString& authorizationToken, QObject *parent = nullptr);
    virtual QNetworkReply* SendApiRequest() override;
    virtual void SetupRequest() override;
signals:
    void OnSuccessSingal(const QList<CarDTO> &replyBody);
    void OnFailureSignal(const QString &message);
private:
    QString authorizationToken;
};

#endif // GETALLCARSREQUEST_H
