#pragma once
#include "Map.h"
#include "Snake.h"

class Apple {
	unsigned int sx;
	unsigned int sy;
	unsigned int x;
	unsigned int y;
	unsigned int benefit;

	Apple(unsigned int x, unsigned int y, unsigned int benefit) {
		sx = x;
		sy = y;
		this->benefit = benefit;
		this->x = rand() % sx;
		this->y = rand() % sy;
	}

	void isEat(Snake& snake) {
		if(x==snake.getPosition(0,))
	}

};

