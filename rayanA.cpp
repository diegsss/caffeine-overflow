//rayan alsabr
//lab

/*
   - Steps to dbug
   1 reprduce the bug
   2 locate the bad code
   3 fix the code
   4 test the fix
   */

#ifndef RAYANA_CPP
#define RAYANA_CPP
#include <GL/glx.h>
#include "fonts.h"
#include "rayanA.h"
#include "Global.h"
#include "Map.h"
//timer functions
//
#include <unistd.h>
#include <ctime>
#include <cmath>
#include <cstring>


static Global &gl = Global::getInstance();
bool moving;

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


static const int
FRONT = 0,
BACK = 1;

/*
   Enemy Enemy(int x,int y, int _dir){
   srand(time(nullptr));
   enemy1.pos.x = x;
   enemy1.pos.y = y; 
   enemy2.pos.x = x;
   enemy2.pos.y = y; 
   enemy3.pos.x = x;
   enemy3.pos.y = y; 
   enemy4.pos.x = x;
   enemy4.pos.y = y; 

   moving = 0;
   switch(_dir){
   case 0:
//image
dir[0] = 0;
dir[1] = 1;
break;
case 1:
//image
dir[0] = 0;
dir[1] = -1;
break;
default:
printf("error\n");
}
}
*/
//
/*
   Door Door(double x, double y)
   {
   gl.door.pos.x = x;
   gl.door.pos.y = y;
   return door;

   }*/

bool CheckPos(int x, int y)
{
	if ( x == gl.enemy1.pos.x && y == gl.enemy1.pos.y) {
		return 1;
	}
	return 0;
}
bool isMoving()
{
	return moving;
}
void drawDoor1Sprite(int cx, int cy, GLuint textid)
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
void drawDoor2Sprite(int cx, int cy, GLuint textid)
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


void drawDoor3Sprite(int cx, int cy, GLuint textid)
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


void Move()
{
	int tmpx = gl.sprite.pos.x;
	int tmpy = gl.sprite.pos.y;
	if (gl.enemy1.pos.x < 0){
		gl.enemy1.pos.x = 15;
	}
	else if(gl.enemy1.pos.x > (float)gl.xres){
		gl.enemy1.pos.x = (float)gl.xres - 15;
	}
	if (gl.enemy1.pos.y < 0){

		gl.enemy1.pos.y = 15;
	}
	else if(gl.enemy1.pos.y > (float)gl.yres){    
		gl.enemy1.pos.y = (float)gl.yres - 15;
	}      

	if (gl.enemy2.pos.x < 0){
		gl.enemy2.pos.x = 15;
	}
	else if(gl.enemy2.pos.x > (float)gl.xres){
		gl.enemy2.pos.x = (float)gl.xres - 15;
	}
	if (gl.enemy2.pos.y < 0){

		gl.enemy2.pos.y = 15;
	}
	else if(gl.enemy2.pos.y > (float)gl.yres){    
		gl.enemy2.pos.y = (float)gl.yres - 15;
	}      

	if (gl.enemy3.pos.x < 0){
		gl.enemy3.pos.x = 15;
	}
	else if(gl.enemy3.pos.x > (float)gl.xres){
		gl.enemy3.pos.x = (float)gl.xres - 15;
	}
	if (gl.enemy3.pos.y < 0){

		gl.enemy3.pos.y = 15;
	}
	else if(gl.enemy3.pos.y > (float)gl.yres){    
		gl.enemy3.pos.y = (float)gl.yres - 15;
	}      

	if (gl.enemy4.pos.x < 0){
		gl.enemy4.pos.x = 15;
	}
	else if(gl.enemy4.pos.x > (float)gl.xres){
		gl.enemy4.pos.x = (float)gl.xres - 15;
	}
	if (gl.enemy4.pos.y < 0){

		gl.enemy4.pos.y = 15;
	}
	else if(gl.enemy4.pos.y > (float)gl.yres){    
		gl.enemy4.pos.y = (float)gl.yres - 15;
	}      

	if (gl.enemy5.pos.x < 0){
		gl.enemy5.pos.x = 15;
	}
	else if(gl.enemy5.pos.x > (float)gl.xres){
		gl.enemy5.pos.x = (float)gl.xres - 15;
	}
	if (gl.enemy5.pos.y < 0){

		gl.enemy5.pos.y = 15;
	}
	else if(gl.enemy5.pos.y > (float)gl.yres){    
		gl.enemy5.pos.y = (float)gl.yres - 15;
	}      


	if(gl.enemy1.pos.x == tmpx && gl.enemy1.pos.y == tmpy){

		gl.sprite.health =0;
		moving = false;

	}
	else{
		if (gl.enemy1.pos.x < 200){
		gl.enemy1.pos.x = gl.enemy1.pos.x - 0.1;
		gl.enemy1.pos.y = gl.enemy1.pos.y - 0.1;
		}
		else
		{
		gl.enemy1.pos.x = gl.enemy1.pos.x - 0.1;
		gl.enemy1.pos.y = gl.enemy1.pos.y - 0.1;
		}
	}
	if(gl.enemy2.pos.x == tmpx && gl.enemy2.pos.y == tmpy){

		gl.sprite.health = 0;
		moving = false;

	}
	else{
		gl.enemy2.pos.x = gl.enemy2.pos.x - 0.1;
		gl.enemy2.pos.y = gl.enemy2.pos.y - 0.1;

	}
	if(gl.enemy3.pos.x == tmpx && gl.enemy3.pos.y == tmpy){

		gl.sprite.health = 0;
		moving = false;

	}
	else{
		if(gl.enemy3.pos.x < 0 ){
		gl.enemy3.pos.x = gl.enemy3.pos.x - 0.1;
		gl.enemy3.pos.y = gl.enemy3.pos.y + 0.1;
		}
		else
		{
		gl.enemy3.pos.x = gl.enemy3.pos.x + 0.1;
		gl.enemy3.pos.y = gl.enemy3.pos.y + 0.1;
		}

	}
	if(gl.enemy4.pos.x == tmpx && gl.enemy4.pos.y == tmpy){

		gl.sprite.health = 0;
		moving = false;

	}
	else{
		if(gl.enemy4.pos.x < 0|| gl.enemy4.pos.y < 0){
		gl.enemy4.pos.x = gl.enemy4.pos.x + 0.1;
		gl.enemy4.pos.y = gl.enemy4.pos.y + 0.1;
		}
		else
		{
		gl.enemy4.pos.x = gl.enemy4.pos.x + 0.1;
		gl.enemy4.pos.y = gl.enemy4.pos.y + 0.1;
		}
	if(gl.enemy5.pos.x == tmpx && gl.enemy5.pos.y == tmpy){

		gl.sprite.health = 0;
		moving = false;

	}
	else{
		if(gl.enemy5.pos.x > 0){
		gl.enemy5.pos.x = gl.enemy5.pos.x + 0.1;
		gl.enemy5.pos.y = gl.enemy5.pos.y + 0.1;
		}
		else{
		gl.enemy5.pos.x = gl.enemy5.pos.x - 0.1;
		gl.enemy5.pos.y = gl.enemy5.pos.y - 0.1;
		}
	}

}
}
void enemyHit()
{
	gl.sprite.health=0;
}
Sprite getSpritePosion(double xpos,double ypos, Sprite sprite)
{
        gl.sprite.pos.x = xpos;
        gl.sprite.pos.y = ypos;

        return sprite;

}

void doorEntered(int x, int y)
{

        int tmpx = x;
        int tmpy = y;
	if(tmpx == gl.door1.pos.x && tmpy == gl.door1.pos.y){
	printf("door1");
	gl.sprite.pos.x = 230;
	gl.sprite.pos.y = 230;
	}
	if(tmpx == gl.door2.pos.x && tmpy == gl.door2.pos.y){
	printf("door2");
	gl.sprite.pos.x = 850;
	gl.sprite.pos.y = 570;
	}
	if( tmpx == gl.door3.pos.x && tmpy == gl.door3.pos.y){
	
	printf("door3");
	gl.sprite.pos.x = 670;
	gl.sprite.pos.y = 450;
	}
}

//-----------------------------------------------------------------------------
//Setup timers
/*const double physicsRate = 1.0 / 60.0;
  const double oobillion = 1.0 / 1e9;
  struct timespec timeStart, timeCurrent;
  struct timespec timePause;
  double physicsCountdown=0.0;
  double timeSpan=0.0;
//unsigned int upause=0;
double timeDiff(struct timespec *start, struct timespec *end)
{
//return the difference in two times.
return (double)(end->tv_sec - start->tv_sec ) +
(double)(end->tv_nsec - start->tv_nsec) * oobillion;
}
void timeCopy(struct timespec *dest, struct timespec *source)
{
//copy one time structure to another.
memcpy(dest, source, sizeof(struct timespec));
}
//-----------------------------------------------------------------------------
*/




#endif
