#ifndef DEF_ACTION
#define DEF_ACTION

#include <iostream>

using namespace std;

class Action //La classe action a pour classes filles Attaque et Defense. Ces dernières n'ont aucun attibut/méthode qui diffèrent. C'est juste plus intuitif de gérer les Attaques et les Defenses avec des noms différents.
{
protected :
    string m_nom;
    string m_desc;
    int m_pt_requis;
    string m_type_requis;
    int m_degat;
public :
    Action();
    Action(string _nom, string _desc, int _pt_requis, string _type_requis, int _degat);
    ~Action();


    int getDegat() const;

    ///je dois bien niqué ma race
    string getType_requis() const;
    int getPt_requis() const;
    string getNom() const;

};
#endif // DEF_ACTION
