#include "Map.h"

Map::Map(int f, int floorType) : map{ nullptr } {

	int row = 1;
	int col = 1;
	this->floor = f;

	if (floorType == 0) {
		map[4][3] = new Area(0b0001, 2, 0);
		map[3][3] = new Area(0b0101, 2, 0);
		map[2][3] = new Area(0b0100, 2, 2);
	}

	if (floorType == 2) {
		map[1][1] = new Area(0b0010, 2, 0);
		map[1][2] = new Area(0b1010, 2, 0);
		map[1][3] = new Area(0b1000, 2, 2);
	}

	if (floorType == 1) {
		generateDungeon();
	}

	for (int row = 0; row < 6; row++) {
		for (int col = 0; col < 6; col++) {
			if (map[row][col] == nullptr) map[row][col] = new Area();
		}
	}

	for (int row = 0; row < 6; row++) {
		for (int col = 0; col < 6; col++) {
			for (int row2 = 0; row2 < 16; row2++) {
				for (int col2 = 0; col2 < 16; col2++) {
					for (int row3 = 0; row3 < 96; (row3 += 2)) {
						for (int col3 = 0; col3 < 192; (col3 += 4)) {
							toDisplay[row3][col3] = (map[row][col]->area[row2][col2]);
							toDisplay[row3][col3 + 1] = (map[row][col]->area[row2][col2]);
							toDisplay[row3][col3 + 2] = (map[row][col]->area[row2][col2]);
							toDisplay[row3][col3 + 3] = (map[row][col]->area[row2][col2]);
							toDisplay[row3 + 1][col3] = (map[row][col]->area[row2][col2]);
							toDisplay[row3 + 1][col3 + 1] = (map[row][col]->area[row2][col2]);
							toDisplay[row3 + 1][col3 + 2] = (map[row][col]->area[row2][col2]);
							toDisplay[row3 + 1][col3 + 3] = (map[row][col]->area[row2][col2]);
						}
					}
				}
			}
		}
	}

}

Map::~Map() {
	// do nothing for now
}

void Map::generateDungeon() {

	int row = 1;
	int col = 1;

	col = rand() % 4 + 1;

	int rb = (int)(pow(2, rand() % 2 + 1));
	int rbl = (int)(pow(2, rand() % 3 + 1));
	int bl = (int)(pow(2, rand() % 2 + 2));

	std::cout << row << col << std::endl;

	if (col == 1) map[1][col] = new Area((rb & 0b0110), 1, 0); // possible doors: right, bottom
	if (col == 2 || col == 3) map[1][col] = new Area((rbl & 0b1110), 1, 0); // possible doors: right, bottom, left
	if (col == 4) map[1][col] = new Area((bl & 0b1100), 1, 0); // possible doors: bottom, left

	Area* ptr;
	ptr = map[1][col];

	while (1) {

		rb = (int)(pow(2, rand() % 2 + 1));
		rbl = (int)(pow(2, rand() % 3 + 1));
		bl = (int)(pow(2, rand() % 2 + 2));

		if (row < 4) {
			if (ptr->flags & 0b0010) { // if right
				if (col == 3) {
					if (map[row][col + 1] == nullptr) map[row][++col] = new Area(0b1100, 1, 1);
				}

				if (col < 3) {
					if (map[row][col + 1] == nullptr) map[row][++col] = new Area(((rb & 0b0110) | 0b1000), 1, 1);
				}
			}

			if (ptr->flags & 0b1000) { // if left
				if (col == 2) {
					if (map[row][col - 1] == nullptr) map[row][--col] = new Area(0b0110, 1, 1);
				}

				if (col > 2) {
					if (map[row][col - 1] == nullptr) map[row][--col] = new Area(((bl & 0b1100) | 0b0010), 1, 1);
				}
			}
		}

		if (ptr->flags & 0b0100) { // if down
			if (row == 3) {
				if (col == 1) map[++row][col] = new Area(0b0011, 1, 1);
				if (col == 4) map[++row][col] = new Area(0b1001, 1, 1);
				else if (col == 2 || col == 3) {
					int i = rand() % 2;
					if (i == 0) map[++row][col] = new Area(0b1001, 1, 1);
					if (i == 1) map[++row][col] = new Area(0b0011, 1, 1);
				}
			}

			if (row <= 2) {
				if (map[row + 1][col] == nullptr) {
					if (col == 4) map[++row][col] = new Area(((bl & 0b1100) | 0b0001), 1, 1);
					if (col == 1) map[++row][col] = new Area(((rb & 0b0110) | 0b0001), 1, 1);
					else if (col == 2 || col == 3) map[++row][col] = new Area(((rbl & 0b1110) | 0b0001), 1, 1);
				}
			}
		}

		ptr = map[row][col];

		if (row == 4) {
			if (ptr->flags & 0b0010) map[row][++col] = new Area(0b1000, 1, 2);
			if (ptr->flags & 0b1000) map[row][--col] = new Area(0b0010, 1, 2);
			break;
		}
	}
}

