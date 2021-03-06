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
#include <Bullet.h>
#include <PlayerTank.h>
#include <QKeyEvent>
#include <QTimer>

class Game : public QGraphicsScene
{
public:
    Game();
    ~Game();
    static const int LEVEL_1 = 1;
    Level loadLevel(uint);
    void drawLevel(Level&);
    void initViewScene(void);
    void keyPressEvent(QKeyEvent *);
private:
    GameObject * createObject(uint);
    LevelLoader levelLoader;
    Level currentLevel;
    QGraphicsView view;
    QVector<GameObject*> objects;
    QVector<Bullet*> bullets;
    QVector<GameObject*> tanks;
    //GameObject * player1Tank = nullptr;
    PlayerTank * player1Tank = nullptr;
    QTimer * bulletTimer;
    QTimer * spawnTimer;
    QTimer * AIControlTimer;
    uint tanksSpawned = 0;
private slots:
    void onBulletTimeout();
    void onSpawnTimeout();
    void onAIControlTimeout();
};

#endif // GAME_H
