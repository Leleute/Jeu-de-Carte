#include <iostream>
#include "fonctions.h"

using namespace std;

void menu(int* choix)
{
    cout<<"\t\t\t\t\t--- MENU ---"<<endl<<endl;
    cout<<"1. Nouvelle partie"<<endl<<"2. Affichage des regles"<<endl<<"3. Ajouter un joueur"<<endl<<"4. voir la collection actuel d'un joueur"<<endl<<"5. voir le deck actuel d'un joueur"<<endl;
    cout<<"6. Boutique"<<endl<<"7. Statistiques des parties jouees"<<endl<<"8. Quitter le jeu"<<endl;
    cin>>*choix;

    while(*choix<1 || *choix>7)
    {
        cout<<"Veuillez recommencer la saisie."<<endl;
        cin>>*choix;
    }
}

void afficherRegles()
{
    cout<<endl<<"\t\t\t\t\t--- REGLES ---"<<endl;
    cout<<"\tChaque joueur peut se constituer un deck a partir de sa collection, dans le but de s'affronter. Un deck         constitue un corps humain."<<endl;
    cout<<"Les organes vitaux feront office de cartes creature, les cartes energie seront symbolises par les vitamines, A, B, C, D,et E, et les cartes speciales representeront la prise de produits dopants, pouvant avoir des effets secondaires         indesirables."<<endl;
    cout<<"Au cours d'un match, un organe vital en attaque un autre par le biais de maladies, et se defend des attaques enemies en prenant des medicaments."<<endl;

}


void demandeRejouer(bool* rejouer)
{
    int choixRejouer = 0;
    cout<<endl<<"Que voulez vous faire?"<<endl;
    cout<<"1. Retour au menu principal"<<endl<<"2. Quitter le jeu"<<endl;
    cin>>choixRejouer;

    while(choixRejouer<1 || choixRejouer>2)
    {
        cout<<"Veuillez recommencer la saisie."<<endl;
        cin>>choixRejouer;
    }

    if(1 == choixRejouer)
        *rejouer = false;
    if(2 == choixRejouer)
    {
        *rejouer = true;
        cout<<endl<<"PROGRAMME QUITTE"<<endl<<"\t\t\t\t\t--- A BIENTOT ---"<<endl;
    }
}

void retirercarteveteur(vector<Carte*>* vecteur, Carte* carteretirer)
{
    for (auto &el:*vecteur)
    {
        if(el->getNom() == carteretirer->getNom())
        {

            el = vecteur->back();
            vecteur->back()=carteretirer;
        }
    }
    vecteur->pop_back();

}
