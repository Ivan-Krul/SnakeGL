#pragma once
#include <math.h>
#include <corecrt_math_defines.h>

namespace mathSupport {
	struct vec2 {
		double X = 0;
		double Y = 0;

		vec2() {}
		vec2(double val) { X = val; Y = val; }
		vec2(double x, double y) { X = x;Y = y; }

		vec2 operator+ (const vec2& one) { return vec2(X + one.X, Y + one.Y); }
		vec2 operator- (const vec2& one) { return vec2(X - one.X, Y - one.Y); }
		vec2 operator* (const vec2& one) { return vec2(X * one.X, Y * one.Y); }
		vec2 operator/ (const vec2& one) { return vec2(X / one.X, Y / one.Y); }
		vec2 operator+ (double one) { return vec2(X + one, Y + one); }
		vec2 operator- (double one) { return vec2(X - one, Y - one); }
		vec2 operator* (double one) { return vec2(X * one, Y * one); }
		vec2 operator/ (double one) { return vec2(X / one, Y / one); }
		vec2 operator- () { return vec2(-X, -Y); }
	};

	struct vec3 {
		double X = 0;
		double Y = 0;
		double Z = 0;

		vec3() {}
		vec3(double x, double y, double z) { X = x;Y = y;Z = z; }
		vec3 operator+(vec3 const& one) { return vec3(X + one.X, Y + one.Y, Z + one.Z); }
		vec3 operator-(vec3 const& one) { return vec3(X - one.X, Y - one.Y, Z - one.Z); }
		vec3 operator*(vec3 const& one) { return vec3(X * one.X, Y * one.Y, Z * one.Z); }
		vec3 operator/(vec3 const& one) { return vec3(X / one.X, Y / one.Y, Z / one.Z); }
		vec3 operator+ (double one) { return vec3(X + one, Y + one, Z + one); }
		vec3 operator- (double one) { return vec3(X - one, Y - one, Z - one); }
		vec3 operator* (double one) { return vec3(X * one, Y * one, Z * one); }
		vec3 operator/ (double one) { return vec3(X / one, Y / one, Z / one); }
		vec3 operator-() { return vec3(-X, -Y, -Z); }
	};

	inline double piphagor(double x1, double y1, double x2, double y2) {
		return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	}
}
