#ifndef SPRITE_H
#define SPITE_H

class Sprite {
	public:
		
		int lives;
		int onoff;
		int frame;
		Vect pos;
		Vect vel;
		Image *image;
		GLuint texture;
		Sprite() {
			lives = 3;
			onoff = 0;
			frame = 0;
			image = nullptr;
			vel.y += 0;
			vel.x = 15;

		}
};

#endif
