#include "Attaque.h"
///CLASSE ATTAQUE
Attaque::Attaque() : Action()
{
}
Attaque::Attaque(string _nom, string _desc, int _pt_requis, string _type_requis, int _degat)
    : Action(_nom, _desc, _pt_requis, _type_requis, _degat)
{
}
Attaque::~Attaque()
{
}
string Attaque::getNom() const
{
    return m_nom;
}
int Attaque::getPt_requis() const
{
    return m_pt_requis;
}
string Attaque::getType_requis() const
{
    return m_type_requis;
}
