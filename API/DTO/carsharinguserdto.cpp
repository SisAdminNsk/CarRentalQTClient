
#include "carsharinguserdto.h"

CarsharingUserDTO::CarsharingUserDTO()
{

}

CarsharingUserDTO::CarsharingUserDTO(const QJsonObject& document){

    Id =  document.value("id").toString();
    Name = document.value("name").toString();
    Surname = document.value("surname").toString();
    Patronymic = document.value("patronymic").toString();
    Phone = document.value("phone").toString();
    Email = document.value("email").toString();
    Age = document.value("age").toInt();
}

