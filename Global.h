#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <ctime>
#include <cmath>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <GL/glx.h>
#include "log.h"
#include "Image.h"
#include "Map.h"
#include "Sprite.h"
#include "diegoC.h"
#include "joseC.h"
#include "fahadA.h"
#include "rayanA.h"

class Global {
	public:
		static Global& getInstance() {
			static Global instance;
			return instance;
		}
		Sprite sprite;
		Map map;
		Image *playerImage;
		GLuint playerTexture;
		GLuint guideTexture;
		GLuint creditsTexture;
		GLuint menuTexture;
		GLuint diegoCTexture;
		GLuint joseCTexture;
		GLuint fahadATexture;
		GLuint rayanATexture;
		GLuint mapTexture;
		GLuint grassTile;
		GLuint roadTile;
		GLuint treeTile;
		GLuint waterTile;
		GLuint blockTile;
		int xres;
		int yres;
		char keys[65536];
		double camera[2];
		int player;
		bool Credits;
	//
		bool keypressed;
		bool GameMenu;
		bool GameOver;
		bool NewGame;
		bool GameStart;
		bool HowToPlay;
		int posArr;
		bool collsion;
		int walk;
		int walkFrame;
		char *user;
	private:
		char map1[10] = "map.txt";
		Global() {
			walk = 0;
			walkFrame = 0;
			xres = 800;
			yres = 600;
			camera[0] = camera[1] = 0.0;
			memset(keys, 0 , 65536);
			player = 1;
			map = Map(map1);
			posArr = 1;
			Credits = false;
			GameMenu = true;
			GameOver = false;
			NewGame = true;
			GameStart = false;
			HowToPlay = false;

			sprite.pos.x = 300 ;
			sprite.pos.y = 400 ;
		//	sprite.vel.x = 0;
		//	sprite.vel.y = 0;
		}
	Global(Global const&);
	void operator=(Global const&);

};

#endif
