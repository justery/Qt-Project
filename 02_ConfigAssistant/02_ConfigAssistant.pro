#-------------------------------------------------
#
# Project created by QtCreator 2014-01-06T21:57:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 02_ConfigAssistant
TEMPLATE = app


SOURCES += main.cpp\
    widget.cpp \
    newprojectdialog.cpp\
    mainwindow.cpp

HEADERS  += mainwindow.h \
    widget.h \
    newprojectdialog.h

FORMS += \
    NewProjectDialog.ui
