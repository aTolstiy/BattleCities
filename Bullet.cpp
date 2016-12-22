#include "Bullet.h"

Bullet::Bullet()
{
    qDebug() << "bullet def ctr";
}

Bullet::Bullet(uint tankDirection)
{
    setPixmap(QPixmap(":/images/bullet.png"));
    objectType = Level::BULLET;
    setDirection(tankDirection);
}

Bullet::~Bullet()
{
    qDebug() << "bullet dstrct";
}

void Bullet::setDirection(uint direction)
{
    orientation = direction;
    setTransformOriginPoint(boundingRect().center());
    setRotation(0);
    switch(direction)
    {
    //TODO: move to GameObject class
    case Tank::up:
        //do nothing
        break;
    case Tank::down:
        setRotation(180);
        break;
    case Tank::left:
        setRotation(-90);
        break;
    case Tank::right:
        setRotation(90);
        break;
    default:
        qDebug() << "uknown rotation direction";
    }

}

uint Bullet::getDirection()
{
    return orientation;
}
