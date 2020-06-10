#ifndef DEF_DEFENSE
#define DEF_DEFENSE

#include <iostream>

#include "Action.h"

using namespace std;
///CLASSE DEFENSE
class Defense : public Action
{
protected :

public :
    Defense();
    Defense(string _nom, string _desc, int _pt_requis, string _type_requis, int _degat);
    ~Defense();

    int getDegat() const;
};
#endif // DEF_DEFENSE
