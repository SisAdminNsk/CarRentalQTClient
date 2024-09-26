#ifndef CARSVIEWMODEL_H
#define CARSVIEWMODEL_H

#include <QWidget>

namespace Ui {
class CarsViewModel;
}

class CarsViewModel : public QWidget
{
    Q_OBJECT

public:
    explicit CarsViewModel(QWidget *parent = nullptr);
    ~CarsViewModel();

private:
    Ui::CarsViewModel *ui;
};

#endif // CARSVIEWMODEL_H
