//Author Diego Chavez

#ifndef DIEGOC_H
#define DIEGOC_H

typedef struct t_button {
	Rect r;
	char text[32];
	int over;
	int down;
	int click;
	float color[3];
	float dcolor[3];
	unsigned int text_color;
} Button;

void Menu(GLenum target, GLuint texture, int xres, int yres);
void Guide(int xres, int yres);
extern int location;

#endif
