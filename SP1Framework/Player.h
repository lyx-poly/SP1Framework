#pragma once
#include "Entity.h"
class Player :
    public Entity
{
public:
    
    Player();
    void Attack(Entity* ptrEntity);
    void Defend();
};

