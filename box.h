#ifndef BOX_H
#define BOX_H
#include <SDL.h>
#include "wall.h"
class box{
public:
    box(int, int);
    box();
    ~box();
    void setorgy(int*);
    void setorgx(int*);
    void setorgcoords();
    void setorgcoords(int, int);
    int getorgx();
    int getorgy();
    SDL_Rect getbox();
    void setx(int);
    void sety(int);
    void resetcoords();
    void setcoords(int, int);
    void setoffscreen();
    int getx();
    int gety();
    int getw();
    int geth();
    void setbox(box);
    bool checkCollision(SDL_Rect);
    void starcheckCollision(box,box,box,box,wall,wall,wall,wall,wall,wall,wall, int, int);
private:
    SDL_Rect crate;
    int orgx;
    int orgy;
};
#endif // BOX_H
