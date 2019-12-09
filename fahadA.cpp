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
const int Sprite::RADIUS = 5;



/*
class Game:public Enemy
{


	public:
		static Game *getInstance();
		static void RemoveInstance();
		Sprite getSpritePosion();





}

*/

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


void endgame(GLenum target, GLuint texture, int xres, int yres)
{
	if(gl.sprite.health == 0 && gl.sprite.lives == 0){
        glBindTexture(target, texture);
        glBegin(GL_QUADS);
                glTexCoord2f(0.0f, 1.0f); glVertex2i(0, 0);
                glTexCoord2f(0.0f, 0.0f); glVertex2i(0, yres);
                glTexCoord2f(1.0f, 0.0f); glVertex2i(xres, yres);
                glTexCoord2f(1.0f, 1.0f); glVertex2i(xres, 0);

        glBindTexture(GL_TEXTURE_2D, 0);
        glClear(GL_COLOR_BUFFER_BIT);

        Rect GameOver;
        GameOver.bot = yres * 0.95f;
        GameOver.left = xres/2;
        GameOver.center = 0;
        ggprint16(&GameOver, 0 ,0xffffffff, "Game Over");
        GameOver.bot = yres * 0.85f;
        GameOver.left = xres/4;
        ggprint16(&GameOver, 0 ,0xffffffff, "Better luck next time");

        glEnd();
	}
}

Sprite getSpritePos(double xpos,double ypos, Sprite sprite)
{
	gl.sprite.pos.x = xpos;
	gl.sprite.pos.y = ypos;
	
	return sprite;

}


Tile getTilePosition(double width, double height, Tile tile)
{
        if(tile.identity != 0) {
                tile.pos.x = width;
                tile.pos.y = height;
        }
        return tile;
}

void physics()
{
	if (gl.sprite.pos.x < 0){
	gl.sprite.pos.x = 15;
	}
	else if(gl.sprite.pos.x > (float)gl.xres){
	gl.sprite.pos.x = (float)gl.xres - 15;
	}
	if (gl.sprite.pos.y < 0){
        
		gl.sprite.pos.y = 15;
	}
	else if(gl.sprite.pos.y > (float)gl.yres){    
        gl.sprite.pos.y = (float)gl.yres - 15;
	}	
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

bool isCollsion() {
    	
	int x = gl.map.nrows;
	int y = gl.map.ncols;
	double width = 20;
	double height = 20;
	gl.map.arr[x][y] = getTilePosition(width,height, gl.map.arr[x][y]);
	if(gl.map.arr[x][y].identity == '5')
	{
		return false;
	}
	if(gl.map.arr[x][y].identity == '3')
	{
		return false;
	}
	if(gl.map.arr[x][y].identity == '1')
	{
		return true;
	}
	if(gl.map.arr[x][y].identity == '2')
	{
		return true;
	}
	if(gl.map.arr[x][y].identity == '4')
	{
		return true;
	}
	
	
   return true;
}
void Sprite::addMoney(int m)
{
	money +=m;
}
int Sprite::getMoney() const
{
	return money;
}
