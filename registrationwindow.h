#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QMainWindow>
#include <QJsonObject>
#include "loadinglabel.h"
#include <QHash>
#include <QCheckBox>
#include <QLineEdit>
#include "ClientAPI/OnUserRouteRequests/registraterequest.h"

namespace Ui {
class RegistrationWindow;
}

class RegistrationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegistrationWindow(QWidget *parent = nullptr);
    ~RegistrationWindow();

private:  
    QSet<QString> registeredUsernames;
    QSet<QString> registeredEmails;

    QString checkboxValidStyleSheet = "QLineEdit { border: 2px solid green; }";
    QString checkboxNotValidStyleSheet = "QLineEdit { border: 2px solid red; }";

    LoadingLabel *loadingLabel = nullptr;
    Ui::RegistrationWindow *ui;
    RegistrateRequest *registrateRequest = nullptr;

    void setupInputFields();
    void setupCheckboxes();
    void connectiWithSignals();

    void onRegistrateRequestStarted();
    void onRegistrateRequestFinished();

    bool isAllFormsValidated();

    void showDefaultEmailClue();
    void showDefaultUsernameClue();

    void onNotValidAction(QLineEdit* lineEdit, QLabel* clue, QCheckBox* checkbox);
    void onValidAction(QLineEdit* lineEdit, QLabel* clue, QCheckBox* checkbox);


private slots:
    void setupRegistrationForm();

    void onRegistratePushButtonClicked();
    void onRegistrationSuccess(const QString& message);
    void onRegistrationError(const QMap<QString, QString>& errors);

    void validateEmail();
    void validatePassword();
    void validateUsername();
    void validateConfirmPassword();
};

#endif // REGISTRATIONWINDOW_H
