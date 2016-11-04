#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>
#include <QVector>
#include <QDebug>

class Level
{
public:
    explicit Level();
    Level(int,int,QVector<int>);
    Level(const Level &);
    QVector<int> getMap(void) const;
    QVector<int> getEnemySpawnPoints(void) const;
    void addEnemySpawnPoint(uint);
    int getHeight(void) const;
    int getWidth(void) const;
    //change this to enum
    //0 empty field; 1 brick wall; 2 steel wall; 3 player1 spawn loc; 4 player2 spawn loc; 5 goblet; 6 enemy spawn loc;
    static const uint TILE_EMPTY = 0;
    static const uint TILE_BRICK = 1;
    static const uint TILE_STEEL = 2;
    static const uint PLAYER1_SPAWN = 3;
    static const uint PLAYER2_SPAWN = 4;
    static const uint GOBLET = 5;
    static const uint ENEMY_SPAWN = 6;
private:
    int mapHeight, mapWidth;
    QVector<int> map;
    QVector<int> enemySpawnPoints;
signals:
public slots:
};

#endif // LEVEL_H
