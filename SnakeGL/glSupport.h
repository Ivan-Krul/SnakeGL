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
}
