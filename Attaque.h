#ifndef DEF_ATTAQUE
#define DEF_ATTAQUE

#include <iostream>

#include "Action.h"

using namespace std;

class Attaque : public Action
{
protected :

public :
    Attaque();
    Attaque(string _nom, string _desc, int _pt_requis, string _type_requis, int _degat);
    ~Attaque();
    string getNom() const;
    string getType_requis() const;
    int getPt_requis() const;

};

#endif // DEF_ATTAQUE
