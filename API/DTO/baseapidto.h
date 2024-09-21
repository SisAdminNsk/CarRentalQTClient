
#ifndef BASEAPIDTO_H
#define BASEAPIDTO_H


#include <QObject>

class BaseApiDTO
{
public:
    virtual QByteArray ToByteArray() = 0;
    BaseApiDTO();
};

#endif // BASEAPIDTO_H
