TEMPLATE = lib
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "/home/giorgos/include"
SOURCES += \
    cedartrie.cpp

CONFIG += c++11

HEADERS += \
    cedartrie.h

target.path = "/home/giorgos/projects/libs"

inc2.path = "/home/giorgos/projects/libs"
inc2.files += *.h
INSTALLS += target inc2
