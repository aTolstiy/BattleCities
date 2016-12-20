#include "PlayerTank.h"

PlayerTank::PlayerTank()
{
}

PlayerTank::PlayerTank(uint tankType):Tank(tankType)
{
    if (tankType == Level::PLAYER1_SPAWN)
    {
        //setPixmap(QPixmap(":/images/playerOne1.png"));
        setPixmap(QPixmap(":/images/playerOne32.png"));
        //default player health, may change to const/enum
        healthPoints = 3;
    }
}


