#-----------------------------------------------------------
#
# Project created by NecessitasQtCreator 2012-08-23T15:12:49
#
#-----------------------------------------------------------

QT       += core gui network

TARGET = lightmaps
TEMPLATE = app


SOURCES += main.cpp \
    lightmaps.cpp \
    mapzoom.cpp \
    slippymap.cpp

HEADERS  += \
    mapzoom.h \
    lightmaps.h \
    slippymap.h

FORMS    +=

CONFIG += mobility
MOBILITY = 

symbian {
    TARGET.UID3 = 0xecdbd123
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}

OTHER_FILES += \
    android/version.xml \
    android/AndroidManifest.xml \
    android/src/org/kde/necessitas/ministro/IMinistro.aidl \
    android/src/org/kde/necessitas/ministro/IMinistroCallback.aidl \
    android/src/org/kde/necessitas/origo/QtApplication.java \
    android/src/org/kde/necessitas/origo/QtActivity.java \
    android/res/values-ru/strings.xml \
    android/res/values-fr/strings.xml \
    android/res/values-nl/strings.xml \
    android/res/values-fa/strings.xml \
    android/res/drawable/logo.png \
    android/res/drawable/icon.png \
    android/res/values-pl/strings.xml \
    android/res/values-et/strings.xml \
    android/res/values-de/strings.xml \
    android/res/values-id/strings.xml \
    android/res/values-es/strings.xml \
    android/res/values-zh-rTW/strings.xml \
    android/res/layout/splash.xml \
    android/res/values-nb/strings.xml \
    android/res/drawable-hdpi/icon.png \
    android/res/values-ja/strings.xml \
    android/res/values-ro/strings.xml \
    android/res/values-it/strings.xml \
    android/res/values-ms/strings.xml \
    android/res/values-pt-rBR/strings.xml \
    android/res/drawable-mdpi/icon.png \
    android/res/values-zh-rCN/strings.xml \
    android/res/drawable-ldpi/icon.png \
    android/res/values/strings.xml \
    android/res/values/libs.xml \
    android/res/values-el/strings.xml \
    android/res/values-rs/strings.xml










