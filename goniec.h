#ifndef A9
#define A9
#include "naglowek.h"

class Goniec : public Figura{
public:
Goniec(){
}
Goniec(Pole& s, Gracz _gracz){
    pole = &s;
    pole->setx(s.getx());
    pole->sety(s.gety());
    gracz = _gracz;
    status = true;
    s1 = bez_promocji;
    znak = "b";
    pole -> narysuj(znak,gracz);
}
bool sprawdzDostepnoscRuchu(Pole p, int x, int y){
    bool xx=false, yy=false;
    if(x >= 0 && x <= 8 && y >= 0 && y <= 8)
        {

        if(s1 == bez_promocji)
        {

            if(x - p.getx() == y - p.gety() || x - p.getx() == p.gety() - y)
            {
                xx = true;
                yy = true;
            }
            if( x - p.gety() == y - p.getx() || x - p.gety() == p.getx() - y)
            {
                xx = true;
                yy = true;
            }
        }
        else
        {
            if(x >= p.getx() - 1 && x <= p.getx() + 1 && y-p.gety() == gracz)
            {
                xx = true; yy = true;
            }
            if(x==p.getx() && y + p.gety() == -gracz)
            {
                xx = true; yy = true;
            }
        }
    }
    return xx&&yy;
}
bool wykonajRuch(int x, int y, Pole *s, Pole& p2)
{
    bool mozliwyRuch = sprawdzDostepnoscRuchu(*pole, x, y);
    if(mozliwyRuch)
    {
        pole -> narysuj(" ");
        pole = &p2;
        if(gracz == gracz1 && y >= 6)
        {
            s1 = promocja;
            znak = "B";
        }
        if(gracz == gracz2 && y <= 2)
        {
            s1 = promocja;
            znak = "B";
        }
        pole -> narysuj(znak, gracz);
        return true;
    }
    else return false;
}
};
#endif
