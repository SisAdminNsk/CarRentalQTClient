
#ifndef STATICUSERDATA_H
#define STATICUSERDATA_H

#include <QString>
#include <QMap>
#include <QMutex>

class DataCache {
public:
    static DataCache& instance(){
        static DataCache instance;
        return instance;
    }

    DataCache(const DataCache&) = delete;
    DataCache& operator=(const DataCache&) = delete;

    void setData(const QString& key, const QString& value) {
        QMutexLocker locker(&mutex);
        data[key] = value;
    }

    QString getData(const QString& key) {
        QMutexLocker locker(&mutex);
        return data.value(key, QString());
    }

private:
    DataCache() {}

    QMap<QString, QString> data;
    QMutex mutex;
};

#endif // STATICUSERDATA_H
