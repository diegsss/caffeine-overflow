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
		Map map;
		GLuint playerTexture;
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
		int currentMap;
		int player;
		bool Credits;
		bool GameMenu;
		bool GameOver;
		bool NewGame;
		bool GameStart;
		bool HowToPlay;
		int posArr;
		char *user;
	private:
		char map1[10] = "map.txt";
		Global() {
			xres = 800;
			yres = 800;
			camera[0] = camera[1] = 0.0;
			memset(keys, 0 , 65536);
			player = 1;
			currentMap = 1;
			map = Map(map1);
			posArr = 1;
			Credits = false;
			GameMenu = true;
			GameOver = false;
			NewGame = true;
			GameStart = false;
			HowToPlay = false;
		}
	Global(Global const&);
	void operator=(Global const&);

};

#endif
