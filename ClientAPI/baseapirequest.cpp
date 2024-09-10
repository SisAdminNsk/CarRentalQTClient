
#include "baseapirequest.h"

BaseAPIRequest::BaseAPIRequest(QObject *parent)
    : QObject{parent}
{

}

BaseAPIRequest::~BaseAPIRequest(){
    delete manager;
    delete replyHandler;
}

