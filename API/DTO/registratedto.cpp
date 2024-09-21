
#include "registratedto.h"

#include <QJsonDocument>
#include <QJsonObject>

RegistrateDTO::RegistrateDTO(const QString& username, const QString& email, const QString& password)
{
    this->username = username;
    this->email = email;
    this->password = password;
}

QByteArray RegistrateDTO::ToByteArray(){

    QJsonObject jsonLike;

    jsonLike["Email"] = email;
    jsonLike["Password"] = password;
    jsonLike["Username"] = username;

    return QJsonDocument(jsonLike).toJson();
}
