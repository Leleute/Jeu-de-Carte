#include "Terrain.h"
///CLASSE TERRAIN
Terrain::Terrain() : Carte(), m_type("Aucun") {}

Terrain::Terrain(string _nom, string _desc, string _typedecarte, string _type)
    : Carte(_nom, _desc,_typedecarte), m_type(_type) {}

Terrain::~Terrain() {}

void Terrain::boostTerrain(Carte* cible)
{
    cible->recevoirBoostTerrain(m_type);
}
///TERRAINS SPECIFIQUES QUI HERITENT TOUS DE LA CLASSE Terrain
//Vitamine A
//Retinol
Retinol::Retinol() : Terrain("Retinol", "Une des trois mollecules de la vitamine A presente dans l'organisme.","Terrain", "VitamineA")
{
}
Retinol::~Retinol()
{
}
//Tretinoine
Tretinoine::Tretinoine() : Terrain("Tretinoine", "Une des trois mollecules de la vitamine A presente dans l'organisme.","Terrain", "VitamineA") {}

Tretinoine::~Tretinoine() {}

//Vitamine B
//Vitamine B1
VitB1:: VitB1() : Terrain("VitamineB1", "Sous-categorie de la vitamine B. Egalement appelee thiamine.","Terrain", "VitamineB") {}

VitB1::~VitB1() {}

//Vitamine B2
VitB2:: VitB2() : Terrain("VitamineB2", "Sous-categorie de la vitamine B. Egalement appelee riboflavine.","Terrain", "VitamineB") {}

VitB2::~ VitB2() {}

//Vitamine C
AcideAscorbique::AcideAscorbique() : Terrain("Acide_L-ascorbique", "VitamineC requise a la synthese de collagene et des globules rouges. Contribue au systeme immunitaire.", "Terrain","VitamineC") {}

AcideAscorbique::~AcideAscorbique() {}

//Vitamine D
Calciferol::Calciferol() : Terrain("Calciferol", "VitamineD influancant plus de 200 genes, et qui aurait une action de reparation de l'ADN.", "Terrain","VitamineD") {}

Calciferol::~Calciferol() {}

//Any
Any::Any() : Terrain("Vitamine_universelle","Boost tous les types d'energies.","Terrain","Any") {}

Any::~Any() {}
