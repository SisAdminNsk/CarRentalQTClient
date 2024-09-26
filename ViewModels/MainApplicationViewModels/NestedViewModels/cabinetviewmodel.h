#ifndef CABINETVIEWMODEL_H
#define CABINETVIEWMODEL_H

#include <QWidget>

#include "ViewModels/MainApplicationViewModels/NestedViewModels/NestedCabinetViewModels/personaldataviewmodel.h"
#include "ViewModels/MainApplicationViewModels/NestedViewModels/NestedCabinetViewModels/activeordersviewmodel.h"
#include "ViewModels/MainApplicationViewModels/NestedViewModels/NestedCabinetViewModels/closedordersviewmodel.h"

namespace Ui {
class CabinetViewModel;
}

class CabinetViewModel : public QWidget
{
    Q_OBJECT

public:
    explicit CabinetViewModel(QWidget *parent = nullptr);
    ~CabinetViewModel();

private:
    Ui::CabinetViewModel *ui;

    PersonalDataViewModel *personalViewModel;
    ActiveOrdersViewModel *activeOrdersViewModel;
    ClosedOrdersViewModel *closedOrdersViewModel;
private slots:
    void OnPersonalDataButtonClicked();
    void OnActiveOrdersButtonClicked();
    void OnClosedOrdersButtonClicked();
};

#endif // CABINETVIEWMODEL_H
