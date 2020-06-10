#ifndef DEF_CARTE
#define DEF_CARTE

#include <iostream>
#include "Action.h"
#include "Attaque.h"
#include "Defense.h"


using namespace std;

class Carte ///Contient au moins une méthode virtuelle pure --> classe abstraite == on ne peut pas créer d'objet de la classe carte. On peut par contre passer par un pointeur
{
protected :
    string m_nom;
    string m_desc;
    string m_typedecarte;
    int m_etat; //0 pour dire que la carte est dans la pile, 1 pour dire qu'elle est sur le terrain DONC active, 2 pour dire qu'elle se désactive et qu'elle est dans le cimetière

public :

    Carte();
    Carte(string _nom, string _desc, string _typedecarte);

    ~Carte();

    ///Methodes
    virtual void afficher() const;

    //Methodes propres aux classes filles, -> virtual
    virtual void attaque_un(Carte* cible); /// = 0 veut dire methode virtuelle pure --> Une carte ne peut pas attaquer (c'est une créature qui le peut)
    virtual void attaque_deux(Carte* cible);
    virtual void seDefendre();
    virtual void recevoirDegat(int degat, int coeff_degat) ;

    virtual void boostTerrain(Carte* cible) ;
    virtual void recevoirBoostTerrain(string _type) ;

    virtual void actionSpeciale(Carte* cible) ;

    virtual void recevoirBoostVie();
    virtual void recevoirBoostDegat();
    virtual void recevoirEvolution();

    virtual void activerRenvoi();
    virtual void desactiverRenvoi();
    ///Coder coder passage de tour ?

    //getters
    virtual bool getRenvoi() const;
    virtual int getVie() const;
    string getNom() const;
    string getDesc() const;

    virtual void setVie(int vie);
    virtual Attaque* getAttaque_un() const;
    virtual Attaque* getAttaque_deux() const;
    virtual Defense* getDefense_un() const;
    ///a rajouter
    virtual bool getRecyclable() const;
    virtual bool getAtk_ok() const;
    virtual void SetAtk_ok(bool test);

    virtual int getVitA() const;
    virtual int getVitB() const;
    virtual int getVitC() const;
    virtual int getVitD() const;

    virtual void SetVitA() ;
    virtual void SetVitB() ;
    virtual void SetVitC() ;
    virtual void SetVitD() ;

    string getType() const;

    virtual void recevoirPasserTour();
    virtual void setSkipFalse();

    virtual bool getSkip() const;


    //setter
};

///Quand la partie commence, tous les états des cartes passent à 0 -> pas besoin de les initialiser lors du constructeur par defaut de chacun des types de carte.

#endif // DEF_CARTE
