#include "Map.h"

Map::Map(int x,int y) {
	this->x = x;
	this->y = y;

	map = new char[x * y];
}
