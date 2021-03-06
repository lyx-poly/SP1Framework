#pragma once
#include "Area.h"
#include <stdlib.h>
#include <time.h>

class Map {
public:
	int floor;
	Area* map[6][6]; // 4x4 map array but taken as 6x6 for camera tracking
	int toDisplay[96][192]; // upscaled to display onto the screen ( 2 x 4 )

	Map(int f, int floorType); // floorType: 1 for normal dungeons, 2 for bosses
	~Map();

	void generateDungeon();

};

