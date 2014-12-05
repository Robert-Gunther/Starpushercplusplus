#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include <string>
#include "hero.h"
#include "LTextures.h"
#include "wall.h"
#include "panel.h"
#include "box.h"
#define ZERO 0
namespace StarPusher {
bool init();
bool loadMedia();
void close();
void openingpiece();
bool boolchange(bool);
void rendersubroutine(int num);
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
//The reason for the Large Number of LTextures is to keep things simple
LTexture gheroTexture;
LTexture gstarTexture;
LTexture g50x50wall;
LTexture g50x100wall;
LTexture g50x150wall;
LTexture g50x300wall;
LTexture g300x50wall;
LTexture g450x50wall;
LTexture g500x50wall;
LTexture gback;
LTexture openingone;
LTexture openingtwo;
LTexture openingthree;
LTexture Titleone;
LTexture Titletwo;
LTexture Titlethree;
LTexture Titlefour;
LTexture Titlefive;
LTexture Titlesix;
LTexture Titleseven;
LTexture Titleeight;
LTexture Titlenine;
LTexture Titleten;
LTexture Titleeleven;
LTexture Titletwelve;
LTexture Titlethirteen;
LTexture Titlefourteen;
LTexture paused;
LTexture ghelp;
LTexture gpanel;
LTexture Tutorialone;
LTexture Tutorialtwo;
LTexture Tutorialthree;
LTexture youwin;
}
using namespace StarPusher;
//These need to be here as they are so greatly bound to the main file
bool LTexture::loadFromFile(std::string path) {
    //Clear the Ltexture
        free();
    //The final texture
    SDL_Texture* newTexture = NULL;
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == NULL) {}
    else {
        //Color key image
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if(newTexture == NULL) {}
        else {
            //Get image dimensions
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
            }
        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
        }
    //Return success
    mTexture = newTexture;
    return mTexture != NULL;
    }
void LTexture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };
    //Set clip rendering coords
    if(clip != NULL) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
        }
    //Render to screen
    SDL_RenderCopyEx(gRenderer, mTexture, clip, &renderQuad, angle, center, flip);

    }
int main(int argc, char* args[]) {
            int level=ZERO;
            int tutor=ZERO;
            bool create=true;
            bool pause=false;
            bool start=true;
            bool help=false;
            bool tutorial=false;
            bool game=false;
            bool quit = false;
            SDL_Event e;
            hero phero;
            box star;
            box startwo;
            box starthree;
            box starfour;
            box starfive;
            panel panelone;
            panel paneltwo;
            panel panelthree;
            panel panelfour;
            panel panelfive;
            wall wallone;
            wall walltwo;
            wall wallthree;
            wall wallfour;
            wall wallfive;
            wall wallsix;
            wall wallseven;
    if(init()) {
        if(loadMedia()) {
            openingpiece();
            while(!quit) {
                //Handle events on queue
                while(SDL_PollEvent(&e) != ZERO) {
                    if(e.type == SDL_QUIT) {quit = true;}
                    if(e.type == SDL_KEYDOWN&&  e.key.repeat == 0) {
                        switch(e.key.keysym.sym) {
                            case SDLK_RETURN:
                                if (start==true&&pause==false&&help==false&&tutorial==false){
                                   start=false;
                                   game=true;
                                   level++;
                                   create=true;
                                }
                                break;
                            case SDLK_p:
                                if (start==false&&help==false){pause=boolchange(pause);}
                                else{}
                                break;
                            case SDLK_t:
                                if (start==true&&tutorial==false&&game==false){
                                    tutorial=true;
                                    start=false;
                                    create=true;
                                    tutor=1;
                                }
                                else{}
                                break;
                            case SDLK_m:
                                if (pause==false){
                                start=true;
                                help=false;
                                tutorial=false;
                                game=false;
                                tutor=ZERO;
                                level=ZERO;
                                }
                                else{}
                                break;
                            case SDLK_h:
                                if (pause==false&&start==true&&game==false){
                                    help=true;
                                    start=false;
                                }
                                else{
                                    start=true;
                                    help=false;
                                }
                                break;
                            case SDLK_ESCAPE:
                                quit=true;
                                break;
                            default:
                                break;
                            }
                        }
                    phero.Event(e);
                    }
                if (create==true){
                        phero.setdefault();
                        star.setoffscreen();
                        startwo.setoffscreen();
                        starthree.setoffscreen();
                        starfour.setoffscreen();
                         starfive.setoffscreen();
                        wallone.setoffscreen();
                        walltwo.setoffscreen();
                        wallthree.setoffscreen();
                        wallfour.setoffscreen();
                        wallfive.setoffscreen();
                        wallsix.setoffscreen();
                        wallseven.setoffscreen();
                        panelone.setoffscreen();
                        paneltwo.setoffscreen();
                        panelthree.setoffscreen();
                        panelfour.setoffscreen();
                        panelfive.setoffscreen();
                }
                if (start==true){
            Titlefourteen.render(ZERO,ZERO);
            rendersubroutine(100);
            }
                else if (pause==true){
            paused.render(ZERO,ZERO);
            SDL_RenderPresent(gRenderer);
            SDL_Delay(500);}
                else if (help==true){
            ghelp.render(ZERO,ZERO);
            rendersubroutine(100);
                }
                else if (tutorial==true){
                if (create==true){star.setcoords(200,200);}
                else{}
                if(tutor==1&&create==true) {
                        panelone.setcoords(400, 200);
                        create=false;
                   }
                else if(tutor==2&& create==true) {
                        wallone.setcoords(400, 100);
                        wallone.setsize(300,50);
                        panelone.setcoords(600, 200);
                        create=false;
                }
                else if(tutor==3&& create==true) {
                        startwo.setcoords(100,100);
                        panelone.setcoords(600, 200);
                        paneltwo.setcoords(500, 400);
                        create=false;
                }
                else{}
                if(tutor==1) {
                if (star.getx()==panelone.getx()&&star.gety()==panelone.gety()){
                    tutor++;
                    create=true;
                }
                else{}
                SDL_RenderPresent(gRenderer);
                }
                else if(tutor==2) {
                if (star.getx()==panelone.getx()&&star.gety()==panelone.gety()){
                    tutor++;
                    create=true;
                }
                else{}
                g50x300wall.render(wallone.getx(),wallone.gety());
                SDL_RenderPresent(gRenderer);}
                else if(tutor==3) {
                if (star.getx()==panelone.getx()&&star.gety()==panelone.gety()&&startwo.getx()==paneltwo.getx()&& startwo.gety()==paneltwo.gety()){
                    tutorial=false;
                    start=true;
                }
                else{}
                SDL_RenderPresent(gRenderer);
                }
                }
                else if (game==true){
                if(level==1&&create==true) {
                        star.setcoords(500,100);
                        wallone.setcoords(120, 150);
                        wallone.setsize(80,50);
                        walltwo.setcoords(250,150);
                        walltwo.setsize(50,100);
                        wallthree.setcoords(120, 150);
                        wallthree.setsize(50, 300);
                        wallfour.setcoords(370, 150);
                        wallfour.setsize(300,50);
                        wallfive.setcoords(120, 400);
                        wallfive.setsize(50, 300);
                        panelone.setcoords(200, 200);
                        create=false;
                }
                else if(level==2&& create==true) {
                        star.setcoords(400,350);
                        startwo.setcoords(200,350);
                        panelone.setcoords(200, 100);
                        paneltwo.setcoords(400, 100);
                        wallone.setcoords(100, 300);
                        wallone.setsize(50,450);
                        walltwo.setcoords(500, 250);
                        walltwo.setsize(100,50);
                        wallthree.setcoords(100, 250);
                        wallthree.setsize(100,50);
                        create=false;
                        }
                else if(level==3&& create==true) {
                    SDL_RenderClear(gRenderer);
                    star.setcoords(100, 350);
                    startwo.setcoords(500,350);
                    starthree.setcoords(300,350);
                    panelone.setcoords(200, 200);
                    paneltwo.setcoords(400, 200);
                    panelthree.setcoords(300, 300);
                    wallone.setcoords(75,250);
                    wallone.setsize(50,450);
                    walltwo.setcoords(75,150);
                    walltwo.setsize(150,50);
                    wallthree.setcoords(275,150);
                    wallthree.setsize(125,50);
                    wallfour.setcoords(525,150);
                    wallfour.setsize(150,50);
                    wallfive.setcoords(225,250);
                    wallfive.setsize(150,50);
                    wallsix.setcoords(375,250);
                    wallsix.setsize(150,50);
                    wallseven.setcoords(325,150);
                    wallseven.setsize(150,50);
                    create=false;
                }
                else if(level==4&& create==true) {
                    star.setcoords(100, 100);
                    startwo.setcoords(300,100);
                    starthree.setcoords(500,100);
                    starfour.setcoords(200,300);
                    starfive.setcoords(400,300);
                    panelone.setcoords(100, 300);
                    paneltwo.setcoords(300, 300);
                    panelthree.setcoords(500, 300);
                    panelfour.setcoords(200,100);
                    panelfive.setcoords(400,100);
                    wallone.setcoords(75,200);
                    wallone.setsize(50,500);
                    create=false;
                    }
                else if(level==5&& create==true) {
                    star.setcoords(300, 100);
                    startwo.setcoords(200,200);
                    starthree.setcoords(400,200);
                    starfour.setcoords(250,300);
                    starfive.setcoords(350,300);
                    panelone.setcoords(300, 100);
                    paneltwo.setcoords(400, 200);
                    panelthree.setcoords(200, 200);
                    panelfour.setcoords(350,300);
                    panelfive.setcoords(250,300);
                    wallone.setcoords(290,200);
                    wallone.setsize(50,50);
                    create=false;}
                else{}
                if(level==1) {
                 if (star.getx()==panelone.getx()&&star.gety()==panelone.gety()){
                    level++;
                    create=true;
                }
                g50x300wall.render(wallone.getx(),wallone.gety());
                g50x300wall.render(wallfour.getx(),wallfour.gety());
                g300x50wall.render(wallthree.getx(), wallthree.gety());
                g300x50wall.render(wallfive.getx(), wallfive.gety());
                SDL_RenderPresent(gRenderer);}
               else if(level==2) {
                 if (star.getx()==panelone.getx()&&star.gety()==panelone.gety()&&startwo.getx()==paneltwo.getx()&& startwo.gety()==paneltwo.gety()){
                    level++;
                    create=true;
                }
                g450x50wall.render(wallone.getx(),wallone.gety());
                g50x100wall.render(walltwo.getx(),walltwo.gety());
                g50x100wall.render(wallthree.getx(),wallthree.gety());
                SDL_RenderPresent(gRenderer);}
                else if(level==3){
                if (star.getx()==panelone.getx()&&star.gety()==panelone.gety()
                    &&startwo.getx()==paneltwo.getx()&& startwo.gety()==paneltwo.gety()
                    &&starthree.getx()==panelthree.getx()&& starthree.gety()==panelthree.gety()){
                    level++;
                    create=true;
                }
                g450x50wall.render(wallone.getx(),wallone.gety());
                g50x150wall.render(walltwo.getx(),walltwo.gety());
                g50x150wall.render(wallthree.getx(),wallthree.gety());
                g50x150wall.render(wallfour.getx(),wallfour.gety());
                g50x150wall.render(wallfive.getx(),wallfive.gety());
                g50x150wall.render(wallsix.getx(),wallsix.gety());
                g50x150wall.render(wallseven.getx(),wallseven.gety());
                SDL_RenderPresent(gRenderer);
                }
                else if(level==4) {
                if (star.getx()==panelone.getx()&&star.gety()==panelone.gety()
                    &&startwo.getx()==paneltwo.getx()&& startwo.gety()==paneltwo.gety()
                    &&starthree.getx()==panelthree.getx()&& starthree.gety()==panelthree.gety()
                    &&starfour.getx()==panelfour.getx()&& starfour.gety()==panelfour.gety()
                    &&starfive.getx()==panelfive.getx()&& starfive.gety()==panelfive.gety()){
                    level++;
                    create=true;
                }
                g500x50wall.render(wallone.getx(),wallone.gety());
                SDL_RenderPresent(gRenderer);}
                else if(level==5) {
                g50x50wall.render(wallone.getx(),wallone.gety());
                SDL_RenderPresent(gRenderer);
                if (star.getx()==panelone.getx()&&star.gety()==panelone.gety()
                    &&startwo.getx()==paneltwo.getx()&& startwo.gety()==paneltwo.gety()
                    &&starthree.getx()==panelthree.getx()&& starthree.gety()==panelthree.gety()
                    &&starfour.getx()==panelfour.getx()&& starfour.gety()==panelfour.gety()
                    &&starfive.getx()==panelfive.getx()&& starfive.gety()==panelfive.gety()){
                    level=ZERO;
                    youwin.render(ZERO,ZERO);
                    SDL_RenderPresent(gRenderer);
                    SDL_Delay(2000);
                    game=false;
                    start=true;
                }
                }
                else{}
            }
                else{}
           // this hold all the crossover data for each level/tutorial
            if (tutorial==true||game==true){
                star.setorgcoords();
                startwo.setorgcoords();
                starthree.setorgcoords();
                starfour.setorgcoords();
                starfive.setorgcoords();
            if(phero.checkCollision(star.getbox())) {star.setbox(phero.move(star));}
                else if(phero.checkCollision(startwo.getbox())) {startwo.setbox(phero.move(startwo));}
                else if(phero.checkCollision(starthree.getbox())) {starthree.setbox(phero.move(starthree));}
                else if(phero.checkCollision(starfour.getbox())) {starfour.setbox(phero.move(starfour));}
                else if(phero.checkCollision(starfive.getbox())) {starfive.setbox(phero.move(starfive));}
                else if(phero.checkCollision(wallone.getwall())) {phero.move(wallone);}
                else if(phero.checkCollision(walltwo.getwall())) {phero.move(walltwo);}
                else if(phero.checkCollision(wallthree.getwall())) {phero.move(wallthree);}
                else if(phero.checkCollision(wallfour.getwall())) {phero.move(wallfour);}
                else if(phero.checkCollision(wallfive.getwall())) {phero.move(wallfive);}
                else if(phero.checkCollision(wallsix.getwall())) {phero.move(wallsix);}
                else if(phero.checkCollision(wallseven.getwall())) {phero.move(wallseven);}
                else{phero.move();}
                star.starcheckCollision(startwo, starthree, starfour, starfive, wallone,
                                        walltwo, wallthree, wallfour, wallfive, wallsix, wallseven, SCREEN_HEIGHT, SCREEN_WIDTH);
                startwo.starcheckCollision(star, starthree, starfour, starfive, wallone,
                                        walltwo, wallthree, wallfour, wallfive, wallsix, wallseven, SCREEN_HEIGHT, SCREEN_WIDTH);
                starthree.starcheckCollision(star, startwo, starfour, starfive, wallone,
                                        walltwo, wallthree, wallfour, wallfive, wallsix, wallseven, SCREEN_HEIGHT, SCREEN_WIDTH);
                starfour.starcheckCollision(star, startwo, starthree, starfive, wallone,
                                        walltwo, wallthree, wallfour, wallfive, wallsix, wallseven, SCREEN_HEIGHT, SCREEN_WIDTH);
                starfive.starcheckCollision(star, startwo, starthree, starfour, wallone,
                                        walltwo, wallthree, wallfour, wallfive, wallsix, wallseven, SCREEN_HEIGHT, SCREEN_WIDTH);
                SDL_RenderClear(gRenderer);
                gback.render(ZERO,ZERO);
                if (tutor==1){Tutorialone.render(ZERO,ZERO);}
                if (tutor==2){Tutorialtwo.render(ZERO,ZERO);}
                if (tutor==3){
                Tutorialthree.render(ZERO,ZERO);}
                gpanel.render(panelone.getx(), panelone.gety());
                gpanel.render(paneltwo.getx(), paneltwo.gety());
                gpanel.render(panelthree.getx(), panelthree.gety());
                gpanel.render(panelthree.getx(), panelthree.gety());
                gpanel.render(panelfour.getx(), panelfour.gety());
                gpanel.render(panelfive.getx(), panelfive.gety());
                gheroTexture.render(phero.getx(), phero.gety());
                gstarTexture.render(star.getx(), star.gety());
                gstarTexture.render(startwo.getx(), startwo.gety());
                gstarTexture.render(starthree.getx(), starthree.gety());
                gstarTexture.render(starfour.getx(), starfour.gety());
                gstarTexture.render(starfive.getx(), starfive.gety());
            }
        }
        }
                }
             phero.~hero();
             star.~box();
             startwo.~box();
             starthree.~box();
             starfour.~box();
             starfive.~box();
             panelone.~panel();
             paneltwo.~panel();
             panelthree.~panel();
             panelfour.~panel();
             panelfive.~panel();
             wallone.~wall();
             walltwo.~wall();
             wallthree.~wall();
             wallfour.~wall();
             wallfive.~wall();
             wallsix.~wall();
             wallseven.~wall();
    close();
    return ZERO;
    }
namespace StarPusher{
bool init() {
    if(SDL_Init(SDL_INIT_VIDEO) < ZERO) {return false;}
    else {
        //Set texture filtering to linear
        if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {}
        //Create window
        gWindow = SDL_CreateWindow("Starpusher", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(gWindow == NULL) {return false;}
        else {
            //Create vsynced renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(gRenderer == NULL) {return false;}
            else {
                //Initialize use of PNG
                int imgFlags = IMG_INIT_PNG;
                if(!(IMG_Init(imgFlags) & imgFlags)) {return false;}
                }
            }
        }
    return true;
    }
bool loadMedia() {// Bad Design created to close the game if a picture is not present
    if(!Titlethirteen.loadFromFile("Textures/Title13.png")||!Titletwelve.loadFromFile("Textures/Title12.png")
       ||!Titleten.loadFromFile("Textures/Title10.png")||!Titlenine.loadFromFile("Textures/Title9.png")
       ||!Titleeight.loadFromFile("Textures/Title8.png")||!Titleseven.loadFromFile("Textures/Title7.png")
       ||!Titlesix.loadFromFile("Textures/Title6.png")||!Titlefive.loadFromFile("Textures/Title5.png")
       ||!Titlefour.loadFromFile("Textures/Title4.png")||!Titlethree.loadFromFile("Textures/Title3.png")
       ||!Titletwo.loadFromFile("Textures/Title2.png")||!Titleone.loadFromFile("Textures/Title1.png")
       ||!openingthree.loadFromFile("Textures/openingthree.png")||!Tutorialthree.loadFromFile("Textures/tutorialthree.png")
       ||!openingtwo.loadFromFile("Textures/openingtwo.png")||!openingone.loadFromFile("Textures/openingone.png")
       ||!gback.loadFromFile("Textures/background.png")||!gheroTexture.loadFromFile("Textures/hero.png")
       ||!gstarTexture.loadFromFile("Textures/star.png")||!Titleeleven.loadFromFile("Textures/Title11.png")
       ||!Titlefourteen.loadFromFile("Textures/Title14.png")||!g300x50wall.loadFromFile("Textures/300X50wall.png")
       ||!ghelp.loadFromFile("Textures/help.png")||!paused.loadFromFile("Textures/paused.png")
       ||!gpanel.loadFromFile("Textures/panel.png")||!Tutorialone.loadFromFile("Textures/tutorialone.png")
       ||!Tutorialtwo.loadFromFile("Textures/tutorialtwo.png")||!g50x300wall.loadFromFile("Textures/50X300wall.png")
       ||!g50x50wall.loadFromFile("Textures/50X50wall.png")||!g50x100wall.loadFromFile("Textures/50X100wall.png")
       ||!g50x150wall.loadFromFile("Textures/50X150wall.png")||!g450x50wall.loadFromFile("Textures/450X50wall.png")
       ||!g500x50wall.loadFromFile("Textures/500X50wall.png")||!youwin.loadFromFile("Textures/Awinnerisyou.png")){
        return false;
        }
       else{return true;}
    }
void close() {
    //Free loaded images
    gheroTexture.free();
    gstarTexture.free();
    gback.free();
    Titlefourteen.free();
    Tutorialone.free();
    Tutorialtwo.free();
    Tutorialthree.free();
    g500x50wall.free();
    g50x100wall.free();
    g50x150wall.free();
    g50x300wall.free();
    g300x50wall.free();
    g450x50wall.free();
    youwin.free();
    ghelp.free();
    gpanel.free();
    paused.free();
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;
    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
    }
bool boolchange(bool change){
    if (change==true){return false;}
    else{return true;}
}
void openingpiece(){
            openingone.render(ZERO,ZERO);
            rendersubroutine(3000);
            openingtwo.render(ZERO,ZERO);
            rendersubroutine(3000);
            openingone.free();
            openingthree.render(ZERO,ZERO);
            rendersubroutine(3000);
            openingtwo.free();
            Titleone.render(ZERO,ZERO);
            rendersubroutine(60);
            openingthree.free();
            Titletwo.render(ZERO,ZERO);
            rendersubroutine(60);
            Titleone.free();
            Titlethree.render(ZERO,ZERO);
            rendersubroutine(60);
            Titletwo.free();
            Titlefour.render(ZERO,ZERO);
            rendersubroutine(60);
            Titlethree.free();
            Titlefive.render(ZERO,ZERO);
            rendersubroutine(60);
            Titlefour.free();
            Titlesix.render(ZERO,ZERO);
            rendersubroutine(60);
            Titlefive.free();
            Titleseven.render(ZERO,ZERO);
            rendersubroutine(60);
            Titlesix.free();
            Titleeight.render(ZERO,ZERO);
            rendersubroutine(60);
            Titleseven.free();
            Titlenine.render(ZERO,ZERO);
            rendersubroutine(60);
            Titleeight.free();
            Titleten.render(ZERO,ZERO);
            rendersubroutine(50);
            Titlenine.free();
            Titleeleven.render(ZERO,ZERO);
            rendersubroutine(50);
            Titleten.free();
            Titletwelve.render(ZERO,ZERO);
            rendersubroutine(50);
            Titleeleven.free();
            Titlethirteen.render(ZERO,ZERO);
            rendersubroutine(50);
            Titletwelve.free();
}
void rendersubroutine(int num){
            SDL_RenderPresent(gRenderer);
            SDL_Delay(num);
            SDL_RenderClear(gRenderer);
}
}
