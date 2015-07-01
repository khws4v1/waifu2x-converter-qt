#-------------------------------------------------
#
# Project created by QtCreator 2015-05-29T18:31:25
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = waifu2x-converter-qt
TEMPLATE = app

CONFIG += c++11

TRANSLATIONS = waifu2x-converter-qt_ja.ts

SOURCES += main.cpp\
        mainwindow.cpp \
    waifu2xconverterqtsettings.cpp \
    processdialog.cpp \
    droplabel.cpp \
    preferencesdialog.cpp \
    aboutdialog.cpp \
    optionpreferencesform.cpp \
    waifu2xconvertercppoptions.cpp

HEADERS  += mainwindow.h \
    waifu2xconverterqtsettings.h \
    processdialog.h \
    droplabel.h \
    preferencesdialog.h \
    aboutdialog.h \
    optionpreferencesform.h \
    waifu2xconvertercppoptions.h

FORMS    += mainwindow.ui \
    processdialog.ui \
    preferencesdialog.ui \
    aboutdialog.ui \
    optionpreferencesform.ui
