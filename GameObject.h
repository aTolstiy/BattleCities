#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsPixmapItem>
#include <Level.h>
#include <QTimer>
#include <QObject>


class GameObject: public QGraphicsPixmapItem
{
public:
   GameObject();
   GameObject(const uint);
   GameObject(const GameObject&);
   uint getObjectType() const;
   virtual ~GameObject();
protected:
    uint objectType; // collision detection
};

#endif // GAMEOBJECT_H
