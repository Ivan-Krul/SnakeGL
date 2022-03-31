#pragma once
#include <gl/GL.h>
#include "mathSupport.h"
#pragma comment(lib, "opengl32.lib")

namespace glSupport {

	void glDotd(GLdouble x, GLdouble y, GLdouble r, GLdouble g, GLdouble b) {
		glColor3d(r, g, b);
		glVertex2d(x, y);
	}

	void glRectangled(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2, GLdouble r, GLdouble g, GLdouble b) {
		glBegin(GL_TRIANGLE_STRIP);
		glDotd(x1, y1, r, g, b);
		glDotd(x1, y2, r, g, b);
		glDotd(x2, y1, r, g, b);
		glDotd(x2, y2, r, g, b);
		glEnd();
	}

	void glDotd(GLdouble x, GLdouble y, mathSupport::vec3 rgb) {
		glColor3d(rgb.X, rgb.Y, rgb.Z);
		glVertex2d(x, y);
	}

	void glRectangled(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2, mathSupport::vec3 rgb) {
		glBegin(GL_TRIANGLE_STRIP);
		glDotd(x1, y1, rgb);
		glDotd(x1, y2, rgb);
		glDotd(x2, y1, rgb);
		glDotd(x2, y2, rgb);
		glEnd();
	}

	void glDotd(mathSupport::vec2 xy, GLdouble r, GLdouble g, GLdouble b) {
		glColor3d(r, g, b);
		glVertex2d(xy.X, xy.Y);
	}

	void glRectangled(mathSupport::vec2 xy1, mathSupport::vec2 xy2, GLdouble r, GLdouble g, GLdouble b) {
		glBegin(GL_TRIANGLE_STRIP);
		glDotd(xy1.X, xy1.Y, r, g, b);
		glDotd(xy1.X, xy2.Y, r, g, b);
		glDotd(xy2.X, xy1.Y, r, g, b);
		glDotd(xy2.X, xy2.Y, r, g, b);
		glEnd();
	}

	void glDotd(mathSupport::vec2 xy, mathSupport::vec3 rgb) {
		glColor3d(rgb.X, rgb.Y, rgb.Z);
		glVertex2d(xy.X, xy.Y);
	}

	void glRectangled(mathSupport::vec2 xy1, mathSupport::vec2 xy2, mathSupport::vec3 rgb) {
		glBegin(GL_TRIANGLE_STRIP);
		glDotd(xy1.X, xy1.Y, rgb.X, rgb.Y, rgb.Z);
		glDotd(xy1.X, xy2.Y, rgb.X, rgb.Y, rgb.Z);
		glDotd(xy2.X, xy1.Y, rgb.X, rgb.Y, rgb.Z);
		glDotd(xy2.X, xy2.Y, rgb.X, rgb.Y, rgb.Z);
		glEnd();
	}

	void glCircled(GLdouble x, GLdouble y, GLuint nPoly, GLdouble radius, GLdouble r, GLdouble g, GLdouble b) {
		glBegin(GL_TRIANGLE_FAN);
		glDotd(x,y, r, g, b);
		double a = M_PI * 2.0 / nPoly;
		for (int i = 0;i <= nPoly;i++) {
			double rx = sin(a * i) * radius + x;
			double ry = cos(a * i) * radius + y;
			glDotd(rx, ry, r, g, b);
		}
		glEnd();
	}
	void glCircled(mathSupport::vec2 xy, GLuint nPoly, GLdouble radius, GLdouble r, GLdouble g, GLdouble b) {
		glBegin(GL_TRIANGLE_FAN);
		glDotd(xy, r, g, b);
		double a = M_PI * 2.0 / nPoly;
		for (int i = 0;i <= nPoly;i++) {
			double rx = sin(a * i) * radius + xy.X;
			double ry = cos(a * i) * radius + xy.Y;
			glDotd(rx, ry, r, g, b);
		}
		glEnd();
	}
	void glCircled(GLdouble x, GLdouble y, GLuint nPoly, GLdouble radius, mathSupport::vec3 rgb) {
		glBegin(GL_TRIANGLE_FAN);
		glDotd(x, y, rgb);
		double a = M_PI * 2.0 / nPoly;
		for (int i = 0;i <= nPoly;i++) {
			double rx = sin(a * i) * radius + x;
			double ry = cos(a * i) * radius + y;
			glDotd(rx, ry, rgb);
		}
		glEnd();
	}
	void glCircled(mathSupport::vec2 xy, GLuint nPoly, GLdouble radius, mathSupport::vec3 rgb) {
		glBegin(GL_TRIANGLE_FAN);
		glDotd(xy, rgb);
		double a = M_PI * 2.0 / nPoly;
		for (int i = 0;i <= nPoly;i++) {
			double rx = sin(a * i) * radius + xy.X;
			double ry = cos(a * i) * radius + xy.Y;
			glDotd(rx, ry, rgb);
		}
		glEnd();
	}

	void glCirclebd(GLdouble x, GLdouble y, GLuint nPoly, GLdouble radius, GLdouble bias, GLdouble r, GLdouble g, GLdouble b) {
		glBegin(GL_TRIANGLE_FAN);
		glDotd(x + bias, y + bias, r, g, b);
		double a = M_PI * 2.0 / nPoly;
		for (int i = 0;i <= nPoly;i++) {
			double rx = sin(a * i) * radius + x + bias;
			double ry = cos(a * i) * radius + y + bias;
			glDotd(rx, ry, r, g, b);
		}
		glEnd();
	}
	void glCirclebd(mathSupport::vec2 xy, GLuint nPoly, GLdouble radius, GLdouble bias, GLdouble r, GLdouble g, GLdouble b) {
		glBegin(GL_TRIANGLE_FAN);
		xy = xy + bias;
		glDotd(xy, r, g, b);
		double a = M_PI * 2.0 / nPoly;
		for (int i = 0;i <= nPoly;i++) {
			double rx = sin(a * i) * radius + xy.X + bias;
			double ry = cos(a * i) * radius + xy.Y + bias;
			glDotd(rx, ry, r, g, b);
		}
		glEnd();
	}
	void glCirclebd(GLdouble x, GLdouble y, GLuint nPoly, GLdouble radius, GLdouble bias, mathSupport::vec3 rgb) {
		glBegin(GL_TRIANGLE_FAN);
		glDotd(x + bias, y + bias, rgb);
		double a = M_PI * 2.0 / nPoly;
		for (int i = 0;i <= nPoly;i++) {
			double rx = sin(a * i) * radius + x + bias;
			double ry = cos(a * i) * radius + y + bias;
			glDotd(rx, ry, rgb);
		}
		glEnd();
	}
	void glCirclebd(mathSupport::vec2 xy, GLuint nPoly, GLdouble radius, GLdouble bias, mathSupport::vec3 rgb) {
		glBegin(GL_TRIANGLE_FAN);
		xy = xy+ bias;
		glDotd(xy, rgb);
		double a = M_PI * 2.0 / nPoly;
		for (int i = 0;i <= nPoly;i++) {
			double rx = sin(a * i) * radius + xy.X;
			double ry = cos(a * i) * radius + xy.Y;
			glDotd(rx, ry, rgb);
		}
		glEnd();
	}
}
