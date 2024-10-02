
#ifndef GETCARSREQUEST_H
#define GETCARSREQUEST_H

#include "API/Endpoints/baseapirequest.h"
#include "API/DTO/getcarsresponse.h"
#include "API/DTO/getcarsdto.h"

class GetCarsRequest : public BaseApiRequest
{
    Q_OBJECT
public:
    explicit GetCarsRequest(const QString& authorizationToken, const GetCarsDTO& getCarsDTO, QObject *parent = nullptr);
    virtual QNetworkReply* SendApiRequest() override;
    virtual void SetupRequest() override;
    void SetQueryString(GetCarsDTO& getCarsDTO);
signals:
    void OnSuccessSingal(const GetCarsResponse &responseBody);
    void OnFailureSignal(const QString &errorMessage);
private:
    QUrl url;
    QString authorizationToken;
    GetCarsDTO getCarsDTO;
};

#endif // GETCARSREQUEST_H
