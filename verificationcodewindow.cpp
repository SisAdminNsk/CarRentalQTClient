#include "verificationcodewindow.h"
#include "ui_verificationcodewindow.h"

VerificationCodeWindow::VerificationCodeWindow(UserRegistrateDTO userRegistrateDTO, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VerificationCodeWindow),
    userRegistrateDTO(userRegistrateDTO)
{
    ui->setupUi(this);

    setWindowIcon(QIcon(":/Media/media/carsharingLogo.png"));

    setFixedSize(350, 175);
    setMinimumSize(350,175);
    setMaximumSize(350,175);

    sendAgainButtonCD = new QTimer(this);

    QObject::connect(ui->submitButton, &QPushButton::clicked, this, &VerificationCodeWindow::onSubmitButtonClicked);
    QObject::connect(ui->sendAgainButton, &QPushButton::clicked, this, &VerificationCodeWindow::onSendAgainButtonClicked);
    QObject::connect(sendAgainButtonCD, &QTimer::timeout, this, &VerificationCodeWindow::onTimerTick);

    setSendAgainButtonCDInSeconds();
    onSendAgainButtonClicked();
}

void VerificationCodeWindow::setSendAgainButtonCDInSeconds(){
    remainingTime = 10;
}

VerificationCodeWindow::~VerificationCodeWindow()
{
    delete ui;
}

void VerificationCodeWindow::onTimerTick(){

    if (remainingTime > 0) {
        remainingTime--;
        ui->timeLabel->setText(QString::fromStdString(std::to_string(remainingTime)) + " сек.");
    } else {
        // упаковать в функцию onTimeout
        sendAgainButtonCD->stop();
        ui->timeLabel->setVisible(false);
        ui->timeLabel->setText("");
        ui->sendAgainButton->setEnabled(true);
    }
}

void VerificationCodeWindow::onSendAgainButtonClicked(){
    setSendAgainButtonCDInSeconds();
    ui->timeLabel->setVisible(true);
    ui->sendAgainButton->setDisabled(true);
    sendAgainButtonCD->start(timerTickInMs);
}

void VerificationCodeWindow::onSubmitButtonClicked(){
    ui->sendAgainButton->setDisabled(true);
    sendAgainButtonCD->start(remainingTime);
    ui->timeLabel->setVisible(true);

    // заблокировать кнопки sendAgainButton до истечения таймера
    // Отправить запрос на эндпоинт endRegistration
    // установить таймер кнопки sendAgainButton
}
