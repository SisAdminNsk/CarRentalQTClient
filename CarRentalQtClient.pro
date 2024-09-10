QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ClientAPI/OnUserRouteRequests/registraterequest.cpp \
    ClientAPI/OnUserRouteRequests/registrateuserreplyhandler.cpp \
    ClientAPI/baseapireplyhandler.cpp \
    ClientAPI/baseapirequest.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ClientAPI/OnUserRouteRequests/registraterequest.h \
    ClientAPI/OnUserRouteRequests/registrateuserreplyhandler.h \
    ClientAPI/baseapireplyhandler.h \
    ClientAPI/baseapirequest.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    serverConfiguration.json

RESOURCES += \
    resources.qrc
