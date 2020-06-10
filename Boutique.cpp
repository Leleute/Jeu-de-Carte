#include "Boutique.h"
#include "Creature.h"
#include "Terrain.h"
#include "Special.h"
#include "Carte.h"
#include <vector>
using namespace std;


Boutique::Boutique()
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

    m_listedescartes.push_back(c1);
    m_listedescartes.push_back(c2);
    m_listedescartes.push_back(c3);
    m_listedescartes.push_back(c4);
    m_listedescartes.push_back(c5);
    m_listedescartes.push_back(c6);
    m_listedescartes.push_back(c7);
    m_listedescartes.push_back(c8);
    m_listedescartes.push_back(c9);
    m_listedescartes.push_back(c10);
    m_listedescartes.push_back(c11);
    m_listedescartes.push_back(c12);
    m_listedescartes.push_back(c13);
    m_listedescartes.push_back(c14);
    m_listedescartes.push_back(c15);
    m_listedescartes.push_back(c16);
    m_listedescartes.push_back(c17);
    m_listedescartes.push_back(c18);
}

Boutique::~Boutique()
{

}

void Boutique::achetercarte(Personne* joueur,string carte_btq)
{
    Carte* coeur = new Coeur;
    Carte* poumon = new Poumon;
    Carte* foie = new Foie;
    Carte* pancreas = new Pancreas;
    Carte* rein = new Rein;
    Carte* cerveau = new Cerveau;
    Carte* boostVie = new BoostVie;
    Carte* boostDegat = new BoostDegat;
    Carte* passerTour = new PasserTour ;
    Carte* renvoi = new Renvoi;
    Carte* evolution = new Evolution;
    Carte* retinol = new Retinol;
    Carte* tretinoine = new Tretinoine;
    Carte* b1 = new VitB1;
    Carte* b2 = new VitB2;
    Carte* acideAscorbique = new AcideAscorbique;
    Carte* calciferol = new Calciferol;
    Carte* any = new Any;

    if("coeur" == carte_btq)
    {
        joueur->Recevoircarte(coeur);
    }
    else if("poumon"==carte_btq)
    {
        joueur->Recevoircarte(poumon);
    }
    else if("foie" == carte_btq)
    {
        joueur->Recevoircarte(foie);
    }
    else if("pancreas" == carte_btq)
    {
        joueur->Recevoircarte(pancreas);
    }
    else if("rein"==carte_btq)
    {
        joueur->Recevoircarte(rein);
    }
    else if("cerveau" == carte_btq)
    {
        joueur->Recevoircarte(cerveau);
    }
    else if("boostVie"==carte_btq)
    {
        joueur->Recevoircarte(boostVie);
    }
    else if("boostDegat"==carte_btq)
    {
        joueur->Recevoircarte(boostDegat);
    }
    else if("passeTour"==carte_btq)
    {
        joueur->Recevoircarte(passerTour);
    }
    else if("renvoi"==carte_btq)
    {
        joueur->Recevoircarte(renvoi);
    }
    else if("evolution"==carte_btq)
    {
        joueur->Recevoircarte(evolution);
    }
    else if("retinol"==carte_btq)
    {
        joueur->Recevoircarte(retinol);
    }
    else if("tretinoine"==carte_btq)
    {
        joueur->Recevoircarte(tretinoine);
    }
    else if("b1"==carte_btq)
    {
        joueur->Recevoircarte(b1);
    }
    else if("b2"==carte_btq)
    {
        joueur->Recevoircarte(b2);
    }
    else if("acideAscorbique"==carte_btq)
    {
        joueur->Recevoircarte(acideAscorbique);
    }
    else if("calciferol"==carte_btq)
    {
        joueur->Recevoircarte(calciferol);
    }
    else if("any"==carte_btq)
    {
        joueur->Recevoircarte(any);
    }
    else  if(carte_btq == "all")
    {
        int i = 0;
        string choix;
        int cpt = 0;

        for(auto &el:m_listedescartes)
        {
            i++;
            cout<<i<<" : "<<el->getNom()<<endl;
        }
        cout<<"Choisissez nom de la carte a ajouter : ";
        cin>>choix;
        for(auto &el:m_listedescartes)
        {
            if(el->getNom()==choix)
            {
                joueur->Recevoircarte(el);
                cpt = 1;
            }
        }


        if (cpt == 0)
        {
            cout<<"Cette carte n'existe pas, verifiez l'orthographe"<<endl;
            return this->achetercarte(joueur,carte_btq);
        }
    }
    else
    {
        cout<<"erreur acheter carte!"<<endl;
    }

}

