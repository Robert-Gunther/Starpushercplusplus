#include "panel.h"
panel::panel(){}
panel::~panel(){}
void panel::setx(int& x){this->x=x;}
void panel::sety(int& y){this->y=y;}
void panel::setcoords(int x, int y){
setx(x);
sety(y);
}
void panel::setoffscreen(){
x=-1000;
x=-1000;
}
int panel::getx(){return x;}
int panel::gety(){return y;}
