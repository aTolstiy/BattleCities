#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <LevelLoader.h>

const int LEVEL_1 = 1;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    //QQmlApplicationEngine engine;
    //engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    qDebug() << "started";


    LevelLoader levelLoader;// = LevelLoader();
    levelLoader.loadLevel(LEVEL_1);


    return app.exec();
}

