
#include "createorupdatecarsharinguserrequestbody.h"
#include <QJsonDocument>

CreateOrUpdateCarsharingUserRequestBody::CreateOrUpdateCarsharingUserRequestBody(const CarsharingUserDTO& carsharingUser)
{
    this->UserId = carsharingUser.Id;
    this->Age = carsharingUser.Age;
    this->Name = carsharingUser.Name;
    this->Surname = carsharingUser.Surname;
    this->Patronymic = carsharingUser.Patronymic;
    this->Phone = carsharingUser.Phone;
}

QByteArray CreateOrUpdateCarsharingUserRequestBody::ToByteArray(){

    QJsonObject jsonLike;

    jsonLike["UserId"] = UserId;
    jsonLike["Name"] = Name;
    jsonLike["Surname"] = Surname;
    jsonLike["Patronymic"] = Patronymic;
    jsonLike["Age"] = Age;
    jsonLike["Phone"] = Phone;

    return QJsonDocument(jsonLike).toJson();
}

