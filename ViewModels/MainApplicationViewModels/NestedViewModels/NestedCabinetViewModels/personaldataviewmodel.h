#ifndef PERSONALDATAVIEWMODEL_H
#define PERSONALDATAVIEWMODEL_H

#include <QWidget>

#include "API/DTO/carsharinguserdto.h"

namespace Ui {
class PersonalDataViewModel;
}

class PersonalDataViewModel : public QWidget
{
    Q_OBJECT

public:
    explicit PersonalDataViewModel(QWidget *parent = nullptr);
    ~PersonalDataViewModel();

    void WhenSwappedToView();
    void FillProfileData(const CarsharingUserDTO& carsharingUser);
    CarsharingUserDTO GetProfileData();
private:
    QString lineEditValidStyleSheet = "QLineEdit { border: 2px solid green; }";
    QString lineEditNotValidStyleSheet = "QLineEdit { border: 2px solid red; }";

    bool isValidAge = false;
    bool isValidName = false;
    bool isValidSurname = false;
    bool isValidPatronymic = false;
    bool isValidPhone = false;

    bool IsAllFormsValidated();

    void ConnectWithSignals();
    CarsharingUserDTO lastProfileData;

    Ui::PersonalDataViewModel *ui;

    bool isAllDataValid = false;
private slots:

    void OnSaveChangesButtonClicked();

    void ValidateAge();
    void ValidateName();
    void ValidateSurname();
    void ValidatePatronymic();
    void ValidatePhone();

    void ValidateAllForms();
};

#endif // PERSONALDATAVIEWMODEL_H
