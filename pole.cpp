#include "pole.h"
#include "pionek.h"
#include "lanca.h"
#include "iostream"
#include "skoczek.h"
#include "malygeneral.h"
#include "duzygeneral.h"
#include "goniec.h"
#include "wieza.h"
#include "krol.h"

void Pole::setx(int _x){x = _x; xs = _x*2+4;}
void Pole::sety(int _y){y = _y; ys = _y*2+4;}
int Pole::getx(){return x;}
int Pole::gety(){return y;}
void Pole::narysuj(Figura f){wstaw_tekst(xs,ys,f.getChar(),"Default");}
void Pole::narysuj(std::string s,Gracz g){std::string kolor; if(g==gracz1)kolor="Red"; else kolor="Blue"; wstaw_tekst(xs,ys,s,kolor);}
void Pole::setFigura(Pionek *_p){p = _p; status = "Pionek"; status_short = "p";}
void Pole::setFigura(Skoczek *_n){n = _n; status = "Skoczek"; status_short = "n";}
void Pole::setFigura(Lanca *_l){l = _l; status = "Lanca"; status_short = "l";}
void Pole::setFigura(mGeneral *_s){s = _s; status = "Srebrny Generał"; status_short = "s";}
void Pole::setFigura(dGeneral *_g){g = _g; status = "Złoty Generał"; status_short = "g";}
void Pole::setFigura(Goniec *_b){b = _b; status = "Goniec"; status_short = "b";}
void Pole::setFigura(Wieza *_r){r = _r; status = "Wieża"; status_short = "r";}
void Pole::setFigura(Krol *_k){k = _k; status = "Król"; status_short = "k";}
std::string Pole::getStatusShort(){return status_short;}
std::string Pole::getStatus(){return status;}
bool Pole::wykonajRuch(int x, int y, Pole& pole, FiguryGracza& figury, Gracz g1)
{

    bool wykonano;
    bool czyJestBicie;
    if(pole.status != "Pionek" && pole.status != "Lanca" && pole.status != "Skoczek" && pole.status != "Srebrny Generał" && pole.status != "Złoty Generał" && pole.status != "Goniec" && pole.status != "Wieża" && pole.status != "Król")
        czyJestBicie = false;
    else czyJestBicie = true;

    if(status == "Pionek")
    {
        wykonano = p -> wykonajRuch(x, y, this, pole);
    }
    else if(status == "Lanca")
    {
        wykonano = l -> wykonajRuch(x, y, this, pole);
    }
    else if(status == "Skoczek")
    {
        wykonano = n -> wykonajRuch(x, y, this, pole);
    }
    else if(status == "Srebrny Generał")
    {
        wykonano = s -> wykonajRuch(x, y, this, pole);
    }
    else if(status == "Złoty Generał")
    {
        wykonano = g -> wykonajRuch(x, y, this, pole);
    }
    else if(status == "Goniec")
    {
        wykonano = b -> wykonajRuch(x, y, this, pole);
    }
    else if(status == "Wieża")
    {
        wykonano = r -> wykonajRuch(x, y, this, pole);
    }
    else if(status == "Król")
    {
        wykonano = k -> wykonajRuch(x, y, this, pole);
    }
    if(czyJestBicie && wykonano)
    {
        if(pole.getStatusShort() == "p")
        {
            pole.p->setPromotion((Promocja)bez_promocji);
            pole.p->setChar("p");
            figury.dodaj('p', pole.p);
        }
        else if(pole.getStatusShort() == "l")
        {
            pole.l->setPromotion((Promocja)bez_promocji);
            pole.l->setChar("l");
            figury.dodaj('l', pole.l);
        }
        else if(pole.getStatusShort() == "n")
        {
            pole.n->setPromotion((Promocja)bez_promocji);
            pole.n->setChar("n");
            figury.dodaj('n', pole.n);
        }
        else if(pole.getStatusShort() == "s")
        {
            pole.s->setPromotion((Promocja)bez_promocji);
            pole.s->setChar("s");
            figury.dodaj('s', pole.s);
        }
        else if(pole.getStatusShort() == "g")
        {
            pole.g->setPromotion((Promocja)bez_promocji);
            pole.g->setChar("g");
            figury.dodaj('g', pole.g);
        }
        else if(pole.getStatusShort() == "b")
        {
            pole.b->setPromotion((Promocja)bez_promocji);
            pole.b->setChar("b");
            figury.dodaj('b', pole.b);
        }
        else if(pole.getStatusShort() == "r")
        {
            pole.r->setPromotion((Promocja)bez_promocji);
            pole.r->setChar("r");
            figury.dodaj('r', pole.r);
        }
        else if(pole.getStatusShort() == "k")
        {
            wstaw_tekst(10,10,"Hurra! Koniec gry!","Green");
            pole.k->setPromotion((Promocja)bez_promocji);
            pole.k->setChar("k");
            figury.dodaj('k', pole.k);
        }
    }
    if(wykonano)
    {
            pole.status_short = status_short;
            pole.status = status;
            status = "";
            if(pole.status == "Pionek")
                pole.p = p;
            if(pole.status == "Lanca")
                pole.l = l;
            if(pole.status == "Skoczek");
                pole.n = n;
            if(pole.status == "Srebrny Generał")
                pole.s = s;
            if(pole.status == "Złoty Generał")
                pole.g = g;
            if(pole.status == "Goniec")
                pole.b = b;
            if(pole.status == "Wieża")
                pole.r = r;
            if(pole.status == "Król")
                pole.k = k;
    }
    return wykonano;
}
Gracz Pole::getGracz()
{

    if(status == "Pionek")
        return p->getPlayer();
    else if(status == "Lanca")
        return l->getPlayer();
    else if(status == "Skoczek")
        return n->getPlayer();
    else if(status == "Srebrny Generał")
        return s->getPlayer();
    else if(status == "Złoty Generał")
        return g->getPlayer();
    else if(status == "Goniec")
        return b->getPlayer();
    else if(status == "Wieża")
        return r->getPlayer();
    else if(status == "Król")
        return k->getPlayer();
    else return brak;
}
