#ifndef DEF_SPECIAL
#define DEF_SPECIAL

#include <iostream>

#include "Carte.h"
#include "Creature.h"

using namespace std;

///CLASSE FILLE DE CARTE

class Special : public Carte
{
protected :
    bool m_cdv; //cycle de vie mentionné dans le CDC = soit elle s'utilise pendant le tour, soit elle reste active jusqu'à la carte speciale suivante.
    bool m_recyclable; //Soit elle retourne dans le deck (en dessous) apres utilisation, soit elle va dans le cimetière

public :
    bool getRecyclable() const;
    Special();
    Special(string _nom, string _desc,string _typedecarte, bool _cdv, bool _recyclable);
    ~Special();

    virtual void actionSpeciale(Carte* cible);
};

///CARTES DE TYPE SPECIALE, QUI HERITENT TOUTES DE Special

class BoostVie : public Special
{
private :
public :
    BoostVie();
    ~BoostVie();

};

class BoostDegat : public Special
{
private :
public :
    BoostDegat();
    ~BoostDegat();

};

class PasserTour : public Special
{
private :
public :
    PasserTour();
    ~PasserTour();

};

class Renvoi : public Special
{
private :
public :
    Renvoi();
    ~Renvoi();

};

class Evolution : public Special
{
private :
public :
    Evolution();
    ~Evolution();

};

#endif // DEF_SPECIAL
