#include "Special.h"
///CLASSE SPACIAL
Special::Special() : Carte() {}

Special::Special(string _nom, string _desc,string _typedecarte, bool _cdv, bool _recyclable)
    : Carte(_nom, _desc,_typedecarte), m_cdv(_cdv), m_recyclable(_recyclable) {}

Special::~Special() {}

void Special::actionSpeciale(Carte* cible)
{
    if("Boost_de_Vie" == this->m_nom)
    {
        cible->recevoirBoostVie();
    }
    else if("Boost_de_degat" == this->m_nom)
    {
        cible->recevoirBoostDegat();
    }
    else if("Evolution" == this->m_nom)
    {
        cible->recevoirEvolution();
    }
    else if("Renvoi_de_degat" == this->m_nom)
    {
        cible->activerRenvoi();
    }
    else if("Passe_ton_tour" == this->m_nom)
    {
        cible->recevoirPasserTour();
    }
}

///CLASSES QUI EN HERITENT
//Boost_de_Vie
BoostVie::BoostVie() : Special("Boost_de_Vie", "Augmente la vie de l'organe actif de 50%.","Special", false, true)
{
}
BoostVie::~BoostVie()
{
}
//Boost_de_degat
BoostDegat::BoostDegat() : Special("Boost_de_degat", "Multiplie par deux les degats de l'organe actif lors de la prochaine attaque.","Special", false, true)
{
}
BoostDegat::~BoostDegat()
{
}
//Passer son tour
PasserTour::PasserTour() : Special("Passe_ton_tour", "Le joueur adverse passe son tour.","Special", false, false)
{
}
PasserTour::~PasserTour()
{
}
//Renvoi
Renvoi::Renvoi() : Special("Renvoi_de_degat", "Renvoit les degats de la prochaine attaque ennemie.","Special", true, false)
{
}
Renvoi::~Renvoi()
{
}
//Evolution
Evolution::Evolution() : Special("Evolution", "Augmente la vie et les degats des attaques de l organe active en l'evoluant.","Special", true, false)
{
}
Evolution::~Evolution()
{
}
bool Special::getRecyclable() const
{
    return m_recyclable;
}
