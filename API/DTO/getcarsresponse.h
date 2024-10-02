
#ifndef GETCARSRESPONSE_H
#define GETCARSRESPONSE_H

#include <QJsonObject>
#include <QList>

#include "API/DTO/cardto.h"

class GetCarsResponse
{
public:
    GetCarsResponse();

    GetCarsResponse(const QJsonObject& document);

    int TotalItem;
    int PageNumber;
    int PageSize;

    QList<CarDTO> Cars;
};

#endif // GETCARSRESPONSE_H
