#include "hero.h"
#include "LTextures.h"
#include "box.h"
#include <iostream>
#define ZERO 0
hero::hero() {
    x = ZERO;
    y = ZERO;
    mCollider.w = hero_WIDTH;
    mCollider.h = hero_HEIGHT;
    mVelX = ZERO;
    mVelY = ZERO;
    }
hero::~hero(){}
void hero::setx(int x){this->x=x;}
void hero::sety(int y){this->y=y;}
void hero::setcoords(int x, int y){
        setx(x);
        sety(y);
        }
int hero::getx(){return x;}
int hero::gety(){return y;}
void hero::setdefault(){setcoords(ZERO,ZERO);}
void hero::Event(SDL_Event& e) {
    if(e.type == SDL_KEYDOWN && e.key.repeat == ZERO) {
        switch(e.key.keysym.sym) {
            case SDLK_UP:
                mVelY -= hero_VEL;
                break;
            case SDLK_DOWN:
                mVelY += hero_VEL;
                break;
            case SDLK_LEFT:
                mVelX -= hero_VEL;
                break;
            case SDLK_RIGHT:
                mVelX += hero_VEL;
                break;
            }
        }
    else if(e.type == SDL_KEYUP && e.key.repeat == ZERO) {
        //Adjust the velocity
        switch(e.key.keysym.sym) {
            case SDLK_UP:
                mVelY += hero_VEL;
                break;
            case SDLK_DOWN:
                mVelY -= hero_VEL;
                break;
            case SDLK_LEFT:
                mVelX += hero_VEL;
                break;
            case SDLK_RIGHT:
                mVelX -= hero_VEL;
                break;
            }
        }
    }
box hero::move(box star) {
    //Move the hero left or right
    x += mVelX;
    mCollider.x = x;
    //If the hero collided with a star extra added to prevent a bug
    if((x < ZERO) || (x + hero_WIDTH > SCREEN_WIDTH)||checkCollision(star.getbox())) {
        //Move back
        star.setx(star.getx()+mVelX);
        x -= mVelX;
        mCollider.x = x;
        }
    //Move the hero up or down
    y += mVelY;
    mCollider.y = y;
    //If the hero collided with a star extra added to prevent a bug
    if((y < ZERO) || (y + hero_HEIGHT > SCREEN_HEIGHT)||checkCollision(star.getbox())) {
        //Move back
        star.sety((star.gety()+mVelY));
        y -= mVelY;
        mCollider.y = y;
        }
        return star;
    }
void hero::move(wall holdpiece) {
    //Move the hero left or right
    x += mVelX;
    mCollider.x = x+1;
    //If the hero collided or went too far to the left or right
    if((x < ZERO) || (x + hero_WIDTH > SCREEN_WIDTH)||checkCollision(holdpiece.getwall())) {
        //Move back
        x -= mVelX;
        mCollider.x = x;
        }
    //Move the hero up or down
    y += mVelY;
    mCollider.y = y;
    //If the hero collided or went too far up or down
    if((y < ZERO) || (y + hero_HEIGHT > SCREEN_HEIGHT)||checkCollision(holdpiece.getwall())) {
        //Move back
        y -= mVelY;
        mCollider.y = y;
        }
    }
void hero::move() {
    //Move the hero left or right
    x += mVelX;
    mCollider.x = x;
    //If the hero collided or went too far to the left or right
    if((x < ZERO) || (x + hero_WIDTH > SCREEN_WIDTH)){
        //Move back
        x -= mVelX;
        mCollider.x = x;
        }
    //Move the hero up or down
    y += mVelY;
    mCollider.y = y;
    //If the hero collided or went too far up or down
    if((y < ZERO) || (y + hero_HEIGHT > SCREEN_HEIGHT)){
        //Move back
        y -= mVelY;
        mCollider.y = y;
        }
    }
bool hero::checkCollision(SDL_Rect b) {
    //The sides of the rectangles
    int* leftA;
    int* topA;
    int* leftB;
    int* topB;
    int rightA, rightB;
    int bottomA, bottomB;
    //Calculate the sides of rect A
    leftA = &mCollider.x;
    rightA = mCollider.x + mCollider.w;
    topA = &mCollider.y;
    bottomA = mCollider.y + mCollider.h;
    //Caculate the sides of rect B
    leftB = &b.x;
    rightB = b.x + b.w;
    topB = &b.y;
    bottomB = b.y + b.h;
    //If any of the sides from A are outside of B
    if(bottomA <= *topB) {return false;}
    if(*topA >= bottomB) {return false;}
    if(rightA <= *leftB) {return false;}
    if(*leftA >= rightB) {return false;}
    //If none of the sides from A are outside B
    return true;
    }
