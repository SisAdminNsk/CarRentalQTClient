
#ifndef REGISTRATEREQUEST_H
#define REGISTRATEREQUEST_H

#include "API/Endpoints/baseapirequest.h"
#include "API/DTO/registratedto.h"

class RegistrateRequest : public BaseApiRequest
{
    Q_OBJECT
public:
    RegistrateRequest(RegistrateDTO registrateDTO, QObject *parent = nullptr);
    virtual QNetworkReply* SendApiRequest() override;
    virtual void SetupRequest() override;
private:
    RegistrateDTO registrateDTO;
signals:
    void OnSuccessSingal(const QString &message);
    void OnFailureSignal(const QMap<QString, QString>& errors);
};

#endif // REGISTRATEREQUEST_H
