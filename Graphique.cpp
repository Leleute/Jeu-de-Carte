#include <iostream>
#include <vector>
#include "allegro.h"
#include "Personne.h"

using namespace std;
//fonctions de base
void allegro()
{
      //Initialisation du mode console
    allegro_init();
    set_color_depth(desktop_color_depth()); // mode graphique initialisation
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1000,650,0,0)!=0) // pas d'affichage (écran noir) si ces deux lignes sont apres les "prend la valeur" des BITMAP
    {
        allegro_message("Erreur mode graphique");
        allegro_exit(); // quitter si probleme
        exit(EXIT_FAILURE);
    }
    install_keyboard();
    install_mouse();
    show_mouse(screen);
}

//Fonction pour charger une BITMAP
BITMAP* charger_image(char nom_fichier[40])
{
    BITMAP* bmp;
    bmp=load_bitmap(nom_fichier,NULL);

    if (!bmp)
    {
        allegro_message("failed to charge : %s ", nom_fichier);
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    else cout<<nom_fichier<<" charge avec succes"<<endl;
    // else printf ("\n%s charge avec succes", nom_fichier);
    return bmp;
}

//Dessine un rectangle, et réagit en changeant de couleur quand on pose la souris dessus
void rectangleAnime(BITMAP*fond,int x1, int y1, int x2, int y2/*, string texte*/)
{
    if(mouse_x>x1 && mouse_x<x2 && mouse_y>y1 && mouse_y<y2)
    {
        rectfill(fond, x1,y1,x2,y2, makecol(121,121,248));
    }
    else
    {
        rectfill(fond, x1,y1,x2,y2, makecol(225,206,154));
    }
    //textprintf_centre_ex(fond, font,(x1+x2)/2,(y1+y2)/2, makecol(0,0,0), -1, texte);
}

//Fonction de retour au menu lors d'un click sur boutton retour
void testClick(BITMAP* bmp, int color, string phase, string* fond_affiche, int* click)
{
    //début du click
    if(mouse_b&1 && 0 == *click)
    {
        *click = 1;

    }
    if(mouse_b&1 && 1 == *click)
    {
        //pendant le click
    }
    //fin du click
    if( 1 == *click && !mouse_b&1)
    {

        if(getpixel(bmp,mouse_x,mouse_y) == color)
        {
            *fond_affiche = phase;
        }
        *click = 0;
    }
}

//fonctions du jeu
//          //
//MENU//
//          //
void afficherMenu(BITMAP* fond, BITMAP* buffer)
{
    ///menu fond
    rectfill(fond, 0,0,SCREEN_W,SCREEN_H, makecol(254,254,226));
    ///rectangles animés
    //Colonne 1
    rectangleAnime(fond,70,70,260,170);
    textprintf_centre_ex(fond, font,165,120, makecol(0,0,0), -1, "NOUVELLE PARTIE");

    rectangleAnime(fond, 70,270,260,370);
    textprintf_centre_ex(fond, font,165,320, makecol(0,0,0), -1, "REGLES DU JEU");

    rectangleAnime(fond, 70,470,260,570);
    textprintf_centre_ex(fond, font,165,520, makecol(0,0,0), -1, "BOUTIQUE");
//Colonne 2
    rectangleAnime(fond, 400,70,590, 170);
    textprintf_centre_ex(fond, font,495,105, makecol(0,0,0), -1, "VOIR LA COLLECTION");
    textprintf_centre_ex(fond, font,495,135, makecol(0,0,0), -1, "D' UN JOUEUR");

    rectangleAnime(fond,400, 270, 590,370);
    textprintf_centre_ex(fond, font,495,305, makecol(0,0,0), -1, "VOIR LE DECK");
    textprintf_centre_ex(fond, font,495,335, makecol(0,0,0), -1, "D' UN JOUEUR");
//colonne 3 Quitter
    rectangleAnime(fond, 730,70,920, 170);
    textprintf_centre_ex(fond, font,825,105, makecol(0,0,0), -1, "MODIFIER LE DECK");
    textprintf_centre_ex(fond, font,825,135, makecol(0,0,0), -1, "D' UN JOUEUR");

    rectangleAnime(fond,400, 470,590,570);
    textprintf_centre_ex(fond, font,495,520, makecol(0,0,0), -1, "CREER UN JOUEUR");//Colonne 2

    if(mouse_x>730 && mouse_x<920 && mouse_y>270 && mouse_y<370 )
    {
        rectfill(fond, 730, 270,920, 370, makecol(231,62,1));
        if(mouse_b&1) //pas besoin que fond_affiche prenne une valeur, on quitte le programme direct
        {
            allegro_message("         A BIENTOT !");
            exit(1);
        }

    }
    else
    {
        rectfill(fond, 730, 270,920, 370, makecol(225,206,154));
    }
    textprintf_centre_ex(fond, font,825,320, makecol(0,0,0), -1, "QUITTER LE JEU");
    //buffer sous-jacent des bouttons
    rectfill(buffer,70,70,260,170,makecol(101,101,101));//new game
    rectfill(buffer,70,270,260,370,makecol(102,102,102));//regles
    rectfill(buffer,70,470,260,570,makecol(103,103,103));//boutique
    rectfill(buffer,400,70,590, 170,makecol(104,104,104));//voir collection
    rectfill(buffer,400, 270, 590,370,makecol(105,105,105));//voir deck
    rectfill(buffer,400, 470,590,570,makecol(106,106,106));//stats
    rectfill(buffer,730,70,920, 170,makecol(107,107,107));
}
//            //
//REGLES//
//            //
void afficherRegles(BITMAP* fond, BITMAP* buffer)
{
    //le fond
    rectfill(fond, 0,0,SCREEN_W,SCREEN_H, makecol(254,254,226));
    //le texte des règles
    textprintf_centre_ex(fond,font,500,120,makecol(149,86,40),-1,"Chaque joueur peut se constituer un deck a partir de sa collection, dans le but de s'affronter en 1 contre 1.");
    rect(fond,350,190,650,215,makecol(149,86,40));
    textprintf_centre_ex(fond,font,500,200,makecol(149,86,40),-1,"Un deck constitue un corps humain.");
    textprintf_centre_ex(fond,font,500,280,makecol(149,86,40),-1,"Les organes vitaux feront office de cartes creature, les cartes energie seront symbolisees par les vitamines A, B, C, D et E");
    textprintf_centre_ex(fond,font,500,300,makecol(149,86,40),-1,"et les cartes speciales representeront la prise de produits dopants, pouvant avoir des effets secondaires indesirables.");
    textprintf_centre_ex(fond,font,500,380,makecol(149,86,40),-1,"Au cours d'un match, un organe vital en attaque un autre par le biais de maladies, et se defend des attaques ennemies");
    textprintf_centre_ex(fond,font,500,400,makecol(149,86,40),-1,"en prenant des medicaments.");
    //le bouton retour
    rectangleAnime(fond,405, 490,595,550);
    textprintf_centre_ex(fond, font,500,520, makecol(0,0,0), -1, "COMPRIS !");
    //le buffer
    rectfill(buffer,405, 490,595,550,makecol(210,210,210));
}
//                  //
//BOUTIQUE//
//                  //
void afficherBoutique(BITMAP* fond, BITMAP* buffer,vector<BITMAP*> image,Personne*joueur)
{
    //le fond
    rectfill(fond, 0,0,SCREEN_W,SCREEN_H, makecol(254,254,226));
    textprintf_centre_ex(fond,font,400,15,makecol(149,86,40),-1,"BOUTIQUE");
    rect(fond,365,12,435,25,makecol(149,86,40));
    //marge de droite
    rectfill(fond,800,0,SCREEN_W,SCREEN_H,makecol(149,86,40));
    //le bouton retour
    rectangleAnime(fond,805,15,995,75);
    textprintf_centre_ex(fond,font,900,45,makecol(0,0,0),-1,"RETOUR");
    //son buffer
    rectfill(buffer,805,15,995,75,makecol(030,030,030));
    //les informations
    //Nom du joueur
    textprintf_ex(fond,font,820,100,makecol(0,0,0),-1,("Joueur : "+ joueur->getNom()).c_str());
    //Son argent
    textprintf_ex(fond,font,820,160,makecol(0,0,0),-1,"Argent restant : %d", joueur->GetArgent());
    rect(fond,805,200,995,476,makecol(255,255,255));
    int posx = 5;
    int posy = 100;
    int couleur_image = 1;
    //Affiche les cartes et les rectangles associés sur le buffer en arriere_plan
    for(int carte = 0; carte<18; carte++)
    {
        if(posx<= 800)
        {
            blit(image[carte],fond,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer,posx,posy,posx+80,posy+116,makecol(couleur_image,couleur_image,couleur_image));
        }
        else if(posx > 800)
        {
            posy += 200;
            posx = 5;
            blit(image[carte],fond,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer,posx,posy,posx+80,posy+116,makecol(couleur_image,couleur_image,couleur_image));
        }
        if(getpixel(buffer,mouse_x,mouse_y) == makecol(couleur_image,couleur_image,couleur_image))
        {
            blit(image[18+carte],fond,0,0,805,200,SCREEN_W,SCREEN_H);
        }
        posx += 100;
        couleur_image++;
    }
}
//                     //
//COLLECTION//
//                     //
void afficherCollection(BITMAP* fond, BITMAP* buffer,vector<BITMAP*> image,Personne* joueur,vector <Carte*> colec,float*posmapy,BITMAP*fond_collection,BITMAP*buffer_collection)
{
    rectfill(buffer,0,0,SCREEN_W,SCREEN_H+(*posmapy),makecol(0,0,0));
    //le fond
    rectfill(fond, 0,0,SCREEN_W,SCREEN_H, makecol(254,254,226));
    textprintf_centre_ex(fond,font,400,15,makecol(149,86,40),-1,"COLLECTION");
    rect(fond,350,12,450,25,makecol(149,86,40));
    //le  fond_collection sur le fond
    rectfill(fond_collection,0,0,fond_collection->w,fond_collection->h,makecol(255,0,255));
    //le buffer_collection sur le fond
    rectfill(buffer_collection,0,0,buffer_collection->w,buffer_collection->h,makecol(255,0,255));
    //marge de droite
    rectfill(fond,800,0,SCREEN_W,SCREEN_H,makecol(149,86,40));
    //rectangle vide
    rect(fond,805,150,805+190,150+276,makecol(255,255,255));
    //le bouton retour
    rectangleAnime(fond,805,550,995,610);
    textprintf_centre_ex(fond,font,900,580,makecol(0,0,0),-1,"RETOUR");
    //son buffer
    rectfill(buffer,805,550,995,610,makecol(033,033,033));
    //nom du joueur
    textprintf_centre_ex(fond,font,900,100,makecol(254,254,226),-1,("Joueur : "+ joueur->getNom()).c_str());
    int posx = 5;
    int posy = 50;
    for(auto &el:colec)
    {
        if(el->getNom() == "VitamineB1")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[0], fond_collection,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_collection,posx,posy,posx+80,posy+116,makecol(1,1,1));
        }
        else  if(el->getNom() == "VitamineB2")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[1], fond_collection,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_collection,posx,posy,posx+80,posy+116,makecol(2,2,2));
        }
        else if(el->getNom() == "Acide_L-ascorbique")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[2], fond_collection,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_collection,posx,posy,posx+80,posy+116,makecol(3,3,3));
        }
        else if(el->getNom() == "Cerveau")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[3], fond_collection,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_collection,posx,posy,posx+80,posy+116,makecol(4,4,4));
        }
        else if(el->getNom() == "Coeur")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[4], fond_collection,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_collection,posx,posy,posx+80,posy+116,makecol(5,5,5));
        }
        else if(el->getNom() == "Calciferol")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[5], fond_collection,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_collection,posx,posy,posx+80,posy+116,makecol(6,6,6));
        }
        else if(el->getNom() == "Boost_de_degat")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[6], fond_collection,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_collection,posx,posy,posx+80,posy+116,makecol(7,7,7));
        }
        else if(el->getNom() == "Evolution")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[7], fond_collection,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_collection,posx,posy,posx+80,posy+116,makecol(8,8,8));
        }
        else if(el->getNom() == "Foie")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[8], fond_collection,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_collection,posx,posy,posx+80,posy+116,makecol(9,9,9));
        }
        else if(el->getNom() == "Pancreas")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[9], fond_collection,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_collection,posx,posy,posx+80,posy+116,makecol(10,10,10));
        }
        else if(el->getNom() == "Passe_ton_tour")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[10], fond_collection,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_collection,posx,posy,posx+80,posy+116,makecol(11,11,11));
        }
        else if(el->getNom() == "Poumon")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[11], fond_collection,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_collection,posx,posy,posx+80,posy+116,makecol(12,12,12));
        }
        else if(el->getNom() == "Rein")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[12], fond_collection,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_collection,posx,posy,posx+80,posy+116,makecol(13,13,13));
        }
        else if(el->getNom() == "Renvoi_de_degat")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[13], fond_collection,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_collection,posx,posy,posx+80,posy+116,makecol(14,14,14));
        }
        else if(el->getNom() == "Retinol")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[14], fond_collection,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_collection,posx,posy,posx+80,posy+116,makecol(15,15,15));
        }
        else if(el->getNom() == "Tretinoine")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[15], fond_collection,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_collection,posx,posy,posx+80,posy+116,makecol(16,16,16));
        }
        else if(el->getNom() == "Boost_de_Vie")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[16], fond_collection,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_collection,posx,posy,posx+80,posy+116,makecol(17,17,17));
        }
        else if(el->getNom() == "Vitamine_universelle")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[17], fond_collection,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_collection,posx,posy,posx+80,posy+116,makecol(18,18,18));
        }
        else
        {
            cout<<"Il reste des cartes non reconnues."<<endl;
        }
        posx += 100;
        //cout<<compteur<<" : " <<el->getNom()<<endl;
    }//fin du for auto el
//Affichage des fonds
    if(mouse_y<70 && mouse_x<800)
    {
        if(*posmapy>=0)
            *posmapy-= 1;
    }
    if(mouse_y>580 && mouse_x<800)
    {
        if(*posmapy<850)
            *posmapy+=1;
    }
    masked_blit(buffer_collection,buffer,0,*posmapy,0,0,SCREEN_W,SCREEN_H);
    masked_blit(fond_collection,fond,0,*posmapy,0,0,SCREEN_W,SCREEN_H);
    //Affichage des zoom
    int couleur_image = 1;
    for(int carte = 0; carte<18; carte++)
    {
        if(getpixel(buffer,mouse_x,mouse_y) == makecol(couleur_image,couleur_image,couleur_image))
        {
            blit(image[18+carte],fond,0,0,805,150,SCREEN_W,SCREEN_H);
        }
        couleur_image++;
    }
}
//          //
//DECK//
//          //
void afficherDeck(BITMAP* fond, BITMAP* buffer,vector<BITMAP*> image,Personne*joueur,float*posmapy,BITMAP*fond_deck,BITMAP*buffer_deck)
{
    rectfill(buffer,0,0,SCREEN_W,SCREEN_H+(*posmapy),makecol(0,0,0));
    //le fond
    rectfill(fond, 0,0,SCREEN_W,SCREEN_H, makecol(254,254,226));
    textprintf_centre_ex(fond,font,400,15,makecol(149,86,40),-1,"DECK");
    rect(fond,360,12,440,25,makecol(149,86,40));
    //le  fond_deck sur le fond
    rectfill(fond_deck,0,0,fond_deck->w,fond_deck->h,makecol(255,0,255));
    //le buffer_deck sur le fond
    rectfill(buffer_deck,0,0,buffer_deck->w,buffer_deck->h,makecol(255,0,255));
    //marge de droite
    rectfill(fond,800,0,SCREEN_W,SCREEN_H,makecol(149,86,40));
    //rectangle vide
    rect(fond,805,150,805+190,150+276,makecol(255,255,255));
    //le bouton retour
    rectangleAnime(fond,805,550,995,610);
    textprintf_centre_ex(fond,font,900,580,makecol(0,0,0),-1,"RETOUR");
    //son buffer
    rectfill(buffer,805,550,995,610,makecol(035,035,035));
    //nom du joueur
    textprintf_centre_ex(fond,font,900,100,makecol(254,254,226),-1,("Joueur : "+ joueur->getNom()).c_str());
    int posx = 5;
    int posy = 50;
    for(auto &el:joueur->Getcolec()->GetDeck())
    {
        if(el->getNom() == "VitamineB1")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[0], fond_deck,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_deck,posx,posy,posx+80,posy+116,makecol(1,1,1));
        }
        else  if(el->getNom() == "VitamineB2")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[1], fond_deck,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_deck,posx,posy,posx+80,posy+116,makecol(2,2,2));
        }
        else if(el->getNom() == "Acide_L-ascorbique")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[2], fond_deck,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_deck,posx,posy,posx+80,posy+116,makecol(3,3,3));
        }
        else if(el->getNom() == "Cerveau")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[3], fond_deck,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_deck,posx,posy,posx+80,posy+116,makecol(4,4,4));
        }
        else if(el->getNom() == "Coeur")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[4], fond_deck,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_deck,posx,posy,posx+80,posy+116,makecol(5,5,5));
        }
        else if(el->getNom() == "Calciferol")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[5], fond_deck,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_deck,posx,posy,posx+80,posy+116,makecol(6,6,6));
        }
        else if(el->getNom() == "Boost_de_degat")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[6], fond_deck,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_deck,posx,posy,posx+80,posy+116,makecol(7,7,7));
        }
        else if(el->getNom() == "Evolution")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[7], fond_deck,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_deck,posx,posy,posx+80,posy+116,makecol(8,8,8));
        }
        else if(el->getNom() == "Foie")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[8], fond_deck,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_deck,posx,posy,posx+80,posy+116,makecol(9,9,9));
        }
        else if(el->getNom() == "Pancreas")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[9], fond_deck,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_deck,posx,posy,posx+80,posy+116,makecol(10,10,10));
        }
        else if(el->getNom() == "Passe_ton_tour")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[10], fond_deck,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_deck,posx,posy,posx+80,posy+116,makecol(11,11,11));
        }
        else if(el->getNom() == "Poumon")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[11], fond_deck,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_deck,posx,posy,posx+80,posy+116,makecol(12,12,12));
        }
        else if(el->getNom() == "Rein")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[12], fond_deck,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_deck,posx,posy,posx+80,posy+116,makecol(13,13,13));
        }
        else if(el->getNom() == "Renvoi_de_degat")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[13], fond_deck,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_deck,posx,posy,posx+80,posy+116,makecol(14,14,14));
        }
        else if(el->getNom() == "Retinol")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[14], fond_deck,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_deck,posx,posy,posx+80,posy+116,makecol(15,15,15));
        }
        else if(el->getNom() == "Tretinoine")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[15], fond_deck,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_deck,posx,posy,posx+80,posy+116,makecol(16,16,16));
        }
        else if(el->getNom() == "Boost_de_Vie")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[16], fond_deck,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_deck,posx,posy,posx+80,posy+116,makecol(17,17,17));
        }
        else if(el->getNom() == "Vitamine_universelle")
        {
            if(posx>=800)
            {
                posx = 5;
                posy += 150;
            }
            blit(image[17], fond_deck,0,0,posx,posy,SCREEN_W,SCREEN_H);
            rectfill(buffer_deck,posx,posy,posx+80,posy+116,makecol(18,18,18));
        }
        else
        {
            cout<<"Il reste des cartes non reconnues."<<endl;
        }
        posx += 100;

    }
    //fin du for auto el
    if(mouse_y<70 && mouse_x<800)
    {
        if(*posmapy>=0)
            *posmapy-= 1;
    }
    if(mouse_y>580 && mouse_x<800)
    {
        if(*posmapy<850)
            *posmapy+=1;
    }
    masked_blit(buffer_deck,buffer,0,*posmapy,0,0,SCREEN_W,SCREEN_H);
    masked_blit(fond_deck,fond,0,*posmapy,0,0,SCREEN_W,SCREEN_H);
    int couleur_image = 1;
    for(int carte = 0; carte<18; carte++)
    {
        if(getpixel(buffer,mouse_x,mouse_y) == makecol(couleur_image,couleur_image,couleur_image))
        {
            blit(image[18+carte],fond,0,0,805,150,SCREEN_W,SCREEN_H);
        }
        couleur_image++;
    }
}
