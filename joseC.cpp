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
void drawEnemy1Sprite(int cx, int cy, GLuint textid) 
{
	
	glBindTexture(GL_TEXTURE_2D, textid);
	glColor3ub(0,0,0);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f); glVertex2i(0,0);
		glTexCoord2f(0.0f, 0.0f); glVertex2i(0,20);
		glTexCoord2f(1.0f, 0.0f); glVertex2i(20,20);
		glTexCoord2f(1.0f, 1.0f); glVertex2i(20,0);
	glEnd();
	float h = 30.0;
	float w = h * .5;
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, textid);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.0f);
	glColor4ub(255, 255, 255, 255);
	int ix = gl.walkFrame % 8;
	int iy = 0;
	if (gl.walkFrame >= 8) 
		iy = 1;
	float fx = (float)ix / 8.0;
	float fy = (float)iy / 2.0;
	glBegin(GL_QUADS);
		glTexCoord2f(fx+.9999, fy + 1.0); glVertex2i(cx-w, cy-h);
		glTexCoord2f(fx+.9999, fy); glVertex2i(cx-w, cy+h);
		glTexCoord2f(fx, fy); glVertex2i(cx+w, cy+h);
		glTexCoord2f(fx, fy + 1.0); glVertex2i(cx+w, cy-h);
	glEnd();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_ALPHA_TEST);
}
void drawEnemy2Sprite(int cx, int cy, GLuint textid) 
{

	glBindTexture(GL_TEXTURE_2D, textid);
	glColor3ub(0,0,0);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f); glVertex2i(0,0);
		glTexCoord2f(0.0f, 0.0f); glVertex2i(0,20);
		glTexCoord2f(1.0f, 0.0f); glVertex2i(20,20);
		glTexCoord2f(1.0f, 1.0f); glVertex2i(20,0);
	glEnd();
	float h = 30.0;
	float w = h * .5;
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, textid);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.0f);
	glColor4ub(255, 255, 255, 255);
	int ix = gl.walkFrame % 8;
	int iy = 0;
	if (gl.walkFrame >= 8) 
		iy = 1;
	float fx = (float)ix / 8.0;
	float fy = (float)iy / 2.0;
	glBegin(GL_QUADS);
		glTexCoord2f(fx+.9999, fy + 1.0); glVertex2i(cx-w, cy-h);
		glTexCoord2f(fx+.9999, fy); glVertex2i(cx-w, cy+h);
		glTexCoord2f(fx, fy); glVertex2i(cx+w, cy+h);
		glTexCoord2f(fx, fy + 1.0); glVertex2i(cx+w, cy-h);
	glEnd();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_ALPHA_TEST);


}
void drawEnemy3Sprite(int cx, int cy, GLuint textid) 
{

	glBindTexture(GL_TEXTURE_2D, textid);
	glColor3ub(0,0,0);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f); glVertex2i(0,0);
		glTexCoord2f(0.0f, 0.0f); glVertex2i(0,20);
		glTexCoord2f(1.0f, 0.0f); glVertex2i(20,20);
		glTexCoord2f(1.0f, 1.0f); glVertex2i(20,0);
	glEnd();
	float h = 30.0;
	float w = h * .5;
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, textid);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.0f);
	glColor4ub(255, 255, 255, 255);
	int ix = gl.walkFrame % 8;
	int iy = 0;
	if (gl.walkFrame >= 8) 
		iy = 1;
	float fx = (float)ix / 8.0;
	float fy = (float)iy / 2.0;
	glBegin(GL_QUADS);
		glTexCoord2f(fx+.9999, fy + 1.0); glVertex2i(cx-w, cy-h);
		glTexCoord2f(fx+.9999, fy); glVertex2i(cx-w, cy+h);
		glTexCoord2f(fx, fy); glVertex2i(cx+w, cy+h);
		glTexCoord2f(fx, fy + 1.0); glVertex2i(cx+w, cy-h);
	glEnd();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_ALPHA_TEST);

}
void drawEnemy4Sprite(int cx, int cy, GLuint textid) 
{

	glBindTexture(GL_TEXTURE_2D, textid);
	glColor3ub(0,0,0);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f); glVertex2i(0,0);
		glTexCoord2f(0.0f, 0.0f); glVertex2i(0,20);
		glTexCoord2f(1.0f, 0.0f); glVertex2i(20,20);
		glTexCoord2f(1.0f, 1.0f); glVertex2i(20,0);
	glEnd();
	float h = 30.0;
	float w = h * .5;
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, textid);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.0f);
	glColor4ub(255, 255, 255, 255);
	int ix = gl.walkFrame % 8;
	int iy = 0;
	if (gl.walkFrame >= 8) 
		iy = 1;
	float fx = (float)ix / 8.0;
	float fy = (float)iy / 2.0;
	glBegin(GL_QUADS);
		glTexCoord2f(fx+.9999, fy + 1.0); glVertex2i(cx-w, cy-h);
		glTexCoord2f(fx+.9999, fy); glVertex2i(cx-w, cy+h);
		glTexCoord2f(fx, fy); glVertex2i(cx+w, cy+h);
		glTexCoord2f(fx, fy + 1.0); glVertex2i(cx+w, cy-h);
	glEnd();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_ALPHA_TEST);
}
void drawEnemy5Sprite(int cx, int cy, GLuint textid) 
{
	

	glBindTexture(GL_TEXTURE_2D, textid);
	glColor3ub(0,0,0);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f); glVertex2i(0,0);
		glTexCoord2f(0.0f, 0.0f); glVertex2i(0,20);
		glTexCoord2f(1.0f, 0.0f); glVertex2i(20,20);
		glTexCoord2f(1.0f, 1.0f); glVertex2i(20,0);
	glEnd();
	float h = 30.0;
	float w = h * .5;
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glBindTexture(GL_TEXTURE_2D, textid);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.0f);
	glColor4ub(255, 255, 255, 255);
	int ix = gl.walkFrame % 8;
	int iy = 0;
	if (gl.walkFrame >= 8) 
		iy = 1;
	float fx = (float)ix / 8.0;
	float fy = (float)iy / 2.0;
	glBegin(GL_QUADS);
		glTexCoord2f(fx+.9999, fy + 1.0); glVertex2i(cx-w, cy-h);
		glTexCoord2f(fx+.9999, fy); glVertex2i(cx-w, cy+h);
		glTexCoord2f(fx, fy); glVertex2i(cx+w, cy+h);
		glTexCoord2f(fx, fy + 1.0); glVertex2i(cx+w, cy-h);
	glEnd();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_ALPHA_TEST);

}
