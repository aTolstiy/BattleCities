#ifndef TANK_H
#define TANK_H
#include "GameObject.h"
#include "Level.h"

class Tank : public GameObject
{
public:
    Tank();
    Tank(uint);
protected:
    int healthPoints = 1;
};

#endif // TANK_H
