#include "Defense.h"
///CLASSE DEFENSE
///Les d�gats ici sont des d�gats r�duits, contrairement aux degats de la classe Attaque qui sont occasionn�s.
Defense::Defense()
{

}

Defense::Defense(string _nom, string _desc, int _pt_requis, string _type_requis, int _degat)
    : Action(_nom, _desc, _pt_requis, _type_requis, _degat)
{

}

Defense::~Defense()
{

}
int Defense::getDegat() const
{
    return m_degat;
}
