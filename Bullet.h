#ifndef BULLET_H
#define BULLET_H
#include "GameObject.h"
#include <Tank.h>
#include <QTimer>

class Bullet : public GameObject
{
public:
    Bullet();
    Bullet(uint);//orientation
    ~Bullet();
    uint getDirection();
private:
    QTimer movementTimer;
    void setDirection(uint);
    uint orientation;
};

#endif // BULLET_H
