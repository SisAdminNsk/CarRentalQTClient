
#include "loadinglabel.h"
#include <QMovie>

LoadingLabel::LoadingLabel(QSize size)
{
    gifImage = new QMovie(":/Media/media/loading1.gif");
    gifImage->setScaledSize(size);

    this->setMovie(gifImage);
    gifImage->start();
}

LoadingLabel::~LoadingLabel(){
    delete gifImage;
}
