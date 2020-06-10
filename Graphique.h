#include <iostream>
//fonctions de base
void allegro();
BITMAP* charger_image(char nom_image[40]);
void rectangleAnime(BITMAP*fond,int x1, int y1, int x2, int y2/*, string texte*/);
void testClick(BITMAP* bmp, int color, string phase, string* fond_affiche, int* click);

//fonctions du jeu
void afficherMenu(BITMAP* fond,BITMAP* buffer);
void afficherRegles(BITMAP* fond, BITMAP* buffer);
void afficherBoutique(BITMAP* fond, BITMAP* buffer,vector<BITMAP*> image,Personne*joueur);
void afficherCollection(BITMAP* fond, BITMAP* buffer,vector<BITMAP*> image,Personne* joueur, vector<Carte*> colec,float*posmapy,BITMAP*fond_collection,BITMAP*buffer_collection);
//void afficherCollection(BITMAP* fond, BITMAP* buffer,vector<BITMAP*> image,Personne*joueur,float*posmapy,BITMAP*fond_collection,BITMAP*buffer_collection);
void afficherDeck(BITMAP* fond, BITMAP* buffer,vector<BITMAP*> image,Personne*joueur,float*posmapy,BITMAP*fond_deck,BITMAP*buffer_deck);


