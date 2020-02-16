#-------------------------------------------------
#
# Project created by QtCreator 2018-11-28T21:39:37
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = Believer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        widget.cpp \
    car.cpp \
    checkpoint.cpp \
    staticobject.cpp \
    opponent.cpp \
    game.cpp \
    abyss.cpp \
    movingobject.cpp \
    bridge.cpp \
    trampoline.cpp \
    mycarfactory.cpp \
    opponentcarfactory.cpp \
    opponentup.cpp \
    opponentright.cpp \
    opponentdown.cpp \
    opponentleft.cpp

HEADERS += \
        widget.h \
    car.h \
    checkpoint.h \
    staticobject.h \
    opponent.h \
    game.h \
    abyss.h \
    drawable.h \
    positional.h \
    movingobject.h \
    moveable.h \
    bridge.h \
    trampoline.h \
    collisionable.h \
    carfactory.h \
    mycarfactory.h \
    opponentcarfactory.h \
    opponentstate.h \
    opponentstate.h \
    opponentup.h \
    opponentright.h \
    opponentdown.h \
    opponentleft.h

FORMS += \
        widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
