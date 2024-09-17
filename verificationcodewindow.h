#ifndef VERIFICATIONCODEWINDOW_H
#define VERIFICATIONCODEWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "ClientAPI/OnUserRouteRequests/Requests/userregistratedto.h";

namespace Ui {
class VerificationCodeWindow;
}

class VerificationCodeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit VerificationCodeWindow(UserRegistrateDTO userRegistrateRequest, QWidget *parent = nullptr);
    ~VerificationCodeWindow();

private:
    int remainingTime;
    int timerTickInMs = 1000;
    Ui::VerificationCodeWindow *ui;
    QTimer *sendAgainButtonCD = nullptr;
    UserRegistrateDTO userRegistrateDTO;

    void setSendAgainButtonCDInSeconds();

private slots:
    void onTimerTick();
    void onSendAgainButtonClicked();
    void onSubmitButtonClicked();
};

#endif // VERIFICATIONCODEWINDOW_H
