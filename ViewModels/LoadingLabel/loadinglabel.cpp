
#include "loadinglabel.h"
#include <QMovie>
#include <QLabel>

LoadingLabel::LoadingLabel(QSize size, QWidget *parent) : QLabel(parent)
{
    gifImage = new QMovie(":/images/Media/loading1.gif");
    gifImage->setScaledSize(size);

    this->setMovie(gifImage);
    gifImage->start();
}

LoadingLabel::LoadingLabel(QWidget *parent) : QLabel(parent){
    gifImage = new QMovie(":/images/Media/loading1.gif");
    this->setMovie(gifImage);
    gifImage->start();
}

LoadingLabel::~LoadingLabel(){
    delete gifImage;
}

