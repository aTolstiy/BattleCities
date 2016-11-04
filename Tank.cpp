#include "Tank.h"

Tank::Tank()
{

}

Tank::Tank(uint tankType)
{
    if (tankType == Level::PLAYER1_SPAWN)
    {
        setPixmap(QPixmap(":/images/playerOne1.png"));
        //default player health, may change to const/enum
        healthPoints = 3;
    }
}
