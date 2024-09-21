
#ifndef REGISTRATEDTO_H
#define REGISTRATEDTO_H

#include "baseapidto.h"



class RegistrateDTO : public BaseApiDTO
{
public:
    RegistrateDTO(const QString& username, const QString& email, const QString& password);

    virtual QByteArray ToByteArray() override;

    QString username;
    QString email;
    QString password;
};

#endif // REGISTRATEDTO_H
