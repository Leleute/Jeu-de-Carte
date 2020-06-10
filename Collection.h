#ifndef DEF_COLLECTION
#define DEF_COLLECTION

#include <vector>
#include <iostream>
#include "Carte.h"


using namespace std;

class Collection
{
protected :

    vector<Carte*> m_collection;
    vector <Carte*> m_deck;
    /** ///A initialiser en cas de dernier recours
        //compteurs de cartes pour la collection
        int m_B1 = 0;
        int m_B2 = 0;
        int m_C = 0;
        int m_cerveau = 0;
        int m_coeur = 0; //5
        int m_D = 0;
        int m_degat = 0;
        int m_evolution = 0;
        int m_foie = 0;
        int m_pancreas = 0;//10
        int m_passeTour = 0;
        int m_poumon = 0;
        int m_rein = 0;
        int m_renvoi = 0;
        int m_retinol = 0;//15
        int m_tretinoine = 0;
        int m_vie = 0;
        int m_any = 0; //18 -> ok

        //compteurs de cartes pour le deck
        int m_d_B1 = 0;
        int m_d_B2 = 0;
        int m_d_C = 0;
        int m_d_cerveau = 0;
        int m_d_coeur = 0; //5
        int m_d_D = 0;
        int m_d_degat = 0;
        int m_d_evolution = 0;
        int m_d_foie = 0;
        int m_d_pancreas = 0;//10
        int m_d_passeTour = 0;
        int m_d_poumon = 0;
        int m_d_rein = 0;
        int m_d_renvoi = 0;
        int m_d_retinol = 0;//15
        int m_d_tretinoine = 0;
        int m_d_vie = 0;
        int m_d_any = 0; //18 -> ok
    **/
public :
    Collection();
    ~Collection();

    void Setcollection(vector<string> colec);
    void Setdeck(vector<string> colec);


    void Constdeck(int tab[21]);

    void ChargerCollection();
    void ChargerDeck();

    vector<Carte*> GetCollection() const;
    vector<Carte*> GetDeck() const;

    void Ajoutcartecolec(Carte* carteajout);
    void Ajoutcartedeck(Carte* carteajout);
    void detruiredeck();

    void Retirercartecolec(Carte* carteretirer);
    void Retirercartedeck(Carte* carteretirer);

    void melangerDeck();
};

#endif // DEF_COLLECTION
