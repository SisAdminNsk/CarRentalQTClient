
#ifndef STATICUSERDATA_H
#define STATICUSERDATA_H

#include <QString>
#include <QMap>
#include <QMutex>

#include "API/DTO/loginresponse.h"
#include "API/DTO/carsharinguserdto.h"

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

    void SaveLoginCredentials(const LoginResponse& loginCredentials){
        QMutexLocker locker(&mutex);
        data["bearer"] = loginCredentials.Token;
        data["userId"] = loginCredentials.UserId;
    }

    LoginResponse GetUserLoginCredentials(){
        if(!data.contains("bearer") || (!data.contains("userId"))){
            throw std::runtime_error("This data should not be here yet");
        }

        LoginResponse loginCredentials;
        loginCredentials.Token = data["bearer"];
        loginCredentials.UserId = data["userId"];

        return loginCredentials;
    }

    void SaveCarhsaringUserProfile(const CarsharingUserDTO& carsharingUser){
        QMutexLocker locker(&mutex);
        userData = carsharingUser;
    }

    CarsharingUserDTO GetCarsharingUserProfile(){
        return userData;
    }

private:
    DataCache() {}

    QMap<QString, QString> data;
    CarsharingUserDTO userData;
    QMutex mutex;
};

#endif // STATICUSERDATA_H
