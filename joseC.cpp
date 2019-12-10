// Jose Chavez
// 4 steps of debugging
// - reproduce the bug
// - Locate the bad code
// - Fix the code
// - Test the fix
//
#include "joseC.h"
#include <math.h>
#include <GL/glx.h>
#include <X11/Xlib.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "string.h"
#include "log.h"
#include "fonts.h"
#include "Map.h"
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

/*
void EnemyMove(int sx, int sy, int ex, int ey, GLuint textid) {
	float playerx = cx;
	float playery = cy;
	float enemyx = ex;
	float enemyy = ey;

	glpushMatrix();

	glTranslatef(enemyx, enemyy, 0.0);
	glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
			glVertex2f(-40, 40);
			glVertex2f(-40, -40);
			glVertex2f(40, -40);
			glVertex2f(40, 40);
		glEnd();

	glPopMatrix();


	float xDistance = abs(playerX-enemyX);
	float yDistance = abs(playerY-enemyY);

	if((playerX - enemyX) * (playerX - enemyX) + 
	   (playerY - enemyY) * (playerY - enemyY) < 400 * 400)	{
		float heading = asin(xDistance/yDistance);

		if(playerY > enemyY) {
			YPos += timeFactor * (200 * ( sin (( 90 + heading) *
			( PI / 180.0f))))
		} else {
			Ypos += -( timeFactor * 200 * (sin (( 90 + heading) *
			(PI / 180.0f))))
		}

		if(playerX > enemyX) {
			XPos += -(timeFactor * timeFactor * (10000 * (cos(
			(90 + heading) * (PI / 180.0f)))));
		} else {
			XPos += timeFactor * timeFactor * (10000 * (cos(
			(90 + heading) * (PI / 180.0f))));
		}
	}
}

*/

void enemyMove(int sx, int sy) {
	if((sx != gl.enemy1.pos.x) || (sy != gl.enemy1.pos.y)) {
		if (sx > gl.enemy1.pos.x) 
			gl.enemy1.pos.x += 2;
		if (sx < gl.enemy1.pos.x)
			gl.enemy1.pos.x -= 2;
		else
			gl.enemy1.pos.x += 0;

		if (sy > gl.enemy1.pos.y)
			gl.enemy1.pos.y += 2;
		if (sy < gl.enemy1.pos.y)
			gl.enemy1.pos.y -= 2;
		else
			gl.enemy1.pos.x += 0;
	}

	if((sx != gl.enemy2.pos.x) || (sy != gl.enemy2.pos.y)) {
		if (sx > gl.enemy2.pos.x) 
			gl.enemy2.pos.x += 3;
		if (sx < gl.enemy2.pos.x)
			gl.enemy2.pos.x -= 6;
		else
			gl.enemy2.pos.x += 0;

		if (sy > gl.enemy2.pos.y)
			gl.enemy2.pos.y += 5;
		if (sy < gl.enemy2.pos.y)
			gl.enemy2.pos.y -= 6;
		else
			gl.enemy2.pos.x += 0;
	}

	if((sx != gl.enemy3.pos.x) || (sy != gl.enemy3.pos.y)) {
		if (sx > gl.enemy3.pos.x) 
			gl.enemy3.pos.x += 7;
		if (sx < gl.enemy3.pos.x)
			gl.enemy3.pos.x -= 9;
		else
			gl.enemy3.pos.x += 0;

		if (sy > gl.enemy3.pos.y)
			gl.enemy3.pos.y += 6;
		if (sy < gl.enemy3.pos.y)
			gl.enemy3.pos.y -= 9;
		else
			gl.enemy3.pos.x += 0;
	}

	if((sx != gl.enemy4.pos.x) || (sy != gl.enemy4.pos.y)) {
		if (sx > gl.enemy4.pos.x) 
			gl.enemy4.pos.x += 2;
		if (sx < gl.enemy4.pos.x)
			gl.enemy4.pos.x -= 2;
		else
			gl.enemy4.pos.x += 0;

		if (sy > gl.enemy4.pos.y)
			gl.enemy4.pos.y += 2;
		if (sy < gl.enemy4.pos.y)
			gl.enemy4.pos.y -= 2;
		else
			gl.enemy4.pos.x += 0;
	}

	if((sx != gl.enemy5.pos.x) || (sy != gl.enemy5.pos.y)) {
		if (sx > gl.enemy5.pos.x) 
			gl.enemy5.pos.x += 2;
		if (sx < gl.enemy5.pos.x)
			gl.enemy5.pos.x -= 2;
		else
			gl.enemy5.pos.x += 0;

		if (sy > gl.enemy5.pos.y)
			gl.enemy5.pos.y += 2;
		if (sy < gl.enemy5.pos.y)
			gl.enemy5.pos.y -= 2;
		else
			gl.enemy5.pos.x += 0;
	}



}
/*
void HighScores_Background(GLenum target, GLuint texture, int xres, int yres)
{
        glBindTexture(target, texture);
        glBegin(GL_QUADS);
                glTexCoord2f(0.0f, 1.0f); glVertex2i(0, 0);
                glTexCoord2f(0.0f, 0.0f); glVertex2i(0, yres);
                glTexCoord2f(1.0f, 0.0f); glVertex2i(xres, yres);
                glTexCoord2f(1.0f, 1.0f); glVertex2i(xres, 0);

        glBindTexture(GL_TEXTURE_2D, 0);
        glClear(GL_COLOR_BUFFER_BIT);

}
	
void show_scores()
{
        HighScores_Background(GL_TEXTURE_2D, gl.highscoreTexture, gl.xres, gl.yres);
                glClear(GL_COLOR_BUFFER_BIT);
                Rect rhighscores;
                rhighscores.bot = gl.yres * 0.95f;
                rhighscores.left = gl.xres/2;
                rhighscores.center = 0;
                ggprint16(&rhighscores, 16, 0x00ffff00, "HighScores");
               // ggprint16(&rhighscores, 16, 0x00ffff00, "Diego\t-> 69");

}
*/





























