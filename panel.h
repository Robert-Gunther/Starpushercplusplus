#ifndef PANEL_H
#define PANEL_H
class panel{
public:
panel();
~panel();
void setx(int&);
void sety(int&);
void setcoords(int, int);
void setoffscreen();
int getx();
int gety();
private:
int x;
int y;
};
#endif // PANEL_H
