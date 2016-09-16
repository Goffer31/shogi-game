#ifndef A1
#define A1
#include "naglowek.h"
class Figura{
protected:
    bool status;
    Promocja s1;
    Gracz gracz;
    Pole *pole;
    std::string znak;
public:
void setPromotion(Promocja ss){s1 = ss;}
Promocja getPromotion(){return s1;}
Gracz getPlayer(){return gracz;}
void setChar(std::string _x){znak = _x;}
std::string getChar(){return znak;}
};
#endif
