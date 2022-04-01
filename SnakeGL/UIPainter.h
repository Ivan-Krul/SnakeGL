#pragma once
#include "mathSupport.h"
#include "defines.h"
#include "soundSupport.h"
#include "glSupport.h"
#include "Game.h"

class UIPainter {
	mathSupport::vec3 ColorSnakeFirst;
	mathSupport::vec3 ColorSnakeSecond;
	mathSupport::vec3 ColorApple;
	mathSupport::vec3 ColorWall;
	Game game;

public:
	void setup() {
		//Snake firs t#e8cb0e
		ColorSnakeFirst = mathSupport::vec3(232, 203, 14);
		ColorSnakeFirst = ColorSnakeFirst / 256.0;

		//Snake second #6b390b
		ColorSnakeSecond = mathSupport::vec3(107,57,11);
		ColorSnakeSecond = ColorSnakeSecond / 256.0;

		//Apple #de1f4c
		ColorApple = mathSupport::vec3(222,31,76);
		ColorApple = ColorApple / 256.0;

		//Wall #121375
		ColorWall = mathSupport::vec3(18, 19, 117);
		ColorWall = ColorWall / 256.0;

		game.setup();
	}

	void logic() {
		bool is_pushed = false;
		if (GetAsyncKeyState('W') && !is_pushed) { game.action(Snake::N); is_pushed = true; }
		if (GetAsyncKeyState('D') && !is_pushed) { game.action(Snake::E); is_pushed = true; }
		if (GetAsyncKeyState('S') && !is_pushed) { game.action(Snake::S); is_pushed = true; }
		if (GetAsyncKeyState('A') && !is_pushed) { game.action(Snake::W); is_pushed = true; }
		if (!is_pushed) game.action(Snake::Null);

		game.write();
	}

	void paint() {
		char* mp = game.executeMap();

		for (int i = 0;i < MapX;i++) {
			for (int j = 0;j < MapY;j++) {
				switch (mp[i + j * MapY]) {
				case S_Apple:
					glSupport::glCirclebd(PixelX*i, PixelY*j, 5, (PixelX + PixelY) / 4.0, (PixelX + PixelY) / 4.0, ColorApple);
					break;
				case S_Wall:
					glSupport::glRectangled(PixelX * i, PixelY * j, PixelX * (i + 1), PixelY * (j + 1), ColorWall);
				default:
					break;
				}

			}
		}
		for (int i = 0;i < game.snake.getSize();i++) {
			double x = game.snake.getPosition(i).first;
			double y = game.snake.getPosition(i).second;

			glSupport::glRectangled(PixelX * x, PixelY * y, PixelX * (x + 1), PixelY * (y + 1), madeColorInterpolate(double(game.snake.getSize() - i) / double(game.snake.getSize())));
		}
		if(!game.isAlive()) glSupport::glRectangled(0,0, PixelX, PixelY, 1,1,1);
	}

	mathSupport::vec3 madeColorInterpolate(double num) {
		mathSupport::vec3 s;
		s = ((ColorSnakeFirst - ColorSnakeSecond) + ColorSnakeSecond)*num;
		return s;
	}
};

