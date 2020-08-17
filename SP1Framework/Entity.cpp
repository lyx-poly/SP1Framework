#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

int Entity::getHP()
{
	return HP;
}

void Entity::setPos(int r, int c)
{
	Position TempPos(r, c);
	Pos = TempPos;
}

Position Entity::getPos()
{
	return Pos;
}
