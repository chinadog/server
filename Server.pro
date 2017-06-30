#-------------------------------------------------
#
# Проект Server создан 2017-01-27 21:29:46
#
#-------------------------------------------------

QT += core sql
QT -= gui

PROJECT = Server

TARGET = $$PROJECT
CONFIG += console
CONFIG -= app_bundle
CONFIG += link_pkgconfig
CONFIG += c++11

TEMPLATE = app

SOURCES += $$PWD/src/main.cpp \
           $$PWD/src/server.cpp \
           $$PWD/src/filter.cpp \
           $$PWD/src/config.cpp \
           $$PWD/src/correl.cpp

HEADERS += $$PWD/src/server.h \
           $$PWD/src/filter.h \
           $$PWD/src/config.h \
           $$PWD/src/correl.h

DESTDIR = $$PWD/build/bin/
MOC_DIR = $$PWD/build/bin/
OBJECTS_DIR = $$PWD/build/bin/

isEmpty(PREFIX) {
    PREFIX=$$PWD
}
CONFIG_PATH = $$PREFIX/etc/Trifecta/
RESOURCES_PATH = $$PREFIX/share/$$PROJECT/

DEFINES += CONFIG_PATH=\\\"$$CONFIG_PATH\\\"
DEFINES += RESOURCES_PATH=\\\"$$RESOURCES_PATH\\\"

PKG_CONFIG_LIBDIR  = $$PREFIX/share/pkgconfig
PKG_CONFIG_LIBDIR += $$system(pkg-config --variable pc_path pkg-config)

PKGCONFIG += TLogger TDB TRules

# installs
target.path     = $$PREFIX/bin

# config
config.path = $$PREFIX/etc/Trifecta
config.files += $$PWD/config/trifecta.conf

# rules
rules.path = $$PREFIX/etc/Trifecta/rules/
rules.files += $$PWD/config/rules/*

INSTALLS += target config rules

OTHER_FILES += $$PWD/config/rules/filter/win.rule
