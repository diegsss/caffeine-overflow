#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
	public:
		int health;
		int onoff;
		int frame;
		Vect pos;
		Vect vel;
		Image *image;
		GLuint texture;
		Enemy() {
			health = 100;
			onoff = 0;
			frame = 0;
			image = nullptr;
			vel.y += 0;
			vel.x = 15;
		}
};

#endif
