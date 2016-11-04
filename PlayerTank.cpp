#include "PlayerTank.h"

PlayerTank::PlayerTank()
{
    setPixmap(QPixmap(":/images/playerOne1.png"));
    //default player health, may change to const/enum
    healthPoints = 3;

}

