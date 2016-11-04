#include "GameObject.h"

GameObject::GameObject()
{

}


GameObject::GameObject(const uint picId)
    : objectType(picId)
{
    /*switch (picId)
    {
    case (Level::TILE_EMPTY)://empty tile
        qDebug() << "empty";
        break;
    case (Level::TILE_BRICK):
        //replace with 16x16
        setPixmap(QPixmap(":/images/brickBig.png"));
        break;
    case (Level::TILE_STEEL):
        setPixmap(QPixmap("D:/brick.png"));
        break;
    case (Level::PLAYER1_SPAWN):
        setPixmap(QPixmap(":/images/playerOne1.png"));
        break;
    case (Level::PLAYER2_SPAWN):
        setPixmap(QPixmap(":/.png"));
        break;
    case (Level::GOBLET):
        setPixmap(QPixmap(":/images/basePlayerOne.png"));
        break;
    case (Level::ENEMY_SPAWN):
        //
        break;
    default:
        qDebug("incorrect value in config");
    }
    */
}

GameObject::GameObject(const GameObject& obj):objectType(obj.objectType)
{
}

uint GameObject::getObjectType() const
{
    return objectType;
}

GameObject::~GameObject()
{

}
