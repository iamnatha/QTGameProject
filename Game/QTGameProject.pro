#-------------------------------------------------
#
# Project created by QtCreator 2019-04-27T17:50:59
#
#-------------------------------------------------

QT       += core gui \
         multimedia # For playing sound

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTGameProject
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
        mainwindow.cpp \
    projectile.cpp \
    personnage.cpp \
    ennemie.cpp \
    personnagescore.cpp \
    jeux.cpp \
    personnagevie.cpp \
    personnageprojectile.cpp \
    coin.cpp \
    coeur.cpp \
    gameover.cpp \
    dragon.cpp \
    troll.cpp \
    zelda.cpp \
    trunk.cpp \
    gameobject.cpp \
    obstacle.cpp

HEADERS += \
        mainwindow.h \
    projectile.h \
    personnage.h \
    ennemie.h \
    personnagescore.h \
    jeux.h \
    personnagevie.h \
    personnageprojectile.h \
    coin.h \
    coeur.h \
    gameover.h \
    dragon.h \
    troll.h \
    zelda.h \
    trunk.h \
    gameobject.h \
    obstacle.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc
