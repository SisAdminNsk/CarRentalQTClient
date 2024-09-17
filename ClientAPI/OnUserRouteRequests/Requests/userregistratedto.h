
#ifndef USERREGISTRATEREQUEST_H
#define USERREGISTRATEREQUEST_H

#include <QString>

class UserRegistrateDTO
{
public:
    QString email;
    QString userName;
    QString password;

    UserRegistrateDTO(QString email, QString username, QString password);
};

#endif // USERREGISTRATEREQUEST_H
