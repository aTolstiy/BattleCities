#include "Steelblock.h"

SteelBlock::SteelBlock()
{
    setPixmap(QPixmap(":/images/steel.png"));
    objectType = Level::TILE_STEEL;
}

