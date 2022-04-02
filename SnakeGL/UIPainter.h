#pragma once
#include "mathSupport.h"
#include "defines.h"
#include "glSupport.h"
#include "Game.h"

#pragma comment(lib, "winmm.lib")

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
		ColorSnakeSecond = mathSupport::vec3(143,89,9);
		ColorSnakeSecond = ColorSnakeSecond / 256.0;

		//Apple #de1f4c
		ColorApple = mathSupport::vec3(222,31,76);
		ColorApple = ColorApple / 256.0;

		//Wall #121375
		ColorWall = mathSupport::vec3(18, 19, 117);
		ColorWall = ColorWall / 256.0;

		game.setup(1);
	}

	void logic() {
		bool is_pushed = false;
		if ((GetAsyncKeyState('W') || GetAsyncKeyState(VK_UP)) && !is_pushed) { game.action(Snake::N); is_pushed = true; }
		if ((GetAsyncKeyState('D') || GetAsyncKeyState(VK_RIGHT)) && !is_pushed) { game.action(Snake::E); is_pushed = true; }
		if ((GetAsyncKeyState('S') || GetAsyncKeyState(VK_DOWN)) && !is_pushed) { game.action(Snake::S); is_pushed = true; }
		if ((GetAsyncKeyState('A') || GetAsyncKeyState(VK_LEFT)) && !is_pushed) { game.action(Snake::W); is_pushed = true; }
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
		if (!game.isAlive()) {
			glSupport::glRectangled(0, 0, PixelX, PixelY, 1, 1, 1);
			
			double X = PixelX * 1;
			double Y = PixelY * (MapY - 1);
			double thick = 10;
			mathSupport::vec3 rgb(0,0,0);
			rgb = rgb / 256.0;

			glSupport::glLined(PixelX, PixelY,PixelX, PixelY*2.0, thick, rgb);
			glSupport::glLined(PixelX, PixelY*2.0, PixelX*1.5, PixelY * 2.0, thick, rgb);
			glSupport::glLined(PixelX * 1.5, PixelY * 2.0, PixelX * 1.5, PixelY * 1.5, thick, rgb);
			glSupport::glLined(PixelX, PixelY*1.5, PixelX * 1.5, PixelY * 1.5, thick, rgb);

			glSupport::glLined(PixelX*2, PixelY, PixelX * 2, PixelY * 1.5, thick, rgb);
			glSupport::glLined(PixelX * 2, PixelY * 1.5, PixelX * 2.5, PixelY * 1.5, thick, rgb);

			glSupport::glLined(PixelX * 3.0, PixelY, PixelX * 3.0, PixelY * 2.0, thick, rgb);
			glSupport::glLined(PixelX * 3.0, PixelY*2.0, PixelX * 3.5, PixelY * 2.0, thick, rgb);
			glSupport::glLined(PixelX * 3.0, PixelY * 1.5, PixelX * 3.5, PixelY * 1.5, thick, rgb);
			glSupport::glLined(PixelX * 3.0, PixelY, PixelX * 3.5, PixelY, thick, rgb);

			glSupport::glLined(PixelX * 4.0, PixelY, PixelX * 4.5, PixelY, thick, rgb);
			glSupport::glLined(PixelX * 4.5, PixelY, PixelX * 4.5, PixelY*1.5, thick, rgb);
			glSupport::glLined(PixelX * 4.5, PixelY * 1.5, PixelX * 4.0, PixelY * 1.5, thick, rgb);
			glSupport::glLined(PixelX * 4.0, PixelY * 1.5, PixelX * 4.0, PixelY * 2.0, thick, rgb);
			glSupport::glLined(PixelX * 4.5, PixelY * 2.0, PixelX * 4.0, PixelY * 2.0, thick, rgb);

			glSupport::glLined(PixelX * 5.0, PixelY, PixelX * 5.5, PixelY, thick, rgb);
			glSupport::glLined(PixelX * 5.5, PixelY, PixelX * 5.5, PixelY * 1.5, thick, rgb);
			glSupport::glLined(PixelX * 5.5, PixelY * 1.5, PixelX * 5.0, PixelY * 1.5, thick, rgb);
			glSupport::glLined(PixelX * 5.0, PixelY * 1.5, PixelX * 5.0, PixelY * 2.0, thick, rgb);
			glSupport::glLined(PixelX * 5.5, PixelY * 2.0, PixelX * 5.0, PixelY * 2.0, thick, rgb);

			glSupport::glLined(PixelX * 7.0, PixelY, PixelX * 7.0, PixelY * 2.0, thick, rgb);
			glSupport::glLined(PixelX * 7.0, PixelY * 2.0, PixelX * 7.5, PixelY * 2.0, thick, rgb);
			//glSupport::glLined(PixelX * 7.5, PixelY * 2.0, PixelX * 7.5, PixelY * 1.5, thick, rgb);
			glSupport::glLined(PixelX * 7.0, PixelY * 1.5, PixelX * 7.5, PixelY * 1.5, thick, rgb);

			glSupport::glLined(PixelX * 8.5, PixelY, PixelX * 8.5, PixelY * 2.0, thick, rgb);
			glSupport::glLined(PixelX * 8.0, PixelY * 1.5, PixelX * 8.5, PixelY * 1.5, thick, rgb);
			glSupport::glLined(PixelX * 8.0, PixelY * 1.5, PixelX * 8.0, PixelY * 2.0, thick, rgb);
		}
	}

	mathSupport::vec3 madeColorInterpolate(double num) {
		mathSupport::vec3 s;
		s = ((ColorSnakeFirst - ColorSnakeSecond) *num+ ColorSnakeSecond);
		return s;
	}

	bool is_work() {
		return game.isAlive();
	}
	int len() {
		return game.len();
	}
};

