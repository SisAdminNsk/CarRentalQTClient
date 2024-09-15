
#ifndef BASEAPIREQUEST_H
#define BASEAPIREQUEST_H

#include <QObject>
#include <QJsonDocument>
#include <QArrayData>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkReply>

#include "baseapireplyhandler.h"

class BaseAPIRequest : public QObject
{
    Q_OBJECT
public:
    explicit BaseAPIRequest(QObject *parent = nullptr);
    ~BaseAPIRequest();
    void setupReplyHandler(BaseAPIReplyHandler *replyHandler);
    virtual void sendRequest() = 0;
private:
    void tryReadServerConfigurationFromJson();

signals:
    void onNotAuthorize();
public slots:
    virtual void replyFinished(QNetworkReply* rep);
protected:
    QNetworkCookieJar *cookieJar;
    BaseAPIReplyHandler *replyHandler = nullptr;
    QNetworkAccessManager *manager = nullptr;
    QString baseServerUrl = nullptr;
};

#endif // BASEAPIREQUEST_H
