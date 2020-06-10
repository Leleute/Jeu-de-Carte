#ifndef DEF_TERRAIN
#define DEF_TERRAIN

#include <iostream>

#include "Carte.h"
#include "Creature.h"

using namespace std;

///CLASSE FILLE DE CARTE

class Terrain : public Carte
{
protected :
    string m_type;

public :
    Terrain();
    Terrain(string _nom, string _desc, string _type, string _typedecarte);

    ~Terrain();

    void boostTerrain(Carte* cible);
};

/// CARTES DE TYPE TERRAIN, QUI HERITENT TOUS DE Terrain
//Vitamine A
//A NOTER : Ici on aurait pu faire une classe Vitamine A, qui hérite de terrain, et dont hériteraient les classes Retinol et Tretinoine, pour ne pas écrire deux fois les mêmes méthodes. Cependant, comme les vitamines A ne sont ici qu'au
//nombre de deux, c'est plus rapide de simplement écrire la même méthode dans les deux plutot que de rajouter une classe.
//Remarque valable aussi pour la vitamine B.
class Retinol : public Terrain
{
private :

public :
    Retinol();
    ~Retinol();

};

class Tretinoine : public Terrain
{
private :
public :
    Tretinoine();
    ~Tretinoine();
};

//Vitamine B
class VitB1 : public Terrain
{
private :
public :
    VitB1();
    ~VitB1();
};

class VitB2 : public Terrain
{
private :
public :
    VitB2();
    ~VitB2();
};

//Vitamine C
class AcideAscorbique : public Terrain
{
private :
public :
    AcideAscorbique();
    ~AcideAscorbique();
};

//Vitamine D
class Calciferol : public Terrain
{
private :
public :
    Calciferol();
    ~Calciferol();
};

//Any
class Any : public Terrain
{
private :
public :
    Any();
    ~Any();
};

#endif // DEF_TERRAIN
