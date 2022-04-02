#pragma once
#include "Map.h"
#include "Snake.h"
#include "soundSupport.h"

class Apple {
public:
	unsigned int sx;
	unsigned int sy;
	unsigned int x;
	unsigned int y;
	unsigned int benefit;

	Apple (){}

	void setup(unsigned int x, unsigned int y, unsigned int benefit = 1) {
		sx = x;
		sy = y;
		this->benefit = benefit;
		this->x = 1+rand() % (sx-2);
		this->y = 1+rand() % (sy-2);
	}

	void isEat(Snake& snake, Map& map) {
		if (x == snake.getPosition(0).first && y == snake.getPosition(0).second) {
			for(int i=0;i<benefit;i++) snake.addTail();
			int i = 0;
			while (map.getMap(x, y) != 0 && i<20) {
				x = 1 + rand() % (sx - 2);
				y = 1 + rand() % (sy - 2);
				i++;
			}
			soundSupport::sound(L"Nom.wav", SND_ASYNC);
		}
	}

};

