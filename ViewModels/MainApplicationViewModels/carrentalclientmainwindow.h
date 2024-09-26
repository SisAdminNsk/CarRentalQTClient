#ifndef CARRENTALCLIENTMAINWINDOW_H
#define CARRENTALCLIENTMAINWINDOW_H

#include <QMainWindow>

#include "ViewModels/MainApplicationViewModels/NestedViewModels/cabinetviewmodel.h"
#include "ViewModels/MainApplicationViewModels/NestedViewModels/carsviewmodel.h"

namespace Ui {
class CarRentalClientMainWindow;
}

class CarRentalClientMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CarRentalClientMainWindow(QWidget *parent = nullptr);
    ~CarRentalClientMainWindow();

private:
    Ui::CarRentalClientMainWindow *ui;
    CabinetViewModel *cabinetViewModel;
    CarsViewModel *carsViewModel;

private slots:
    void OnCabinetButtonClicked();
    void OnCarsButtonClicked();
};

#endif // CARRENTALCLIENTMAINWINDOW_H
