#include <iostream>
#include <stdio.h>
#include <string>
#include "naglowek.h"
#include "pole.h"
#include "pionek.h"
#include "figura.h"
#include <unistd.h>
#include "include/FiguryGracza.h"
#include "lanca.h"
#include <string>
#include <sstream>
#include <iostream>
#include "skoczek.h"
#include "malygeneral.h"
#include "duzygeneral.h"
#include "goniec.h"
#include "wieza.h"
#include "krol.h"
#include <fstream>
#include <cstdlib>

using namespace std;

#if defined (__WIN32) || defined (__WIN32__)
#define A 5
#include <windows.h>
void gotoxy(short int x, short int y) {
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}
void wstaw_tekst(unsigned int x, unsigned int y, string s)
{
    gotoxy(x, y);
    cout<<s;
}
#endif // defined
#if defined (__unix__) || defined (__unix)
#define A 6
void wstaw_tekst(unsigned int x, unsigned int y, string s, string kolor = "Default")
{
    stringstream ss;
    string s2;
    if(kolor == "Default")
        s2 = "\033[39m";
    else if(kolor == "Red")
        s2 = "\033[31m";
    else if(kolor == "Green")
        s2 = "\033[32m";
    else if(kolor == "Yellow")
        s2 = "\033[33m";
    else if(kolor == "Blue")
        s2 = "\033[34m";
    else
        s2 = "\033[97m";
    ss<<"\033["<<y<<";"<<x<<"H"<<s2<<s;
    cout<<ss.str();
}
void ustaw_kolor(string kolor)
{
    stringstream ss;
    string s;
    if(kolor == "Black")
        s = "\033[40m";
    else if(kolor == "Red")
        s = "\033[41m";
    else if(kolor == "Green")
        s = "\033[42m";
    else if(kolor == "Yellow")
        s= "\033[43m";
    else
        s = "\033[107m";
    ss<<"Default \033[31mRed";
    cout<<s;
}
#endif // defined

void rysuj_szachownice()
{
    for(int i = 0; i < 20; i++)
    {
        wstaw_tekst(0,i,"                                         ","Blue");
    }
    for(int i = 0; i < 9; i++)
    {
        if(i == 0)
            wstaw_tekst(2*i+4,3,"1","Yellow");
        else if(i == 1)
            wstaw_tekst(2*i+4,3,"2","Yellow");
        else if(i == 2)
            wstaw_tekst(2*i+4,3,"3","Yellow");
        else if(i == 3)
            wstaw_tekst(2*i+4,3,"4","Yellow");
        else if(i == 4)
            wstaw_tekst(2*i+4,3,"5","Yellow");
        else if(i == 5)
            wstaw_tekst(2*i+4,3,"6","Yellow");
        else if(i == 6)
            wstaw_tekst(2*i+4,3,"7","Yellow");
        else if(i == 7)
            wstaw_tekst(2*i+4,3,"8","Yellow");
        else if(i == 8)
            wstaw_tekst(2*i+4,3,"9","Yellow");
    }
    for(int i = 0; i < 9; i++)
    {
        if(i == 0)
            wstaw_tekst(2,2*i+4,"A","Yellow");
        else if(i == 1)
            wstaw_tekst(2,2*i+4,"B","Yellow");
        else if(i == 2)
            wstaw_tekst(2,2*i+4,"C","Yellow");
        else if(i == 3)
            wstaw_tekst(2,2*i+4,"D","Yellow");
        else if(i == 4)
            wstaw_tekst(2,2*i+4,"E","Yellow");
        else if(i == 5)
            wstaw_tekst(2,2*i+4,"F","Yellow");
        else if(i == 6)
            wstaw_tekst(2,2*i+4,"G","Yellow");
        else if(i == 7)
            wstaw_tekst(2,2*i+4,"H","Yellow");
        else if(i == 8)
            wstaw_tekst(2,2*i+4,"I","Yellow");
    }
    for(int i = 1; i < 18; i++)
        for(int j = 1; j < 18; j++)
        {
            if(j%2 == 0)wstaw_tekst(i+3,j+3,"-","Yellow");
            else if(i%2 == 0)wstaw_tekst(i+3,j+3,"|","Yellow");
        }

}

bool symulujKolizje(Pole wyjscie[8], string figura, int ileElementow)
{
    int i = 0;
    while(i<ileElementow)
    {
        cout<<wyjscie[i].getGracz()<<endl;
        if(wyjscie[i].getGracz() != 0)
            return true;
        i++;
    }
    return false;
}

std::string menu()
{
    std::string wybor;
    wstaw_tekst(3,3,"1. Nowa gra","Yellow");
    wstaw_tekst(3,4,"2. Wczytaj gre","Yellow");
    wstaw_tekst(3,5,"3. Wczytaj powtorke", "Yellow");
    wstaw_tekst(3,6,"4. Wyjdz z gry","Yellow");
    wstaw_tekst(3,7,"","Yellow");
    cin>>wybor;
    if(wybor == "1")
        wybor = "Reczny";
    if(wybor == "2")
        wybor = "AutomatSzybki";
    if(wybor == "3")
        wybor = "AutomatWolny";
    if(wybor == "4")
        exit(0);
    return wybor;
}

int main()
{
    bool kolizja;
    string tryb = menu();
    rysuj_szachownice();
	Pole **pole;
	pole = new Pole*[9];
	char wybor[4];
	for(int i = 0; i<9; i++)
        pole[i] = new Pole[9];
    for(int i = 0; i<9; i++)
        for(int j=0; j<9; j++)
        {
            pole[i][j].setx(i);
            pole[i][j].sety(j);
        }
    Pionek *p11 = new Pionek(pole[0][2],gracz1);
    pole[0][2].setFigura(p11);
    Pionek *p12 = new Pionek(pole[1][2],gracz1);
    pole[1][2].setFigura(p12);
    Pionek *p13 = new Pionek(pole[2][2],gracz1);
    pole[2][2].setFigura(p13);
    Pionek *p14 = new Pionek(pole[3][2],gracz1);
    pole[3][2].setFigura(p14);
    Pionek *p15 = new Pionek(pole[4][2],gracz1);
    pole[4][2].setFigura(p15);
    Pionek *p16 = new Pionek(pole[5][2],gracz1);
    pole[5][2].setFigura(p16);
    Pionek *p17 = new Pionek(pole[6][2],gracz1);
    pole[6][2].setFigura(p17);
    Pionek *p18 = new Pionek(pole[7][2],gracz1);
    pole[7][2].setFigura(p18);
    Pionek *p19 = new Pionek(pole[8][2],gracz1);
    pole[8][2].setFigura(p19);
    Pionek *p21 = new Pionek(pole[0][6],gracz2);
    pole[0][6].setFigura(p21);
    Pionek *p22 = new Pionek(pole[1][6],gracz2);
    pole[1][6].setFigura(p22);
    Pionek *p23 = new Pionek(pole[2][6],gracz2);
    pole[2][6].setFigura(p23);
    Pionek *p24 = new Pionek(pole[3][6],gracz2);
    pole[3][6].setFigura(p24);
    Pionek *p25 = new Pionek(pole[4][6],gracz2);
    pole[4][6].setFigura(p25);
    Pionek *p26 = new Pionek(pole[5][6],gracz2);
    pole[5][6].setFigura(p26);
    Pionek *p27 = new Pionek(pole[6][6],gracz2);
    pole[6][6].setFigura(p27);
    Pionek *p28 = new Pionek(pole[7][6],gracz2);
    pole[7][6].setFigura(p28);
    Pionek *p29 = new Pionek(pole[8][6],gracz2);
    pole[8][6].setFigura(p29);
    Lanca *l11 = new Lanca(pole[0][0],gracz1);
    pole[0][0].setFigura(l11);
    Lanca *l12 = new Lanca(pole[8][0],gracz1);
    pole[8][0].setFigura(l12);
    Lanca *l21 = new Lanca(pole[0][8],gracz2);
    pole[0][8].setFigura(l21);
    Lanca *l22 = new Lanca(pole[8][8],gracz2);
    pole[8][8].setFigura(l22);

    Skoczek *n11 = new Skoczek(pole[1][0],gracz1);
    pole[1][0].setFigura(n11);
    Skoczek *n12 = new Skoczek(pole[7][0],gracz1);
    pole[7][0].setFigura(n12);
    Skoczek *n21 = new Skoczek(pole[1][8],gracz2);
    pole[1][8].setFigura(n21);
    Skoczek *n22 = new Skoczek(pole[7][8],gracz2);
    pole[7][8].setFigura(n22);

    mGeneral *s11 = new mGeneral(pole[2][0],gracz1);
    pole[2][0].setFigura(s11);
    mGeneral *s12 = new mGeneral(pole[6][0],gracz1);
    pole[6][0].setFigura(s12);
    mGeneral *s21 = new mGeneral(pole[2][8],gracz2);
    pole[2][8].setFigura(s21);
    mGeneral *s22 = new mGeneral(pole[6][8],gracz2);
    pole[6][8].setFigura(s22);

    dGeneral *g11 = new dGeneral(pole[3][0],gracz1);
    pole[3][0].setFigura(g11);
    dGeneral *g12 = new dGeneral(pole[5][0],gracz1);
    pole[5][0].setFigura(g12);
    dGeneral *g21 = new dGeneral(pole[3][8],gracz2);
    pole[3][8].setFigura(g21);
    dGeneral *g22 = new dGeneral(pole[5][8],gracz2);
    pole[5][8].setFigura(g22);

    Goniec *b1 = new Goniec(pole[7][1],gracz1);
    pole[7][1].setFigura(b1);
    Goniec *b2 = new Goniec(pole[1][7],gracz2);
    pole[1][7].setFigura(b2);

    Wieza *r1 = new Wieza(pole[1][1],gracz1);
    pole[1][1].setFigura(r1);
    Wieza *r2 = new Wieza(pole[7][7],gracz2);
    pole[7][7].setFigura(r2);

    Krol *k1 = new Krol(pole[4][0],gracz1);
    pole[4][0].setFigura(k1);
    Krol *k2 = new Krol(pole[4][8],gracz2);
    pole[4][8].setFigura(k2);

    FiguryGracza figuryGracza1;
    FiguryGracza figuryGracza2;
    Gracz ruchGracza = gracz1;
    fstream zapis;
        if(tryb == "Reczny")
            zapis.open("zapis.txt",ios::out);
        if(tryb != "Reczny")
            zapis.open("zapis.txt",ios::in);
    while(1)
    {

        wstaw_tekst(25,5,"Figury gracza 1:","Green");
        wstaw_tekst(25,6,"                      ","Green");
        wstaw_tekst(25,6,"");
        figuryGracza1.wypisz();
        wstaw_tekst(25,8,"Figury gracza 2:","Green");
        wstaw_tekst(25,9,"                      ","Green");
        wstaw_tekst(25,9,"","Green");
        figuryGracza2.wypisz();
        int i1,j1,i2,j2;
        string ktoryGracz;
        ruchGracza == gracz1 ? ktoryGracz = "1" : ktoryGracz = "2";
        wstaw_tekst(25,19,"Ruch wykonuje gracz "+ktoryGracz,"Green");
        wstaw_tekst(25,20,"          ","Green");
        wstaw_tekst(25,20,"","Green");
        if(tryb == "Reczny")
        {
            cin>>wybor;
            zapis<<wybor[0]<<wybor[1]<<wybor[2]<<wybor[3]<<endl;
        }
        if(tryb != "Reczny")
        {
            zapis>>wybor;
            if(tryb == "AutomatWolny")
                sleep(1);
            if(zapis.eof())
            {
                zapis.close();
                zapis.open("zapis.txt",ios::out | ios::app);
                tryb = "Reczny";
            }
        }

        if(wybor[0]>='A' && wybor[0] <= 'I')
            j1 = wybor[0]-'A';
        if(wybor[0] >= '1' && wybor[0] <= '9')
            i1 = wybor[0]-'1';
        if(wybor[1]>='A' && wybor[1] <= 'I')
            j1 = wybor[1]-'A';
        if(wybor[1] >= '1' && wybor[1] <= '9')
            i1 = wybor[1]-'1';

        if(wybor[2]>='A' && wybor[2] <= 'I')
            j2 = wybor[2]-'A';
        if(wybor[2] >= '1' && wybor[2] <= '9')
            i2 = wybor[2]-'1';
        if(wybor[3]>='A' && wybor[3] <= 'I')
            j2 = wybor[1]-'A';
        if(wybor[3] >= '1' && wybor[3] <= '9')
            i2 = wybor[3]-'1';
        if(wybor[0] >= 'a' && wybor[0] <='z')
        {
            if(wybor[1]>='A' && wybor[1] <= 'I')
                j2 = wybor[1]-'A';
            if(wybor[1] >= '1' && wybor[1] <= '9')
                i2 = wybor[2]-'1';
            if(wybor[2]>='A' && wybor[2] <= 'I')
                j2 = wybor[1]-'A';
            if(wybor[2] >= '1' && wybor[2] <= '9')
                i2 = wybor[2]-'1';
            if(pole[i2][j2].getStatus()=="")
            {
                bool wykonaj;
                if(ruchGracza == gracz1)
                    wykonaj = figuryGracza1.sprawdz(wybor[0]);
                else wykonaj = figuryGracza2.sprawdz(wybor[0]);
                if(wybor[0] == 'p' && wykonaj)
                {
                    Pionek *as = new Pionek();
                    if(ruchGracza == gracz1)
                    {
                        pole[i2][j2].setFigura(figuryGracza1.usun(wybor[0],as));
                    }
                    if(ruchGracza == gracz2)
                        pole[i2][j2].setFigura(figuryGracza2.usun(wybor[0],as));
                        pole[i2][j2].narysuj(pole[i2][j2].getStatusShort(),ruchGracza);
                    delete as;
                }
                if(wybor[0] == 'l' && wykonaj)
                {
                    Lanca *as = new Lanca();
                    if(ruchGracza == gracz1)
                    {
                        pole[i2][j2].setFigura(figuryGracza1.usun(wybor[0],as));
                    }
                    if(ruchGracza == gracz2)
                        pole[i2][j2].setFigura(figuryGracza2.usun(wybor[0],as));
                        pole[i2][j2].narysuj(pole[i2][j2].getStatusShort(),ruchGracza);
                    delete as;
                }
                if(wybor[0] == 'n' && wykonaj)
                {
                    Skoczek *as = new Skoczek();
                    if(ruchGracza == gracz1)
                    {
                        pole[i2][j2].setFigura(figuryGracza1.usun(wybor[0],as));
                    }
                    if(ruchGracza == gracz2)
                        pole[i2][j2].setFigura(figuryGracza2.usun(wybor[0],as));
                        pole[i2][j2].narysuj(pole[i2][j2].getStatusShort(),ruchGracza);
                    delete as;
                }
                if(wybor[0] == 's' && wykonaj)
                {
                    mGeneral *as = new mGeneral();
                    if(ruchGracza == gracz1)
                    {
                        pole[i2][j2].setFigura(figuryGracza1.usun(wybor[0],as));
                    }
                    if(ruchGracza == gracz2)
                        pole[i2][j2].setFigura(figuryGracza2.usun(wybor[0],as));
                        pole[i2][j2].narysuj(pole[i2][j2].getStatusShort(),ruchGracza);
                    delete as;
                }
                if(wybor[0] == 'g' && wykonaj)
                {
                    dGeneral *as = new dGeneral();
                    if(ruchGracza == gracz1)
                    {
                        pole[i2][j2].setFigura(figuryGracza1.usun(wybor[0],as));
                    }
                    if(ruchGracza == gracz2)
                        pole[i2][j2].setFigura(figuryGracza2.usun(wybor[0],as));
                        pole[i2][j2].narysuj(pole[i2][j2].getStatusShort(),ruchGracza);
                    delete as;
                }
                if(wybor[0] == 'b' && wykonaj)
                {
                    Goniec *as = new Goniec();
                    if(ruchGracza == gracz1)
                    {
                        pole[i2][j2].setFigura(figuryGracza1.usun(wybor[0],as));
                    }
                    if(ruchGracza == gracz2)
                        pole[i2][j2].setFigura(figuryGracza2.usun(wybor[0],as));
                        pole[i2][j2].narysuj(pole[i2][j2].getStatusShort(),ruchGracza);
                    delete as;
                }
                if(wybor[0] == 'r' && wykonaj)
                {
                    Wieza *as = new Wieza();
                    if(ruchGracza == gracz1)
                    {
                        pole[i2][j2].setFigura(figuryGracza1.usun(wybor[0],as));

                    }
                    if(ruchGracza == gracz2)
                        pole[i2][j2].setFigura(figuryGracza2.usun(wybor[0],as));
                        pole[i2][j2].narysuj(pole[i2][j2].getStatusShort(),ruchGracza);
                    delete as;
                }
                if(wybor[0] == 'k' && wykonaj)
                {
                    Krol *as = new Krol();
                    if(ruchGracza == gracz1)
                    {
                        pole[i2][j2].setFigura(figuryGracza1.usun(wybor[0],as));

                    }
                    if(ruchGracza == gracz2)
                        pole[i2][j2].setFigura(figuryGracza2.usun(wybor[0],as));
                        pole[i2][j2].narysuj(pole[i2][j2].getStatusShort(),ruchGracza);
                    delete as;
                }
                if(ruchGracza == gracz1 && wykonaj)
                    ruchGracza = gracz2;
                else if(ruchGracza == gracz2 && wykonaj)
                    ruchGracza = gracz1;
            }
            continue;
        }
        kolizja = false;
        if(pole[i1][j1].getStatus()=="Wieża" || pole[i1][j1].getStatus()=="Lanca")
        {
            int Dl = i1-i2+j1-j2;
            if(Dl < 0)Dl *= -1;
            Pole xyz[Dl-1];
            int iDl = i2-i1;
            int jDl = j2-j1;
            bool czyWykonac = true;
            if(iDl != 0 && jDl != 0)
                czyWykonac = false;
            int j=0;
            if(czyWykonac)
            {
                if(iDl > 0)
                    for(int i = i1+1; i < i2; i++)
                    {
                        xyz[j]=pole[i][j1];
                        if(pole[i][j1].getGracz()!=0)
                        {
                            kolizja = true;
                        }
                        j++;

                    }
                if(iDl < 0)
                    for(int i = i1-1; i > i2; i--)
                    {
                        xyz[j]=pole[i][j1];
                        if(pole[i][j1].getGracz()!=0)
                        {
                            kolizja = true;
                        }
                        j++;
                    }
                if(jDl > 0)
                    for(int i = j1+1; i < j2; i++)
                    {
                        xyz[j]=pole[i1][i];
                        if(pole[i1][i].getGracz()!=0)
                        {
                            kolizja = true;
                        }
                        j++;
                    }
                if(jDl < 0)
                    for(int i = j1-1; i > j2; i--)
                    {
                        xyz[j]=pole[i1][i];
                        if(pole[i1][i].getGracz()!=0)
                        {
                            kolizja = true;
                        }
                        j++;
                    }
            }
            //kolizja = symulujKolizje(xyz,"Wieża",jDl+iDl-1);
        }
        if(pole[i1][j1].getStatus()=="Goniec")
        {
            int iDl1 = (i1-i2);
            int jDl1 = (j1-j2);
            if(iDl1 < 0)iDl1 *= -1;
            if(jDl1 < 0)jDl1 *= -1;
            int Dl = iDl1+jDl1;
            Dl = Dl/2;
            if(Dl < 0)Dl *= -1;
            Pole xyz[Dl-1];
            int iDl = i2-i1;
            int jDl = j2-j1;
            int j=0;
            cout<<Dl;
            //if(iDl != jDl)
            //    break;
            if(iDl > 0 && jDl > 0)
                for(int i = i1+1; i < i2; i++)
                {
                    int z = j1+j+1;
                        xyz[j]=pole[i][z];

                        j++;
                }
            if(iDl < 0 && jDl > 0)
                for(int i = i1-1; i > i2; i--)
                {
                    int z = j1+j+1;
                        xyz[j]=pole[i][z];
                        j++;
                }
            if(iDl > 0 && jDl < 0)
                for(int i = i1+1; i < i2; i++)
                {
                        int z = j1-j-1;
                        xyz[j]=pole[i][z];
                        j++;
                }
            if(iDl < 0 && jDl < 0)
                for(int i = i1-1; i > i2; i--)
                {
                        int z = j1-j1-1;
                        xyz[j]=pole[i][z];
                        j++;
                }

            kolizja = symulujKolizje(xyz,"Goniec",Dl);
        }
        if(!kolizja)
        {
            if(ruchGracza == pole[i1][j1].getGracz() && ruchGracza == gracz1 && pole[i2][j2].getGracz() != ruchGracza)
            {
                if(pole[i1][j1].wykonajRuch(i2,j2,pole[i2][j2],figuryGracza1,ruchGracza))
                    ruchGracza = gracz2;
            }
            if(ruchGracza == pole[i1][j1].getGracz() && ruchGracza == gracz2 && pole[i2][j2].getGracz() != ruchGracza)
            {
                if(pole[i1][j1].wykonajRuch(i2,j2,pole[i2][j2],figuryGracza2,ruchGracza))
                    ruchGracza = gracz1;
            }
        }

    }
	return 0;
}
