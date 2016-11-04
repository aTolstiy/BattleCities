#ifndef GAME_H
#define GAME_H

#include <LevelLoader.h>
#include <Level.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <GameObject.h>
#include <Brick.h>
#include <Goblet.h>
#include <Steelblock.h>
#include <Tank.h>
#include <PlayerTank.h>
#include <QKeyEvent>

class Game
{
public:
    Game();
    static const int LEVEL_1 = 1;
    Level loadLevel(uint);
    void drawLevel(Level&);
    void initViewScene(void);
    void keyPressEvent(QKeyEvent *);
private:
    GameObject * createObject(uint);
    LevelLoader levelLoader;
    Level currentLevel;
    QGraphicsScene scene;
    QGraphicsView view;
    QVector<GameObject*> objects;
    GameObject * player1Tank = nullptr;
};

#endif // GAME_H
