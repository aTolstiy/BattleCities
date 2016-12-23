#ifndef TANK_H
#define TANK_H
#include "GameObject.h"
#include "Level.h"

class Tank : public GameObject
{
public:
    Tank();
    Tank(uint);
    enum Orientation {up, right, down, left};//move me to gameobj.cpp
    enum Order {moveUP, moveRIGHT, moveDOWN, moveLEFT, fire};
    void setOrientation(uint const);
    uint getOrientation(void);
    void giveOrder(uint);
protected:
    uint healthPoints = 1;
    uint orientation = down;
private:
    bool hasOrder = false;
};

#endif // TANK_H
