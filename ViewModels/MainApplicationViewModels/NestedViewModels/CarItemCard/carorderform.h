#ifndef CARORDERFORM_H
#define CARORDERFORM_H

#include <QMainWindow>

namespace Ui {
class CarOrderForm;
}

class CarOrderForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit CarOrderForm(QWidget *parent = nullptr);
    ~CarOrderForm();

private:
    void Setup();
    void SetupApiRequest();
    void SetupInputWidgets();
    void SetupWindow();

    Ui::CarOrderForm *ui;
};

#endif // CARORDERFORM_H
