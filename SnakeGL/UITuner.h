#pragma once
#include "mathSupport.h"

class UITuner {
	mathSupport::vec3 s0;
	mathSupport::vec3 s1;

	mathSupport::vec3 a0;

	int sx;
	int sy;
	int resolX = 5;
	int resolY = 5;
public:
	UITuner(int x, int y);

	int getSizeX() { return sx; }
	int getSizeY() { return sy; }

	int getResolX() { return resolX; }
	int getResolY() { return resolY; }

	mathSupport::vec3 firstSnakeColor() { return s0; }
	mathSupport::vec3 secondSnakeColor() { return s1; }
	mathSupport::vec3 appleColor() { return a0; }

	mathSupport::vec2 madeSquish(int x, int y);

	mathSupport::vec3 madeColorInterpolate(double num);
};

