/*Author: Diego Chavez
 *
 * 4 Steps to debugging
 * 1. Reproduce the problem
 * 2. locate the bad code
 * 3. fix the bad code
 * 4. tes the fix
 *
 *
 *
 *
 * */
#include "math.h"
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
#include "diegoC.h"
#include "Map.h"
#include "Global.h"
#define MAXBUTTONS 5

static Global &gl = Global::getInstance();

char map1[10] = "map.txt";


int nbuttons = 0;
int location = 0;
Button button[MAXBUTTONS];

Map m1(map1);

void Camera();

void diegoC (int x, int y, GLuint textid)
{
	float wid = 120.0f;
	glColor3ub(255, 255, 255);
	glPushMatrix();
	glTranslatef((float) x, (float)y, 0);
	glBindTexture(GL_QUADS, textid);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f); glVertex2i(-wid/2, -wid/2);
		glTexCoord2f(0.0f, 0.0f); glVertex2i(-wid/2,  wid/2);
		glTexCoord2f(1.0f, 0.0f); glVertex2i( wid/2,  wid/2);
		glTexCoord2f(1.0f, 1.0f); glVertex2i( wid/2, -wid/2);
	glEnd();
	glPopMatrix();

	Rect r;
	r.bot = y;
	r.left = x + 90;
	r.center = 0;
	ggprint16(&r, 16, 0xffffffff, "Diego Chavez");

}
void Menu(GLenum target, GLuint texture, int xres, int yres)
{
	//show the background image
	glBindTexture(target, texture);
	glColor3ub(255, 255, 255);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f); glVertex2i(0, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex2i(0, yres); 
		glTexCoord2f(1.0f, 0.0f); glVertex2i(xres, yres);
		glTexCoord2f(1.0f, 1.0f); glVertex2i(xres, 0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
	Rect r;
	nbuttons=0;

	//size, position, & color
	button[nbuttons].r.width = 140;
	button[nbuttons].r.height = 60;
	button[nbuttons].r.left = 50;
	button[nbuttons].r.bot = 560;
	button[nbuttons].r.right =
		button[nbuttons].r.left + button[nbuttons].r.width;
	button[nbuttons].r.top = button[nbuttons].r.bot +
		button[nbuttons].r.height;
	button[nbuttons].r.centerx = (button[nbuttons].r.left +
		button[nbuttons].r.right) / 2;
	button[nbuttons].r.centery = (button[nbuttons].r.bot +
		button[nbuttons].r.top) / 2;
	strcpy(button[nbuttons].text, "Start");
	button[nbuttons].down = 0;
	button[nbuttons].click = 0;
	button[nbuttons].color[0] = 0.0f;
	button[nbuttons].color[1] = 0.8f;
	button[nbuttons].color[2] = 0.1f;
	button[nbuttons].dcolor[0] = button[nbuttons].color[0] * 0.5f;
	button[nbuttons].dcolor[1] = button[nbuttons].color[1] * 0.5f;
	button[nbuttons].dcolor[2] = button[nbuttons].color[2] * 0.5f;
	button[nbuttons].text_color = 0x00ffffff;
	nbuttons++;

	button[nbuttons].r.width = 140;
	button[nbuttons].r.height = 60;
	button[nbuttons].r.left = 50;
	button[nbuttons].r.bot = 440;
	button[nbuttons].r.right =
		button[nbuttons].r.left + button[nbuttons].r.width;
	button[nbuttons].r.top = button[nbuttons].r.bot +
		button[nbuttons].r.height;
	button[nbuttons].r.centerx = (button[nbuttons].r.left +
		button[nbuttons].r.right) / 2;
	button[nbuttons].r.centery = (button[nbuttons].r.bot +
		button[nbuttons].r.top) / 2;
	strcpy(button[nbuttons].text, "How to play");
	button[nbuttons].down = 0;
	button[nbuttons].click = 0;
	button[nbuttons].color[0] = 0.0f;
	button[nbuttons].color[1] = 0.8f;
	button[nbuttons].color[2] = 0.1f;
	button[nbuttons].dcolor[0] = button[nbuttons].color[0] * 0.5f;
	button[nbuttons].dcolor[1] = button[nbuttons].color[1] * 0.5f;
	button[nbuttons].dcolor[2] = button[nbuttons].color[2] * 0.5f;
	button[nbuttons].text_color = 0x00ffffff;
	nbuttons++;

	button[nbuttons].r.width = 140;
	button[nbuttons].r.height = 60;
	button[nbuttons].r.left = 50;
	button[nbuttons].r.bot = 320;
	button[nbuttons].r.right =
		button[nbuttons].r.left + button[nbuttons].r.width;
	button[nbuttons].r.top = button[nbuttons].r.bot +
		button[nbuttons].r.height;
	button[nbuttons].r.centerx = (button[nbuttons].r.left +
		button[nbuttons].r.right) / 2;
	button[nbuttons].r.centery = (button[nbuttons].r.bot +
		button[nbuttons].r.top) / 2;
	strcpy(button[nbuttons].text, "Scores");
	button[nbuttons].down = 0;
	button[nbuttons].click = 0;
	button[nbuttons].color[0] = 0.0f;
	button[nbuttons].color[1] = 0.8f;
	button[nbuttons].color[2] = 0.1f;
	button[nbuttons].dcolor[0] = button[nbuttons].color[0] * 0.5f;
	button[nbuttons].dcolor[1] = button[nbuttons].color[1] * 0.5f;
	button[nbuttons].dcolor[2] = button[nbuttons].color[2] * 0.5f;
	button[nbuttons].text_color = 0x00ffffff;
	nbuttons++;
	
	button[nbuttons].r.width = 140;
	button[nbuttons].r.height = 60;
	button[nbuttons].r.left = 50;
	button[nbuttons].r.bot = 200;
	button[nbuttons].r.right =
		button[nbuttons].r.left + button[nbuttons].r.width;
	button[nbuttons].r.top = button[nbuttons].r.bot +
		button[nbuttons].r.height;
	button[nbuttons].r.centerx = (button[nbuttons].r.left +
		button[nbuttons].r.right) / 2;
	button[nbuttons].r.centery = (button[nbuttons].r.bot +
		button[nbuttons].r.top) / 2;
	strcpy(button[nbuttons].text, "Credits");
	button[nbuttons].down = 0;
	button[nbuttons].click = 0;
	button[nbuttons].color[0] = 0.0f;
	button[nbuttons].color[1] = 0.8f;
	button[nbuttons].color[2] = 0.1f;
	button[nbuttons].dcolor[0] = button[nbuttons].color[0] * 0.5f;
	button[nbuttons].dcolor[1] = button[nbuttons].color[1] * 0.5f;
	button[nbuttons].dcolor[2] = button[nbuttons].color[2] * 0.5f;
	button[nbuttons].text_color = 0x00ffffff;
	nbuttons++;

	button[nbuttons].r.width = 140;
	button[nbuttons].r.height = 60;
	button[nbuttons].r.left = 50;
	button[nbuttons].r.bot = 80;
	button[nbuttons].r.right =
		button[nbuttons].r.left + button[nbuttons].r.width;
	button[nbuttons].r.top = button[nbuttons].r.bot +
		button[nbuttons].r.height;
	button[nbuttons].r.centerx = (button[nbuttons].r.left +
		button[nbuttons].r.right) / 2;
	button[nbuttons].r.centery = (button[nbuttons].r.bot +
		button[nbuttons].r.top) / 2;
	strcpy(button[nbuttons].text, "Quit");
	button[nbuttons].down = 0;
	button[nbuttons].click = 0;
	button[nbuttons].color[0] = 0.0f;
	button[nbuttons].color[1] = 0.8f;
	button[nbuttons].color[2] = 0.1f;
	button[nbuttons].dcolor[0] = button[nbuttons].color[0] * 0.5f;
	button[nbuttons].dcolor[1] = button[nbuttons].color[1] * 0.5f;
	button[nbuttons].dcolor[2] = button[nbuttons].color[2] * 0.5f;
	button[nbuttons].text_color = 0x00ffffff;
	nbuttons++;

	//draw the buttons
	for (int i=0; i< MAXBUTTONS; i++) {
		glColor3f(1.0f, 1.0f, 0.0f);
			
		if (location == i) {
			glColor3fv(button[i].dcolor);
		} 
		else {
			glColor3fv(button[i].color);
		}
		
		glBegin(GL_QUADS);
			glVertex2i(button[i].r.left,  button[i].r.bot);
			glVertex2i(button[i].r.left,  button[i].r.top);
			glVertex2i(button[i].r.right, button[i].r.top);
			glVertex2i(button[i].r.right, button[i].r.bot);
		glEnd();

		r.left = button[i].r.centerx;
		r.bot  = button[i].r.centery-8;
		r.center = 1;
		
		ggprint16(&r, 0, button[i].text_color, button[i].text);
	} 
     glEnd();	
}
void Guide(GLenum target, GLuint texture, int xres, int yres) 
{
	glBindTexture(target, texture);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f); glVertex2i(0, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex2i(0, yres); 
		glTexCoord2f(1.0f, 0.0f); glVertex2i(xres, yres);
		glTexCoord2f(1.0f, 1.0f); glVertex2i(xres, 0);
	
	glBindTexture(GL_TEXTURE_2D, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	Rect HowToPlay;
	HowToPlay.bot = yres * 0.95f;
	HowToPlay.left = xres/2;
	HowToPlay.center = 0;
	ggprint16(&HowToPlay, 0 ,0xffffffff, "Game Guide");
	HowToPlay.bot = yres * 0.85f;
	HowToPlay.left = xres/4;
	ggprint16(&HowToPlay, 0 ,0xffffffff, "Use wasd keys to move");
	HowToPlay.bot = yres * 0.75f;
	HowToPlay.left = xres/4;
	ggprint16(&HowToPlay, 0 ,0xffffffff, "You are trapped in a maze and have to escape!");
	HowToPlay.bot = yres * 0.65f;
	HowToPlay.left = xres/4;
	ggprint16(&HowToPlay, 0 ,0xffffffff, "Make it out the maze to win!");
	
	glEnd();
}
void Credits_Background(GLenum target, GLuint texture, int xres, int yres)
{
	glBindTexture(target, texture);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f); glVertex2i(0, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex2i(0, yres); 
		glTexCoord2f(1.0f, 0.0f); glVertex2i(xres, yres);
		glTexCoord2f(1.0f, 1.0f); glVertex2i(xres, 0);
	
	glBindTexture(GL_TEXTURE_2D, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	//glEnd();

}
void generateTexture(int glSize, GLuint &textID, Image img)
{
	glGenTextures(glSize, &textID);
	glBindTexture(GL_TEXTURE_2D, textID);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, img.width, img.height, 0, GL_RGB, GL_UNSIGNED_BYTE, img.data);
	glActiveTexture(GL_TEXTURE0);
}
void drawTile(int width, int length, GLuint id)
{
	double fx = (double) width;
	double fy = (double) length;

	int x = gl.map.tilesize[0];
	int y = gl.map.tilesize[1];

	glColor3ub(255, 255, 255);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, id);
	glTranslated(fx, fy, 0);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);glVertex2i(0,0);
		glTexCoord2f(0.0f, 1.0f);glVertex2i(0,-y);
		glTexCoord2f(1.0f, 1.0f);glVertex2i(x,-y);
		glTexCoord2f(1.0f, 0.0f);glVertex2i(x,0);
	glEnd();
	glPopMatrix();
}
Tile tilePosition(double width, double height, Tile tile)
{
	if(tile.identity != 0) {
		tile.pos.x = width;
		tile.pos.y = height;
	}
	return tile;
}
void drawMap()
{
	double width = 0;
	double height = 0;
	int renderCols = gl.xres / gl.map.tilesize[0] + 2;
	int colId = static_cast<int>((int) gl.camera[0] / gl.map.dbsz[0]);
	for (int cols = 0; cols < renderCols; cols++) {
		int rowId = gl.map.nrows -1;
		for (int rows = 0; rows < gl.map.nrows; rows++) {
			width = colId * gl.map.dbsz[0];
			height = rows * gl.map.dbsz[1];
			if (gl.map.arr[rowId][colId].identity == '1') {
				drawTile(width, height, gl.grassTile);
				gl.map.arr[rowId][colId] = tilePosition(width, height, gl.map.arr[rowId][colId]);
			}
			if (gl.map.arr[rowId][colId].identity == '2') {
				drawTile(width, height, gl.roadTile);
				gl.map.arr[rowId][colId] = tilePosition(width, height, gl.map.arr[rowId][colId]);
			}
			if (gl.map.arr[rowId][colId].identity == '3') {
				drawTile(width, height, gl.blockTile);
				gl.map.arr[rowId][colId] = tilePosition(width, height, gl.map.arr[rowId][colId]);
			}
			if (gl.map.arr[rowId][colId].identity == '4') {
				drawTile(width, height, gl.treeTile);
				gl.map.arr[rowId][colId] = tilePosition(width, height, gl.map.arr[rowId][colId]);
			}
			if (gl.map.arr[rowId][colId].identity == '5') {
				drawTile(width, height, gl.waterTile);
				gl.map.arr[rowId][colId] = tilePosition(width, height, gl.map.arr[rowId][colId]);
			}
			--rowId;
		}
		colId = (colId + 1) % gl.map.ncols;
	}
}
void Camera() 
{
    if (gl.keys[XK_Right]) {
        if (gl.sprite.pos.x < 10) {
            gl.sprite.pos.x = 10;
            gl.camera[0] = 0.0;
        }

        if (gl.sprite.pos.x > gl.xres / 2 + 100) {
            printf("left");

        }
        gl.camera[0] -= 1;


        if (gl.camera[0] < 0.0) {
            gl.camera[0] = 0.0;
        }
    }

    if (gl.keys[XK_Left]) {
        if (gl.sprite.pos.x < gl.xres / 2 - 100) {
            printf("right");

        }
        gl.camera[0] += 1;

        if (gl.camera[0] < 0.0) {
            gl.camera[0] = 0.0;
        }

        if (gl.sprite.pos.x > gl.xres) {
            gl.sprite.pos.x = gl.xres;
            gl.camera[0] = 0.0;
        }
    }

}
void drawSprite(int cx, int cy, GLuint textid) 
{
	
	glBindTexture(GL_TEXTURE_2D, textid);
	glColor3ub(0,0,0);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f); glVertex2i(0,0);
		glTexCoord2f(0.0f, 0.0f); glVertex2i(0,20);
		glTexCoord2f(1.0f, 0.0f); glVertex2i(20,20);
		glTexCoord2f(1.0f, 1.0f); glVertex2i(20,0);
		glTexCoord2f(0.0f, 1.0f); glVertex2i(0,0);
		glTexCoord2f(0.0f, 0.0f); glVertex2i(0,20);
		glTexCoord2f(1.0f, 0.0f); glVertex2i(20,20);
		glTexCoord2f(1.0f, 1.0f); glVertex2i(20,0);
	glEnd();
	//float h = 25.0;
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
		glTexCoord2f(fx, fy + 1.0);     glVertex2i(cx-w, cy-h);
		glTexCoord2f(fx, fy);          glVertex2i(cx-w, cy+h);
		glTexCoord2f(fx+.9999, fy);    glVertex2i(cx+w, cy+h);
		glTexCoord2f(fx+.9999, fy+1.0); glVertex2i(cx+w, cy-h);
	/*	glTexCoord2f(fx, fy + .5); glVertex2i(cx-w, cy-h);
		glTexCoord2f(fx, fy); glVertex2i(cx-w, cy+h);
		glTexCoord2f(fx+.125, fy); glVertex2i(cx+w, cy+h);
		glTexCoord2f(fx+.125, fy + .5); glVertex2i(cx+w, cy-h);*/
	glEnd();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_ALPHA_TEST);
}
void show_credits()
{
        Credits_Background(GL_TEXTURE_2D, gl.creditsTexture, gl.xres, gl.yres);
	extern void joseC(float, float, GLuint);
        extern void fahadA(int, int, GLuint);
        extern void rayanA(int, int, GLuint);
        extern void diegoC(int, int, GLuint);
                glClear(GL_COLOR_BUFFER_BIT);
                Rect rcredits;
                rcredits.bot = gl.yres * 0.95f;
                rcredits.left = gl.xres/2;
                rcredits.center = 0;
                ggprint16(&rcredits, 16, 0x00ffff00, "Credits");
                ggprint16(&rcredits, 16, 0x00ffff00, "Credits");

                // moves pictures so they scale to monitors resolution
                float offset = 0.18f;
                joseC((gl.xres/2 - 100), gl.yres * (1 - offset*2), gl.joseCTexture);
                fahadA((gl.xres/2 - 100), gl.yres * (1 - offset*3), gl.fahadATexture);
                rayanA((gl.xres/2 - 100), gl.yres * (1 - offset*4), gl.rayanATexture);
                diegoC((gl.xres/2 - 100), gl.yres * (1 - offset*5), gl.diegoCTexture);
        glEnd();
}
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
	
	extern void joseC(float, float, GLuint);
        extern void fahadA(int, int, GLuint);
        extern void rayanA(int, int, GLuint);
        extern void diegoC(int, int, GLuint);
        
	glClear(GL_COLOR_BUFFER_BIT);
                Rect rhighscores;
                rhighscores.bot = gl.yres * 0.95f;
                rhighscores.left = gl.xres/2;
                rhighscores.center = 0;
                ggprint16(&rhighscores, 16, 0x00ffff00, "HighScores");
                
                float offset = 0.18f;
		joseC((gl.xres/2 - 100), gl.yres * (1 - offset*2), gl.joseCTexture);
                fahadA((gl.xres/2 - 100), gl.yres * (1 - offset*3), gl.fahadATexture);
                rayanA((gl.xres/2 - 100), gl.yres * (1 - offset*4), gl.rayanATexture);
                diegoC((gl.xres/2 - 100), gl.yres * (1 - offset), gl.diegoCTexture);

}



































