#ifndef GAME_H
#define GAME_H

#include <LevelLoader.h>
#include <Level.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <GameObject.h>

class Game
{
public:
    Game();
    static const int LEVEL_1 = 1;
    Level loadLevel(uint);
    void drawLevel(Level&);
    void initViewScene(void);
private:
    LevelLoader levelLoader;
    Level currentLevel;
    QGraphicsScene scene;
    QGraphicsView view;
    QVector<GameObject*> objects;
};

#endif // GAME_H
