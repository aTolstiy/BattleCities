#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsPixmapItem>
#include <Level.h>


class GameObject: public QGraphicsPixmapItem
{
public:
   GameObject();
   GameObject(const uint);
   GameObject(const GameObject&);
   virtual ~GameObject();
protected:
    uint objectType; // collision detection
};

#endif // GAMEOBJECT_H
