
#ifndef LOGINUSERREQUEST_H
#define LOGINUSERREQUEST_H

#include "ClientAPI/baseapirequest.h"

class LoginUserRequest : public BaseAPIRequest
{
    Q_OBJECT
public:
    explicit LoginUserRequest(const QString &login, const QString &password,  QObject *parent = nullptr);
    virtual void sendRequest() override;
private:
    QJsonObject loginUserForm;
    QNetworkRequest loginUserRequest;
signals:
    void onSuccess(const QString &message);
    void onFailure(const QString &message);
};

#endif // LOGINUSERREQUEST_H
