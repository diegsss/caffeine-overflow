/*
 * Fahad alqahtani
 * -steps to dbug
 *  1 reprduce the bug
 *  2 locate the bad code
 *  3 fix the code
 *  4 test the fix
 *	
 *
 * */
#include "iostream"
#include <GL/glx.h>
#include "fonts.h"
#include "fahadA.h"
#include "Global.h"
#include "Map.h"

static Global &gl = Global::getInstance();
char map[10] = "map.txt";

void fahadA(int x, int y, GLuint id)
{
	Rect r;
	float wid = 120.0f;

	// Displays my name
	r.bot = y;
	r.left = x + 90;
	r.center = 0;
	ggprint16(&r, 16, 0x00ffff00, "Fahad Alqahtani");
	// Displays my picture
	glColor3ub(255, 255, 255);
	glPushMatrix();
	glTranslatef((float)x, (float)y, 0);
	glBindTexture(GL_TEXTURE_2D, id);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f); glVertex2i(-wid/2, -wid/2);
	glTexCoord2f(0.0f, 0.0f); glVertex2i(-wid/2,  wid/2);
	glTexCoord2f(1.0f, 0.0f); glVertex2i( wid/2,  wid/2);
	glTexCoord2f(1.0f, 1.0f); glVertex2i( wid/2, -wid/2);
	glEnd();
	glPopMatrix();
}




void physics()
{
	
	if (gl.keys[XK_w]) {
            gl.sprite.pos.y=gl.sprite.pos.y+3; 
        }
	if (gl.keys[XK_s]) {
            gl.sprite.pos.y=gl.sprite.pos.y-3;
        }
        if (gl.keys[XK_a]) {
            gl.sprite.pos.x=gl.sprite.pos.x-3;
        }
        if (gl.keys[XK_d]) {
            gl.sprite.pos.x=gl.sprite.pos.x+3;
        }


}
/*
bool isWalkable(int x, int y) {
    if(x < 0 || y < 0 || x > 101 || y > 101)
        return false;
    int ret = gl.map.arr[rows][ncols];
//#ifdef DEBUG
    if(ret == 15)
    return false;
//#else
//#endif
    return ret;
}

//#endif 
*/

