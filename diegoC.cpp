//Author: Diego Chavez
//
#include <GL/glx.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "fonts.h"
#include "diegoC.h"
#define MAXBUTTONS 5

int nbuttons = 0;
int location = 0;
Button button[MAXBUTTONS];

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
}
void HowToPlay(int xres, int yres) 
{
	glClear(GL_COLOR_BUFFER_BIT);

	Rect HowToPlay;
	HowToPlay.bot = yres * 0.95f;
	HowToPlay.left = xres/2;
	HowToPlay.center = 0;
	ggprint16(&HowToPlay, 0 ,0xffffffff, "Game Guide");
	HowToPlay.bot = yres * 0.85f;
	HowToPlay.left = xres/4;
	ggprint16(&HowToPlay, 0 ,0xffffffff, "Use arrow keys to move");
	HowToPlay.bot = yres * 0.75f;
	HowToPlay.left = xres/4;
	ggprint16(&HowToPlay, 0 ,0xffffffff, "Battle enemies by getting their attention");
	HowToPlay.bot = yres * 0.65f;
	HowToPlay.left = xres/4;
	ggprint16(&HowToPlay, 0 ,0xffffffff, "Defeat all enemies to win");

}
