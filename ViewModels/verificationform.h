#ifndef VERIFICATIONFORM_H
#define VERIFICATIONFORM_H

#include <QMainWindow>
#include <QTimer>
#include <QIntValidator>

#include "API/DTO/registratedto.h"
#include "API/Endpoints/Users/Requests/verificationrequest.h"
#include "ViewModels/LoadingLabel/loadinglabel.h"

namespace Ui {
class VerificationForm;
}

class VerificationForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit VerificationForm(RegistrateDTO registrateDTO, QNetworkCookieJar *parentCookies,  QWidget *parent = nullptr);
    ~VerificationForm();

private:
    void Setup();
    Ui::VerificationForm *ui;
    RegistrateDTO registrateDTO;
    VerificationRequest *verificationRequest = nullptr;

    LoadingLabel *loadingLabel = nullptr;
    QNetworkCookieJar *cookieJar = nullptr;

    int remainingTimeInSec;
    int timerTickInMs;

    QTimer *sendAgainTimer = nullptr;

    void SetupTimer();
    void SetupInputVerificationCode();
    void SetupVerificationRequest(RegistrateDTO registrateDTO, QString verificationCode);
private slots:

    void SetSendAgainButtonTimeoutInSec();
    void OnTimerTick();
    void OnSendAgainButtonClicked();
    void OnSubmitButtonClicked();
    void OnCloseButtonClicked();

    void OnVerificationError(const QString& message);
    void OnVerificationSuccess(const QString& message);

    void OnVerificationRequestFinished();
    void OnVerificationRequestStarted();
};

#endif // VERIFICATIONFORM_H
