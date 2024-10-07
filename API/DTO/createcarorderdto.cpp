
#include "createcarorderdto.h"

#include <QJsonObject>
#include <QJsonDocument>

CreateCarOrderDTO::CreateCarOrderDTO()
{

}

QByteArray CreateCarOrderDTO::ToByteArray(){

    QJsonObject jsonLike;

    jsonLike["CarId"] = CarId;
    jsonLike["CarsharingUserId"] = CarsharingUserId;

    QJsonObject leaseDateTime;
    leaseDateTime["StartOfLease"] = StartOfLease;
    leaseDateTime["EndOfLease"] = EndOfLease;
    jsonLike["LeaseDateTime"] = leaseDateTime;

    jsonLike["Comment"] = Comment;
    jsonLike["ApproximatePrice"] = ApproximatePrice;

    return QJsonDocument(jsonLike).toJson();
}

