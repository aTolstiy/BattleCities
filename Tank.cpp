#include "Tank.h"

Tank::Tank()
{

}

Tank::Tank(uint tankType):GameObject(tankType)
{
    if (tankType == Level::PLAYER1_SPAWN)
    {
        //default player health, may change to const/enum
        healthPoints = 3;
        setOrientation(up);
    }
    else if (tankType == Level::TANK)
    {
        healthPoints = 1;
        setOrientation(down);
        setPixmap(QPixmap(":/images/playerAI_1.gif"));
    }
}

void Tank::setOrientation(uint newOrient)
{
    orientation = newOrient;
    setTransformOriginPoint(boundingRect().center());
    setRotation(0);
    switch(newOrient)
    {
    case up:
        //do nothing
        break;
    case down:
        setRotation(180);
        break;
    case left:
        setRotation(-90);
        break;
    case right:
        setRotation(90);
        break;
    default:
        qDebug() << "uknown rotation direction";
    }
}

uint Tank::getOrientation(void)
{
    return orientation;
}

void Tank::giveOrder(uint order)
{
    hasOrder = true;
}
