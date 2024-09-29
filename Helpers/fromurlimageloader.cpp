
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

void FromURLImageLoader::LoadImage(const QString &urlString, CarCardViewModel *carCard){

    QUrl url(urlString);
    QNetworkRequest request(url);
    QNetworkReply *reply = manager.get(request);

    connect(reply, &QNetworkReply::finished, [this, reply, carCard]() {
        OnImageDownloaded(reply, carCard);
    });
}

void FromURLImageLoader::OnImageDownloaded(QNetworkReply *reply, CarCardViewModel *carCard){

    if (reply->error() == QNetworkReply::NoError) {

        QPixmap pixmap;
        pixmap.loadFromData(reply->readAll());
        carCard->SetImageFromPixmap(pixmap);
    }
    reply->deleteLater();

    mutex.lock();
    loadedImages++;
    this->carCards.push_back(carCard);
    progressBar->setValue(loadedImages); // Обновляем прогресс-бар
    mutex.unlock();

    // Проверяем, завершена ли загрузка всех изображений
    if (loadedImages == totalImages) {
        emit OnAllImagesDownloaded(carCards);
    }
}
