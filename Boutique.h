#ifndef DEF_BOUTIQUE
#define DEF_BOUTIQUE

#include <iostream>
#include "Personne.h"
#include "Carte.h"
#include <vector>



using namespace std;

class Boutique
{
protected :
    Personne* m_joueur;
    vector<Carte*> m_listedescartes;

public :
    Boutique();
    ~Boutique();

    void achetercarte(Personne* joueur,string carte_btq);
};
#endif // DEF_BOUTIQUE
