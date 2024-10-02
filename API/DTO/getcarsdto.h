
#ifndef GETCARSDTO_H
#define GETCARSDTO_H

#include "baseapidto.h"
#include <QUrlQuery>

class GetCarsDTO : public BaseApiDTO
{
public:
    GetCarsDTO
    (
        const int pageNumber,
        const int pageSize,
        const QString& sortOrder,
        const QString& sortBy
    );

    virtual QByteArray ToByteArray() override;
    QUrlQuery ToUrlQuery();

    int PageNumber;
    int PageSize;
    QString SortOrder;
    QString SortBy;
};

#endif // GETCARSDTO_H
