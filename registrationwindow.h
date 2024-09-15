#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QMainWindow>
#include <QJsonObject>
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
    QString checkboxValidStyleSheet = "QLineEdit { border: 2px solid green; }";
    QString checkboxNotValidStyleSheet = "QLineEdit { border: 2px solid red; }";

    Ui::RegistrationWindow *ui;
    RegistrateRequest *registrateRequest = nullptr;

    void setupInputFields();
    void setupCheckboxes();
    void connectiWithSignals();

private slots:
    void setupRegistrationForm();

    void onRegistratePushButtonClicked();
    void onRegistrationSuccess(const QString& message);
    void onRegistrationError(const QList<QString>& message);

    void validateEmail();
    void validatePassword();
    void validateUsername();
    void validateConfirmPassword();
};

#endif // REGISTRATIONWINDOW_H
