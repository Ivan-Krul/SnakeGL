#pragma once
class Map {
public:
	char* map;
	int x;
	int y;

	Map(int x,int y) {
		this->x = x;
		this->y = y;

		map = new char[x * y];
	}

	~Map() {
		delete[] map;
	}

};

