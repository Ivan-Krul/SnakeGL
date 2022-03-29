#pragma once
#include "mathSupport.h"

class UITuner {
public:
	mathSupport::vec3 s0;
	mathSupport::vec3 s1;

	UITuner() {
		s0.X = 232.0;
		s0.Y = 203.0;
		s0.Z = 14.0;
		s1.X = 107.0;
		s1.Y = 57.0;
		s1.Z = 11.0;
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

