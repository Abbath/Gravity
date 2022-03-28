#-------------------------------------------------
#
# Project created by QtCreator 2016-12-18T19:06:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gravity
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    view.cpp \
    core.cpp

HEADERS  += mainwindow.hpp \
    view.hpp \
    core.hpp \
    defs.hpp

FORMS    += mainwindow.ui \
    view.ui
