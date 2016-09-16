#ifndef A2
#define A2
#include <string>
#include "figura.h"
#include "include/FiguryGracza.h"

class Pole{
int xs,ys;
int x, y;
Pionek *p;
Lanca *l;
Skoczek *n;
mGeneral *s;
dGeneral *g;
Goniec *b;
Wieza *r;
Krol *k;
std::string status;
std::string status_short;
public:
void setx(int _x);
void sety(int _y);
int getx();
int gety();
Gracz getGracz();
std::string getStatus();
std::string getStatusShort();
void narysuj(Figura);
void narysuj(std::string,Gracz = gracz1);
void setFigura(Pionek *_p);
void setFigura(Skoczek *_n);
void setFigura(Lanca *_l);
void setFigura(mGeneral *_s);
void setFigura(dGeneral *_g);
void setFigura(Goniec *_b);
void setFigura(Wieza *_r);
void setFigura(Krol *_k);
bool wykonajRuch(int x, int y, Pole& pole, FiguryGracza& g1, Gracz g);
void postawFigure();
};
#endif
