#ifndef CARRESERVATIONFORM_H
#define CARRESERVATIONFORM_H

#include <QDialog>
#include <QLabel>

#include "API/DTO/cardto.h"
#include "API/DTO/carsharinguserdto.h"

namespace Ui {
class CarReservationForm;
}

class CarReservationForm : public QDialog
{
    Q_OBJECT

public:
    explicit CarReservationForm
    (
        const CarDTO& car,
        const QPixmap& carImagePixmap,
        const CarsharingUserDTO& carsharingUser,
        const QDateTime& serverDate,QWidget *parent = nullptr
    );

    ~CarReservationForm();

private:
    void Setup();
    void SetupApiRequest();
    void SetupInputWidgets();
    void SetupWindow();

    void FillPersonalData();
    void FillCarData();

    QDateTime serverDateTime;
    CarDTO car;
    QPixmap carImagePixmap;
    CarsharingUserDTO carsharingUser;

    Ui::CarReservationForm *ui;
private slots:
    void OnStartOfLeaseDateSelected(const QDate& date);
    void OnEndOfLeaseDateSelected(const QDate& date);

    void OnStartOfLeaseTimeSelected(const int currentSelectedIndex);
    void OnEndOfLeaseTimeSelected(const int currentSelectedIndex);
};

#endif // CARRESERVATIONFORM_H
