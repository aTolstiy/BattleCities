#include "GameObject.h"

GameObject::GameObject()
{
}


GameObject::GameObject(const uint picId)
    : objectType(picId)
{
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
