#include "Level.h"

Level::Level()
{
    qDebug() << "def ctr";
}

Level::Level(int height, int width, QVector<int> loadedMap):mapHeight(height), mapWidth(width), map(loadedMap)
{
    qDebug() << "int int qvect ctr";
}

Level::Level(const Level &other):
      mapHeight(other.mapHeight),
      mapWidth(other.mapWidth),
      map(other.map)
{
}

int Level::getWidth(void) const
{
    return mapWidth;
}
int Level::getHeight(void) const
{
    return mapHeight;
}

QVector<int> Level::getMap(void) const
{
    return map;
}
