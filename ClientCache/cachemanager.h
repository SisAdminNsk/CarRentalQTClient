
#ifndef CACHEMANAGER_H
#define CACHEMANAGER_H

#include <QObject>
#include <QSettings>

class CacheManager
{
public:
    CacheManager();

    static void SaveToCache(QString key, QVariant value);
    static QVariant LoadFromCache(QString key);
};

#endif // CACHEMANAGER_H
