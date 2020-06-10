#include "allegro.h"
#include "GraphiqueClassCombat.h"
#include "Combat.h"
#include <ctime>
#include <algorithm>
#include "Creature.h"
#include "Graphique.h"

#include <cstdlib>

Combat::Combat(Personne* joueur1, Personne* joueur2)
{
    m_joueur1 = joueur1;
    m_joueur2 = joueur2;
}

Combat::~Combat()
{

}

Personne* Combat::GetJoueur1() const
{
    return m_joueur1;
}

bool Combat::getIAj2() const
{
    return m_IAj2;
}

bool Combat::getIAj1() const
{
    return m_IAj1;
}

void Combat::setIAj1(bool IA)
{
    m_IAj1 = IA;
}

void Combat::setIAj2(bool IA)
{
    m_IAj2 = IA;
}

Personne* Combat::GetJoueur2() const
{
    return m_joueur2;
}


void Combat::choixcarteEnjeu()
{
    srand (time(NULL));
    int num1;
    int num2;
    num1 = rand()%21;
    num2 = rand()%21;
    m_joueur1->Setenjeu(m_joueur1->Getcolec()->GetDeck()[num1]);
    m_joueur2->Setenjeu(m_joueur2->Getcolec()->GetDeck()[num2]);
}

void Combat::retirercarteEnjeu()
{
    m_joueur1->Getcolec()->Retirercartedeck(m_joueur1->Getenjeu());
    m_joueur2->Getcolec()->Retirercartedeck(m_joueur2->Getenjeu());
}

void Combat::Setdeck1(vector<Carte*> deck)
{

    for(auto &el:deck)
    {
        m_deck1.push(el);
    }
}

void Combat::Setdeck2(vector<Carte*> deck)
{
    for(auto &el:deck)
    {
        m_deck2.push(el);
    }
}

queue<Carte*> Combat::Getdeck1() const
{
    return m_deck1;
}

queue<Carte*> Combat::Getdeck2() const
{
    return m_deck2;
}
//ajout
bool Combat::getAtk_reussie() const
{
    return m_atk_reussie;
}

void Combat::setTrueAtk_reussie()
{
    m_atk_reussie = true;

}
void Combat::setFalseAtk_reussie()
{
    m_atk_reussie = false;
}

void Combat::tourjoueur1(bool* carte_pioche, bool* choix_action, string* choix1, string* choix2, Carte** cartepioche, BITMAP* fond, BITMAP*buffer, int* click, bool* tourdejeu)
{
    srand(time(NULL));
    ///Initialisation
    Carte* foie= new Foie;
    Carte* cerveau= new Cerveau;
    Carte* coeur= new Coeur;
    Carte* pancreas= new Pancreas;
    Carte* rein= new Rein;
    Carte* poumon= new Poumon;
    int random;
    ///Information sur le joueur
    Carte* crea = new Creature;
    int nbpdvretirer;
    ///Si on skip le tour
    ///Check si la creature est en vie
    if(m_joueur1->Getcrea_actif()->getSkip() == true)
    {
        ///On change de tour de jeu
        *tourdejeu = false;
        ///On ne skip plus le tour
        m_joueur1->Getcrea_actif()->setSkipFalse();
        while(this->m_joueur1->Getcrea_actif()->getVie() <= 0)
        {
            ///Si la Premiere carte du deck est une creature
            if(Getdeck1().front()->getType() == "Creature")
            {
                ///On retire les PDV au joueur
                nbpdvretirer = 0 - this->m_joueur1->Getcrea_actif()->getVie();
                m_joueur1->Setvie(m_joueur1->Getvie()-nbpdvretirer);

                ///L'ancienne carte active va au cimetiere
                m_joueur1->Setcimetiere(m_joueur1->Getcrea_actif());

                ///On augmente de 1 le nombre de creature morte dans le deck
                m_joueur1->setNbrCreaMorte(m_joueur1->getNbrCreaMorte() + 1);

                ///La creature active devient la premiere carte du deck
                GetJoueur1()->Setcrea_actif(Getdeck1().front());

                ///On retire la premiere carte du deck
                m_deck1.pop();

                ///On set ses pdv
                if(GetJoueur1()->Getcrea_actif()->getNom() == "Foie") GetJoueur1()->Getcrea_actif()->setVie(foie->getVie());
                if(GetJoueur1()->Getcrea_actif()->getNom() == "Coeur") GetJoueur1()->Getcrea_actif()->setVie(coeur->getVie());
                if(GetJoueur1()->Getcrea_actif()->getNom() == "Cerveau") GetJoueur1()->Getcrea_actif()->setVie(cerveau->getVie());
                if(GetJoueur1()->Getcrea_actif()->getNom() == "Pancreas") GetJoueur1()->Getcrea_actif()->setVie(pancreas->getVie());
                if(GetJoueur1()->Getcrea_actif()->getNom() == "Rein") GetJoueur1()->Getcrea_actif()->setVie(rein->getVie());
                if(GetJoueur1()->Getcrea_actif()->getNom() == "Poumon") GetJoueur1()->Getcrea_actif()->setVie(poumon->getVie());
            }
            /// Si ce n'est pas une creature
            else
            {
                /// Passage de la premiere carte a la derniere carte
                crea = Getdeck1().front();
                m_deck1.push(crea);
                m_deck1.pop();
            }
        }
    }
    else
    {
        ///Check si la creature est en vie
        while(this->m_joueur1->Getcrea_actif()->getVie() <= 0)
        {
            ///Si la Premiere carte du deck est une creature
            if(Getdeck1().front()->getType() == "Creature")
            {
                ///On retire les PDV au joueur
                nbpdvretirer = 0 - this->m_joueur1->Getcrea_actif()->getVie();
                m_joueur1->Setvie(m_joueur1->Getvie()-nbpdvretirer);

                ///L'ancienne carte active va au cimetiere
                m_joueur1->Setcimetiere(m_joueur1->Getcrea_actif());

                ///On augmente de 1 le nombre de creature morte dans le deck
                m_joueur1->setNbrCreaMorte(m_joueur1->getNbrCreaMorte() + 1);

                ///La creature active devient la premiere carte du deck
                GetJoueur1()->Setcrea_actif(Getdeck1().front());

                ///On retire la premiere carte du deck
                m_deck1.pop();

                ///On set ses pdv
                if(GetJoueur1()->Getcrea_actif()->getNom() == "Foie") GetJoueur1()->Getcrea_actif()->setVie(foie->getVie());
                if(GetJoueur1()->Getcrea_actif()->getNom() == "Coeur") GetJoueur1()->Getcrea_actif()->setVie(coeur->getVie());
                if(GetJoueur1()->Getcrea_actif()->getNom() == "Cerveau") GetJoueur1()->Getcrea_actif()->setVie(cerveau->getVie());
                if(GetJoueur1()->Getcrea_actif()->getNom() == "Pancreas") GetJoueur1()->Getcrea_actif()->setVie(pancreas->getVie());
                if(GetJoueur1()->Getcrea_actif()->getNom() == "Rein") GetJoueur1()->Getcrea_actif()->setVie(rein->getVie());
                if(GetJoueur1()->Getcrea_actif()->getNom() == "Poumon") GetJoueur1()->Getcrea_actif()->setVie(poumon->getVie());
            }
            /// Si ce n'est pas une creature
            else
            {
                /// Passage de la premiere carte a la derniere carte
                crea = Getdeck1().front();
                m_deck1.push(crea);
                m_deck1.pop();
            }
        }

        ///A ne faire qu'une fois, avant de piocher la carte
        if(*carte_pioche == false)
        {
            ///Boost des points d'energies de la creature active
            for(auto &el:m_joueur1->Getener_actif())
            {
                el->boostTerrain(m_joueur1->Getcrea_actif());
            }
            ///Initialisation des variables
            *choix1 = "";
            this->setFalseAtk_reussie();

            ///Pioche de la premiere carte du deck
            (*cartepioche) = m_deck1.front();
            m_deck1.pop();
            *carte_pioche = true;
        }

        if (*choix1 !="Oui" && *carte_pioche == true)
        {

            if(getIAj1() == false)
            {
                textprintf_centre_ex(fond,font,400,551,makecol(0,0,0),-1,"Voulez vous activer la carte piochee?");
                //Premier boutton
                rectangleAnime(fond,105,560,105+190,560+80);
                rectfill(buffer,105,560,105+190,560+80,makecol(215,215,215));
                textprintf_centre_ex(fond,font,200,595,makecol(0,0,0),-1,"OUI");
                //Deuxieme boutton
                rectangleAnime(fond,105+400,560,105+190+400,560+80);
                rectfill(buffer,105+400,560,105+190+400,560+80,makecol(216,216,216));
                textprintf_centre_ex(fond,font,600,595,makecol(0,0,0),-1,"NON");
                if(mouse_b&1 && 0 == *click)//début du click
                {
                    *click = 1;
                }
                if( 1 == *click && !mouse_b&1)//fin du click
                {
                    if(getpixel(buffer,mouse_x,mouse_y) == makecol(215,215,215))
                    {
                        if((*cartepioche)->getType() =="Creature")
                        {
                            *choix1 = "Oui";
                            this->m_joueur1->Setcimetiere(this->m_joueur1->Getcrea_actif()) ;
                            this->m_joueur1->Setcrea_actif((*cartepioche));
                        }
                        if((*cartepioche)->getType() =="Terrain")
                        {
                            *choix1 = "Oui";
                            this->m_joueur1->Setener_actif((*cartepioche));
                        }
                        if((*cartepioche)->getType() =="Special")
                        {
                            if((*cartepioche)->getNom() =="Passe_ton_tour")
                            {
                                ///Si elle doit etre envoyée dans le deck
                                if((*cartepioche)->getRecyclable() == true )m_deck1.push((*cartepioche));
                                ///Si elle doit etre envoyée au cimetiere
                                if((*cartepioche)->getRecyclable() == false )m_joueur1->Setcimetiere((*cartepioche));
                                ///Activation
                                (*cartepioche)->actionSpeciale(m_joueur2->Getcrea_actif());
                            }
                            else
                            {

                                ///Si elle doit etre envoyée dans le deck
                                if((*cartepioche)->getRecyclable() == true )m_deck1.push((*cartepioche));
                                ///Si elle doit etre envoyée au cimetiere
                                if((*cartepioche)->getRecyclable() == false )m_joueur1->Setcimetiere((*cartepioche));
                                ///Activation
                                (*cartepioche)->actionSpeciale(m_joueur1->Getcrea_actif());
                            }
                            *choix1 = "Oui";
                        }
                    }
                    if(getpixel(buffer,mouse_x,mouse_y) == makecol(216,216,216))
                    {
                        if((*cartepioche)->getType() =="Creature")
                        {
                            *choix1 = "Oui";
                            m_deck1.push((*cartepioche));
                        }
                        if((*cartepioche)->getType() =="Terrain")
                        {
                            *choix1 = "Oui";
                            m_deck1.push((*cartepioche));
                        }
                        if((*cartepioche)->getType() =="Special")
                        {
                            *choix1 = "Oui";
                            m_deck1.push((*cartepioche));
                        }
                    }
                    *click = 0;
                }

            }
            if(getIAj1() == true)
            {
                if((*cartepioche)->getType() =="Creature")
                {
                    *choix1 = "Oui";
                    m_deck1.push((*cartepioche));
                }
                if((*cartepioche)->getType() =="Terrain")
                {
                    *choix1 = "Oui";
                    this->m_joueur1->Setener_actif((*cartepioche));
                }
                if((*cartepioche)->getType() =="Special")
                {
                    if((*cartepioche)->getNom() =="Passe_ton_tour")
                    {
                        ///Si elle doit etre envoyée dans le deck
                        if((*cartepioche)->getRecyclable() == true )m_deck1.push((*cartepioche));
                        ///Si elle doit etre envoyée au cimetiere
                        if((*cartepioche)->getRecyclable() == false )m_joueur1->Setcimetiere((*cartepioche));
                        ///Activation
                        (*cartepioche)->actionSpeciale(m_joueur2->Getcrea_actif());
                    }
                    else
                    {

                        ///Si elle doit etre envoyée dans le deck
                        if((*cartepioche)->getRecyclable() == true )m_deck1.push((*cartepioche));
                        ///Si elle doit etre envoyée au cimetiere
                        if((*cartepioche)->getRecyclable() == false )m_joueur1->Setcimetiere((*cartepioche));
                        ///Activation
                        (*cartepioche)->actionSpeciale(m_joueur1->Getcrea_actif());
                    }
                    *choix1 = "Oui";
                }
            }
        }


        ///A ne faire qu'une fois que le choix est valide
        if(*choix1 == "Oui" && *carte_pioche == true)
        {
            ///A ne faire qu'une fois
            if(*choix_action == false)
            {

                *choix_action = true;
            }
            /// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            if(getAtk_reussie() == false && *choix_action == true)
            {
                this->setFalseAtk_reussie();
                if (getIAj1() == false)
                {
                    textprintf_centre_ex(fond,font,400,551,makecol(0,0,0),-1,"Choisissez une action");
                    //Premier boutton
                    rectangleAnime(fond,5,560,5+190,640);
                    rectfill(buffer,5,560,5+190,640,makecol(221,221,221));
                    textprintf_centre_ex(fond,font,100,595,makecol(0,0,0),-1,"ATTAQUE UN");
                    //2e boutton
                    rectangleAnime(fond,205,560,205+190,640);
                    rectfill(buffer,205,560,205+190,640,makecol(222,222,222));
                    textprintf_centre_ex(fond,font,300,595,makecol(0,0,0),-1,"ATTAQUE DEUX");
                    //3e boutton
                    rectangleAnime(fond,405,560,405+190,640);
                    rectfill(buffer,405,560,405+190,640,makecol(223,223,223));
                    textprintf_centre_ex(fond,font,500,595,makecol(0,0,0),-1,"DEFENSE");
                    //4e boutton
                    rectangleAnime(fond,605,560,605+190,640);
                    rectfill(buffer,605,560,605+190,640,makecol(224,224,224));
                    textprintf_centre_ex(fond,font,700,595,makecol(0,0,0),-1,"PASSER");
                    if(mouse_b&1 && 0 == *click)//début du click
                    {
                        *click = 1;
                    }
                    if( 1 == *click && !mouse_b&1)//fin du click
                    {
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(221,221,221))
                        {
                            this->GetJoueur1()->Getcrea_actif()->attaque_un(GetJoueur2()->Getcrea_actif());
                            if(this->GetJoueur1()->Getcrea_actif()->getAtk_ok() == true)this->setTrueAtk_reussie();
                        }
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(222,222,222))
                        {
                            this->GetJoueur1()->Getcrea_actif()->attaque_deux(GetJoueur2()->Getcrea_actif());
                            if(this->GetJoueur1()->Getcrea_actif()->getAtk_ok() == true)this->setTrueAtk_reussie();
                        }
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(223,223,223))
                        {
                            this->GetJoueur1()->Getcrea_actif()->seDefendre();
                            if(this->GetJoueur1()->Getcrea_actif()->getAtk_ok() == true)this->setTrueAtk_reussie();
                        }
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(224,224,224))
                        {
                            this->setTrueAtk_reussie();
                        }
                        *click = 0;
                    }
                }
                if (getIAj1() == true)
                {
                    if (getIAj1() == true)
                    {
                        random = rand()%4;
                        if (random == 0)  *choix2 = m_joueur1->Getcrea_actif()->getAttaque_un()->getNom();
                        if (random == 1)  *choix2 = m_joueur1->Getcrea_actif()->getAttaque_deux()->getNom();
                        if (random == 2)  *choix2 = m_joueur1->Getcrea_actif()->getDefense_un()->getNom();
                        if (random == 3)  *choix2 = "Rien";
                    }
                    if(*choix2 == m_joueur1->Getcrea_actif()->getAttaque_un()->getNom())
                    {
                        this->GetJoueur1()->Getcrea_actif()->attaque_un(GetJoueur2()->Getcrea_actif());
                        if(this->GetJoueur1()->Getcrea_actif()->getAtk_ok() == true)this->setTrueAtk_reussie();
                    }
                    if(*choix2 == m_joueur1->Getcrea_actif()->getAttaque_deux()->getNom())
                    {
                        this->GetJoueur1()->Getcrea_actif()->attaque_deux(GetJoueur2()->Getcrea_actif());
                        if(this->GetJoueur1()->Getcrea_actif()->getAtk_ok() == true)this->setTrueAtk_reussie();
                    }
                    if(*choix2 == m_joueur1->Getcrea_actif()->getDefense_un()->getNom())
                    {
                        this->GetJoueur1()->Getcrea_actif()->seDefendre();
                        if(this->GetJoueur1()->Getcrea_actif()->getAtk_ok() == true)this->setTrueAtk_reussie();
                    }
                    if(*choix2 == "Rien")
                    {
                        this->setTrueAtk_reussie();
                    }
                }

            }

            if(*carte_pioche == true && *choix_action == true && *choix1 == "Oui" && getAtk_reussie() == true)
            {
                ///On reinitialise le tour
                *carte_pioche = false;
                *choix_action = false;
                *choix1 = "";
                *choix2 = "";
                m_atk_reussie = false;
                *tourdejeu = false;
            }
        }
    }
}


void Combat::tourjoueur2(bool* carte_pioche, bool* choix_action, string* choix1, string* choix2, Carte** cartepioche, BITMAP* fond, BITMAP*buffer, int* click, bool* tourdejeu)
{
    srand(time(NULL));
    ///Initialisation
    Carte* foie= new Foie;
    Carte* cerveau= new Cerveau;
    Carte* coeur= new Coeur;
    Carte* pancreas= new Pancreas;
    Carte* rein= new Rein;
    Carte* poumon= new Poumon;
    int random;
    ///Information sur le joueur
    Carte* crea = new Creature;
    int nbpdvretirer;
    ///Si on skip le tour
    ///Check si la creature est en vie
    if(m_joueur2->Getcrea_actif()->getSkip() == true)
    {
        ///On change de tour de jeu
        *tourdejeu = true;
        ///On ne skip plus le tour
        m_joueur2->Getcrea_actif()->setSkipFalse();
        while(this->m_joueur2->Getcrea_actif()->getVie() <= 0)
        {
            ///Si la Premiere carte du deck est une creature
            if(Getdeck1().front()->getType() == "Creature")
            {
                ///On retire les PDV au joueur
                nbpdvretirer = 0 - this->m_joueur2->Getcrea_actif()->getVie();
                m_joueur2->Setvie(m_joueur2->Getvie()-nbpdvretirer);

                ///L'ancienne carte active va au cimetiere
                m_joueur2->Setcimetiere(m_joueur2->Getcrea_actif());

                ///On augmente de 1 le nombre de creature morte dans le deck
                m_joueur2->setNbrCreaMorte(m_joueur2->getNbrCreaMorte() + 1);

                ///La creature active devient la premiere carte du deck
                GetJoueur2()->Setcrea_actif(Getdeck1().front());

                ///On retire la premiere carte du deck
                m_deck1.pop();

                ///On set ses pdv
                if(GetJoueur2()->Getcrea_actif()->getNom() == "Foie") GetJoueur2()->Getcrea_actif()->setVie(foie->getVie());
                if(GetJoueur2()->Getcrea_actif()->getNom() == "Coeur") GetJoueur2()->Getcrea_actif()->setVie(coeur->getVie());
                if(GetJoueur2()->Getcrea_actif()->getNom() == "Cerveau") GetJoueur2()->Getcrea_actif()->setVie(cerveau->getVie());
                if(GetJoueur2()->Getcrea_actif()->getNom() == "Pancreas") GetJoueur2()->Getcrea_actif()->setVie(pancreas->getVie());
                if(GetJoueur2()->Getcrea_actif()->getNom() == "Rein") GetJoueur2()->Getcrea_actif()->setVie(rein->getVie());
                if(GetJoueur2()->Getcrea_actif()->getNom() == "Poumon") GetJoueur2()->Getcrea_actif()->setVie(poumon->getVie());
            }
            /// Si ce n'est pas une creature
            else
            {
                /// Passage de la premiere carte a la derniere carte
                crea = Getdeck1().front();
                m_deck1.push(crea);
                m_deck1.pop();
            }
        }
    }
    else
    {
        ///Check si la creature est en vie
        while(this->m_joueur2->Getcrea_actif()->getVie() <= 0)
        {
            ///Si la Premiere carte du deck est une creature
            if(Getdeck1().front()->getType() == "Creature")
            {
                ///On retire les PDV au joueur
                nbpdvretirer = 0 - this->m_joueur2->Getcrea_actif()->getVie();
                m_joueur2->Setvie(m_joueur2->Getvie()-nbpdvretirer);

                ///L'ancienne carte active va au cimetiere
                m_joueur2->Setcimetiere(m_joueur2->Getcrea_actif());

                ///On augmente de 1 le nombre de creature morte dans le deck
                m_joueur2->setNbrCreaMorte(m_joueur2->getNbrCreaMorte() + 1);

                ///La creature active devient la premiere carte du deck
                GetJoueur2()->Setcrea_actif(Getdeck1().front());

                ///On retire la premiere carte du deck
                m_deck1.pop();

                ///On set ses pdv
                if(GetJoueur2()->Getcrea_actif()->getNom() == "Foie") GetJoueur2()->Getcrea_actif()->setVie(foie->getVie());
                if(GetJoueur2()->Getcrea_actif()->getNom() == "Coeur") GetJoueur2()->Getcrea_actif()->setVie(coeur->getVie());
                if(GetJoueur2()->Getcrea_actif()->getNom() == "Cerveau") GetJoueur2()->Getcrea_actif()->setVie(cerveau->getVie());
                if(GetJoueur2()->Getcrea_actif()->getNom() == "Pancreas") GetJoueur2()->Getcrea_actif()->setVie(pancreas->getVie());
                if(GetJoueur2()->Getcrea_actif()->getNom() == "Rein") GetJoueur2()->Getcrea_actif()->setVie(rein->getVie());
                if(GetJoueur2()->Getcrea_actif()->getNom() == "Poumon") GetJoueur2()->Getcrea_actif()->setVie(poumon->getVie());
            }
            /// Si ce n'est pas une creature
            else
            {
                /// Passage de la premiere carte a la derniere carte

                crea = Getdeck1().front();
                m_deck1.push(crea);
                m_deck1.pop();
            }
        }

        ///A ne faire qu'une fois, avant de piocher la carte
        if(*carte_pioche == false)
        {
            ///Boost des points d'energies de la creature active
            for(auto &el:m_joueur2->Getener_actif())
            {
                el->boostTerrain(m_joueur2->Getcrea_actif());
            }
            ///Initialisation des variables
            *choix1 = "";
            this->setFalseAtk_reussie();

            ///Pioche de la premiere carte du deck
            (*cartepioche) = m_deck1.front();
            m_deck1.pop();
            *carte_pioche = true;
        }

        if (*choix1 !="Oui" && *carte_pioche == true)
        {

            if(getIAj2() == false)
            {
                textprintf_centre_ex(fond,font,400,551,makecol(0,0,0),-1,"Voulez vous activer la carte piochee?");
                //Premier boutton
                rectangleAnime(fond,105,560,105+190,560+80);
                rectfill(buffer,105,560,105+190,560+80,makecol(215,215,215));
                textprintf_centre_ex(fond,font,200,595,makecol(0,0,0),-1,"OUI");
                //Deuxieme boutton
                rectangleAnime(fond,105+400,560,105+190+400,560+80);
                rectfill(buffer,105+400,560,105+190+400,560+80,makecol(216,216,216));
                textprintf_centre_ex(fond,font,600,595,makecol(0,0,0),-1,"NON");
                if(mouse_b&1 && 0 == *click)//début du click
                {
                    *click = 1;
                }
                if( 1 == *click && !mouse_b&1)//fin du click
                {
                    if(getpixel(buffer,mouse_x,mouse_y) == makecol(215,215,215))
                    {
                        if((*cartepioche)->getType() =="Creature")
                        {
                            *choix1 = "Oui";
                            this->m_joueur2->Setcimetiere(this->m_joueur2->Getcrea_actif()) ;
                            this->m_joueur2->Setcrea_actif((*cartepioche));
                        }
                        if((*cartepioche)->getType() =="Terrain")
                        {
                            *choix1 = "Oui";
                            this->m_joueur2->Setener_actif((*cartepioche));
                        }
                        if((*cartepioche)->getType() =="Special")
                        {
                            if((*cartepioche)->getNom() =="Passe_ton_tour")
                            {
                                ///Si elle doit etre envoyée dans le deck
                                if((*cartepioche)->getRecyclable() == true )m_deck2.push((*cartepioche));
                                ///Si elle doit etre envoyée au cimetiere
                                if((*cartepioche)->getRecyclable() == false )m_joueur2->Setcimetiere((*cartepioche));
                                ///Activation
                                (*cartepioche)->actionSpeciale(m_joueur1->Getcrea_actif());
                            }
                            else
                            {

                                ///Si elle doit etre envoyée dans le deck
                                if((*cartepioche)->getRecyclable() == true )m_deck2.push((*cartepioche));
                                ///Si elle doit etre envoyée au cimetiere
                                if((*cartepioche)->getRecyclable() == false )m_joueur2->Setcimetiere((*cartepioche));
                                ///Activation
                                (*cartepioche)->actionSpeciale(m_joueur2->Getcrea_actif());
                            }
                            *choix1 = "Oui";
                        }
                    }
                    if(getpixel(buffer,mouse_x,mouse_y) == makecol(216,216,216))
                    {
                        if((*cartepioche)->getType() =="Creature")
                        {
                            *choix1 = "Oui";
                            m_deck1.push((*cartepioche));
                        }
                        if((*cartepioche)->getType() =="Terrain")
                        {
                            *choix1 = "Oui";
                            m_deck1.push((*cartepioche));
                        }
                        if((*cartepioche)->getType() =="Special")
                        {
                            *choix1 = "Oui";
                            m_deck1.push((*cartepioche));
                        }
                    }
                    *click = 0;
                }

            }
            if(getIAj2() == true)
            {
                if((*cartepioche)->getType() =="Creature")
                {
                    *choix1 = "Oui";
                    m_deck1.push((*cartepioche));
                }
                if((*cartepioche)->getType() =="Terrain")
                {
                    *choix1 = "Oui";
                    this->m_joueur2->Setener_actif((*cartepioche));
                }
                if((*cartepioche)->getType() =="Special")
                {
                    if((*cartepioche)->getNom() =="Passe_ton_tour")
                    {
                        ///Si elle doit etre envoyée dans le deck
                        if((*cartepioche)->getRecyclable() == true )m_deck2.push((*cartepioche));
                        ///Si elle doit etre envoyée au cimetiere
                        if((*cartepioche)->getRecyclable() == false )m_joueur2->Setcimetiere((*cartepioche));
                        ///Activation
                        (*cartepioche)->actionSpeciale(m_joueur1->Getcrea_actif());
                    }
                    else
                    {

                        ///Si elle doit etre envoyée dans le deck
                        if((*cartepioche)->getRecyclable() == true )m_deck2.push((*cartepioche));
                        ///Si elle doit etre envoyée au cimetiere
                        if((*cartepioche)->getRecyclable() == false )m_joueur2->Setcimetiere((*cartepioche));
                        ///Activation
                        (*cartepioche)->actionSpeciale(m_joueur2->Getcrea_actif());
                    }
                    *choix1 = "Oui";
                }
            }
        }


        ///A ne faire qu'une fois que le choix est valide
        if(*choix1 == "Oui" && *carte_pioche == true)
        {
            ///A ne faire qu'une fois
            if(*choix_action == false)
            {

                *choix_action = true;
            }
            /// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            if(getAtk_reussie() == false && *choix_action == true)
            {
                this->setFalseAtk_reussie();
                if (getIAj2() == false)
                {
                    textprintf_centre_ex(fond,font,400,551,makecol(0,0,0),-1,"Choisissez une action");
                    //Premier boutton
                    rectangleAnime(fond,5,560,5+190,640);
                    rectfill(buffer,5,560,5+190,640,makecol(221,221,221));
                    textprintf_centre_ex(fond,font,100,595,makecol(0,0,0),-1,"ATTAQUE UN");
                    //2e boutton
                    rectangleAnime(fond,205,560,205+190,640);
                    rectfill(buffer,205,560,205+190,640,makecol(222,222,222));
                    textprintf_centre_ex(fond,font,300,595,makecol(0,0,0),-1,"ATTAQUE DEUX");
                    //3e boutton
                    rectangleAnime(fond,405,560,405+190,640);
                    rectfill(buffer,405,560,405+190,640,makecol(223,223,223));
                    textprintf_centre_ex(fond,font,500,595,makecol(0,0,0),-1,"DEFENSE");
                    //4e boutton
                    rectangleAnime(fond,605,560,605+190,640);
                    rectfill(buffer,605,560,605+190,640,makecol(224,224,224));
                    textprintf_centre_ex(fond,font,700,595,makecol(0,0,0),-1,"PASSER");
                    if(mouse_b&1 && 0 == *click)//début du click
                    {
                        *click = 1;
                    }
                    if( 1 == *click && !mouse_b&1)//fin du click
                    {
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(221,221,221))
                        {
                            this->GetJoueur2()->Getcrea_actif()->attaque_un(GetJoueur1()->Getcrea_actif());
                            if(this->GetJoueur2()->Getcrea_actif()->getAtk_ok() == true)this->setTrueAtk_reussie();
                        }
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(222,222,222))
                        {
                            this->GetJoueur2()->Getcrea_actif()->attaque_deux(GetJoueur1()->Getcrea_actif());
                            if(this->GetJoueur2()->Getcrea_actif()->getAtk_ok() == true)this->setTrueAtk_reussie();
                        }
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(223,223,223))
                        {
                            this->GetJoueur2()->Getcrea_actif()->seDefendre();
                            if(this->GetJoueur2()->Getcrea_actif()->getAtk_ok() == true)this->setTrueAtk_reussie();
                        }
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(224,224,224))
                        {
                            this->setTrueAtk_reussie();
                        }
                        *click = 0;
                    }
                }
                if (getIAj2() == true)
                {
                    if (getIAj2() == true)
                    {
                        random = rand()%4;
                        if (random == 0)  *choix2 = m_joueur2->Getcrea_actif()->getAttaque_un()->getNom();
                        if (random == 1)  *choix2 = m_joueur2->Getcrea_actif()->getAttaque_deux()->getNom();
                        if (random == 2)  *choix2 = m_joueur2->Getcrea_actif()->getDefense_un()->getNom();
                        if (random == 3)  *choix2 = "Rien";
                    }
                    if(*choix2 == m_joueur2->Getcrea_actif()->getAttaque_un()->getNom())
                    {
                        this->GetJoueur2()->Getcrea_actif()->attaque_un(GetJoueur1()->Getcrea_actif());
                        if(this->GetJoueur2()->Getcrea_actif()->getAtk_ok() == true)this->setTrueAtk_reussie();
                    }
                    if(*choix2 == m_joueur2->Getcrea_actif()->getAttaque_deux()->getNom())
                    {
                        this->GetJoueur2()->Getcrea_actif()->attaque_deux(GetJoueur1()->Getcrea_actif());
                        if(this->GetJoueur2()->Getcrea_actif()->getAtk_ok() == true)this->setTrueAtk_reussie();
                    }
                    if(*choix2 == m_joueur2->Getcrea_actif()->getDefense_un()->getNom())
                    {
                        this->GetJoueur2()->Getcrea_actif()->seDefendre();
                        if(this->GetJoueur2()->Getcrea_actif()->getAtk_ok() == true)this->setTrueAtk_reussie();
                    }
                    if(*choix2 == "Rien")
                    {
                        this->setTrueAtk_reussie();
                    }
                }

            }

            if(*carte_pioche == true && *choix_action == true && *choix1 == "Oui" && getAtk_reussie() == true)
            {
                ///On reinitialise le tour
                *carte_pioche = false;
                *choix_action = false;
                *choix1 = "";
                *choix2 = "";
                m_atk_reussie = false;
                *tourdejeu = true;
            }
        }
    }
}
