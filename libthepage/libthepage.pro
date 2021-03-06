QT += gui thelib

TEMPLATE = lib
DEFINES += LIBTHEPAGE_LIBRARY
TARGET = thepage

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

unix:!macx {
    QT += thelib

    CI = $$(CI)
    if (isEmpty(CI)) {
        target.path = $$[QT_INSTALL_LIBS]
    } else {
        target.path = /usr/lib
    }

    INSTALLS += target
}

win32 {
    INCLUDEPATH += "C:/Program Files/thelibs/include"
    LIBS += -L"C:/Program Files/thelibs/lib" -lthe-libs
}

SOURCES += \
    document.cpp \
    documentprovider.cpp \
    documentprovidermanager.cpp \
    page.cpp

HEADERS += \
    document.h \
    documentprovider.h \
    documentprovidermanager.h \
    libthepage_global.h \
    page.h \
    plugininterface.h
