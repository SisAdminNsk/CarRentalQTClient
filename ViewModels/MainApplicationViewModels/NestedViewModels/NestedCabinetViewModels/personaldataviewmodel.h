#ifndef PERSONALDATAVIEWMODEL_H
#define PERSONALDATAVIEWMODEL_H

#include <QWidget>

#include "API/DTO/carsharinguserdto.h"
#include "ViewModels/LoadingLabel/loadinglabel.h"
#include "API/Endpoints/CarsharingUsers/Requests/createorupdatecarsharinguserrequest.h"

namespace Ui {
class PersonalDataViewModel;
}

class PersonalDataViewModel : public QWidget
{
    Q_OBJECT

public:
    explicit PersonalDataViewModel(const LoginResponse& loginResponse,QWidget *parent = nullptr);
    ~PersonalDataViewModel();

    void WhenSwappedToView();
    void FillProfileData(const CarsharingUserDTO& carsharingUser);
    CarsharingUserDTO GetProfileData();
private:
    LoadingLabel *loadingLabel;
    CreateOrUpdateCarsharingUserRequest *createOrUpdateCarsharingUserRequest = nullptr;

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

    LoginResponse loginResponse;
    Ui::PersonalDataViewModel *ui;

    bool isAllDataValid = false;

    void OnSaveChangesRequestStarted();
    void OnSaveChangesRequestFinished();
private slots:

    void OnSaveChangesButtonClicked();

    void ValidateAge();
    void ValidateName();
    void ValidateSurname();
    void ValidatePatronymic();
    void ValidatePhone();

    void ValidateAllForms();

    void OnCreateOrUpdateCarsharingUserSuccess(const QString& message);
    void OnCreateOrUpdateCarsharingUserFailure(const QList<QString>& Errors);
};

#endif // PERSONALDATAVIEWMODEL_H
