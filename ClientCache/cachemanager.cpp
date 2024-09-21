
#include "cachemanager.h"

CacheManager::CacheManager()
{

}

void CacheManager::SaveToCache(QString key, QVariant value){

    QSettings settings;

    settings.setValue(key, value);
}

QVariant CacheManager::LoadFromCache(QString key){

    QSettings settings;

    return settings.value(key);
}

