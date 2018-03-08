#-------------------------------------------------
#
# Project created by QtCreator 2016-07-17T14:07:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtOpencvTest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cvmanipulation.cpp

HEADERS  += mainwindow.h \
    cvmanipulation.h

FORMS    += mainwindow.ui

INCLUDEPATH += .
INCLUDEPATH += /usr/local/include
INCLUDEPATH += /usr/local/include/opencv
INCLUDEPATH += /usr/local/include/opencv2
INCLUDEPATH += /usr/local/include/opencv2/core
INCLUDEPATH += /usr/local/include/opencv2/highgui
INCLUDEPATH += /usr/local/include/opencv2/imgproc
INCLUDEPATH += /usr/local/include/opencv2/flann
INCLUDEPATH += /usr/local/include/opencv2/photo
INCLUDEPATH += /usr/local/include/opencv2/video
INCLUDEPATH += /usr/local/include/opencv2/features2d
INCLUDEPATH += /usr/local/include/opencv2/objdetect
INCLUDEPATH += /usr/local/include/opencv2/calib3d
INCLUDEPATH += /usr/local/include/opencv2/ml
INCLUDEPATH += /usr/local/include/opencv2/contrib

LIBS += `pkg-config opencv --cflags --libs`
#CONFIG += link_pkgconfig
#PKGCONFIG += opencv
