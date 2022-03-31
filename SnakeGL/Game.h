#pragma once
#include "Map.h"
#include "Snake.h"
#include "Apple.h"
#include "defines.h"

class Game {
	Map map;
	Snake snake;
	Apple apple;

	Game() {
		map.setup(MapX,MapY);
		snake.setup(MapX, MapY);
		apple.setup(MapX, MapY);

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

	void Action(Snake::Keys dir) {
		if (snake.isAlive()) {
			snake.move(dir);
			apple.isEat(snake, map);
			int sx = snake.getPosition(0).first;
			int sy = snake.getPosition(0).second;
			if (map.getMap(sx, sy) == S_Wall) snake.madeDeath();
		}
	}

	void Write() {
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

		map.setMap(apple.x, apple.y, S_Apple);
	}

	char* executeMap() {
		return map.executeMap();
	}

};

