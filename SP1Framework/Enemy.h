#pragma once
#include "Entity.h"
class Enemy : class Entity
{
public:
	Enemy();
	void Define(int hp, int dmg); // Sets stats to an enemy object
	void movement(); // Movement AI
	void Attack(Entity* ptrEntity);
	void Defend();
	~Enemy();
};

