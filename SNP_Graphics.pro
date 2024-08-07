QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainview.cpp \
    matprocess.cpp \
    plane.cpp \
    sceneobject.cpp \
    sphere.cpp \
    vec2.cpp \
    vec3.cpp \
    vecfunctions.cpp \
    windowqgv.cpp

HEADERS += \
    mainview.hpp \
    matprocess.hpp \
    plane.hpp \
    sceneobject.hpp \
    settings.hpp \
    sphere.hpp \
    vec2.hpp \
    vec3.hpp \
    vecfunctions.hpp \
    windowqgv.hpp

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
