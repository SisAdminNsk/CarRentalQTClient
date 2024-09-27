#ifndef CARSVIEWMODEL_H
#define CARSVIEWMODEL_H

#include <QWidget>

#include "API/DTO/loginresponse.h"

namespace Ui {
class CarsViewModel;
}

class CarsViewModel : public QWidget
{
    Q_OBJECT

public:
    explicit CarsViewModel(const LoginResponse& loginResponse, QWidget *parent = nullptr);
    ~CarsViewModel();

private:
    Ui::CarsViewModel *ui;
};

#endif // CARSVIEWMODEL_H
