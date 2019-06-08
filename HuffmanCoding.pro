TEMPLATE = app
CONFIG += console c++1z
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        buildhufftree.cpp \
        buildhufftreetester.cpp \
        calculatefrequency.cpp \
        calculatefrequencytester.cpp \
        huffcodetreenode.cpp \
        huffcom.cpp \
        huffcomstring.cpp \
        main.cpp \
        messagedecode.cpp \
        messagedecodetester.cpp \
        messageencode.cpp \
        messageencodetester.cpp \
        nodecreate.cpp \
        nodecreatetester.cpp \
        treedelete.cpp \
        treedeletetester.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/gtest/release/ -lgtest
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/gtest/debug/ -lgtest
else:unix: LIBS += -L$$PWD/../lib/gtest/ -lgtest

INCLUDEPATH += $$PWD/../lib/gtest/include
DEPENDPATH += $$PWD/../lib/gtest/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../lib/gtest/release/libgtest.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../lib/gtest/debug/libgtest.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../lib/gtest/release/gtest.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../lib/gtest/debug/gtest.lib
else:unix: PRE_TARGETDEPS += $$PWD/../lib/gtest/libgtest.a

HEADERS += \
    buildhufftree.h \
    calculatefrequency.h \
    huffcodetreenode.h \
    huffcom.h \
    huffcomstring.h \
    messagedecode.h \
    messageencode.h \
    nodecreate.h \
    treedelete.h
