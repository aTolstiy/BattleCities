#ifndef PLAYERTANK_H
#define PLAYERTANK_H
#include "Tank.h"
#include <QObject>
#include <QKeyEvent>


class PlayerTank :  public Tank
{
public:

    PlayerTank();
    PlayerTank(uint);
};

#endif // PLAYERTANK_H
