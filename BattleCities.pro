TEMPLATE = app

QT += qml quick\
      widgets
CONFIG += c++11

SOURCES += main.cpp \
    LevelLoader.cpp \
    Level.cpp \
    Game.cpp \
    GameObject.cpp \
    Bullet.cpp \
    Tank.cpp \
    Brick.cpp \
    Goblet.cpp \
    Steelblock.cpp \
    PlayerTank.cpp

RESOURCES += qml.qrc \
    BattleCity.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    LevelLoader.h \
    Level.h \
    Game.h \
    GameObject.h \
    Bullet.h \
    Tank.h \
    Brick.h \
    Goblet.h \
    Steelblock.h \
    PlayerTank.h

