#ifndef PERSONALDATAVIEWMODEL_H
#define PERSONALDATAVIEWMODEL_H

#include <QWidget>

namespace Ui {
class PersonalDataViewModel;
}

class PersonalDataViewModel : public QWidget
{
    Q_OBJECT

public:
    explicit PersonalDataViewModel(QWidget *parent = nullptr);
    ~PersonalDataViewModel();

private:
    Ui::PersonalDataViewModel *ui;
};

#endif // PERSONALDATAVIEWMODEL_H
