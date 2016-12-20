#include "Brick.h"

Brick::Brick()
{
    setPixmap(QPixmap(":/images/brick.png"));
    objectType = Level::TILE_BRICK;
}


