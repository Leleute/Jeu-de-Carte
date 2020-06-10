#include <iostream>
#include <vector>
#include "allegro.h"
#include "Combat.h"
#include "Personne.h"
#include "Graphique.h"
#include "Carte.h"

using namespace std;

///         ///
///MAP///
///         ///
void afficherBoucleDeJeu(BITMAP*fond, BITMAP*buffer, Personne*joueur1,Personne* joueur2,BITMAP*verso)
{
    //le fond
    rectfill(fond, 0,0,SCREEN_W,SCREEN_H, makecol(254,254,226));
    textprintf_centre_ex(fond,font,400,15,makecol(149,86,40),-1,"COMBAT");
    rect(fond,365,12,435,25,makecol(149,86,40));
    //marge de droite
    rectfill(fond,800,0,SCREEN_W,SCREEN_H,makecol(149,86,40));
//marge du bas
    rectfill(fond,0,550,799,650,makecol(225,206,154));
//le bouton retour
    rectangleAnime(fond,805,15,995,75);
    textprintf_centre_ex(fond,font,900,45,makecol(0,0,0),-1,"QUITTER LA PARTIE");
    //son buffer
    rectfill(buffer,805,15,995,75,makecol(037,037,037));
    //informations

    textprintf_centre_ex(fond,font,900,170,makecol(255,255,255),-1, "%d",joueur2->Getvie());
    rect(fond,805,200,995,476,makecol(255,255,255));

    //  textprintf_ex(fond,font,810,520,makecol(0,0,0),-1,"Carte enjeu 1 : ");
    //  textprintf_ex(fond,font,810,570,makecol(0,0,0),-1,"Carte enjeu 2 : ");
    //les cartes faces cachées
    int posx=60;
    int posy = 30;
    for(int i=0; i<12; i++)
    {
        if(posx<= 461)
        {
            blit(verso,fond,0,0,posx,posy,SCREEN_W,SCREEN_H);
        }
        if(posx>461)
        {
            posx=60;
            posy+=130;
            blit(verso,fond,0,0,posx,posy,SCREEN_W,SCREEN_H);
        }
        posx+= 180;
    }
    //Masquer les "cartes enjeu"
    rectfill(fond,420,30,420+80,30+116,makecol(254,254,226));
    rectfill(fond,60,420,60+80,420+116,makecol(254,254,226));
    //Les éafficher  sur le côté pour que ça soit plus visuel
    blit(verso,fond,0,0,660,70,SCREEN_W,SCREEN_H);
    blit(verso,fond,0,0,660,395,SCREEN_W,SCREEN_H);
}
///             ///
///ENJEU///
///             ///
void afficherCarteEnjeu(BITMAP*fond,BITMAP*buffer,vector<BITMAP*>image,string enjeu,int y)
{
    if( enjeu == "VitamineB1")
    {

        blit(image[0], fond,0,0,660,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,660,y,660+80,y+116,makecol(1,1,1));

    }
    else if( enjeu == "VitamineB2")
    {

        blit(image[1], fond,0,0,660,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,660,y,660+80,y+116,makecol(2,2,2));

    }
    else if( enjeu == "Acide_L-ascorbique")
    {

        blit(image[2], fond,0,0,660,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,660,y,660+80,y+116,makecol(3,3,3));

    }
    else if( enjeu == "Cerveau")
    {

        blit(image[3], fond,0,0,660,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,660,y,660+80,y+116,makecol(4,4,4));

    }
    else if( enjeu == "Coeur")
    {

        blit(image[4], fond,0,0,660,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,660,y,660+80,y+116,makecol(5,5,5));

    }
    else if( enjeu == "Calciferol")
    {

        blit(image[5], fond,0,0,660,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,660,y,660+80,y+116,makecol(6,6,6));

    }
    else if( enjeu == "Boost_de_degat")
    {

        blit(image[6], fond,0,0,660,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,660,y,660+80,y+116,makecol(7,7,7));

    }
    else if( enjeu == "Evolution")
    {

        blit(image[7], fond,0,0,660,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,660,y,660+80,y+116,makecol(8,8,8));

    }
    else if( enjeu == "Foie")
    {

        blit(image[8], fond,0,0,660,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,660,y,660+80,y+116,makecol(9,9,9));

    }
    else if( enjeu == "Pancreas")
    {

        blit(image[9], fond,0,0,660,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,660,y,660+80,y+116,makecol(10,10,10));

    }
    else if( enjeu == "Passe_ton_tour")
    {

        blit(image[10], fond,0,0,660,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,660,y,660+80,y+116,makecol(11,11,11));

    }
    else if( enjeu == "Poumon")
    {

        blit(image[11], fond,0,0,660,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,660,y,660+80,y+116,makecol(12,12,12));

    }
    else if( enjeu == "Rein")
    {

        blit(image[12], fond,0,0,660,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,660,y,660+80,y+116,makecol(13,13,13));

    }
    else if( enjeu == "Renvoi_de_degat")
    {

        blit(image[13], fond,0,0,660,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,660,y,660+80,y+116,makecol(14,14,14));

    }
    else if( enjeu == "Retinol")
    {

        blit(image[14], fond,0,0,660,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,660,y,660+80,y+116,makecol(15,15,15));

    }
    else  if( enjeu == "Tretinoine")
    {

        blit(image[15], fond,0,0,660,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,660,y,660+80,y+116,makecol(16,16,16));

    }
    else if( enjeu == "Boost_de_Vie")
    {

        blit(image[16], fond,0,0,660,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,660,y,660+80,y+116,makecol(17,17,17));

    }
    else if( enjeu == "Vitamine_universelle")
    {

        blit(image[17], fond,0,0,660,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,660,y,660+80,y+116,makecol(18,18,18));

    }


}
///                     ///
///CREATURE///
///                     ///
void afficherCreatureActive(BITMAP*fond,BITMAP*buffer,vector<BITMAP*> image,string nom,int y)
{
    if(nom == "Cerveau")
    {
        blit(image[3],fond,0,0,240,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,240,y,240+80,y+116,makecol(4,4,4));
    }
    else if(nom == "Coeur")
    {
        blit(image[4],fond,0,0,240,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,240,y,240+80,y+116,makecol(5,5,5));
    }
    else if(nom == "Foie")
    {
        blit(image[8],fond,0,0,240,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,240,y,240+80,y+116,makecol(9,9,9));
    }
    else if(nom == "Pancreas")
    {
        blit(image[9],fond,0,0,240,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,240,y,240+80,y+116,makecol(10,10,10));
    }
    else if(nom == "Poumon")
    {
        blit(image[11],fond,0,0,240,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,240,y,240+80,y+116,makecol(12,12,12));
    }
    else if(nom == "Rein")
    {
        blit(image[12],fond,0,0,240,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,240,y,240+80,y+116,makecol(13,13,13));
    }
}
///               ///
/// ZOOM ///
///               ///
void afficherZoom(BITMAP* fond,BITMAP* buffer, vector<BITMAP*> image, int vie_crea1, int vie_crea2)
{
    if(getpixel(buffer,mouse_x,mouse_y) == makecol(1,1,1))
    {
        blit(image[18],fond,0,0,805,200,SCREEN_W,SCREEN_H);
    }
    else  if(getpixel(buffer,mouse_x,mouse_y) == makecol(2,2,2))
    {
        blit(image[19],fond,0,0,805,200,SCREEN_W,SCREEN_H);
    }
    else  if(getpixel(buffer,mouse_x,mouse_y) == makecol(3,3,3))
    {
        blit(image[20],fond,0,0,805,200,SCREEN_W,SCREEN_H);
    }
    else  if(getpixel(buffer,mouse_x,mouse_y) == makecol(4,4,4))
    {
        blit(image[21],fond,0,0,805,200,SCREEN_W,SCREEN_H);
        if(mouse_x>260 && mouse_x<340 && mouse_y>290 && mouse_y<406)
        {
            textprintf_ex(fond,font,975,215,makecol(0,0,0),-1,"%d",vie_crea1);
        }
        if(mouse_x>260 && mouse_x<340 && mouse_y>160 && mouse_y<276)
        {
            textprintf_ex(fond,font,975,215,makecol(0,0,0),-1,"%d",vie_crea2);
        }
    }
    else  if(getpixel(buffer,mouse_x,mouse_y) == makecol(5,5,5))
    {
        blit(image[22],fond,0,0,805,200,SCREEN_W,SCREEN_H);
        if(mouse_x>260 && mouse_x<340 && mouse_y>290 && mouse_y<406)
        {
            textprintf_ex(fond,font,975,215,makecol(0,0,0),-1,"%d",vie_crea1);
        }
        if(mouse_x>260 && mouse_x<340 && mouse_y>160 && mouse_y<276)
        {
            textprintf_ex(fond,font,975,215,makecol(0,0,0),-1,"%d",vie_crea2);
        }
    }
    else  if(getpixel(buffer,mouse_x,mouse_y) == makecol(6,6,6))
    {
        blit(image[23],fond,0,0,805,200,SCREEN_W,SCREEN_H);
    }
    else  if(getpixel(buffer,mouse_x,mouse_y) == makecol(7,7,7))
    {
        blit(image[24],fond,0,0,805,200,SCREEN_W,SCREEN_H);
    }
    else  if(getpixel(buffer,mouse_x,mouse_y) == makecol(8,8,8))
    {
        blit(image[25],fond,0,0,805,200,SCREEN_W,SCREEN_H);
    }
    else  if(getpixel(buffer,mouse_x,mouse_y) == makecol(9,9,9))
    {
        blit(image[26],fond,0,0,805,200,SCREEN_W,SCREEN_H);
        if(mouse_x>260 && mouse_x<340 && mouse_y>290 && mouse_y<406)
        {
            textprintf_ex(fond,font,975,215,makecol(0,0,0),-1,"%d",vie_crea1);
        }
        if(mouse_x>260 && mouse_x<340 && mouse_y>160 && mouse_y<276)
        {
            textprintf_ex(fond,font,975,215,makecol(0,0,0),-1,"%d",vie_crea2);
        }
    }
    else  if(getpixel(buffer,mouse_x,mouse_y) == makecol(10,10,10))
    {
        blit(image[27],fond,0,0,805,200,SCREEN_W,SCREEN_H);
        if(mouse_x>260 && mouse_x<340 && mouse_y>290 && mouse_y<406)
        {
            textprintf_ex(fond,font,975,215,makecol(0,0,0),-1,"%d",vie_crea1);
        }
        if(mouse_x>260 && mouse_x<340 && mouse_y>160 && mouse_y<276)
        {
            textprintf_ex(fond,font,975,215,makecol(0,0,0),-1,"%d",vie_crea2);
        }
    }
    else  if(getpixel(buffer,mouse_x,mouse_y) == makecol(11,11,11))
    {
        blit(image[28],fond,0,0,805,200,SCREEN_W,SCREEN_H);
    }
    else  if(getpixel(buffer,mouse_x,mouse_y) == makecol(12,12,12))
    {
        blit(image[29],fond,0,0,805,200,SCREEN_W,SCREEN_H);
        if(mouse_x>260 && mouse_x<340 && mouse_y>290 && mouse_y<406)
        {
            textprintf_ex(fond,font,975,215,makecol(0,0,0),-1,"%d",vie_crea1);
        }
        if(mouse_x>260 && mouse_x<340 && mouse_y>160 && mouse_y<276)
        {
            textprintf_ex(fond,font,975,215,makecol(0,0,0),-1,"%d",vie_crea2);
        }
    }
    else  if(getpixel(buffer,mouse_x,mouse_y) == makecol(13,13,13))
    {
        blit(image[30],fond,0,0,805,200,SCREEN_W,SCREEN_H);
        if(mouse_x>260 && mouse_x<340 && mouse_y>290 && mouse_y<406)
        {
            textprintf_ex(fond,font,975,215,makecol(0,0,0),-1,"%d",vie_crea1);
        }
        if(mouse_x>260 && mouse_x<340 && mouse_y>160 && mouse_y<276)
        {
            textprintf_ex(fond,font,975,215,makecol(0,0,0),-1,"%d",vie_crea2);
        }
    }
    else  if(getpixel(buffer,mouse_x,mouse_y) == makecol(14,14,14))
    {
        blit(image[31],fond,0,0,805,200,SCREEN_W,SCREEN_H);
    }
    else  if(getpixel(buffer,mouse_x,mouse_y) == makecol(15,15,15))
    {
        blit(image[32],fond,0,0,805,200,SCREEN_W,SCREEN_H);
    }
    else  if(getpixel(buffer,mouse_x,mouse_y) == makecol(16,16,16))
    {
        blit(image[33],fond,0,0,805,200,SCREEN_W,SCREEN_H);
    }
    else  if(getpixel(buffer,mouse_x,mouse_y) == makecol(17,17,17))
    {
        blit(image[34],fond,0,0,805,200,SCREEN_W,SCREEN_H);
    }
    else  if(getpixel(buffer,mouse_x,mouse_y) == makecol(18,18,18))
    {
        blit(image[35],fond,0,0,805,200,SCREEN_W,SCREEN_H);
    }
}
///               ///
///PIOCHE///
///               ///
void afficherPioche(BITMAP*fond,BITMAP*buffer,vector<BITMAP*>image,string pioche,int y)
{
    if( pioche == "VitamineB1")
    {

        blit(image[0], fond,0,0,240,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,240,y,240+80,y+116,makecol(1,1,1));

    }
    else if( pioche == "VitamineB2")
    {

        blit(image[1], fond,0,0,240,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,240,y,240+80,y+116,makecol(2,2,2));

    }
    else if( pioche == "Acide_L-ascorbique")
    {

        blit(image[2], fond,0,0,240,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,240,y,240+80,y+116,makecol(3,3,3));

    }
    else if( pioche == "Cerveau")
    {

        blit(image[3], fond,0,0,240,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,240,y,240+80,y+116,makecol(4,4,4));

    }
    else if( pioche == "Coeur")
    {

        blit(image[4], fond,0,0,240,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,240,y,240+80,y+116,makecol(5,5,5));

    }
    else if( pioche == "Calciferol")
    {

        blit(image[5], fond,0,0,240,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,240,y,240+80,y+116,makecol(6,6,6));

    }
    else if( pioche == "Boost_de_degat")
    {

        blit(image[6], fond,0,0,240,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,240,y,240+80,y+116,makecol(7,7,7));

    }
    else if( pioche == "Evolution")
    {

        blit(image[7], fond,0,0,240,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,240,y,240+80,y+116,makecol(8,8,8));

    }
    else if( pioche == "Foie")
    {

        blit(image[8], fond,0,0,240,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,240,y,240+80,y+116,makecol(9,9,9));

    }
    else if( pioche == "Pancreas")
    {

        blit(image[9], fond,0,0,240,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,240,y,240+80,y+116,makecol(10,10,10));

    }
    else if( pioche == "Passe_ton_tour")
    {

        blit(image[10], fond,0,0,240,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,240,y,240+80,y+116,makecol(11,11,11));

    }
    else if( pioche == "Poumon")
    {

        blit(image[11], fond,0,0,240,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,240,y,240+80,y+116,makecol(12,12,12));

    }
    else if( pioche == "Rein")
    {

        blit(image[12], fond,0,0,240,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,240,y,240+80,y+116,makecol(13,13,13));

    }
    else if( pioche == "Renvoi_de_degat")
    {

        blit(image[13], fond,0,0,240,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,240,y,240+80,y+116,makecol(14,14,14));

    }
    else if( pioche == "Retinol")
    {

        blit(image[14], fond,0,0,240,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,240,y,240+80,y+116,makecol(15,15,15));

    }
    else  if( pioche == "Tretinoine")
    {

        blit(image[15], fond,0,0,240,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,240,y,240+80,y+116,makecol(16,16,16));

    }
    else if( pioche == "Boost_de_Vie")
    {

        blit(image[16], fond,0,0,240,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,240,y,240+80,y+116,makecol(17,17,17));

    }
    else if( pioche == "Vitamine_universelle")
    {

        blit(image[17], fond,0,0,240,y,SCREEN_W,SCREEN_H);
        rectfill(buffer,240,y,240+80,y+116,makecol(18,18,18));

    }
}
///                    ///
///ENERGIES///
///                    ///
void afficherEnergies(BITMAP*fond,BITMAP*buffer,vector<BITMAP*> image, string nom_ener, int x1, int y1, int x2, int y2)
{
    if(nom_ener == "VitamineB1")
    {
        blit(image[0],fond, 0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(1,1,1));
    }
    else  if(nom_ener == "VitamineB2")
    {
        blit(image[1],fond, 0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(2,2,2));
    }
    else  if(nom_ener == "Acide_L-ascorbique")
    {
        blit(image[2],fond, 0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(3,3,3));
    }
    else  if(nom_ener == "Calciferol")
    {
        blit(image[5],fond, 0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(6,6,6));
    }
    else  if(nom_ener == "Retinol")
    {
        blit(image[14],fond, 0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(15,15,15));
    }
    else  if(nom_ener == "Tretinoine")
    {
        blit(image[15],fond, 0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(16,16,16));
    }
    else  if(nom_ener == "Vitamine_universelle")
    {
        blit(image[17],fond, 0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(18,18,18));
    }
}
///                     ///
///CIMETIERE///
///                     ///
void afficherDerniereCarteCimetiere(BITMAP*fond, BITMAP* buffer, vector<BITMAP*> image, string nom_carte, int x1, int y1, int x2, int y2)
{
    if( nom_carte == "VitamineB1")
    {

        blit(image[0], fond,0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(1,1,1));

    }
    else if( nom_carte == "VitamineB2")
    {

        blit(image[1], fond,0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(2,2,2));

    }
    else if( nom_carte == "Acide_L-ascorbique")
    {

        blit(image[2], fond,0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(3,3,3));

    }
    else if( nom_carte == "Cerveau")
    {

        blit(image[3], fond,0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(4,4,4));

    }
    else if( nom_carte == "Coeur")
    {

        blit(image[4], fond,0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(5,5,5));

    }
    else if( nom_carte == "Calciferol")
    {

        blit(image[5], fond,0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(6,6,6));

    }
    else if( nom_carte == "Boost_de_degat")
    {

        blit(image[6], fond,0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(7,7,7));

    }
    else if( nom_carte == "Evolution")
    {

        blit(image[7], fond,0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(8,8,8));

    }
    else if( nom_carte == "Foie")
    {

        blit(image[8], fond,0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(9,9,9));

    }
    else if( nom_carte == "Pancreas")
    {

        blit(image[9], fond,0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(10,10,10));

    }
    else if( nom_carte == "Passe_ton_tour")
    {

        blit(image[10], fond,0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(11,11,11));

    }
    else if( nom_carte == "Poumon")
    {

        blit(image[11], fond,0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(12,12,12));

    }
    else if( nom_carte == "Rein")
    {

        blit(image[12], fond,0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(13,13,13));

    }
    else if( nom_carte == "Renvoi_de_degat")
    {

        blit(image[13], fond,0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(14,14,14));

    }
    else if( nom_carte == "Retinol")
    {

        blit(image[14], fond,0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(15,15,15));

    }
    else  if( nom_carte == "Tretinoine")
    {

        blit(image[15], fond,0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(16,16,16));

    }
    else if( nom_carte == "Boost_de_Vie")
    {

        blit(image[16], fond,0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(17,17,17));

    }
    else if( nom_carte == "Vitamine_universelle")
    {

        blit(image[17], fond,0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(18,18,18));

    }
}
///                  ///
///SPECIALE///
///                  ///
void afficherSpeciale(BITMAP*fond, BITMAP* buffer, vector<BITMAP*> image, string nom_carte, int x1, int y1, int x2, int y2)
{
    if(nom_carte == "Boost_de_degat")
    {
        blit(image[6],fond, 0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(7,7,7));
    }
    if(nom_carte == "Evolution")
    {
        blit(image[7],fond, 0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(8,8,8));
    }
    if(nom_carte == "Passe_ton_tour")
    {
        blit(image[10],fond, 0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(11,11,11));
    }
    if(nom_carte == "Renvoi_de_degat")
    {
        blit(image[13],fond, 0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(14,14,14));
    }
    if(nom_carte == "Boost_de_Vie")
    {
        blit(image[16],fond, 0,0,x1,y1,SCREEN_W,SCREEN_H);
        rectfill(buffer,x1,y1,x2,y2,makecol(17,17,17));
    }
}

void afficherVecteurEnergiesActives(BITMAP*fond, BITMAP* buffer, vector<BITMAP*> image, vector<Carte*> Ener)
{
    int posx = 520;
    int posy = 267;
    for(const auto &el: Ener)
    {
        if(el->getNom() == "VitamineB1")
        {
            blit(image[0],fond,0,0,posx,posy,SCREEN_W,SCREEN_H);
        }
        else  if(el->getNom() == "VitamineB2")
        {
            blit(image[1],fond,0,0,posx,posy,SCREEN_W,SCREEN_H);
        }
        else  if(el->getNom() == "Acide_L-ascorbique")
        {
            blit(image[2],fond,0,0,posx,posy,SCREEN_W,SCREEN_H);
        }
        else  if(el->getNom() == "Calciferol")
        {
            blit(image[5],fond,0,0,posx,posy,SCREEN_W,SCREEN_H);
        }
        else  if(el->getNom() == "Retinol")
        {
            blit(image[14],fond,0,0,posx,posy,SCREEN_W,SCREEN_H);
        }
        else  if(el->getNom() == "Tretinoine")
        {
            blit(image[15],fond,0,0,posx,posy,SCREEN_W,SCREEN_H);
        }
        else  if(el->getNom() == "Vitamine_universelle")
        {
            blit(image[0],fond,0,0,posx,posy,SCREEN_W,SCREEN_H);
        }

        posx += 20;
    }
}
