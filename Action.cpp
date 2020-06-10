#include "Action.h"

Action::Action()
    : m_nom("SansNom"), m_desc("SansDesc"), m_pt_requis(0), m_type_requis(0), m_degat(0)
{

}

Action::Action(string _nom, string _desc, int _pt_requis, string _type_requis, int _degat)
    : m_nom(_nom), m_desc(_desc), m_pt_requis(_pt_requis), m_type_requis(_type_requis), m_degat(_degat)
{

}

Action::~Action()
{

}

int Action::getDegat() const
{
    return m_degat;
}

//ajout
string Action::getType_requis() const
{
    return m_type_requis;
}

int Action::getPt_requis() const
{
    return m_pt_requis;
}

string Action::getNom() const
{
    return m_nom;
}
