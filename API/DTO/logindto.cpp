
#include "API/DTO/logindto.h"

#include <QJsonDocument>
#include <QJsonObject>

LoginDTO::LoginDTO(const QString& email, const QString& password)
{
    this->email = email;
    this->password = password;
}

QByteArray LoginDTO::ToByteArray(){

    QJsonObject jsonLike;

    jsonLike["Email"] = email;
    jsonLike["Password"] = password;

    return QJsonDocument(jsonLike).toJson();
}

