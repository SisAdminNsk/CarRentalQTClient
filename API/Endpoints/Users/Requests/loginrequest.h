
#ifndef LOGINREQUEST_H
#define LOGINREQUEST_H

#include "API/Endpoints/baseapirequest.h"
#include "API/DTO/logindto.h"

class LoginRequest : public BaseApiRequest
{
    Q_OBJECT
public:
    explicit LoginRequest(LoginDTO loginDTO, QObject *parent = nullptr);
    virtual QNetworkReply* SendApiRequest() override;
    virtual void SetupRequest() override;
private:
    LoginDTO loginDTO;
signals:
    void OnSuccessSignal(const QString &message);
    void OnFailureSignal(const QString &message);
};

#endif // LOGINREQUEST_H
