QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Spielerliste.cpp \
    main.cpp \
    mainwindow.cpp \
    spielfenster.cpp \
    zufallsgenerator.cpp
    spielfenster.cpp

HEADERS += \
    Spielerliste.h \
    mainwindow.h \
    spielfenster.h \
    zufallsgenerator.h
    spielfenster.h

FORMS += \
    mainwindow.ui \
    spielfenster.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    images/background.png \
    images/baer.png \
    images/cherry.png \
    images/mainpage.png \
    images/shot .png
