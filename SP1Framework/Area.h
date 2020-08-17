#pragma once
#include <iostream>

class Area {
public:
	int area[16][16];
	unsigned short flags;

	Area();
	Area(unsigned short flags, int doorSize, int roomType);

	void display();
};

