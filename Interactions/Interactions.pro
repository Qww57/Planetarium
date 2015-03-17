TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/main.cpp \
    src/star.cpp \
    src/utilitaires.cpp

include(deployment.pri)
qtcAddDeployment()


unix|win32: LIBS += -lopencv_highgui

HEADERS += \
    include/star.h \
    include/utilitaires.h

unix|win32: LIBS += -lopencv_core
