#ifndef CARRENTALCLIENTWINDOW_H
#define CARRENTALCLIENTWINDOW_H

#include <QWidget>

namespace Ui {
class CarRentalClientWindow;
}

class CarRentalClientWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CarRentalClientWindow(QWidget *parent = nullptr);
    ~CarRentalClientWindow();

private:
    Ui::CarRentalClientWindow *ui;
};

#endif // CARRENTALCLIENTWINDOW_H
