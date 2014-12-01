#ifndef LTEXTURE_H
#define LTEXTURE_H
#include <string>
#include <SDL.h>
#include <SDL_image.h>
class LTexture {
    public:
        LTexture();
        ~LTexture();
        bool loadFromFile(std::string path);
        //Deallocates texture
        void free();
        //Set color modulation
        void setColor(Uint8 red, Uint8 green, Uint8 blue);
        //Set blending
        void setBlendMode(SDL_BlendMode blending);
        //Set alpha modulation
        void setAlpha(Uint8 alpha);
        //Renders texture at given point
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
