#ifndef A4
#define A4
#include <string>

void wstaw_tekst(unsigned int x, unsigned int y, std::string s,std::string kolor);

enum Promocja{
bez_promocji,
promocja
};
enum Gracz{
gracz1 = 1,
gracz2 = -1,
brak = 0
};

class Pole;
class Figura;
class Pionek;
class Lanca;
class Skoczek;
class mGeneral;
class dGeneral;
class Goniec;
class Wieza;
class Krol;
#endif
