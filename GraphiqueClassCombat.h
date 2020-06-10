
#define DEF_COMBAT
#ifdef DEF_COMBAT

#include "Personne.h"
#include <queue>

class Combat
{
protected :
    Personne* m_joueur1;
    Personne* m_joueur2;


    queue<Carte*> m_deck1;
    queue<Carte*> m_deck2;

    //ajout
    bool m_atk_reussie;

    bool m_IAj1;
    bool m_IAj2;
    /** if true==creature->getAtk_ok, on fait passer m_atk_reussie = true // meme chose pour le cas de false**/

    ///faire une spéciale qui change les cartes enjeu, avec une carte au hasard du cimetiere (marche seulement si cimetiere != NULL)


public :
    Combat(Personne* joueur1, Personne* joueur2);
    ~Combat();
    void choixcarteEnjeu();
    void retirercarteEnjeu();

    bool getIAj2() const;
    bool getIAj1() const;

    void setIAj1(bool IA);
    void setIAj2(bool IA);

    Personne* GetJoueur1() const;
    Personne* GetJoueur2() const;

    void Setdeck1(vector<Carte*> deck);
    void Setdeck2(vector<Carte*> deck);

    queue<Carte*> Getdeck1() const;
    queue<Carte*> Getdeck2() const;

    //ajout
    bool getAtk_reussie() const;
    void setTrueAtk_reussie();
    void setFalseAtk_reussie();

    void tourjoueur1(bool* carte_pioche, bool* choix_action, string* choix1, string* choix2, Carte** cartepioche, BITMAP* fond, BITMAP*buffer, int* click, bool* tourdejeu);
    void tourjoueur2(bool* carte_pioche, bool* choix_action, string* choix1, string* choix2, Carte** cartepioche, BITMAP* fond, BITMAP*buffer, int* click, bool* tourdejeu);

    ///méthodes (a priori)
    /**
    //Avant le début
    void melangerDeck();
    void carteEnjeu(Carte* enjeu); //à appeler pour j1 puis J2

    //Boucle de jeu

    void piocherCarte(); //utiliser ou passer
    void faireAction(); //atk1, 2, ou def1

    **/

};


#endif // DEF_COMBAT
