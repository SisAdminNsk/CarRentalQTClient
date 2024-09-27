
#ifndef CARSHARINGUSERDTO_H
#define CARSHARINGUSERDTO_H

#include <QJsonObject>

class CarsharingUserDTO
{
public:
    CarsharingUserDTO();

    CarsharingUserDTO(const QJsonObject& document);

    QString Id;
    QString Name;
    QString Surname;
    QString Patronymic;
    QString Email;
    QString Phone;
    int Age;
};

#endif // CARSHARINGUSERDTO_H
