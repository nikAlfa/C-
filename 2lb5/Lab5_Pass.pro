QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    passwindow.cpp \
    person.cpp \
    date.cpp

HEADERS += \
    mainwindow.hpp \
    passwindow.hpp \
    person.hpp \
    date.hpp

FORMS += \
    mainwindow.ui

RESOURCES += \
    resources.qrc
