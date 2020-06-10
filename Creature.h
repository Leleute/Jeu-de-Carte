#ifndef DEF_CREATURE
#define DEF_CREATURE

#include <iostream>

#include "Carte.h"
#include "Action.h"
#include "Attaque.h"
#include "Defense.h"

using namespace std;

///CLASSE FILLE DE CARTE

class Creature : public Carte
{
protected :
    int m_vie;
    int m_def;

    //int m_point_de_terrain pour chaque terrain;
    int m_vitA;
    int m_vitB;
    int m_vitC;
    int m_vitD;

    //ajout d'un coefficient d'attaque pour ne pas avoir à gérer les m_degats dans attaque pour la carte spéciale BoostDegat
    int m_coeff_degat;

    Attaque* m_atk1;
    Attaque* m_atk2;  //IMPLIQUE UNE CLASSE ACTION, ayant pour classes filles ATTAQUE et DEFENSE, avec en attibuts communs nom, description, degats(occasionnés ou réduits)
    Defense* m_def1; //Au moins une defense, ou à rajouter en fonction des cartes

    bool m_renvoi = false; ///de base, aucun renvoi

    bool m_atk_ok;
    bool m_skip = false;

public :
    Creature();
    Creature(string _nom, string _desc, string _typedecarte,int _vie, int _def, int _vitA, int _vitB, int _vitC, int _vitD, int _coeff_degat, Attaque* _atk1, Attaque* _atk2, Defense* _def1);

    ~Creature();

    //Méthodes
    void attaque_un(Carte* cible);
    void attaque_deux(Carte* cible);
    void recevoirDegat(int degat, int coeff_degat);
    void seDefendre();

    void recevoirBoostTerrain(string _type);

    //void recevoirActionSpeciale();
    virtual void recevoirBoostVie();
    virtual void recevoirBoostDegat();
    virtual void recevoirEvolution();
    virtual void activerRenvoi();
    virtual void desactiverRenvoi();
    ///RESTE DEUX METHODES SPECIALES A CODER

    //getters
    bool getRenvoi() const;
    int getVie() const;
    Attaque* getAttaque_un() const;
    Attaque* getAttaque_deux() const;
    Defense* getDefense_un() const;

    virtual bool getAtk_ok() const;
    virtual int getVitA() const;
    virtual int getVitB() const;
    virtual int getVitC() const;
    virtual int getVitD() const;

    virtual void setVie(int vie);

    virtual void SetAtk_ok(bool test);
    virtual void SetVitA(int vit);
    virtual void SetVitB(int vit);
    virtual void SetVitC(int vit);
    virtual void SetVitD(int vit);

    void recevoirPasserTour();
    void setSkipFalse();

    bool getSkip() const;
};

///CARTES DE TYPE CREATURE, QUI HERITENT TOUS DE Creature

class Coeur : public Creature
{
private :
public :
    Coeur();
    ~Coeur();
};

class Poumon : public Creature
{
private :
public :
    Poumon();
    ~Poumon();
};

class Foie : public Creature
{
private :
public :
    Foie();
    ~Foie();
};

class Pancreas : public Creature
{
private :
public :
    Pancreas();
    ~Pancreas();
};

class Rein : public Creature
{
private :
public :
    Rein();
    ~Rein();
};

class Cerveau : public Creature
{
private :
public :
    Cerveau();
    ~Cerveau();
};

#endif // DEF_CREATURE
