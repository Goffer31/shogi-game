#ifndef FIGURYGRACZA_H
#define FIGURYGRACZA_H
#include "../naglowek.h"

class FiguryGracza
{
    public:
        FiguryGracza();
        virtual ~FiguryGracza();
        void dodaj(char x, Pionek *_p);
        void dodaj(char x, dGeneral *_g);
        void dodaj(char x, Lanca *_l);
        void dodaj(char x, Skoczek *_n);
        void dodaj(char x, mGeneral *_s);
        void dodaj(char x, Goniec *_b);
        void dodaj(char x, Wieza *_r);
        void dodaj(char x, Krol *_k);
        Pionek* usun(char x, Pionek *pp);
        dGeneral* usun(char x, dGeneral *gg);
        Lanca* usun(char x, Lanca *ll);
        Skoczek* usun(char x, Skoczek *nn);
        mGeneral* usun(char x, mGeneral *ss);
        Goniec* usun(char x, Goniec *bb);
        Wieza* usun(char x, Wieza *rr);
        Krol* usun(char x, Krol *kk);
        void wypisz();
        bool sprawdz(char x);
    protected:
    private:
        char figury[40];
        Pionek* p[18];
        Lanca* l[4];
        Skoczek* n[4];
        mGeneral* s[4];
        dGeneral* g[4];
        Goniec* b[2];
        Wieza *r[2];
        Krol *k[2];
};

#endif // FIGURYGRACZA_H
