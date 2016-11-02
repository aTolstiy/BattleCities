//#include <QGuiApplication>
//#include <QQmlApplicationEngine>
#include <QApplication>

#include <QGraphicsScene>
#include <QGraphicsView>

#include <LevelLoader.h>
#include <Level.h>
#include <game.h>

void drawLevel(Level);

const int LEVEL_1 = 1;

int main(int argc, char *argv[])
{
    //QGuiApplication app(argc, argv);
    QApplication app(argc, argv);

    Game game;

    qDebug() << "App path : " << app.applicationDirPath();

    return app.exec();
}

