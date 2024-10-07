
#ifndef CREATECARORDERDTO_H
#define CREATECARORDERDTO_H

#include "baseapidto.h"

class CreateCarOrderDTO : public BaseApiDTO
{
public:
    CreateCarOrderDTO();
    virtual QByteArray ToByteArray() override;

    QString CarId;
    QString CarsharingUserId;
    QString StartOfLease;
    QString EndOfLease;
    QString Comment;
    double ApproximatePrice;
};

#endif // CREATECARORDERDTO_H
