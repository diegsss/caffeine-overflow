#ifndef Door_H
#define Door_H

class Door {
        public:
                int onoff;
                int frame;
                Vect pos;
                Vect vel;
                int dir[2];
                Image *image;
                GLuint texture;
                Door() {
                        onoff = 0;
                        frame = 0;
                        image = nullptr;
                        vel.y += 0;
                        vel.x = 15;
                }
    public:
        Door(double x, double y);
        void DoorEntered(double x,double y,Sprite sprite);
       // void DrawEnemy(int xres,int yres, int x, int y);
        void hit();
};

#endif

