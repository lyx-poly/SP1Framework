#pragma once
class Position
{
public:
	int row, col;
	Position();
	Position(int r, int c);
	int getRow();
	int getCol();
};