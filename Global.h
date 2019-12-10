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
#include "Enemy.h"
#include "diegoC.h"
#include "joseC.h"
#include "fahadA.h"
#include "rayanA.h"
#include "Door.h"

class Global {
	public:
		static Global& getInstance() {
			static Global instance;
			return instance;
		}
		Sprite sprite;
		Enemy enemy1;
		Enemy enemy2;
		Enemy enemy3;
		Enemy enemy4;
		Enemy enemy5;
		Door door1;
		Door door2;
		Door door3;
		Map map;
		Image *playerImage;
		Image *enemyImage;
		Image *doorImage;
		GLuint playerTexture;
		GLuint enemyTexture;
		GLuint doorTexture;
		GLuint guideTexture;
		GLuint creditsTexture;
		GLuint menuTexture;
		GLuint highscoreTexture;
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
		GLuint doorTile;
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
		bool HighScores;
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
			HighScores = false;
			
			//Player position
			sprite.pos.x = 300;
			sprite.pos.y = 400;
		
			//Enemy position
			enemy1.pos.x = 1000;
			enemy1.pos.y = 800;
			enemy2.pos.x = 495;
			enemy2.pos.y = 670;
			enemy3.pos.x = 504;
			enemy3.pos.y = 257;
			enemy4.pos.x = 647;
			enemy4.pos.y = 165;
			enemy5.pos.x = 545;
			enemy5.pos.y = 571;

			door1.pos.x = 670;
			door1.pos.y = 450;
			door2.pos.x = 230;
			door2.pos.y = 650;
			door3.pos.x = 850;
			door3.pos.y = 570;
			
		}
	Global(Global const&);
	void operator=(Global const&);

};

#endif
