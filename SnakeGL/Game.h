#pragma once
#include "Map.h"
#include "Snake.h"
#include "Apple.h"
#include "defines.h"

#pragma comment(lib, "winmm.lib")

class Game {
	Map map;
	unsigned int nApple;
	Apple* apple;
public:
	Snake snake;

	void setup(unsigned int nApple) {
		map.setup(MapX,MapY);
		snake.setup(MapX, MapY);
		apple = new Apple[nApple];
		for(int i=0;i<nApple;i++)
			apple[i].setup(MapX, MapY,1);
		this->nApple = nApple;
		map.fill(S_Void);

		for (int i = 0;i < MapY;i++) {
			if (i == 0 || i + 1 == MapX)
				for (int j = 0;j < MapX;j++) map.setMap(j, i, S_Wall);
			else { 
				map.setMap(0, i, S_Wall);
				map.setMap(MapX - 1, i, S_Wall);
			}
		}
	}

	int len() {
		return snake.getSize();
	}

	void action(Snake::Keys dir) {
		if (snake.isAlive()) {
			snake.move(dir);
			snake.coliderTail();
			for(int i=0;i<nApple;i++)
				apple[i].isEat(snake, map);
			int sx = snake.getPosition(0).first;
			int sy = snake.getPosition(0).second;
			if (map.getMap(sx, sy) == S_Wall) snake.madeDeath();
		}
	}

	void write() {
		map.fill(S_Void);

		for (int i = 0;i < MapY;i++) {
			if (i == 0 || i + 1 == MapX)
				for (int j = 0;j < MapX;j++) map.setMap(j, i, S_Wall);
			else {
				map.setMap(0, i, S_Wall);
				map.setMap(MapX - 1, i, S_Wall);
			}
		}

		for (int i = 0;i < snake.getSize();i++)
			map.setMap(snake.getPosition(i).first, snake.getPosition(i).second, S_Snake);

		for (int i = 0;i < nApple;i++)
			map.setMap(apple[i].x, apple[i].y, S_Apple);
	}

	char* executeMap() {
		return map.executeMap();
	}

	bool isAlive() {
		return snake.isAlive();
	}

	~Game()
	{
		delete[] apple;
	}

};

