#-------------------------------------------------
#
# Project created by QtCreator 2018-07-15T18:05:42
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mario
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


SOURCES += \
        main.cpp \
    blocks.cpp \
    gameboard.cpp \
    mario.cpp \
    background.cpp \
    coins.cpp \
    myscene.cpp \
    globalapplication.cpp \
    baseblock.cpp \
    cloud.cpp \
    monster.cpp \
    mushroom.cpp \
    questionmark.cpp \
    stone.cpp \
    tube.cpp \
    flower.cpp \
    flag.cpp \
    sound.cpp \
    coinnumber.cpp

HEADERS += \
    blocks.h \
    gameboard.h \
    mario.h \
    background.h \
    coins.h \
    myscene.h \
    globalapplication.h \
    baseblock.h \
    cloud.h \
    monster.h \
    mushroom.h \
    questionmark.h \
    stone.h \
    tube.h \
    flower.h \
    flag.h \
    sound.h \
    coinnumber.h

FORMS += \
        mainwindow.ui

RC_ICONS = icon.ico
