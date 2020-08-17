#include "Enemy.h"

Enemy::Enemy()
{
	//
}

void Enemy::Define(int hp, int dmg)
{
	HP = hp;
	Damage = dmg;
}

void Enemy::movement()
{
}

void Enemy::Attack(Entity* ptrEntity)
{
}

void Enemy::Defend()
{
}

void Enemy::sethealth(int health)
{
	Hp = health;
	return 0;
}

Enemy::~Enemy()
{
	//
}
