
#ifndef BASEAPIREPLYHANDLER_H
#define BASEAPIREPLYHANDLER_H


#include <QObject>
#include <QNetworkReply>

class BaseAPIReplyHandler : public QObject{
    Q_OBJECT
public:
    explicit BaseAPIReplyHandler(QObject *parent = nullptr);

    virtual void Handle(QNetworkReply* rep) = 0;
};

#endif // BASEAPIREPLYHANDLER_H
