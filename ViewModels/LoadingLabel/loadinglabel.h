
#ifndef LOADINGLABEL_H
#define LOADINGLABEL_H

#include <QLabel>

class LoadingLabel : public QLabel
{
    Q_OBJECT
public:
    LoadingLabel(QSize size, QWidget *parent = nullptr);
    ~LoadingLabel();
private:
    QMovie* gifImage = nullptr;
};

#endif // LOADINGLABEL_H
