
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QNetworkReply>
#include <QMovie>
#include "registrationwindow.h"

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
    void onLoginError(const QString &message);
    void onLoginSuccess(const QString &message);
    void onRegistratePushButtonClicked();
    void onLoginPushButtonClicked();

private:
    void onLoginRequestStarted();
    void onLoginRequestFinished();

    RegistrationWindow registrationWindow;
    Ui::MainWindow *ui;

    QLabel *loadingLabel = nullptr;
    QMovie *movie = nullptr;

    void setupLoginForm();
};

#endif // MAINWINDOW_H
