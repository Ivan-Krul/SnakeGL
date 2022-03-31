#pragma once
#include "mathSupport.h"
#include "defines.h"
#include "soundSupport.h"

class UIPainter {
	mathSupport::vec3 ColorSnakeFirst;
	mathSupport::vec3 ColorSnakeSecond;
	mathSupport::vec3 ColorApple;

	UIPainter() {
		//Snake first#e8cb0e
		ColorSnakeFirst = mathSupport::vec3(232, 203, 14);
		ColorSnakeFirst = ColorSnakeFirst / 256.0;

		//Snake second #6b390b
		ColorSnakeSecond = mathSupport::vec3(107,57,11);
		ColorSnakeSecond = ColorSnakeSecond / 256.0;

		//Apple #de1f4c
		ColorApple = mathSupport::vec3(222,31,76);
		ColorApple = ColorApple / 256.0;
	}

	mathSupport::vec3 madeColorInterpolate(double num) {
		mathSupport::vec3 s;
		s = ((ColorSnakeFirst - ColorSnakeSecond) + ColorSnakeSecond)*num;
		return s;
	}
};

