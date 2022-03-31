#pragma once
class Map {
	char* map;
	unsigned int x;
	unsigned int y;
public:
	Map() {}

	void setup(unsigned int x, unsigned int y);

	void fill(char what);

	unsigned int getX() {
		return x;
	}

	unsigned int getY() {
		return y;
	}

	char* executeMap() {
		return map;
	}

	char getMap(unsigned int x, unsigned int y);

	void setMap(unsigned int x, unsigned int y, char what);

	~Map() {
		delete[] map;
	}

};

