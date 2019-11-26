// Jose Chavez
// 4 steps of debugging
// - reproduce the bug
// - Locate the bad code
// - Fix the code
// - Test the fix
//
#include "joseC.h"
#include <GL/glx.h>
#include "fonts.h"
#include "Global.h"

static Global &gl = Global::getInstance();

void joseC(float x, float y, GLuint textid)
{

	//show name
	Rect name;
	name.left = x + 90;
	name.bot = y;
	name.center = 0;
	ggprint16(&name, 16, 0x00ffff00, "Jose Chavez");
	glColor3ub(225, 225, 225);
	float wid = 60.0f;
	glPushMatrix();
	glTranslatef(x, y, 0);
	glBindTexture(GL_TEXTURE_2D, textid);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f);
	glVertex2i(-wid, -wid);
	glTexCoord2f(0.0f, 0.0f);
	glVertex2i(-wid, wid);
	glTexCoord2f(1.0f, 0.0f);
	glVertex2i(wid, wid);
	glTexCoord2f(1.0f, 1.0f);
	glVertex2i(wid, -wid);
	glEnd();
	glPopMatrix();
}


