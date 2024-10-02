
#include "fromurlimageloader.h"

FromURLImageLoader::FromURLImageLoader(QProgressBar *progressBar, QObject *parent)
    : QObject{parent},
    progressBar(progressBar)
{
    this->loadedImages = 0;
    this->totalImages = 0;
}

void FromURLImageLoader::SetTargetsForDownloadCount(int count){

    this->totalImages = count;
    progressBar->setRange(0, totalImages);
}

void FromURLImageLoader::SendRequest(const QString& urlString, CarCardViewModel* carCard, bool keepOrder){
    QUrl url(urlString);
    QNetworkRequest request(url);
    QNetworkReply *reply = manager.get(request);

    connect(reply, &QNetworkReply::finished, [this, reply, keepOrder, carCard]() {
        OnImageDownloaded(reply, carCard, keepOrder);
    });
}

void FromURLImageLoader::LoadImage(const QString &urlString, CarCardViewModel *carCard){
    SendRequest(urlString, carCard);
}

void FromURLImageLoader::LoadImagesWithOrderSaving(const QList<QString>& urls, QList<CarCardViewModel*> carCards){

    this->carCards.clear();
    this->carCards.resize(urls.size());
    carImageToPosition.clear();

    for(size_t i=0;i<urls.size();i++){

        carImageToPosition[urls[i]] = i;
        SendRequest(urls[i], carCards[i], true);
    }
}

void FromURLImageLoader::OnImageDownloaded(QNetworkReply *reply, CarCardViewModel *carCard, bool keepOrder){

    if (reply->error() == QNetworkReply::NoError) {

        QPixmap pixmap;
        pixmap.loadFromData(reply->readAll());
        carCard->SetImageFromPixmap(pixmap);
    }
    reply->deleteLater();

    mutex.lock();
    loadedImages++;

    if(keepOrder){
        auto index = carImageToPosition[reply->url().toString()];
        this->carCards[index] = carCard;
    }
    else{
        this->carCards.push_back(carCard);
    }

    progressBar->setValue(loadedImages);
    mutex.unlock();

    if (loadedImages == totalImages) {
        emit OnAllImagesDownloaded(carCards);
    }
}
