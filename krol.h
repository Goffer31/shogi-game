#ifndef A11
#define A11
#include "naglowek.h"

class Krol : public Figura{
public:
Krol(){
}
Krol(Pole& s, Gracz _gracz){
    pole = &s;
    pole->setx(s.getx());
    pole->sety(s.gety());
    gracz = _gracz;
    status = true;
    s1 = bez_promocji;
    znak = "k";
    pole -> narysuj(znak,gracz);
}
bool sprawdzDostepnoscRuchu(Pole p, int x, int y){
    bool xx=false, yy=false;
    if(x >= 0 && x <= 8 && y >= 0 && y <= 8)
        {

        if(s1 == bez_promocji)
        {
            if(x >= p.getx() - 1 && x <= p.getx() +1 && y >= p.gety() - 1 && y <= p.gety() + 1)
            {
                xx = true;
                yy = true;
            }
        }
        else
        {
            if(x >= p.getx() - 1 && x <= p.getx() +1 && y >= p.gety() - 1 && y <= p.gety() + 1)
            {
                xx = true;
                yy = true;
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
            znak = "K";
        }
        if(gracz == gracz2 && y <= 2)
        {
            s1 = promocja;
            znak = "K";
        }
        pole -> narysuj(znak, gracz);
        return true;
    }
    else return false;
}
};
#endif
