#ifndef SPRITE_H
#define SPITE_H

class Sprite {
	public:
		
		int lives;
		int health;
		static const int RADIUS;
		int onoff;
		int money;
		int frame;
		Vect pos;
		Vect vel;
		Image *image;
		GLuint texture;
		Sprite() {
			lives = 3;
			health = 100;
			onoff = 0;
			money = 0;
			frame = 0;
			image = nullptr;
			vel.y += 0;
			vel.x = 15;

		}
		Sprite(double xpos,double ypos);
		void addMoney(int m);
		int getMoney() const;
};

#endif
