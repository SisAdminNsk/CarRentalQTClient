QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    API/DTO/baseapidto.cpp \
    API/DTO/logindto.cpp \
    API/DTO/registratedto.cpp \
    API/Endpoints/Users/RepliesHandlers/loginreplyhandler.cpp \
    API/Endpoints/Users/RepliesHandlers/registratereplyhandler.cpp \
    API/Endpoints/Users/RepliesHandlers/verificatereplyhandler.cpp \
    API/Endpoints/Users/Requests/loginrequest.cpp \
    API/Endpoints/Users/Requests/registraterequest.cpp \
    API/Endpoints/Users/Requests/verificationrequest.cpp \
    API/Endpoints/baseapireplyhandler.cpp \
    API/Endpoints/baseapirequest.cpp \
    ClientCache/cachemanager.cpp \
    Configuration/configurationmanager.cpp \
    ViewModels/LoadingLabel/loadinglabel.cpp \
    ViewModels/Validators/formvalidator.cpp \
    ViewModels/registrationform.cpp \
    ViewModels/verificationform.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    API/DTO/baseapidto.h \
    API/DTO/logindto.h \
    API/DTO/registratedto.h \
    API/Endpoints/Users/RepliesHandlers/loginreplyhandler.h \
    API/Endpoints/Users/RepliesHandlers/registratereplyhandler.h \
    API/Endpoints/Users/RepliesHandlers/verificatereplyhandler.h \
    API/Endpoints/Users/Requests/loginrequest.h \
    API/Endpoints/Users/Requests/registraterequest.h \
    API/Endpoints/Users/Requests/verificationrequest.h \
    API/Endpoints/baseapireplyhandler.h \
    API/Endpoints/baseapirequest.h \
    ClientCache/cachemanager.h \
    Configuration/configurationmanager.h \
    ViewModels/LoadingLabel/loadinglabel.h \
    ViewModels/Validators/formvalidator.h \
    ViewModels/registrationform.h \
    ViewModels/verificationform.h \
    mainwindow.h

FORMS += \
    ViewModels/registrationform.ui \
    ViewModels/verificationform.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
