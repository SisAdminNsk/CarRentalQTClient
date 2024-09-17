QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ClientAPI/OnUserRouteRequests/Requests/userregistratedto.cpp \
    ClientAPI/OnUserRouteRequests/loginuserreplyhandler.cpp \
    ClientAPI/OnUserRouteRequests/loginuserrequest.cpp \
    ClientAPI/OnUserRouteRequests/registraterequest.cpp \
    ClientAPI/OnUserRouteRequests/registrateuserreplyhandler.cpp \
    ClientAPI/OnUserRouteRequests/verificatecoderequest.cpp \
    ClientAPI/baseapireplyhandler.cpp \
    ClientAPI/baseapirequest.cpp \
    RegistrationWindowDependeces/formvalidator.cpp \
    carrentalclientwindow.cpp \
    loadinglabel.cpp \
    main.cpp \
    mainwindow.cpp \
    registrationwindow.cpp \
    verificationcodewindow.cpp

HEADERS += \
    ClientAPI/OnUserRouteRequests/Requests/userregistratedto.h \
    ClientAPI/OnUserRouteRequests/loginuserreplyhandler.h \
    ClientAPI/OnUserRouteRequests/loginuserrequest.h \
    ClientAPI/OnUserRouteRequests/registraterequest.h \
    ClientAPI/OnUserRouteRequests/registrateuserreplyhandler.h \
    ClientAPI/OnUserRouteRequests/verificatecoderequest.h \
    ClientAPI/baseapireplyhandler.h \
    ClientAPI/baseapirequest.h \
    RegistrationWindowDependeces/formvalidator.h \
    carrentalclientwindow.h \
    loadinglabel.h \
    mainwindow.h \
    registrationwindow.h \
    verificationcodewindow.h

FORMS += \
    RegistrationWindow.ui \
    carrentalclientwindow.ui \
    mainwindow.ui \
    verificationcodewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    media/carsharingLogo.png \
    media/email.png \
    media/loading.gif \
    media/loading1.gif \
    media/loginIcon.png \
    media/passwordIcon.png \
    media/usernameIcon.png \
    serverConfiguration.json

RESOURCES += \
    resources.qrc
