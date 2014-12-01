#ifndef HERO_H
#define HERO_H
#include <SDL.h>
#include "box.h"
#include "wall.h"
class hero {
    public:
        static const int hero_WIDTH = 25;
        static const int hero_HEIGHT = 50;
        static const int hero_VEL = 10;
        hero();
        ~hero();
        void Event(SDL_Event& e);
        box move(box);
        void move(wall);
        void move();
        void setx(int);
        void sety(int);
        void setcoords(int, int);
        void setdefault();
        int getx();
        int gety();
        bool checkCollision(SDL_Rect);
    private:
        int x, y;
        int mVelX, mVelY;
        int SCREEN_HEIGHT;
        int SCREEN_WIDTH;
        SDL_Rect mCollider;
    };
#endif // HERO_H
