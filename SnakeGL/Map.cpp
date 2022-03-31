#include "Map.h"

void Map::setup(unsigned int x, unsigned int y) {
	this->x = x;
	this->y = y;

	map = new char[x * y];
}

void Map::fill(char what) {
	for (int i = 0;i < x * y;i++)
		map[i] = what;
}

char Map::getMap(unsigned int x, unsigned int y) {
	unsigned int lx = x < this->x ? x : this->x - 1;
	unsigned int ly = y < this->y ? y : this->y - 1;
	return map[lx + ly * this->x];
}

void Map::setMap(unsigned int x, unsigned int y, char what) {
	unsigned int lx = x < this->x ? x : this->x - 1;
	unsigned int ly = y < this->y ? y : this->y - 1;
	map[lx + ly * this->x] = what;
}
