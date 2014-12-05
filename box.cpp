#include "box.h"
#include <SDL.h>
#include "wall.h"
#define offcoord -1000
#define WIDTH 40
#define HEIGHT 40
#define ZERO 0
box::box(int x, int y){
    setcoords(x,y);
    crate.w=WIDTH;
    crate.h=HEIGHT;
    setorgcoords();
}
box::box(){
    setoffscreen();
    crate.w=WIDTH;
    crate.h=HEIGHT;
    setorgcoords();
}
box::~box(){}
void box::setorgx(int* x){orgx=*x;}
void box::setorgy(int* y){orgy=*y;}
int  box::getorgx(){return orgx;}
int box::getorgy(){return orgy;}
SDL_Rect box::getbox(){return crate;}
void box::setx(int x){crate.x=x;}
void box::sety(int y){crate.y=y;}
int box::getx(){return crate.x;}
int box::gety(){return crate.y;}
int box::geth(){return crate.h;}
int box::getw(){return crate.w;}
void box::setorgcoords(){setorgcoords(crate.x,crate.y);}
void box::setorgcoords(int x, int y){
setorgx(&x);
setorgy(&y);
}
void box::setcoords(int x, int y){
setx(x);
sety(y);
}
void box::resetcoords(){setcoords(orgx, orgy);}
void box::setbox(box temp){setcoords(temp.getx(),temp.gety());}
void box::setoffscreen(){setcoords(offcoord, offcoord);}
void box::starcheckCollision(box startwo, box starthree, box starfour, box starfive,wall wallone,
                   wall walltwo, wall wallthree, wall wallfour, wall wallfive, wall wallsix,
                   wall wallseven, int SCREEN_HEIGHT, int SCREEN_WIDTH){
if(checkCollision(wallone.getwall())
        ||checkCollision(walltwo.getwall())
        ||checkCollision(wallthree.getwall())
        ||checkCollision(wallfour.getwall())
        ||checkCollision(wallfive.getwall())
        ||checkCollision(wallsix.getwall())
        ||checkCollision(wallseven.getwall())
        ||checkCollision(startwo.getbox())
        ||checkCollision(starthree.getbox())
        ||checkCollision(starfour.getbox())
        ||checkCollision(starfive.getbox())
        ||(crate.x < ZERO) || (crate.x + crate.w > SCREEN_WIDTH)
        ||(crate.y < ZERO) || (crate.y + crate.h > SCREEN_HEIGHT)) {
    resetcoords();
    }
                   }
bool box::checkCollision(SDL_Rect b) {
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
    //Calculate the sides of rect A
    leftA = crate.x;
    rightA = crate.x + crate.w;
    topA = crate.y;
    bottomA = crate.y + crate.h;
    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;
    //If any of the sides from A are outside of B
    if(bottomA <= topB) {
        return false;
        }
    if(topA >= bottomB) {
        return false;
        }
    if(rightA <= leftB) {
        return false;
        }
    if(leftA >= rightB) {
        return false;
        }
    //If none of the sides from A are outside B
    return true;
    }
