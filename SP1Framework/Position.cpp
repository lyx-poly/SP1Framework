#include "Position.h"

Position::Position()
{
	row = 0;
	col = 0;
}

Position::Position(int r, int c)
{
	row = r;
	col = c;
}

int Position::getRow()
{
	return row;
}

int Position::getCol()
{
	return col;
}
