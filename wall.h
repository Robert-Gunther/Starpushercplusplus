#ifndef WALL_H
#define WALL_H
#include <SDL.h>
class wall{
public:
wall();
wall(int, int, int, int);
~wall();
SDL_Rect getwall();
int getx();
int gety();
void setx(int*);
void sety(int*);
void setH(int*);
void setW(int*);
void setcoords(int, int);
void setsize(int,int);
void setoffscreen();
private:
    SDL_Rect block;
};
#endif // WALL_H
