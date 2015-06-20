CONFIG += link_pkgconfig

PKGCONFIG += libnotify

HEADERS += \
    $$PWD/libnotifyhandler.h

SOURCES += \
    $$PWD/libnotifyhandler.c

INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD
