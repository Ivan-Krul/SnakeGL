#pragma once
#include "mathSupport.h"

class UITuner {
public:
	mathSupport::vec3 s0;
	mathSupport::vec3 s1;
	int sx;
	int sy;
	int resolX = 5;
	int resolY = 5;

	UITuner(int x,int y) {
		sx = x;
		sy = y;
		s0.X = 232.0;
		s0.Y = 203.0;
		s0.Z = 14.0;
		s1.X = 107.0;
		s1.Y = 57.0;
		s1.Z = 11.0;
		while (sx % resolX != 0) {
			resolX--;
		}
		while (sy % resolY != 0) {
			resolY--;
		}
	}

	mathSupport::vec2 madeSquish(int x, int y) {
		x *= resolX;
		y *= resolY;
		if (x > sx) x = sx;
		if (y > sy) y = sy;

		mathSupport::vec2 s;
		s.X = double(x) - double(sx) / 2.0;
		s.Y = double(y) - double(sy) / 2.0;
		s.X = s.X * 2.0 / double(sx);
		s.Y = s.Y * 2.0 / double(sy);
		return s;
	}

	mathSupport::vec3 madeInterpolate(double num) {
		mathSupport::vec3 s;
		s.X = num * (s0.X - s1.X) + s1.X;
		s.Y = num * (s0.Y - s1.Y) + s1.Y;
		s.Z = num * (s0.Z - s1.Z) + s1.Z;
		s=s / 256.0;
		return s;
	}
};

