
#ifndef FROMURLIMAGELOADER_H
#define FROMURLIMAGELOADER_H


#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPixmap>
#include <QUrl>
#include <QStringList>
#include <QProgressBar>
#include <QMutex>

#include "ViewModels/MainApplicationViewModels/NestedViewModels/CarItemCard/carcardviewmodel.h"


class FromURLImageLoader : public QObject
{
    Q_OBJECT
public:
    explicit FromURLImageLoader(QProgressBar *progressBar, QObject *parent = nullptr);
    void LoadImage(const QString &urlString, CarCardViewModel *carCard);
    void SetTargetsForDownloadCount(int count);
private:

    QList<CarCardViewModel*> carCards;
    QNetworkAccessManager manager;
    QProgressBar *progressBar;
    int totalImages = 0;
    int loadedImages = 0;
    QMutex mutex;
private slots:
    void OnImageDownloaded(QNetworkReply *reply, CarCardViewModel *carCard);
signals:
    void OnAllImagesDownloaded(QList<CarCardViewModel*> carCards);
};

#endif // FROMURLIMAGELOADER_H
