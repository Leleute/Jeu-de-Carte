#include <iostream>

void afficherBoucleDeJeu(BITMAP*fond, BITMAP*buffer, Personne*joueur1, Personne*joueur2,BITMAP*verso);
void afficherCarteEnjeu(BITMAP*fond,BITMAP*buffer,vector<BITMAP*>image,string enjeu, int y);
void afficherCreatureActive(BITMAP*fond,BITMAP*buffer,vector<BITMAP*> image,string nom,int y);

void afficherZoom(BITMAP* fond,BITMAP* buffer, vector<BITMAP*> image, int vie_crea1, int vie_crea2);
void afficherPioche(BITMAP*fond,BITMAP*buffer,vector<BITMAP*>image,string pioche,int y);
void afficherEnergies(BITMAP*fond,BITMAP*buffer,vector<BITMAP*> image, string nom_ener, int x1, int y1, int x2, int y2);
void afficherDerniereCarteCimetiere(BITMAP*fond, BITMAP* buffer, vector<BITMAP*> image, string nom_carte, int x1, int y1, int x2, int y2);
void afficherSpeciale(BITMAP*fond, BITMAP* buffer, vector<BITMAP*> image, string nom_carte, int x1, int y1, int x2, int y2);
void afficherVecteurEnergiesActives(BITMAP*fond, BITMAP* buffer, vector<BITMAP*> image, vector<Carte*> Ener);
