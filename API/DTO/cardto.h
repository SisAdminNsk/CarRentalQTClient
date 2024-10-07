
#ifndef CARDTO_H
#define CARDTO_H

#include <QString>
#include <QJsonObject>

class CarDTO
{
public:
    CarDTO(QString id, QString brand, QString model, int power, QString carClass, double baseRentalPricePerHour, double acceleration, QString carImageUri);

    QString Id;
    QString Brand;
    QString Model;
    int Power;
    QString CarClass;
    double BaseRentalPricePerHour;
    QString CarImageURI;
    double CarAcceleration;

    CarDTO(const QJsonObject& document);

    CarDTO();
};

#endif // CARDTO_H
