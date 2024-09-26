
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <ViewModels/LoadingLabel/loadinglabel.h>
#include "ViewModels/registrationform.h"
#include "API/DTO/cardto.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void OnLoginError(const QString &message);
    void OnLoginSuccess(const QString &message);

    void OnGetCarsSuccess(const QList<CarDTO>& cars);
    void OnGetCarsFailure(const QString& message);


    void OnLoginRequestStarted();
    void OnLoginRequestFinished();

    void OnRegistratePushButtonClicked();
    void OnLoginPushButtonClicked();

private:
    void Setup();

    Ui::MainWindow *ui;
    LoadingLabel *loadingLabel;
    RegistrationForm *registrationForm;
};

#endif // MAINWINDOW_H
