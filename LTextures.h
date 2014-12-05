#ifndef LTEXTURE_H
#define LTEXTURE_H
#include <string>
#include <SDL.h>
#include <SDL_image.h>
//Note: This Modified version of Lazy foos LTexture is named the same as the above in tribute to it
class LTexture {
    public:
        LTexture();
        ~LTexture();
        bool loadFromFile(std::string path);
        //Deallocates texture
        void free();
        void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
        //Gets image dimensions
        int getWidth();
        int getHeight();
    private:
        SDL_Texture* mTexture;
        int mWidth;
        int mHeight;
    };
#endif // LTEXTURE_H
