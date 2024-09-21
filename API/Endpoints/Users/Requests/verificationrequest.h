
#ifndef VERIFICATIONREQUEST_H
#define VERIFICATIONREQUEST_H

#include "API/Endpoints/baseapirequest.h"
#include "API/DTO/registratedto.h"

class VerificationRequest : public BaseApiRequest
{
    Q_OBJECT
public:
    VerificationRequest(RegistrateDTO registrateDTO, QString verificationCode, QObject *parent = nullptr);
    virtual QNetworkReply* SendApiRequest() override;
    virtual void SetupRequest() override;
private:
    RegistrateDTO registrateDTO;
    QString verificationCode;
signals:
    void OnSuccessSignal(const QString &message);
    void OnFailureSignal(const QString &message);
};

#endif // VERIFICATIONREQUEST_H
