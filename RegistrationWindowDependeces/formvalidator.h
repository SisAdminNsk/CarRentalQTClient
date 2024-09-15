
#ifndef FORMVALIDATOR_H
#define FORMVALIDATOR_H


#include <QObject>

class FormValidator : public QObject
{
    Q_OBJECT
public:
    explicit FormValidator(QObject *parent = nullptr);
public:
    static bool isValidEmail(const QString &email);
    static bool isValidUsername(const QString &username);
    static bool isValidPassword(const QString &password);
signals:

};

#endif // FORMVALIDATOR_H
