#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include "allegro.h"
#include <cstdio>

#include "Include.h"

/**
Dans cette version graphique, seul le main est commenté et modifié, toutes les fonctions de cette version hors fonctions graphiques sont semblables aux fonctions de la version console.
Pour les commentaires, se référer à la version console.
**/


//Pour ce qui est des texprintf_ex sur Allegro dans lesquels on cherche à afficher des "valeur : x" avec x un int sur un buffer :
//Cette fonction ne reconnaissant que des string, et x étant un int, il nous fallait convertir un int en string.
//C++11 et les bibliothèques nécessaires à l'appel de la fonction to_string étant actifs, to_string() ne compilait pas et n'était pas reconnue
//D'après notre chargé de TP, ce serait dû à un probleme d'IDE voir de machine.
//Les textprintf_ex() sont donc appelés sous la forme C et non C++ : textprintf_ex(...,...,"valeur : %d", x)

using namespace std;

int main()
{
    srand(time == NULL);

    allegro();

    //Déclaration des variables
    bool carte_pioche = false;
    bool choix_carte = false;
    bool rejouer = false;
    bool creationdeck = false;
    bool boucleDeJeu = false;
    bool creerjoueur = false;
    bool tourdejeu = true;
    bool tourdejeuactif = true;


    string choix1;
    string choix2;
    string nomj;
    string fond_affiche = "menu";
    string nom_joueur_boutique = "null"; //Sert pour la collection la boutique et le deck
    string nom_joueur_1 = "null";
    string nom_joueur_2 = "null";
    string IAchoix = "";

    int cpt = 0;
    int cptcreerjoueur;
    int click = 0;
    int random_joueur = rand()%101;
    int victoire;
    int affichage_joueur = 0;

    float posmapy = 0;

    //On instancie les objets qu'on veut utiliser via des pointeurs
    Carte* cartepioche;
    Carte* carte;
    vector <Carte*> save;
    Boutique* mag = new Boutique;
    Combat* comb;

    Personne* joueur;
    Personne* joueur1;
    Personne* joueur2;

    //Déclaration des BITMAP
    BITMAP* fond; //fond affiché sur le screen
    BITMAP* buffer; // double buffering pour les clicks

    vector<BITMAP*> image;
    image.push_back(charger_image("B1.bmp"));
    image.push_back(charger_image("B2.bmp"));
    image.push_back(charger_image("C.bmp"));
    image.push_back(charger_image("cerveau.bmp"));
    image.push_back(charger_image("coeur.bmp")); //5
    image.push_back(charger_image("D.bmp"));
    image.push_back(charger_image("degat.bmp"));
    image.push_back(charger_image("evolution.bmp"));
    image.push_back(charger_image("foie.bmp"));
    image.push_back(charger_image("pancreas.bmp")); //10
    image.push_back(charger_image("passeTour.bmp"));
    image.push_back(charger_image("poumon.bmp"));
    image.push_back(charger_image("rein.bmp"));
    image.push_back(charger_image("renvoi.bmp"));
    image.push_back(charger_image("retinol.bmp")); //15
    image.push_back(charger_image("tretinoine.bmp"));
    image.push_back(charger_image("vie.bmp"));
    image.push_back(charger_image("vit_any.bmp")); //18

    image.push_back(charger_image("B1_zoom.bmp"));
    image.push_back(charger_image("B2_zoom.bmp"));//20
    image.push_back(charger_image("C_zoom.bmp"));
    image.push_back(charger_image("cerveau_zoom.bmp"));
    image.push_back(charger_image("coeur_zoom.bmp"));
    image.push_back(charger_image("D_zoom.bmp"));
    image.push_back(charger_image("degat_zoom.bmp"));//25
    image.push_back(charger_image("evolution_zoom.bmp"));
    image.push_back(charger_image("foie_zoom.bmp"));
    image.push_back(charger_image("pancreas_zoom.bmp"));
    image.push_back(charger_image("passeTour_zoom.bmp"));
    image.push_back(charger_image("poumon_zoom.bmp"));//30
    image.push_back(charger_image("rein_zoom.bmp"));
    image.push_back(charger_image("renvoi_zoom.bmp"));
    image.push_back(charger_image("retinol_zoom.bmp"));
    image.push_back(charger_image("tretinoine_zoom.bmp"));
    image.push_back(charger_image("vie_zoom.bmp"));//35
    image.push_back(charger_image("vit_any_zoom.bmp"));//36

    BITMAP* fond_collection;
    BITMAP* buffer_collection;
    BITMAP*fond_deck;
    BITMAP*buffer_deck;
    BITMAP*carte_verso;

    //affectation des BITMAP
    fond=create_bitmap(SCREEN_W,SCREEN_H);
    buffer=create_bitmap(SCREEN_W,SCREEN_H);
    fond_collection=create_bitmap(800,1500);
    buffer_collection=create_bitmap(800,1500);
    fond_deck=create_bitmap(800,1500);
    buffer_deck=create_bitmap(800,1500);
    carte_verso=charger_image("verso.bmp");

    while(!key[KEY_ESC])
    {
        ///                     ///
        ///     MENU      ///
        ///                     ///
        clear_bitmap(fond);
        clear_bitmap(buffer);

        if("menu"==fond_affiche)
        {
            rectfill(buffer,0,0,SCREEN_W,SCREEN_H,makecol(0,0,0));
            afficherMenu(fond,buffer);
            if(mouse_b&1 && 0 == click)//début du click
            {
                click = 1;
            }
            if(mouse_b&1 && 1 == click)
            {
                //pendant le click
            }
            if( 1 == click && !mouse_b&1)//fin du click
            {
                if(getpixel(buffer,mouse_x,mouse_y) == makecol(101,101,101))
                {
                    allegro_message("Entrez dans la console le nom du Joueur 1.");
                    cin>>nom_joueur_1;
                    allegro_message("Entrez dans la console le nom du Joueur 2.");
                    cin>>nom_joueur_2;
                    fond_affiche = "nouvelle partie";
                }
                if(getpixel(buffer,mouse_x,mouse_y) == makecol(102,102,102))
                {
                    fond_affiche = "regles";
                }
                if(getpixel(buffer,mouse_x,mouse_y) == makecol(103,103,103))
                {
                    allegro_message("Entrez dans la console le nom du joueur voulant acheter des cartes.");
                    cin>>nom_joueur_boutique;
                    fond_affiche = "boutique";
                }
                if(getpixel(buffer,mouse_x,mouse_y) == makecol(104,104,104))
                {
                    allegro_message("Entrez dans la console le nom du joueur dont vous voulez voir la collection.");
                    cin>>nom_joueur_boutique;
                    fond_affiche = "voir collection";
                }
                if(getpixel(buffer,mouse_x,mouse_y) == makecol(105,105,105))
                {
                    allegro_message("Entrez dans la console le nom du joueur dont vous voulez voir le deck.");
                    cin>>nom_joueur_boutique;
                    fond_affiche = "voir deck";
                }
                if(getpixel(buffer,mouse_x,mouse_y) == makecol(106,106,106))
                {
                    allegro_message("Veuillez rentrer le nom de joueur a creer");
                    joueur = new Personne;
                    creerjoueur = true;
                    fond_affiche = "boutique";
                }
                if(getpixel(buffer,mouse_x,mouse_y) == makecol(107,107,107))
                {
                    allegro_message("Entrez dans la console le nom du joueur pour qui vous voulez modifier le deck.");
                    cin>>nom_joueur_boutique;
                    fond_affiche = "creer deck";
                }
                click = 0;
            }
        }
        ///                     ///
        ///NEW GAME ///
        ///                     ///
        else if("nouvelle partie" == fond_affiche)
        {
            if(random_joueur>=0 && random_joueur<=50)
            {
                joueur1 = new Personne(nom_joueur_1);
                joueur2 = new Personne(nom_joueur_2);
            }
            else if(random_joueur>50 && random_joueur<=100)
            {
                joueur1= new Personne(nom_joueur_2);
                joueur2= new Personne(nom_joueur_1);
            }
            //Le fait une seule fois
            if(boucleDeJeu==false)
            {

                if (joueur1 ->getOuvertureFichier() == true && joueur2->getOuvertureFichier() == true)
                {
                    joueur1->setNbrCreaMorte(0);
                    joueur2->setNbrCreaMorte(0);
                    comb = new Combat(joueur1, joueur2);
                    joueur1->Getcolec()->melangerDeck();
                    joueur2->Getcolec()->melangerDeck();
                    comb->choixcarteEnjeu();
                    comb->retirercarteEnjeu();
                }
                else
                {
                    allegro_message("Le joueur n'existe pas");
                    fond_affiche ="menu";
                    boucleDeJeu = false;
                }
                for (auto &el:comb->GetJoueur1()->Getcolec()->GetDeck())
                {
                    if (el->getType() == "Creature") comb->GetJoueur1()->Setcrea_actif(el);
                }

                for (auto &el:comb->GetJoueur2()->Getcolec()->GetDeck())
                {
                    if (el->getType() == "Creature") comb->GetJoueur2()->Setcrea_actif(el);
                }
                comb->Setdeck1(comb->GetJoueur1()->Getcolec()->GetDeck());
                comb->Setdeck2(comb->GetJoueur2()->Getcolec()->GetDeck());

                for(int i = 0; i<20; i++)
                {
                    if (comb->GetJoueur1()->Getcolec()->GetDeck()[i]->getType() == "Creature") comb->GetJoueur1()->setNbrCrea(comb->GetJoueur1()->getNbrCrea()+1);
                    if (comb->GetJoueur2()->Getcolec()->GetDeck()[i]->getType() == "Creature") comb->GetJoueur2()->setNbrCrea(comb->GetJoueur2()->getNbrCrea()+1);
                }
                while (IAchoix != "Valide")
                {
                    allegro_message(("Le joueur "+comb->GetJoueur1()->getNom()+" est il un IA ? Repondez par OUI ou NON dans la console").c_str());
                    cin>>IAchoix;
                    if(IAchoix == "OUI")
                    {
                        comb->setIAj1(true);
                        IAchoix = "Valide";
                    }
                    if(IAchoix == "NON")
                    {
                        comb->setIAj1(false);
                        IAchoix = "Valide";
                    }
                }
                IAchoix = "";
                while (IAchoix != "Valide")
                {
                    allegro_message(("Le joueur "+comb->GetJoueur2()->getNom()+" est il un IA ? Repondez par OUI ou NON dans la console").c_str());
                    cin>>IAchoix;
                    if(IAchoix == "OUI")
                    {
                        comb->setIAj2(true);
                        IAchoix = "Valide";
                    }
                    if(IAchoix == "NON")
                    {
                        comb->setIAj2(false);
                        IAchoix = "Valide";
                    }
                }
                victoire = 0;
                boucleDeJeu=true;
            }
            afficherBoucleDeJeu(fond, buffer,joueur1,joueur2,carte_verso);

            if(victoire == 0)
            {
                textprintf_centre_ex(fond,font,900,90,makecol(0,0,0),-1,("Vie de "+comb->GetJoueur1()->getNom()+" :").c_str());
                textprintf_centre_ex(fond,font,900,105,makecol(255,255,255),-1, "%d",comb->GetJoueur1()->Getvie());
                textprintf_centre_ex(fond,font,900,155,makecol(0,0,0),-1,("Vie de "+comb->GetJoueur2()->getNom()+" :").c_str());
                textprintf_centre_ex(fond,font,900,170,makecol(255,255,255),-1, "%d",comb->GetJoueur2()->Getvie());
                if (tourdejeuactif == true)
                {
                        affichage_joueur = 1;
                        comb->tourjoueur1(&carte_pioche,&choix_carte,&choix1,&choix2,&cartepioche,fond,buffer,&click, &tourdejeu);
                }
                if (tourdejeuactif == false)
                {
                        affichage_joueur = 2;
                        comb->tourjoueur2(&carte_pioche,&choix_carte,&choix1,&choix2,&cartepioche,fond,buffer,&click, &tourdejeu);
                }
                tourdejeuactif = tourdejeu;

                //Victoire du joueur1
                if (comb->GetJoueur1()->Getvie() <= 0 ) victoire = 1;
                if (comb->GetJoueur2()->getNbrCreaMorte() == comb->GetJoueur2()->getNbrCrea() - 1 && comb->GetJoueur2()->Getcrea_actif()->getVie() <= 0) victoire = 1;
                ///Victoire du joueur2
                if (comb->GetJoueur2()->Getvie() <= 0 ) victoire = 2;
                if (comb->GetJoueur1()->getNbrCreaMorte() == comb->GetJoueur1()->getNbrCrea() - 1 && comb->GetJoueur1()->Getcrea_actif()->getVie() <= 0) victoire = 2;
            }
            //Le joueur 1 gagne -> Carte enjeu
            if (victoire == 2)
            {
                cout<<"Victoire du joueur 1 !"<<endl;
                //On ajoute la carte enjeu du joueur 2 a la collection du joueur 1
                joueur1->ChargerCollection();
                joueur1->Recevoircarte(comb->GetJoueur2()->Getenjeu());
                //On retire la carte enjeu de la collection du joueur 2
                joueur2->ChargerCollection();
                joueur2->Getcolec()->Retirercartecolec(comb->GetJoueur2()->Getenjeu());
                //Le perdant doit recreer un deck
                nom_joueur_boutique = nom_joueur_2;
                cout<<"NOM JOUEUR 2" <<nom_joueur_2;
                fond_affiche = "creer deck";
                //On sauvegarde tt les fichiers
                joueur1->SaveFichierColec();
                joueur1->SaveFichierDeck();
                joueur2->SaveFichierColec();
                joueur2->SaveFichierDeck();
                boucleDeJeu = false;
                IAchoix = "";
                joueur1->resetpers();
                joueur2->resetpers();
            }
            ///Le joueur 2 gagne -> Carte enjeu
            if (victoire == 1)
            {
                cout<<"Victoire du joueur 2 !"<<endl;
                joueur2->ChargerCollection();
                joueur1->ChargerCollection();
                //On ajoute la carte enjeu du joueur 1 a la collection du joueur 2
                joueur1->Recevoircarte(comb->GetJoueur1()->Getenjeu());
                //On retire la carte enjeu de la collection du joueur 1
                joueur1->Getcolec()->Retirercartecolec(comb->GetJoueur2()->Getenjeu());
                //On remet la cate enjeu du joueur 2 dans son deck
                joueur2->Getcolec()->Ajoutcartedeck(comb->GetJoueur2()->Getenjeu());
                //Le perdant doit recreer un deck
                nom_joueur_boutique = nom_joueur_1;
                fond_affiche = "creer deck";
                //On sauvegarde ts les fichiers
                joueur1->SaveFichierColec();
                joueur1->SaveFichierDeck();
                joueur2->SaveFichierColec();
                joueur2->SaveFichierDeck();
                boucleDeJeu = false;
                IAchoix = "";
                joueur1->resetpers();
                joueur2->resetpers();
            }
            rectfill(buffer,0,0,SCREEN_W,SCREEN_H,makecol(0,0,0));
            //Affichage du fond

            //Affichage Pioche

            /**
                        ///Affichage des cartes enjeu des deux joueurs, demandé masquées dans le CDC
                        //Nom des cartes enjeu
                        textprintf_centre_ex(fond,font,900,545,makecol(255,255,255),-1,(""+comb->GetJoueur1()->Getenjeu()->getNom()).c_str());
                        textprintf_centre_ex(fond,font,900,595,makecol(255,255,255),-1,(""+comb->GetJoueur2()->Getenjeu()->getNom()).c_str());

                        afficherCarteEnjeu(fond,buffer,image,comb->GetJoueur1()->Getenjeu()->getNom(), 395);
                        afficherCarteEnjeu(fond,buffer,image,comb->GetJoueur2()->Getenjeu()->getNom(), 70 );
            **/
            //Affichage des cartes créatures actives des deux joueurs
            //Affichage de la derniere carte energie posée pour les deux joueurs
            //Affichage de la derniere carte mise au cimetiere pour chaque joueur

            if(affichage_joueur == 1)
            {
                afficherCreatureActive(fond,buffer,image,comb->GetJoueur1()->Getcrea_actif()->getNom(),290);
                if(comb->GetJoueur1()->Getener_actif().size() > 0)
                {
                    //Seulement si le vecteur n'est pas vide
                    afficherEnergies(fond,buffer,image, comb->GetJoueur1()->Getener_actif().back()->getNom(),60,290,60+80,290+116);
                }
                if(comb->GetJoueur1()->Getcimetiere().size() > 0)
                {
                    //Seulement si le vecteur n'est pas vide
                    afficherDerniereCarteCimetiere(fond,buffer,image,comb->GetJoueur1()->Getcimetiere().back()->getNom(),420,420,420+80,420+116);
                }
                afficherPioche(fond,buffer,image,cartepioche->getNom(),420);
                textprintf_ex(fond,font,60,425,makecol(149,86,40),-1," Vit A : %d",comb->GetJoueur1()->Getcrea_actif()->getVitA());
                textprintf_ex(fond,font,60,445,makecol(149,86,40),-1," Vit B : %d",comb->GetJoueur1()->Getcrea_actif()->getVitB());
                textprintf_ex(fond,font,60,465,makecol(149,86,40),-1," Vit C : %d",comb->GetJoueur1()->Getcrea_actif()->getVitC());
                textprintf_ex(fond,font,60,485,makecol(149,86,40),-1," Vit D : %d",comb->GetJoueur1()->Getcrea_actif()->getVitD());

                if(mouse_x>60 && mouse_x<140 && mouse_y> 290 && mouse_y< 406)
                {
                    //C EST ICI QU ON VEUT LE AFFICHER VECTEUR ENERGIE
                    afficherVecteurEnergiesActives(fond,buffer,image,comb->GetJoueur1()->Getener_actif());
                }
            }
            if(affichage_joueur == 2)
            {
                afficherCreatureActive(fond,buffer,image,comb->GetJoueur2()->Getcrea_actif()->getNom(),160);
                if(comb->GetJoueur2()->Getener_actif().size() > 0)
                {
                    //Seulement si le vecteur n'est pas vide
                    afficherEnergies(fond,buffer,image, comb->GetJoueur2()->Getener_actif().back()->getNom(),420,160,420+80,160+116);
                }
                if(comb->GetJoueur2()->Getcimetiere().size() > 0)
                {
                    //Seulement si le vecteur n'est pas vide
                    afficherDerniereCarteCimetiere(fond,buffer,image,comb->GetJoueur2()->Getcimetiere().back()->getNom(),60,30,60+80,30+116);
                }
                afficherPioche(fond,buffer,image,cartepioche->getNom(),30);
                textprintf_ex(fond,font,420,55,makecol(149,86,40),-1," Vit A : %d",comb->GetJoueur2()->Getcrea_actif()->getVitA());
                textprintf_ex(fond,font,420,75,makecol(149,86,40),-1," Vit B : %d",comb->GetJoueur2()->Getcrea_actif()->getVitB());
                textprintf_ex(fond,font,420,95,makecol(149,86,40),-1," Vit C : %d",comb->GetJoueur2()->Getcrea_actif()->getVitC());
                textprintf_ex(fond,font,420,115,makecol(149,86,40),-1," Vit D : %d",comb->GetJoueur2()->Getcrea_actif()->getVitD());

                if(mouse_x>420 && mouse_x< 500 && mouse_y>160 && mouse_y< 276)
                {
                    //C EST ICI QU ON VEUT LE AFFICHER VECTEUR ENERGIE
                    afficherVecteurEnergiesActives(fond,buffer,image,comb->GetJoueur2()->Getener_actif());
                }
            }
            //Affichage des cartes spéciales, que l'on n'activera pas parce que toutes nos cartes sont à effet instantané, et donc ne restent pas sur le terrain
//            if(comb->GetJoueur1()->Getspe_actif())
//            {
//                afficherSpeciale(fond,buffer,image,comb->GetJoueur1()->Getspe_actif()->getNom(), 420,290,420+80,290+116);
//            }
//            if(comb->GetJoueur2()->Getspe_actif())
//            {
//                afficherSpeciale(fond,buffer,image,comb->GetJoueur2()->Getspe_actif()->getNom(),60,160,60+80,160+116);
//            }

            //Affichage des zoom peu importe le joueur
            afficherZoom(fond,buffer,image,comb->GetJoueur1()->Getcrea_actif()->getVie(), comb->GetJoueur2()->Getcrea_actif()->getVie());

            if(mouse_b&1 && 0 == click)//début du click
            {
                click = 1;
            }
            if( 1 == click && !mouse_b&1)//fin du click
            {
                if(getpixel(buffer,mouse_x,mouse_y) == makecol(037,037,037))
                {
                    boucleDeJeu = false;
                    delete joueur1;
                    delete joueur2;
                    delete comb;
                    fond_affiche = "menu";
                }
                click = 0;
            }
        }
        ///                      ///
        ///     REGLES    ///
        ///                     ///
        if("regles"==fond_affiche)
        {
            rectfill(buffer,0,0,SCREEN_W,SCREEN_H,makecol(0,0,0));
            afficherRegles(fond,buffer);
            testClick(buffer,makecol(210,210,210),"menu",&fond_affiche,&click);
        }
        ///                     ///
        /// BOUTIQUE  ///
        ///                     ///
        if("boutique"==fond_affiche)
        {
            rectfill(buffer,0,0,SCREEN_W,SCREEN_H,makecol(0,0,0));
            if(creerjoueur == false)joueur = new Personne(nom_joueur_boutique);
            afficherBoutique(fond,buffer,image,joueur);
            if(creerjoueur == true) rectfill(fond,805,15,995,75,makecol(149,86,40));
            if( joueur->getOuvertureFichier() == false && creerjoueur == false)
            {
                allegro_message("Le joueur n'existe pas");
                fond_affiche ="menu";
            }
            if(mouse_b&1 && 0 == click)//début du click
            {
                click = 1;
            }
            if(mouse_b&1 && 1 == click)
            {
                //pendant le click, A LAISSER VIDE
            }
            if( 1 == click && !mouse_b&1)//fin du click
            {
                if(getpixel(buffer,mouse_x,mouse_y) != makecol(030,030,030))
                {
                    if(joueur->GetArgent()>= 5)
                    {
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(1,1,1))
                        {
                            mag->achetercarte(joueur,"b1");
                            allegro_message("Carte Vitamine B1 achetee!");
                            joueur->SetArgent(joueur->GetArgent()-5);
                            joueur->SaveFichierColec();
                            cptcreerjoueur++;
                        }
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(2,2,2))
                        {
                            mag->achetercarte(joueur,"b2");
                            allegro_message("Carte Vitamine B2 achetee!");
                            joueur->SetArgent(joueur->GetArgent()-5);
                            joueur->SaveFichierColec();
                            cptcreerjoueur++;
                        }
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(3,3,3))
                        {
                            mag->achetercarte(joueur,"acideAscorbique");
                            allegro_message("Carte Acide Ascorbique achetee!");
                            joueur->SetArgent(joueur->GetArgent()-5);
                            joueur->SaveFichierColec();
                            cptcreerjoueur++;
                        }
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(4,4,4))
                        {
                            mag->achetercarte(joueur,"cerveau");
                            allegro_message("Carte Cerveau achetee!");
                            joueur->SetArgent(joueur->GetArgent()-5);
                            joueur->SaveFichierColec();
                            cptcreerjoueur++;
                        }
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(5,5,5))
                        {
                            mag->achetercarte(joueur,"coeur");
                            allegro_message("Carte Coeur achetee!");
                            joueur->SetArgent(joueur->GetArgent()-5);
                            joueur->SaveFichierColec();
                            cptcreerjoueur++;
                        }
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(6,6,6))
                        {
                            mag->achetercarte(joueur,"calciferol");
                            allegro_message("Carte Calciferol achetee!");
                            joueur->SetArgent(joueur->GetArgent()-5);
                            joueur->SaveFichierColec();
                            cptcreerjoueur++;
                        }
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(7,7,7))
                        {
                            mag->achetercarte(joueur,"boostDegat");
                            allegro_message("Carte Boost de Degats achetee!");
                            joueur->SetArgent(joueur->GetArgent()-5);
                            joueur->SaveFichierColec();
                            cptcreerjoueur++;
                        }
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(8,8,8))
                        {
                            mag->achetercarte(joueur,"evolution");
                            allegro_message("Carte Evolution achetee!");
                            joueur->SetArgent(joueur->GetArgent()-5);
                            joueur->SaveFichierColec();
                            cptcreerjoueur++;
                        }
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(9,9,9))
                        {
                            mag->achetercarte(joueur,"foie");
                            allegro_message("Carte Foie achetee!");
                            joueur->SetArgent(joueur->GetArgent()-5);
                            joueur->SaveFichierColec();
                            cptcreerjoueur++;
                        }
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(10,10,10))
                        {
                            mag->achetercarte(joueur,"pancreas");
                            allegro_message("Carte Pancreas achetee!");
                            joueur->SetArgent(joueur->GetArgent()-5);
                            joueur->SaveFichierColec();
                            cptcreerjoueur++;
                        }
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(11,11,11))
                        {
                            mag->achetercarte(joueur,"passeTour");
                            allegro_message("Carte Passe ton Tour achetee!");
                            joueur->SetArgent(joueur->GetArgent()-5);
                            joueur->SaveFichierColec();
                            cptcreerjoueur++;
                        }
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(12,12,12))
                        {
                            mag->achetercarte(joueur,"poumon");
                            allegro_message("Carte Poumon achetee!");
                            joueur->SetArgent(joueur->GetArgent()-5);
                            joueur->SaveFichierColec();
                            cptcreerjoueur++;
                        }
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(13,13,13))
                        {
                            mag->achetercarte(joueur,"rein");
                            allegro_message("Carte Rein achetee!");
                            joueur->SetArgent(joueur->GetArgent()-5);
                            joueur->SaveFichierColec();
                            cptcreerjoueur++;
                        }
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(14,14,14))
                        {
                            mag->achetercarte(joueur,"renvoi");
                            allegro_message("Carte Renvoi de Degats achetee!");
                            joueur->SetArgent(joueur->GetArgent()-5);
                            joueur->SaveFichierColec();
                            cptcreerjoueur++;
                        }
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(15,15,15))
                        {
                            mag->achetercarte(joueur,"retinol");
                            allegro_message("Carte Retinol achetee!");
                            joueur->SetArgent(joueur->GetArgent()-5);
                            joueur->SaveFichierColec();
                            cptcreerjoueur++;
                        }
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(16,16,16))
                        {
                            mag->achetercarte(joueur,"tretinoine");
                            allegro_message("Carte Tretinoine achetee!");
                            joueur->SetArgent(joueur->GetArgent()-5);
                            joueur->SaveFichierColec();
                            cptcreerjoueur++;
                        }
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(17,17,17))
                        {
                            mag->achetercarte(joueur,"boostVie");
                            allegro_message("Carte Boost de Vie achetee!");
                            joueur->SetArgent(joueur->GetArgent()-5);
                            joueur->SaveFichierColec();
                            cptcreerjoueur++;
                        }
                        if(getpixel(buffer,mouse_x,mouse_y) == makecol(18,18,18))
                        {
                            mag->achetercarte(joueur,"any");
                            allegro_message("Carte Vitamine Universelle achetee!");
                            joueur->SetArgent(joueur->GetArgent()-5);
                            joueur->SaveFichierColec();
                            cptcreerjoueur++;
                        }
                    }
                    else if(joueur->GetArgent()<5)
                    {
                        if((getpixel(buffer,mouse_x,mouse_y) != makecol(0,0,0)) && (getpixel(buffer,mouse_x,mouse_y) != makecol(030,030,030)) )
                        {
                            allegro_message("Vous n'avez plus assez d'argent! Retour au menu immediat!");
                            fond_affiche = "menu";
                        }
                    }
                }
                else if(getpixel(buffer,mouse_x,mouse_y) == makecol(030,030,030) && creerjoueur == false )
                {
                    fond_affiche = "menu";
                }
                if(cptcreerjoueur == 30 && creerjoueur == true)
                {
                    fond_affiche = "creer deck";
                    cptcreerjoueur = 0;
                }
                click = 0;
            }
        }
        ///                                     ///
        ///   VOIR COLLECTION    ///
        ///                                     ///
        if("voir collection" == fond_affiche)
        {
            rectfill(buffer,0,0,SCREEN_W,SCREEN_H,makecol(0,0,0));
            Personne* joueur = new Personne(nom_joueur_boutique);
            if( joueur->getOuvertureFichier() == false)
            {
                allegro_message("Le joueur n'existe pas");
                fond_affiche ="menu";
            }
            afficherCollection(fond, buffer,image,joueur,joueur->Getcolec()->GetCollection(),&posmapy,fond_collection,buffer_collection);
            testClick(buffer,makecol(033,033,033),"menu",&fond_affiche,&click);
        }
        ///                                     ///
        ///         VOIR DECK          ///
        ///                                     ///
        if("voir deck" == fond_affiche)
        {
            rectfill(buffer,0,0,SCREEN_W,SCREEN_H,makecol(0,0,0));
            joueur = new Personne(nom_joueur_boutique);
            if( joueur->getOuvertureFichier() == false)
            {
                allegro_message("Le joueur n'existe pas");
                fond_affiche ="menu";
            }
            afficherDeck(fond, buffer,image,joueur,&posmapy,fond_deck,buffer_deck);
            testClick(buffer,makecol(035,035,035),"menu",&fond_affiche,&click);
        }
        ///                                    ///
        ///       CREER DECK        ///
        ///                                   ///
        if("creer deck" == fond_affiche)
        {
            //On commense par afficher la collection
            rectfill(buffer,0,0,SCREEN_W,SCREEN_H,makecol(0,0,0));
            //A faire seulement lors de la premiere ouverture
            if("creer deck" == fond_affiche && creationdeck == false)
            {
                //Chargement du joueur, destruction de l'ancien deck et sauvegarde de la collection
                if(creerjoueur == false)joueur = new Personne(nom_joueur_boutique);
                creationdeck = true;
                if (joueur ->getOuvertureFichier() == true || creerjoueur == true)
                {
                    if(creerjoueur == false) joueur->Getcolec()->detruiredeck();
                    save = joueur->Getcolec()->GetCollection();
                }
                if(joueur->getOuvertureFichier() == false && creerjoueur == false)
                {
                    allegro_message("Le joueur n'existe pas");
                    fond_affiche ="menu";
                    creationdeck = false;
                }
            }
            afficherCollection(fond, buffer,image,joueur, save, &posmapy,fond_collection,buffer_collection);
            if(creerjoueur == true) rectfill(fond,805,15,995,75,makecol(149,86,40));
            textprintf_centre_ex(fond,font,900,500,makecol(254,254,226),-1,"Prenez encore %d cartes.",21-cpt);
            rectfill(fond,805,550,999,610,makecol(149,86,40));
            if(mouse_b&1 && 0 == click)//début du click
            {
                click = 1;
            }
            if(mouse_b&1 && 1 == click)
            {
                //pendant le click, A LAISSER VIDE
            }
            //Lorsque l'on clique sur une carte
            if( 1 == click && !mouse_b&1)//fin du click
            {
                if(getpixel(buffer,mouse_x,mouse_y) != makecol(030,030,030))
                {
                    // On capte la couleur du buffer pour connaitre la carte
                    if(getpixel(buffer,mouse_x,mouse_y) == makecol(1,1,1))
                    {
                        //On initialise la carte
                        carte = new VitB1;
                        // On affiche la carte ajouter
                        allegro_message("Carte Vitamine B1 ajoutee au deck");
                        //On la retire du vecteur d'affichage
                        retirercarteveteur(&save, carte);
                        //On l'ajoute au deck
                        joueur->Getcolec()->Ajoutcartedeck(carte);
                        // On augmente le compteur
                        cpt++;
                    }
                    if(getpixel(buffer,mouse_x,mouse_y) == makecol(2,2,2))
                    {
                        carte = new VitB2;
                        allegro_message("Carte Vitamine B2 ajoutee au deck");
                        retirercarteveteur(&save, carte);
                        joueur->Getcolec()->Ajoutcartedeck(carte);
                        cpt++;
                    }
                    if(getpixel(buffer,mouse_x,mouse_y) == makecol(3,3,3))
                    {
                        carte = new AcideAscorbique;
                        allegro_message("Carte Acide Ascorbique ajoutee au deck");
                        retirercarteveteur(&save, carte);
                        joueur->Getcolec()->Ajoutcartedeck(carte);
                        cpt++;
                    }
                    if(getpixel(buffer,mouse_x,mouse_y) == makecol(4,4,4))
                    {
                        carte = new Cerveau;
                        allegro_message("Carte Cerveau ajoutee au deck");
                        retirercarteveteur(&save, carte);
                        joueur->Getcolec()->Ajoutcartedeck(carte);
                        cpt++;;
                    }
                    if(getpixel(buffer,mouse_x,mouse_y) == makecol(5,5,5))
                    {
                        carte = new Coeur;
                        allegro_message("Carte Coeur ajoutee au deck");
                        retirercarteveteur(&save, carte);
                        joueur->Getcolec()->Ajoutcartedeck(carte);
                        cpt++;
                    }
                    if(getpixel(buffer,mouse_x,mouse_y) == makecol(6,6,6))
                    {
                        carte = new Calciferol;
                        allegro_message("Carte Calciferol ajoutee au deck");
                        retirercarteveteur(&save, carte);
                        joueur->Getcolec()->Ajoutcartedeck(carte);
                        cpt++;;
                    }
                    if(getpixel(buffer,mouse_x,mouse_y) == makecol(7,7,7))
                    {
                        carte = new BoostDegat;
                        allegro_message("Carte Boost de Degats ajoutee au deck");
                        retirercarteveteur(&save, carte);
                        joueur->Getcolec()->Ajoutcartedeck(carte);
                        cpt++;;
                    }
                    if(getpixel(buffer,mouse_x,mouse_y) == makecol(8,8,8))
                    {
                        carte = new Evolution;
                        allegro_message("Carte Evolution ajoutee au deck");
                        retirercarteveteur(&save, carte);
                        joueur->Getcolec()->Ajoutcartedeck(carte);
                        cpt++;
                    }
                    if(getpixel(buffer,mouse_x,mouse_y) == makecol(9,9,9))
                    {
                        carte = new Foie;
                        allegro_message("Carte Foie ajoutee au deck");
                        retirercarteveteur(&save, carte);
                        joueur->Getcolec()->Ajoutcartedeck(carte);
                        cpt++;;
                    }
                    if(getpixel(buffer,mouse_x,mouse_y) == makecol(10,10,10))
                    {
                        carte = new Pancreas;
                        allegro_message("Carte Pancreas ajoutee au deck");
                        retirercarteveteur(&save, carte);
                        joueur->Getcolec()->Ajoutcartedeck(carte);
                        cpt++;;
                    }
                    if(getpixel(buffer,mouse_x,mouse_y) == makecol(11,11,11))
                    {
                        carte = new PasserTour;
                        allegro_message("Carte Passe ton Tour ajoutee au deck");
                        retirercarteveteur(&save, carte);
                        joueur->Getcolec()->Ajoutcartedeck(carte);
                        cpt++;
                    }
                    if(getpixel(buffer,mouse_x,mouse_y) == makecol(12,12,12))
                    {
                        carte = new Poumon;
                        allegro_message("Carte Poumon ajoutee au deck");
                        retirercarteveteur(&save, carte);
                        joueur->Getcolec()->Ajoutcartedeck(carte);
                        cpt++;
                    }
                    if(getpixel(buffer,mouse_x,mouse_y) == makecol(13,13,13))
                    {
                        carte = new Rein;
                        allegro_message("Carte Rein ajoutee au deck");
                        retirercarteveteur(&save, carte);
                        joueur->Getcolec()->Ajoutcartedeck(carte);
                        cpt++;
                    }
                    if(getpixel(buffer,mouse_x,mouse_y) == makecol(14,14,14))
                    {
                        carte = new Renvoi;
                        allegro_message("Carte Renvoi de Degats ajoutee au deck");
                        retirercarteveteur(&save, carte);
                        joueur->Getcolec()->Ajoutcartedeck(carte);
                        cpt++;
                    }
                    if(getpixel(buffer,mouse_x,mouse_y) == makecol(15,15,15))
                    {
                        carte = new Retinol;
                        allegro_message("Carte Retinol ajoutee au deck");
                        retirercarteveteur(&save, carte);
                        joueur->Getcolec()->Ajoutcartedeck(carte);
                        cpt++;
                    }
                    if(getpixel(buffer,mouse_x,mouse_y) == makecol(16,16,16))
                    {
                        carte = new Tretinoine;
                        allegro_message("Carte Tretinoine ajoutee au deck");
                        retirercarteveteur(&save, carte);
                        joueur->Getcolec()->Ajoutcartedeck(carte);
                        cpt++;
                    }
                    if(getpixel(buffer,mouse_x,mouse_y) == makecol(17,17,17))
                    {
                        carte = new BoostVie;
                        allegro_message("Carte Boost de Vie ajoutee au deck");
                        retirercarteveteur(&save, carte);
                        joueur->Getcolec()->Ajoutcartedeck(carte);
                        cpt++;
                    }
                    if(getpixel(buffer,mouse_x,mouse_y) == makecol(18,18,18))
                    {
                        carte = new Any;
                        allegro_message("Carte Vitamine Universelle ajoutee au deck");
                        retirercarteveteur(&save, carte);
                        joueur->Getcolec()->Ajoutcartedeck(carte);
                        cpt++;
                    }
                }
                click = 0;
            }
            //Lorsque l'on a le bon nombre de carte
            if (cpt == 21)
            {
                //On sauvegarde le deck
                joueur->SaveFichierDeck();
                //Le comtpteur retourne a 0
                cpt = 0;
                //On retourne au menu
                fond_affiche = "menu";
                creationdeck = false;
                creerjoueur = false;
            }
        }
        blit(fond,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
    return 0;
}
END_OF_MAIN();
