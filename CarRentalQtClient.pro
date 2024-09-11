QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ClientAPI/OnUserRouteRequests/loginuserreplyhandler.cpp \
    ClientAPI/OnUserRouteRequests/loginuserrequest.cpp \
    ClientAPI/OnUserRouteRequests/registraterequest.cpp \
    ClientAPI/OnUserRouteRequests/registrateuserreplyhandler.cpp \
    ClientAPI/baseapireplyhandler.cpp \
    ClientAPI/baseapirequest.cpp \
    carrentalclientwindow.cpp \
    loadinglabel.cpp \
    main.cpp \
    mainwindow.cpp \
    registrationwindow.cpp

HEADERS += \
    ClientAPI/OnUserRouteRequests/loginuserreplyhandler.h \
    ClientAPI/OnUserRouteRequests/loginuserrequest.h \
    ClientAPI/OnUserRouteRequests/registraterequest.h \
    ClientAPI/OnUserRouteRequests/registrateuserreplyhandler.h \
    ClientAPI/baseapireplyhandler.h \
    ClientAPI/baseapirequest.h \
    carrentalclientwindow.h \
    loadinglabel.h \
    mainwindow.h \
    registrationwindow.h

FORMS += \
    RegistrationWindow.ui \
    carrentalclientwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    media/loading.gif \
    media/loading1.gif \
    serverConfiguration.json

RESOURCES += \
    resources.qrc
