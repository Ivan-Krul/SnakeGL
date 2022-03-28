#pragma once
#include <gl/gl.h>
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
}
