
#ifndef BASEAPIREPLYHANDLER_H
#define BASEAPIREPLYHANDLER_H


#include <QObject>
#include <QtNetwork/QNetworkReply>

class BaseApiReplyHandler : public QObject
{
    Q_OBJECT
public:
    BaseApiReplyHandler(QObject *parent = nullptr);
    virtual void Handle(QNetworkReply* reply) = 0;
};

#endif // BASEAPIREPLYHANDLER_H
