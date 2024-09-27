
#ifndef GETCARSHARINGUSERREQUEST_H
#define GETCARSHARINGUSERREQUEST_H

#include "API/Endpoints/baseapirequest.h"
#include "API/DTO/carsharinguserdto.h"
#include "API/DTO/loginresponse.h"

class GetCarsharingUserRequest : public BaseApiRequest
{
    Q_OBJECT
public:
    explicit GetCarsharingUserRequest(const LoginResponse& loginResponse, QObject *parent = nullptr);
    virtual QNetworkReply* SendApiRequest() override;
    virtual void SetupRequest() override;
private:
    LoginResponse loginResponse;
signals:
    void OnSuccessSingal(const CarsharingUserDTO &carsharingUser);
    void OnFailureSignal(const QList<QString> &errors);
};

#endif // GETCARSHARINGUSERREQUEST_H
