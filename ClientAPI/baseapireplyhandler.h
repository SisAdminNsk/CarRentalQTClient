
#ifndef BASEAPIREPLYHANDLER_H
#define BASEAPIREPLYHANDLER_H


#include <QObject>

class BaseAPIReplyHandler : public QObject{
    Q_OBJECT
public:
    explicit BaseAPIReplyHandler(QObject *parent = nullptr);

    virtual void Handle() = 0;
};

#endif // BASEAPIREPLYHANDLER_H
