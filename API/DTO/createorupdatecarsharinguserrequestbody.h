
#ifndef CREATEORUPDATECARSHARINGUSERREQUESTBODY_H
#define CREATEORUPDATECARSHARINGUSERREQUESTBODY_H

#include <QString>
#include "API/DTO/baseapidto.h"
#include "API/DTO/carsharinguserdto.h"

class CreateOrUpdateCarsharingUserRequestBody : BaseApiDTO
{
public:
    CreateOrUpdateCarsharingUserRequestBody(const CarsharingUserDTO& carsharingUser);
    virtual QByteArray ToByteArray() override;

    QString UserId;
    QString Name;
    QString Surname;
    QString Patronymic;
    int Age;
    QString Phone;
};

#endif // CREATEORUPDATECARSHARINGUSERREQUESTBODY_H
