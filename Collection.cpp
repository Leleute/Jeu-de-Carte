#include "Collection.h"
#include "Creature.h"
#include "Special.h"
#include "Terrain.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>

Collection::Collection()
{

}

Collection::~Collection()
{

}

void Collection::Setcollection(vector<string> nomcarte )
{
    Carte* c1 = new Coeur;
    Carte* c2 = new Poumon;
    Carte* c3 = new Foie;
    Carte* c4 = new Pancreas;
    Carte* c5 = new Rein;
    Carte* c6 = new Cerveau;
    Carte* c7 = new BoostVie;
    Carte* c8 = new BoostDegat;
    Carte* c9 = new PasserTour ;
    Carte* c10 = new Renvoi;
    Carte* c11 = new Evolution;
    Carte* c12 = new Retinol;
    Carte* c13 = new Tretinoine;
    Carte* c14 = new VitB1;
    Carte* c15 = new VitB2;
    Carte* c16 = new AcideAscorbique;
    Carte* c17 = new Calciferol;
    Carte* c18 = new Any;

    vector<Carte*>*save = new vector<Carte*>;

    for(auto &el:nomcarte)
    {
        if(el == "Coeur")
        {
            save->push_back(c1);
        }
        if(el == "Poumon")
        {
            save->push_back(c2);
        }
        if(el == "Foie")
        {
            save->push_back(c3);
        }
        if(el == "Pancreas")
        {
            save->push_back(c4);
        }
        if(el == "Rein")
        {
            save->push_back(c5);
        }
        if(el == "Cerveau")
        {
            save->push_back(c6);
        }
        if(el == "Boost_de_Vie")
        {
            save->push_back(c7);
        }
        if(el == "Boost_de_degat")
        {
            save->push_back(c8);
        }
        if(el == "Passe_ton_tour")
        {
            save->push_back(c9);
        }
        if(el == "Renvoi_de_degat")
        {
            save->push_back(c10);
        }
        if(el == "Evolution")
        {
            save->push_back(c11);
        }
        if(el == "Retinol")
        {
            save->push_back(c12);
        }
        if(el == "Tretinoine")
        {
            save->push_back(c13);
        }
        if(el == "VitamineB1")
        {
            save->push_back(c14);
        }
        if(el == "VitamineB2")
        {
            save->push_back(c15);
        }
        if(el == "Acide_L-ascorbique")
        {
            save->push_back(c16);
        }
        if(el == "Calciferol")
        {
            save->push_back(c17);
        }
        if(el == "Vitamine_universelle")
        {
            save->push_back(c18);
        }
    }
    m_collection = *save;
}

void Collection::Setdeck(vector<string> nomcarte )
{
    Carte* c1 = new Coeur;
    Carte* c2 = new Poumon;
    Carte* c3 = new Foie;
    Carte* c4 = new Pancreas;
    Carte* c5 = new Rein;
    Carte* c6 = new Cerveau;
    Carte* c7 = new BoostVie;
    Carte* c8 = new BoostDegat;
    Carte* c9 = new PasserTour ;
    Carte* c10 = new Renvoi;
    Carte* c11 = new Evolution;
    Carte* c12 = new Retinol;
    Carte* c13 = new Tretinoine;
    Carte* c14 = new VitB1;
    Carte* c15 = new VitB2;
    Carte* c16 = new AcideAscorbique;
    Carte* c17 = new Calciferol;
    Carte* c18 = new Any;

    vector<Carte*>*save = new vector<Carte*>;

    for(auto &el:nomcarte)
    {
        if(el == "Coeur")
        {
            save->push_back(c1);
        }
        if(el == "Poumon")
        {
            save->push_back(c2);
        }
        if(el == "Foie")
        {
            save->push_back(c3);
        }
        if(el == "Pancreas")
        {
            save->push_back(c4);
        }
        if(el == "Rein")
        {
            save->push_back(c5);
        }
        if(el == "Cerveau")
        {
            save->push_back(c6);
        }
        if(el == "Boost_de_Vie")
        {
            save->push_back(c7);
        }
        if(el == "Boost_de_degat")
        {
            save->push_back(c8);
        }
        if(el == "Passe_ton_tour")
        {
            save->push_back(c9);
        }
        if(el == "Renvoi_de_degat")
        {
            save->push_back(c10);
        }
        if(el == "Evolution")
        {
            save->push_back(c11);
        }
        if(el == "Retinol")
        {
            save->push_back(c12);
        }
        if(el == "Tretinoine")
        {
            save->push_back(c13);
        }
        if(el == "VitamineB1")
        {
            save->push_back(c14);
        }
        if(el == "VitamineB2")
        {
            save->push_back(c15);
        }
        if(el == "Acide_L-ascorbique")
        {
            save->push_back(c16);
        }
        if(el == "Calciferol")
        {
            save->push_back(c17);
        }
        if(el == "Vitamine_universelle")
        {
            save->push_back(c18);
        }
    }
    m_deck = *save;
}


void Collection::Constdeck(int tab[21])
{
    for(int i=0; i<21; i++)
    {
        this->m_deck.push_back(m_collection[tab[i]]);
    }
}


vector<Carte*> Collection::GetCollection() const
{
    return m_collection;
}

vector<Carte*> Collection::GetDeck() const
{
    return m_deck;
}

void Collection::Ajoutcartecolec(Carte* carteajout)
{

    m_collection.push_back(carteajout);

}

void Collection::Ajoutcartedeck(Carte* carteajout)
{

    m_deck.push_back(carteajout);

}

void Collection::Retirercartecolec(Carte* carteretirer)
{
    int cpt = 0;
    for (auto &el:m_collection)
    {
        if(el->getNom() == carteretirer->getNom())
        {

            el = m_collection.back();
            m_collection.back()=carteretirer;
            cpt = 1;
        }
    }
    if (cpt == 1)m_collection.pop_back();
    else cout<<"Cette carte n'est pas dans votre collection"<<endl;

}

void Collection::detruiredeck()
{
    for (int i = 0; i<21 ; i++) m_deck.pop_back();

}

void Collection::Retirercartedeck(Carte* carteretirer)
{
    int cpt = 0;
    for (auto &el:m_deck)
    {
        if(el->getNom() == carteretirer->getNom())
        {

            el = m_deck.back();
            m_deck.back()=carteretirer;
            cpt = 1;
        }
    }
    if (cpt == 1)m_deck.pop_back();
    else cout<<"Cette carte n'est pas dans votre collection"<<endl;

}

void Collection::melangerDeck()
{
    srand(time == NULL);
    random_shuffle(m_deck.begin(),m_deck.end());
}


