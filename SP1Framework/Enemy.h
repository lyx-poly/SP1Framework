#pragma once
#include "Entity.h"
class Enemy : class Entity
{
public:
	int enemytype;

	Enemy();
	void Define(int type); // Sets stats to an enemy object based
	void movement(); // Movement AI
	void Attack(Entity* ptrEntity);
	void Defend(); 
	~Enemy();
};

