
#include "getcarsdto.h"

#include <QJsonObject>
#include <QJsonDocument>

GetCarsDTO::GetCarsDTO(const int pageNumber,
                       const int pageSize,
                       const QString& sortOrder,
                       const QString& sortBy) :
    PageNumber(pageNumber),
    PageSize(pageSize),
    SortOrder(sortOrder),
    SortBy(sortBy)
{

}

QByteArray GetCarsDTO::ToByteArray(){

    QJsonObject jsonLike;

    jsonLike["PageNumber"] = PageNumber;
    jsonLike["PageSize"] = PageSize;
    jsonLike["SortOrder"] = SortOrder;
    jsonLike["SortBy"] = SortBy;

    return QJsonDocument(jsonLike).toJson();
}

QUrlQuery GetCarsDTO::ToUrlQuery(){

    QUrlQuery query;

    query.addQueryItem("pageNumber",QString::number(PageNumber));
    query.addQueryItem("pageSize", QString::number(PageSize));
    query.addQueryItem("sortBy", SortBy);
    query.addQueryItem("sortOrder", SortOrder);

    return query;
}
