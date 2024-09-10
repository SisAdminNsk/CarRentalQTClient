
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
private:
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    BaseAPIReplyHandler *replyHandler = nullptr;
signals:
    void onNotAuthorize();
public slots:
    virtual void replyFinished(QNetworkReply* rep);

};

#endif // BASEAPIREQUEST_H
