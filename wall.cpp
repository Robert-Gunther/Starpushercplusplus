#include "wall.h"
#include <SDL.h>
#define offsize 1
#define offcoord -1000
wall::wall(){
setoffscreen();
setsize(offsize,offsize);
}
wall::wall(int x, int y, int w, int h){
setcoords(x,y);
setsize(h,w);
}
wall::~wall(){}
SDL_Rect wall::getwall(){return block;}
int wall::getx(){return block.x;}
int wall::gety(){return block.y;}
void wall::setx(int* x){block.x=*x;}
void wall::sety(int* y){block.y=*y;}
void wall::setH(int* h){block.h=*h;}
void wall::setW(int* w){block.w=*w;}
void wall::setcoords(int x, int y){
    setx(&x);
    sety(&y);
}
void wall::setsize(int inh, int inw){
setH(&inh);
setW(&inw);
}
void wall::setoffscreen(){
setcoords(offcoord,offcoord);
setsize(offsize,offsize);
}

