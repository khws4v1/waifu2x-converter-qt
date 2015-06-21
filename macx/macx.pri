QT += macextras

LIBS += -framework Cocoa

HEADERS += \
    $$PWD/usernotificationwrapper.h

OBJECTIVE_HEADERS += \
    $$PWD/usernotificationhandler.h

OBJECTIVE_SOURCES += \
    $$PWD/usernotificationhandler.mm \
    $$PWD/usernotificationwrapper.mm

INCLUDEPATH += $$PWD
