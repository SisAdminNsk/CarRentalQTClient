
#ifndef REGISTRATEREQUEST_H
#define REGISTRATEREQUEST_H

#include <QObject>
#include "ClientAPI/baseapirequest.h"

class RegistrateRequest : public BaseAPIRequest
{
    Q_OBJECT
public:
    explicit RegistrateRequest(QString login, QString password, QObject *parent = nullptr);
    virtual void sendRequest() override;
private:
    QJsonObject registrationUserForm;
    QNetworkRequest registrationRequest;
signals:
    void onSuccess(const QString &message);
    void onFailure(const QString &message);
};

#endif // REGISTRATEREQUEST_H
