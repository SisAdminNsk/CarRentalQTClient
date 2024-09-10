
#ifndef REGISTRATEREQUEST_H
#define REGISTRATEREQUEST_H


#include <QObject>

class RegistrateRequest : public QObject
{
    Q_OBJECT
public:
    explicit RegistrateRequest(QObject *parent = nullptr);

signals:

};

#endif // REGISTRATEREQUEST_H
