
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkReply>
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
    void onRegistrationError(const QString &message);
    void onRegistrationSuccess(const QString &message);
    void onLoginError(const QString &message);
    void onLoginSuccess(const QString &message);
    void on_pushButton_2_clicked();

private:
    RegistrationWindow registrationWindow;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
