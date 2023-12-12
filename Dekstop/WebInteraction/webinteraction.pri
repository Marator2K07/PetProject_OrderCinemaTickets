QT += qml
QT += quickwidgets

HEADERS += \
    $$PWD/typesforrequestmethod.h \
    $$PWD/webcontext.h \
    $$PWD/webrequestinfo.h \
    $$PWD/webrequestwidget.h

SOURCES += \
    $$PWD/webcontext.cpp \
    $$PWD/webrequestinfo.cpp \
    $$PWD/webrequestwidget.cpp

DISTFILES += \
    $$PWD/Resourses/QML/QMLLoadingPicture.qml

RESOURCES += \
    $$PWD/Pictures.qrc \
    $$PWD/QML.qrc
