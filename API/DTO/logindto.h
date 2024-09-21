
#ifndef LOGINDTO_H
#define LOGINDTO_H

#include "API/DTO/baseapidto.h"

class LoginDTO : public BaseApiDTO
{
public:
    virtual QByteArray ToByteArray() override;
    LoginDTO(const QString& email, const QString& password);

    QString email;
    QString password;
};

#endif // LOGINDTO_H
