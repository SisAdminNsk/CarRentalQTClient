QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    API/DTO/baseapidto.cpp \
    API/DTO/cardto.cpp \
    API/DTO/carsharinguserdto.cpp \
    API/DTO/createcarorderdto.cpp \
    API/DTO/createorupdatecarsharinguserrequestbody.cpp \
    API/DTO/getcarsdto.cpp \
    API/DTO/getcarsresponse.cpp \
    API/DTO/logindto.cpp \
    API/DTO/loginresponse.cpp \
    API/DTO/registratedto.cpp \
    API/Endpoints/CarOrders/RepliesHandlers/createcarorderreplyhandler.cpp \
    API/Endpoints/CarOrders/RepliesHandlers/getservertimereplyhandler.cpp \
    API/Endpoints/CarOrders/Requests/createcarorderrequest.cpp \
    API/Endpoints/CarOrders/Requests/getservertimerequest.cpp \
    API/Endpoints/Cars/RepliesHandlers/getallcarsreplyhandler.cpp \
    API/Endpoints/Cars/RepliesHandlers/getcarsreplyhandler.cpp \
    API/Endpoints/Cars/Requests/getallcarsrequest.cpp \
    API/Endpoints/Cars/Requests/getcarsrequest.cpp \
    API/Endpoints/CarsharingUsers/RepliesHandlers/createorupdatecarsharinguserreplyhandler.cpp \
    API/Endpoints/CarsharingUsers/RepliesHandlers/getcarsharinguserreplyhandler.cpp \
    API/Endpoints/CarsharingUsers/Requests/createorupdatecarsharinguserrequest.cpp \
    API/Endpoints/CarsharingUsers/Requests/getcarsharinguserrequest.cpp \
    API/Endpoints/Users/RepliesHandlers/getverificationcodereplyhandler.cpp \
    API/Endpoints/Users/RepliesHandlers/loginreplyhandler.cpp \
    API/Endpoints/Users/RepliesHandlers/registratereplyhandler.cpp \
    API/Endpoints/Users/RepliesHandlers/verificatereplyhandler.cpp \
    API/Endpoints/Users/Requests/getverificationcoderequest.cpp \
    API/Endpoints/Users/Requests/loginrequest.cpp \
    API/Endpoints/Users/Requests/registraterequest.cpp \
    API/Endpoints/Users/Requests/verificationrequest.cpp \
    API/Endpoints/baseapireplyhandler.cpp \
    API/Endpoints/baseapirequest.cpp \
    Configuration/configurationmanager.cpp \
    Helpers/fromurlimageloader.cpp \
    ViewModels/LoadingLabel/loadinglabel.cpp \
    ViewModels/MainApplicationViewModels/NestedViewModels/CarItemCard/carcardviewmodel.cpp \
    ViewModels/MainApplicationViewModels/NestedViewModels/CarItemCard/carreservationform.cpp \
    ViewModels/MainApplicationViewModels/NestedViewModels/NestedCabinetViewModels/activeordersviewmodel.cpp \
    ViewModels/MainApplicationViewModels/NestedViewModels/NestedCabinetViewModels/closedordersviewmodel.cpp \
    ViewModels/MainApplicationViewModels/NestedViewModels/NestedCabinetViewModels/personaldataviewmodel.cpp \
    ViewModels/MainApplicationViewModels/NestedViewModels/cabinetviewmodel.cpp \
    ViewModels/MainApplicationViewModels/NestedViewModels/carsviewmodel.cpp \
    ViewModels/MainApplicationViewModels/carrentalclientmainwindow.cpp \
    ViewModels/Validators/formvalidator.cpp \
    ViewModels/Validators/personaldatavalidator.cpp \
    ViewModels/registrationform.cpp \
    ViewModels/verificationform.cpp \
    main.cpp \
    mainwindow.cpp \
    staticuserdata.cpp

HEADERS += \
    API/DTO/baseapidto.h \
    API/DTO/cardto.h \
    API/DTO/carsharinguserdto.h \
    API/DTO/createcarorderdto.h \
    API/DTO/createorupdatecarsharinguserrequestbody.h \
    API/DTO/getcarsdto.h \
    API/DTO/getcarsresponse.h \
    API/DTO/logindto.h \
    API/DTO/loginresponse.h \
    API/DTO/registratedto.h \
    API/Endpoints/CarOrders/RepliesHandlers/createcarorderreplyhandler.h \
    API/Endpoints/CarOrders/RepliesHandlers/getservertimereplyhandler.h \
    API/Endpoints/CarOrders/Requests/createcarorderrequest.h \
    API/Endpoints/CarOrders/Requests/getservertimerequest.h \
    API/Endpoints/Cars/RepliesHandlers/getallcarsreplyhandler.h \
    API/Endpoints/Cars/RepliesHandlers/getcarsreplyhandler.h \
    API/Endpoints/Cars/Requests/getallcarsrequest.h \
    API/Endpoints/Cars/Requests/getcarsrequest.h \
    API/Endpoints/CarsharingUsers/RepliesHandlers/createorupdatecarsharinguserreplyhandler.h \
    API/Endpoints/CarsharingUsers/RepliesHandlers/getcarsharinguserreplyhandler.h \
    API/Endpoints/CarsharingUsers/Requests/createorupdatecarsharinguserrequest.h \
    API/Endpoints/CarsharingUsers/Requests/getcarsharinguserrequest.h \
    API/Endpoints/Users/RepliesHandlers/getverificationcodereplyhandler.h \
    API/Endpoints/Users/RepliesHandlers/loginreplyhandler.h \
    API/Endpoints/Users/RepliesHandlers/registratereplyhandler.h \
    API/Endpoints/Users/RepliesHandlers/verificatereplyhandler.h \
    API/Endpoints/Users/Requests/getverificationcoderequest.h \
    API/Endpoints/Users/Requests/loginrequest.h \
    API/Endpoints/Users/Requests/registraterequest.h \
    API/Endpoints/Users/Requests/verificationrequest.h \
    API/Endpoints/baseapireplyhandler.h \
    API/Endpoints/baseapirequest.h \
    Configuration/configurationmanager.h \
    Helpers/fromurlimageloader.h \
    ViewModels/LoadingLabel/loadinglabel.h \
    ViewModels/MainApplicationViewModels/NestedViewModels/CarItemCard/carcardviewmodel.h \
    ViewModels/MainApplicationViewModels/NestedViewModels/CarItemCard/carreservationform.h \
    ViewModels/MainApplicationViewModels/NestedViewModels/NestedCabinetViewModels/activeordersviewmodel.h \
    ViewModels/MainApplicationViewModels/NestedViewModels/NestedCabinetViewModels/closedordersviewmodel.h \
    ViewModels/MainApplicationViewModels/NestedViewModels/NestedCabinetViewModels/personaldataviewmodel.h \
    ViewModels/MainApplicationViewModels/NestedViewModels/cabinetviewmodel.h \
    ViewModels/MainApplicationViewModels/NestedViewModels/carsviewmodel.h \
    ViewModels/MainApplicationViewModels/carrentalclientmainwindow.h \
    ViewModels/Validators/formvalidator.h \
    ViewModels/Validators/personaldatavalidator.h \
    ViewModels/registrationform.h \
    ViewModels/verificationform.h \
    mainwindow.h \
    staticuserdata.h

FORMS += \
    ViewModels/MainApplicationViewModels/NestedViewModels/CarItemCard/carcardviewmodel.ui \
    ViewModels/MainApplicationViewModels/NestedViewModels/CarItemCard/carreservationform.ui \
    ViewModels/MainApplicationViewModels/NestedViewModels/NestedCabinetViewModels/activeordersviewmodel.ui \
    ViewModels/MainApplicationViewModels/NestedViewModels/NestedCabinetViewModels/closedordersviewmodel.ui \
    ViewModels/MainApplicationViewModels/NestedViewModels/NestedCabinetViewModels/personaldataviewmodel.ui \
    ViewModels/MainApplicationViewModels/NestedViewModels/cabinetviewmodel.ui \
    ViewModels/MainApplicationViewModels/NestedViewModels/carsviewmodel.ui \
    ViewModels/MainApplicationViewModels/carrentalclientmainwindow.ui \
    ViewModels/registrationform.ui \
    ViewModels/verificationform.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    Media/carsharingLogo.png \
    Media/email.png \
    Media/loading.gif \
    Media/loading1.gif \
    Media/loading2.gif \
    Media/loginIcon.png \
    Media/passwordIcon.png \
    Media/usernameIcon.png \
    Media/verificationIcon.png
