#pragma once
#include "Map.h"
#include "Snake.h"

class Apple {
public:
	unsigned int sx;
	unsigned int sy;
	unsigned int x;
	unsigned int y;
	unsigned int benefit;

	Apple(unsigned int x, unsigned int y, unsigned int benefit = 1) {
		sx = x;
		sy = y;
		this->benefit = benefit;
		this->x = rand() % sx;
		this->y = rand() % sy;
	}

	void isEat(Snake& snake, Map& map) {
		if (x == snake.getPosition(0).first && y == snake.getPosition(0).second) {
			for(int i=0;i<benefit;i++) snake.addTail();
			int i = 0;
			while (map.getMap(x, y) != 0 && i<20) {
				x = rand() % sx;
				y = rand() % sy;
				i++;
			}
		}
	}

};

