#include "Carte.h"

Carte::Carte()
    : m_nom("SansNom"), m_desc("SansDescription"), m_etat(0)
{

}

Carte::Carte(string _nom, string _desc, string _typedecarte)
    : m_nom(_nom), m_desc(_desc), m_typedecarte(_typedecarte)
{

}

Carte::~Carte()
{
    //Vide
}

void Carte::afficher() const
{
    cout<<"Nom : "<<this->m_nom<<endl;
    cout<<"Description : "<<this->m_desc<<endl;
}

void Carte::attaque_un(Carte* cible)
{

}  /// = 0 veut dire methode virtuelle pure --> Une carte ne peut pas attaquer (c'est une créature qui le peut)
void Carte::attaque_deux(Carte* cible)
{

}
void Carte::seDefendre()
{

}
void Carte::recevoirDegat(int degat, int coeff_degat)
{

}

void Carte::boostTerrain(Carte* cible)
{

}
void Carte::recevoirBoostTerrain(string _type)
{

}

void Carte::actionSpeciale(Carte* cible)
{

}

void Carte::recevoirBoostVie()
{

}
void Carte::recevoirBoostDegat()
{

}
void Carte::recevoirEvolution()
{

}

void Carte::activerRenvoi()
{

}

bool Carte::getRecyclable() const
{

}

void Carte::desactiverRenvoi() {}

bool Carte::getRenvoi() const {}

void Carte::SetAtk_ok(bool test)
{

}

void Carte::setVie(int vie)
{

}

int Carte::getVie() const
{

}

bool Carte::getAtk_ok() const
{

}

string Carte::getNom() const
{
    return m_nom;
}
string Carte::getDesc() const
{
    return m_desc;
}

Attaque* Carte::getAttaque_un() const
{

}
Attaque* Carte::getAttaque_deux() const
{

}

Defense* Carte::getDefense_un() const
{

}

/// A rajouter
string Carte::getType() const
{
    return m_typedecarte;
}

int Carte::getVitA() const
{

}
int Carte::getVitB() const
{

}
int Carte::getVitC() const
{

}
int Carte::getVitD() const
{

}

void Carte::SetVitA()
{

}
void Carte::SetVitB()
{

}
void Carte::SetVitC()
{

}
void Carte::SetVitD()
{

}

void Carte::recevoirPasserTour() {}
void Carte::setSkipFalse() {}

bool Carte::getSkip() const {}
