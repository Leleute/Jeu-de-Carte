#ifndef DEF_PERSONNE
#define DEF_PERSONNE

#include <iostream>
#include "Collection.h"
#include <vector>

using namespace std;

class Personne
{
private :
    string m_nom;
    ///vecteurs, file, pile etc.
    int m_vie;
    int m_argent;
    Collection* m_colec = new Collection;



    int m_nbrCrea;
    int m_nbrCreaMorte;
    bool m_ouverturefichier = false;




    vector<Carte*> m_cimetiere;
    Carte* m_crea_actif;
    vector<Carte*> m_ener_actif;
    Carte* m_spe_actif;
    Carte* m_enjeu;

public :
    bool getOuvertureFichier() const;
    void setOuvertureFichier(bool ouverture);
    int getNbrCrea() const;
    int getNbrCreaMorte() const;
    void setNbrCrea(int crea);
    void setNbrCreaMorte(int crea);
    void resetpers();

    Personne();
    Personne(string _nom);
    ~Personne();

    void SetCollection(Collection* listenom);
    int GetArgent() const;
    void SetArgent(int argent);
    Collection* Getcolec();
    string getNom();

    void sePresenter() const;
    void ChargerCollection();
    void AfficherCollection();
    void AfficherDeck();

    void Recevoircarte(Carte* carteajout);
    void SaveFichierColec();
    void SaveFichierDeck();
    void creerdeck();

    int Getvie() const;
    vector<Carte*> Getcimetiere() const;
    Carte* Getcrea_actif() const;
    vector<Carte*> Getener_actif() const;
    Carte* Getspe_actif() const;
    Carte* Getenjeu() const;

    void Setvie(int vie);
    void Setcimetiere(Carte* newcim);
    void Setcrea_actif(Carte* newcrea);
    void Setener_actif(Carte* newener);
    void Setspe_actif(Carte* newspe);
    void Setenjeu(Carte* enjeu);




};
#endif // DEF_PERSONNE
