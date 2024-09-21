
#ifndef BASEAPIREQUEST_H
#define BASEAPIREQUEST_H

#include <QObject>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkCookieJar>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

#include "API/Endpoints/baseapireplyhandler.h"

class BaseApiRequest : public QObject
{
    Q_OBJECT
public:
    explicit BaseApiRequest(QObject *parent = nullptr);
    ~BaseApiRequest();
    virtual QNetworkReply* SendApiRequest() = 0;

    void SetCookies(QNetworkCookieJar *cookies);
    QNetworkCookieJar* GetCookies();

private:
    void SetServerConfiguration();
    QNetworkCookieJar *cookies = nullptr;
signals:
    void OnNotAuthorizeSignal();
protected:
    virtual void SetupRequest() = 0;
    void Setup(BaseApiReplyHandler* replyHandler);

    QNetworkRequest request;
    QNetworkAccessManager *manager = nullptr;
    BaseApiReplyHandler *replyHandler = nullptr;
    QString baseServerUrl = nullptr;
public slots:
    virtual void ReplyFinished(QNetworkReply* rep);
};

#endif // BASEAPIREQUEST_H
