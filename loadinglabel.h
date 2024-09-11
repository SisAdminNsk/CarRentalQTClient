
#ifndef LOADINGLABEL_H
#define LOADINGLABEL_H

#include <QLabel>

class LoadingLabel : public QLabel
{
public:
    LoadingLabel(QSize size);
    ~LoadingLabel();

private:
    QMovie* gifImage = nullptr;
};

#endif // LOADINGLABEL_H
