#include "LTextures.h"
#include <SDL.h>
#include <SDL_image.h>
#define ZERO 0
LTexture::LTexture() {
    //Initialize
    mTexture = NULL;
    mWidth = ZERO;
    mHeight = ZERO;
    }
LTexture::~LTexture() {
    //Deallocate
    free();
    }
void LTexture::free() {
    //Free texture if it exists
    if(mTexture != NULL) {
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        mWidth = ZERO;
        mHeight = ZERO;
        }
    }
int  LTexture::getWidth() {return mWidth;}
int  LTexture::getHeight() {return mHeight;}
