#include "Personne.h"
#include <fstream>
#include <iostream>
#include "Creature.h"
#include "Boutique.h"
#include <sstream>
#include <string>

Personne::Personne()
{
    cin>>m_nom;
    m_vie = 5;
    m_argent = 300;
    /// HORS ALLEGRO//
    /**Boutique mag;
    cout<<"Nom du joueur a creer  : ";
    cin>>m_nom;
    m_vie = 10;
    m_argent = 100;
    ///Creation de la collection
    for (int i=0; i<30; i++)
    {
        mag.achetercarte(this,"all");
        m_argent = m_argent - 2;
    }
    ///Creation du deck
    this->creerdeck();*/
}

Personne::Personne(string _nom)
    : m_nom(_nom)
{
    m_vie = 5;
    ChargerCollection();
}

Personne::~Personne() {}

void Personne::sePresenter() const
{
    cout<<"Je m'appelle "<<m_nom<<"."<<endl;
    /// AJOUTER : j'ai X cartes dans ma collection.
}

void Personne::SetCollection(Collection* colec)
{
    m_colec = colec;
}

Collection* Personne::Getcolec()
{
    return m_colec;
}

void Personne::ChargerCollection()
{
    string ligne;
    Collection* save = new Collection;
    bool cpt = true;
    vector<string> sav;
    vector<string> sav2;
    ifstream fp { (this->m_nom+"colec.txt").c_str()} ; // On essaye d'ouvrir le fichier;
    if(fp) // On teste si tout est OK
    {

        fp>>m_argent;
        while(getline(fp,ligne))
        {
            if (cpt == true )sav.push_back(ligne);
        }
        save->Setcollection(sav);
        this->SetCollection(save);
        fp.close();
        m_ouverturefichier = true;

    }
    else
    {
        cout << "Erreur : Impossible d'ouvrir le fichier." << endl;
        m_ouverturefichier = false;
    }

    ifstream fp1 { (this->m_nom+"deck.txt").c_str()} ; // On essaye d'ouvrir le fichier;
    if(fp1) // On teste si tout est OK
    {
        while(getline(fp1,ligne))
        {
            sav2.push_back(ligne);
        }
        save->Setdeck(sav2);
        this->SetCollection(save);
        fp1.close();
    }
    else
    {
        cout << "Erreur : Impossible d'ouvrir le fichier." << endl;
    }




    this->SetCollection(save);
}

void Personne::AfficherCollection()
{
    cout<<"Vous avez actuellement "<<m_argent<<" euros"<<endl<<endl;

    int compteur = 0;
    for(auto &el:this->Getcolec()->GetCollection())
    {
        compteur++;
        cout<<compteur<<" : " <<el->getNom()<<endl;
    }
}

bool Personne::getOuvertureFichier() const
{
    return m_ouverturefichier;
}

void Personne::setOuvertureFichier(bool a)
{
    m_ouverturefichier = a ;
}

void Personne::AfficherDeck()
{
    int compteur = 0;
    for(auto &el:this->Getcolec()->GetDeck())
    {
        compteur++;
        cout<<compteur<<" : " <<el->getNom()<<endl;
    }
}

void Personne::Recevoircarte(Carte* carte)
{
    this->m_colec->Ajoutcartecolec(carte);
}

void Personne::SaveFichierColec()
{
    ofstream fp {(m_nom+"colec.txt").c_str(), ios::out};
    if(fp)
    {
        fp<<m_argent<<endl;
        for (auto &el:this->Getcolec()->GetCollection())
        {
            fp<<el->getNom()<<endl;
        }

    }
    else
    {
        cout<<"Erreur"<<endl;
    }
}

void Personne::SaveFichierDeck()
{
    ofstream fp {(m_nom+"deck.txt").c_str(), ios::out};
    if(fp)
    {
        for (auto &el:m_colec->GetDeck())
        {
            fp<<el->getNom()<<endl;
        }

    }
    else
    {
        cout<<"Erreur"<<endl;
    }
}



void Personne::creerdeck()
{
    int cpt[21];
    this->AfficherCollection();
    cout<<"Taper le numero des 21 cartes que vous voulez dans votre deck : "<<endl;
    for (int i=0; i<21; i++)
    {
        cin>>cpt[i];
        cpt[i]--;
        for(int j=0; j<i; j++)
        {
            if (cpt[j] == cpt[i])
            {
                cout<<"vous ne pouvez pas avoir le meme numero de carte 2 fois dans votre deck, veuillez recommencer"<<endl;
                i=i-1;
            }
        }
    }
    m_colec->Constdeck(cpt);
}

int Personne::GetArgent() const
{
    return m_argent;
}

void Personne::SetArgent(int argent)
{
    m_argent = argent;
}

int Personne::Getvie() const
{
    return m_vie;
}

vector<Carte*> Personne::Getcimetiere() const
{
    return m_cimetiere;
}

Carte* Personne::Getcrea_actif() const
{
    return m_crea_actif;
}

vector<Carte*> Personne::Getener_actif() const
{
    return m_ener_actif;
}

Carte* Personne::Getspe_actif() const
{
    return m_spe_actif;
}

Carte* Personne::Getenjeu() const
{
    return m_enjeu;
}

void Personne::Setvie(int vie)
{
    m_vie = vie;
}

void Personne::Setcimetiere(Carte* newcim)
{
    m_cimetiere.push_back(newcim);
}

void Personne::Setcrea_actif(Carte* newcrea)
{
    m_crea_actif = newcrea;
}

void Personne::Setener_actif(Carte* newener)
{
    m_ener_actif.push_back(newener);
}

void Personne::Setspe_actif(Carte* newspe)
{
    m_spe_actif = newspe;
}

void Personne::Setenjeu(Carte* enjeu)
{
    m_enjeu = enjeu;
}

int Personne::getNbrCrea() const
{
    return m_nbrCrea;
}
int Personne::getNbrCreaMorte() const
{
    return m_nbrCreaMorte;
}

string Personne::getNom()
{
    return m_nom;
}

void Personne::setNbrCrea(int crea)
{
    m_nbrCrea = crea;
}

void Personne::setNbrCreaMorte(int crea)
{
    m_nbrCreaMorte = crea;
}

void Personne::resetpers()
{
    while( m_cimetiere.size() != 0)
    {
        m_cimetiere.pop_back();
    }
    while( m_ener_actif.size() != 0)
    {
        m_ener_actif.pop_back();
    }
    m_ener_actif;
    m_spe_actif = NULL;
    m_enjeu = NULL;
}





