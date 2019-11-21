//Author: Rayan Alsabr

#include <GL/glx.h>
#include "fonts.h"
#include "rayanA.h"


void rayanA(int x, int y, GLuint textureId)
{
	float wid = 120.0f;
	glColor3ub(255, 255, 255);
	glPushMatrix();
	glTranslatef((float) x, (float) y, 0);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f);
		glVertex2i(-wid / 2, -wid / 2);
		glTexCoord2f(0.0f, 0.0f);
		glVertex2i(-wid / 2, wid / 2);
		glTexCoord2f(1.0f, 0.0f);
		glVertex2i(wid / 2, wid / 2);
		glTexCoord2f(1.0f, 1.0f);
		glVertex2i(wid / 2, -wid / 2);
	glEnd();
	glPopMatrix();
	Rect r;
	r.bot = y;
	r.left = x + 90;
	r.center = 0;
	ggprint16(&r, 16, 0x00ffffff, "Rayan Alsabr");
}
