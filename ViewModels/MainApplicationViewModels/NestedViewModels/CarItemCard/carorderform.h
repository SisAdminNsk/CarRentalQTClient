#ifndef CARORDERFORM_H
#define CARORDERFORM_H

#include <QMainWindow>
#include "API/DTO/cardto.h"
#include "API/DTO/carsharinguserdto.h"

namespace Ui {
class CarOrderForm;
}

class CarOrderForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit CarOrderForm
    (
        const CarDTO& car,
        const CarsharingUserDTO& carsharingUser,
        const QDate& serverDate,
        QWidget *parent = nullptr
    );

    ~CarOrderForm();

private:
    void Setup();
    void SetupApiRequest();
    void SetupInputWidgets();
    void SetupWindow();

    QDate serverDate;
    CarDTO car;
    CarsharingUserDTO carsharingUser;

    Ui::CarOrderForm *ui;

private slots:
    void OnStartOfLeaseDateSelected(const QDate& date);
    void OnEndOfLeaseDateSelected(const QDate& date);

    void OnStartOfLeaseTimeSelected(const int currentSelectedIndex);
    void OnEndOfLeaseTimeSelected(const int currentSelectedIndex);
};

#endif // CARORDERFORM_H
