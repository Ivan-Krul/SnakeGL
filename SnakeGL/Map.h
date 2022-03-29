#pragma once
class Map {
public:
	char* map;
	int x;
	int y;

	Map(int x, int y);

	~Map() {
		delete[] map;
	}

};

