#ifndef TANK_H
#define TANK_H
#include "GameObject.h"
#include "Level.h"

class Tank : public GameObject
{
public:
    Tank();
    Tank(uint);
    enum Orientation {up, right, down, left};
    void setOrientation(uint const);
    uint getOrientation(void);
protected:
    uint healthPoints = 1;
    uint orientation = up;
};

#endif // TANK_H
