#-------------------------------------------------
#
# Project created by QtCreator 2022-07-01T03:34:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = practice
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    chromosome.cpp \
    ga.cpp \
    inputwindow.cpp \
    inputguiwindow.cpp \
    parameterswindow.cpp \
    dataga.cpp \
    gawindow.cpp \
    presenter.cpp \
    model.cpp \
    problemsolve.cpp

HEADERS  += mainwindow.h \
    chromosome.h \
    ga.h \
    inputwindow.h \
    inputguiwindow.h \
    parameterswindow.h \
    dataga.h \
    gawindow.h \
    presenter.h \
    model.h \
    problemsolve.h \
    datastruct.h

FORMS    += mainwindow.ui \
    inputwindow.ui \
    inputguiwindow.ui \
    parameterswindow.ui \
    gawindow.ui
