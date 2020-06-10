#include "Creature.h"
///CLASSE CREATURE
Creature::Creature() : Carte(), m_vie(5), m_def(0) //Inutilisé
{

}

Creature::Creature(string _nom, string _desc,string _typedecarte,int _vie, int _def, int _vitA, int _vitB, int _vitC, int _vitD, int _coeff_degat, Attaque* _atk1, Attaque* _atk2, Defense* _def1)
    : Carte(_nom, _desc,_typedecarte), m_vie(_vie), m_def(_def), m_vitA(_vitA), m_vitB(_vitB), m_vitC(_vitC), m_vitD(_vitD), m_coeff_degat(_coeff_degat), m_atk1(_atk1), m_atk2(_atk2), m_def1(_def1)
{

}

Creature::~Creature()
{
    //Vide
}

bool Creature::getAtk_ok() const
{
    return m_atk_ok;
}
void Creature::SetAtk_ok(bool test)
{
    m_atk_ok = test;
}
//Méthodes
void Creature::attaque_un(Carte* cible)
{
    if("VitamineA" == m_atk1->getType_requis())
    {
        if(m_vitA >= m_atk1->getPt_requis())
        {
            if(false == cible->getRenvoi())
            {
                cible->recevoirDegat(m_atk1->getDegat(), m_coeff_degat);
                m_vitA -= m_atk1->getPt_requis();
            }
            else if(true == cible->getRenvoi())
            {
                this->recevoirDegat(m_atk1->getDegat(), m_coeff_degat);
                m_vitA -= m_atk1->getPt_requis();
            }
            cible->desactiverRenvoi(); ///la cible perd son renvoi de sort
            this->m_coeff_degat = 1; //Apres chaque attaque, le coeff de dégat repasse à 1 -> effet sur une seule attaque pour BoostDegat
            m_atk_ok = true;
        }
        else
        {
            cout<<"Energie Vit A insuffisante"<<endl;
            m_atk_ok = false;

        }

    }
    else if("VitamineB" == m_atk1->getType_requis())
    {
        if(m_vitB >= m_atk1->getPt_requis())
        {
            if(false == cible->getRenvoi())
            {
                cible->recevoirDegat(m_atk1->getDegat(), m_coeff_degat);
                m_vitB -= m_atk1->getPt_requis();
            }
            else if(true == cible->getRenvoi())
            {
                this->recevoirDegat(m_atk1->getDegat(), m_coeff_degat);
                m_vitB -= m_atk1->getPt_requis();
            }
            cible->desactiverRenvoi(); ///la cible perd son renvoi de sort
            this->m_coeff_degat = 1; //Apres chaque attaque, le coeff de dégat repasse à 1 -> effet sur une seule attaque pour BoostDegat
            m_atk_ok = true;
        }
        else
        {
            cout<<"Energie Vit B insuffisante"<<endl;
            m_atk_ok = false;

        }
    }
    else if("VitamineC" == m_atk1->getType_requis())
    {
        if(m_vitC >= m_atk1->getPt_requis())
        {
            if(false == cible->getRenvoi())
            {
                cible->recevoirDegat(m_atk1->getDegat(), m_coeff_degat);
                m_vitC -= m_atk1->getPt_requis();
            }
            else if(true == cible->getRenvoi())
            {
                this->recevoirDegat(m_atk1->getDegat(), m_coeff_degat);
                m_vitC -= m_atk1->getPt_requis();
            }
            cible->desactiverRenvoi(); ///la cible perd son renvoi de sort
            this->m_coeff_degat = 1; //Apres chaque attaque, le coeff de dégat repasse à 1 -> effet sur une seule attaque pour BoostDegat

            m_atk_ok = true;
        }
        else
        {
            cout<<"Energie Vit C insuffisante"<<endl;
            m_atk_ok = false;
        }
    }
    else if("VitamineD" == m_atk1->getType_requis())
    {
        if(m_vitD >= m_atk1->getPt_requis())
        {
            if(false == cible->getRenvoi())
            {
                cible->recevoirDegat(m_atk1->getDegat(), m_coeff_degat);
                m_vitD -= m_atk1->getPt_requis();
            }
            else if(true == cible->getRenvoi())
            {
                this->recevoirDegat(m_atk1->getDegat(), m_coeff_degat);
                m_vitD -= m_atk1->getPt_requis();
            }
            cible->desactiverRenvoi(); ///la cible perd son renvoi de sort
            this->m_coeff_degat = 1; //Apres chaque attaque, le coeff de dégat repasse à 1 -> effet sur une seule attaque pour BoostDegat
            m_atk_ok = true;
        }
        else
        {
            cout<<"Energie Vit D insuffisante"<<endl;
            m_atk_ok = false;

        }

    }


}
void Creature::attaque_deux(Carte* cible)
{
    if("VitamineA" == m_atk2->getType_requis())
    {
        if(m_vitA >= m_atk2->getPt_requis())
        {
            //Attaque speciale
            if(false == cible->getRenvoi())
            {
                if(this->m_atk2->getNom() == "Mort_cerebrale")
                {
                    //tue le lanceur
                    this->m_vie = 0;
                    //tue l adversaire
                    cible->recevoirDegat(cible->getVie(), 1);
                    m_vitA -= m_atk2->getPt_requis();

                }
                //Attaques normales
                else
                {
                    cible->recevoirDegat(m_atk2->getDegat(), m_coeff_degat);
                    m_vitA -= m_atk2->getPt_requis();
                }
            }
            else if(true == cible->getRenvoi())
            {
                if(this->m_atk2->getNom() == "Mort_cerebrale")
                {
                    //tue le lanceur
                    this->m_vie = 0;
                    //mais pas l'adversaire
                    m_vitA -= m_atk2->getPt_requis();
                }
                //else renvoi normal
                else
                {
                    this->recevoirDegat(m_atk2->getDegat(), m_coeff_degat);
                    m_vitA -= m_atk2->getPt_requis();
                }
            }

            cible->desactiverRenvoi();
            this->m_coeff_degat = 1;
            m_atk_ok = true;
        }
        else
        {
            cout<<"Energie vit A insuffisante"<<endl;
            m_atk_ok = false;
        }
    }
    else if("VitamineB" == m_atk2->getType_requis())
    {
        if(m_vitB >= m_atk2->getPt_requis())
        {
            //Attaque speciale
            if(false == cible->getRenvoi())
            {
                if(this->m_atk2->getNom() == "Mort_cerebrale")
                {
                    //tue le lanceur
                    this->m_vie = 0;
                    //tue l adversaire
                    cible->recevoirDegat(cible->getVie(), 1);
                    m_vitB -= m_atk2->getPt_requis();

                }
                //Attaques normales
                else
                {
                    cible->recevoirDegat(m_atk2->getDegat(), m_coeff_degat);
                    m_vitB -= m_atk2->getPt_requis();
                }
            }
            else if(true == cible->getRenvoi())
            {
                if(this->m_atk2->getNom() == "Mort_cerebrale")
                {
                    //tue le lanceur
                    this->m_vie = 0;
                    //mais pas l'adversaire
                    m_vitB -= m_atk2->getPt_requis();
                }
                //else renvoi normal
                else
                {
                    this->recevoirDegat(m_atk2->getDegat(), m_coeff_degat);
                    m_vitB -= m_atk2->getPt_requis();
                }
            }

            cible->desactiverRenvoi();
            this->m_coeff_degat = 1;
            m_atk_ok = true;
        }
        else
        {
            cout<<"Energie vit B insuffisante"<<endl;
            m_atk_ok = false;
        }
    }
    else if("VitamineC" == m_atk2->getType_requis())
    {
        if(m_vitC >= m_atk2->getPt_requis())
        {
            //Attaque speciale
            if(false == cible->getRenvoi())
            {
                if(this->m_atk2->getNom() == "Mort_cerebrale")
                {
                    //tue le lanceur
                    this->m_vie = 0;
                    //tue l adversaire
                    cible->recevoirDegat(cible->getVie(), 1);
                    m_vitC -= m_atk2->getPt_requis();

                }
                //Attaques normales
                else
                {
                    cible->recevoirDegat(m_atk2->getDegat(), m_coeff_degat);
                    m_vitC -= m_atk2->getPt_requis();
                }
            }
            else if(true == cible->getRenvoi())
            {
                if(this->m_atk2->getNom() == "Mort_cerebrale")
                {
                    //tue le lanceur
                    this->m_vie = 0;
                    //mais pas l'adversaire
                    m_vitC -= m_atk2->getPt_requis();
                }
                //else renvoi normal
                else
                {
                    this->recevoirDegat(m_atk2->getDegat(), m_coeff_degat);
                    m_vitC -= m_atk2->getPt_requis();
                }
            }

            cible->desactiverRenvoi();
            this->m_coeff_degat = 1;
            m_atk_ok = true;
        }
        else
        {
            cout<<"Energie vit C insuffisante"<<endl;
            m_atk_ok = false;
        }
    }
    else if("VitamineD" == m_atk2->getType_requis())
    {
        if(m_vitD >= m_atk2->getPt_requis())
        {
            //Attaque speciale
            if(false == cible->getRenvoi())
            {
                if(this->m_atk2->getNom() == "Mort_cerebrale")
                {
                    //tue le lanceur
                    this->m_vie = 0;
                    //tue l adversaire
                    cible->recevoirDegat(cible->getVie(), 1);
                    m_vitD -= m_atk2->getPt_requis();

                }
                //Attaques normales
                else
                {
                    cible->recevoirDegat(m_atk2->getDegat(), m_coeff_degat);
                    m_vitD -= m_atk2->getPt_requis();
                }
            }
            else if(true == cible->getRenvoi())
            {
                if(this->m_atk2->getNom() == "Mort_cerebrale")
                {
                    //tue le lanceur
                    this->m_vie = 0;
                    //mais pas l'adversaire
                    m_vitD -= m_atk2->getPt_requis();
                }
                //else renvoi normal
                else
                {
                    this->recevoirDegat(m_atk2->getDegat(), m_coeff_degat);
                    m_vitD -= m_atk2->getPt_requis();
                }
            }

            cible->desactiverRenvoi();
            this->m_coeff_degat = 1;
            m_atk_ok = true;
        }
        else
        {
            cout<<"Energie vit D insuffisante"<<endl;
            m_atk_ok = false;
        }
    }

}


void Creature::recevoirDegat(int degat, int coeff_degat)
{
    this->m_vie -= degat*coeff_degat + this->m_def; //Vie = vie - degat + defense, avec degat >= defense
    this->m_def = 0;
    ///AJOUTER LA PERTE DE VIE DU JOUEUR
}

void Creature::seDefendre()
{
    if("VitamineA" == this->m_def1->getType_requis())
    {
        if(this->m_vitA >= this->m_def1->getPt_requis())
        {
            this->m_def = m_def1->getDegat();
            this->m_vitA -= this->m_def1->getPt_requis();
            this->m_atk_ok = true;
        }
        else
        {
            cout<<"Energie vit A insuffisante."<<endl;
            m_atk_ok = false;
        }
    }
    if("VitamineB" == this->m_def1->getType_requis())
    {
        if(this->m_vitB >= this->m_def1->getPt_requis())
        {
            this->m_def = m_def1->getDegat();
            this->m_vitB -= this->m_def1->getPt_requis();
            this->m_atk_ok = true;
        }
        else
        {
            cout<<"Energie vit B insuffisante."<<endl;
            m_atk_ok = false;
        }
    }
    if("VitamineC" == this->m_def1->getType_requis())
    {
        if(this->m_vitC >= this->m_def1->getPt_requis())
        {
            this->m_def = m_def1->getDegat();
            this->m_vitC -= this->m_def1->getPt_requis();
            this->m_atk_ok = true;
        }
        else
        {
            cout<<"Energie vit C insuffisante."<<endl;
            m_atk_ok = false;
        }
    }
    if("VitamineD" == this->m_def1->getType_requis())
    {
        if(this->m_vitD >= this->m_def1->getPt_requis())
        {
            this->m_def = m_def1->getDegat();
            this->m_vitD -= this->m_def1->getPt_requis();
            this->m_atk_ok = true;
        }
        else
        {
            cout<<"Energie vit D insuffisante."<<endl;
            m_atk_ok = false;
        }
    }
}

void Creature::recevoirBoostTerrain(string _type)
{
    if("VitamineA" == _type)
        m_vitA+=1;
    if("VitamineB" == _type)
        m_vitB+=1;
    if("VitamineC" == _type)
        m_vitC+=1;
    if("VitamineD" == _type)
        m_vitD+=1;
    if("Any" == _type)
    {
        m_vitA+=1;
        m_vitB+=1;
        m_vitC+=1;
        m_vitD+=1;
    }
}



void Creature::recevoirBoostVie()
{
    this->m_vie = (15/10)*this->m_vie;
}

void Creature::recevoirBoostDegat()
{
    this->m_coeff_degat = 2;
}

void Creature::recevoirEvolution()
{
    /*
    //Changement de description
    if("Coeur" == this->m_nom)
        this->m_desc = "Coeur ameliore, plus puissant que le coeur commun.";
    if("Poumon" == this->m_nom)
        this->m_desc  = "Poumon ameliore, plus puissant que le poumon commun.";
    if("Rein" == this->m_nom)
        this->m_desc = "Rein ameliore, plus puissant que le rein commun.";
    if("Pancreas" == this->m_nom)
        this->m_desc = "Pancreas ameliore, plus puissant que le pancreas commun.";
    if("Foie" == this->m_nom)
        this->m_desc = "Foie ameliore, plus puissant que le foi commun.";
    if("Cerveau" == this->m_nom)
        this->m_desc = "Cerveau ameliore, plus puissant que le cerveau commun.";

    //Changement de nom
    this->m_nom += "_ameliore";
    */
    //Changement d'attaques/ de dégats d'attaque
    this->m_coeff_degat = 2; //Augmente l'attaque de la prochaine attaque

    //Changement de vie
    this->m_vie += 3;

}

void Creature::activerRenvoi()
{
    this->m_renvoi = true;
}
void Creature::desactiverRenvoi()
{
    this->m_renvoi = false;
}


//GETTERS
bool Creature::getRenvoi() const
{
    return m_renvoi;
}

int Creature::getVie() const
{
    return m_vie;
}
Attaque* Creature::getAttaque_un() const
{
    return m_atk1;
}
Attaque* Creature::getAttaque_deux() const
{
    return m_atk2;
}
Defense* Creature::getDefense_un() const
{
    return m_def1;
}

///CREATURES SPECIFIQUES QUI HERITENT DE LA CLASSE Creature
//Coeur 7pv 3,3 HP, vitA vitB, 2def D
Coeur::Coeur() : Creature("Coeur", "Organe creux qui assure la circulation du sang dans l'organisme.","Creature", 7, 0, 0, 0, 0, 0,1/**coeff attaque**/, new Attaque("Cancer","Cree une tumeur sur l'organe cible. Occasionne 3 HP", 1, "VitamineA", 3),
                              new Attaque("Paludisme","Provoque la malaria. Occasionne 3 HP",1,"VitamineB",3), new Defense("Perfusion","Administration de medicaments par voie parenterale. Protege de 2 HP",1,"VitamineD",2)) {} ///vie, defense, points vitamines de base x4, coeff de degat

Coeur::~Coeur() {}

//Poumon 6pv, 3,4 HP, vitB vitC, 3def B
Poumon::Poumon() : Creature("Poumon", "Organe permettant d'echanger des gaz vitaux.","Creature", 6, 0, 0, 0, 0, 0,1, new Attaque("Rhume","Maladie infectieuse. Occasionne 3HP", 1, "VitamineB", 3),
                                new Attaque("Pneumonie","Infection des voie aeriennes. Occasionne 4 HP", 2, "VitamineC", 4), new Defense("Anesthesie", "Supprime la sensation de douleur. Protege de 3 HP", 1, "VitamineB", 3) ) {}

Poumon::~Poumon() {}

//Foie 5pv, 3,3 HP, vitC vitD, 3def A
Foie::Foie() : Creature("Foie","Organe secretant la bile et jouant un role dans plus de 300 fonctions vitales.","Creature",5, 0, 0,0,0,0,1, new Attaque("Grippe", "Maladie virale. Occasionne 3 HP", 1, "VitamineC", 3),
                            new Attaque("Coma_Ethylique","Exces d'alcool. Occasionne 3 HP", 1, "VitamineD", 3), new Defense("Vaccin", "Insertion d anticorps dans l organisme pour provoquer une reaction immunitaire. Protege de 3 HP", 1, "VitamineA", 3)) {}

Foie::~Foie() {}

//Pancreas 5pv, 5,5 HP vitD vit A, 2def C
Pancreas::Pancreas() : Creature("Pancreas", "Glande amphicrine annexe au tube digestif.","Creature", 5, 0, 0,0,0,0,1, new Attaque("Sida", "Virus d'immunodeficience humaine. Occasionne 5 HP", 2, "VitamineD", 5),
                                    new Attaque("Tuberculose", "Maladie Infectieuse grave. Occasionne 5 HP", 2, "VitamineA", 5), new Defense("Antibiotique", "Bloque la croissance des bacteries. Protege de 2 HP", 1, "VitamineC", 2)) {}

Pancreas::~Pancreas() {}

//Rein 6pv, 3,3 HP, vitA vitB, 3def B
Rein::Rein() : Creature("Rein", "Organe implique dans la regulation de la pression sanguine et l'elimination des toxines.", "Creature",6, 0,0,0,0,0,1, new Attaque("Varicelle", "Maladie infantile eruptive. Occasionne 3 HP", 1, "VitamineA", 3),
                            new Attaque("Polykystose", "Insufisance reinale chronique. Occasionne 3 HP", 1, "VitamineB", 3), new Defense("Aspirine", "Acide acetylsalicylique. Agit contre la douleur. Protege de 3 HP", 1, "VitamineB", 3)) {}

Rein::~Rein() {}

///Creature à aptitude speciale
//Cerveau 7pv, 4, OS HP, vitB, vitD, 1def A
Cerveau::Cerveau() : Creature("Cerveau", "Principal organe du systeme nerveux.", "Creature",7, 0, 0, 0, 0, 0, 1, new Attaque("AVC", "Infarctus cerebral. Occasionne 4 HP", 1, "VitamineB", 4),
                                  new Attaque("Mort_cerebrale", "Tue a la fois l'organe allie et l organe ennemi.", 3, "VitamineD", 0), new Defense("Neurochirurgie", "Operation neurologique reparatrice. Protege de 1HP", 1, "VitamineA", 1)) {}

Cerveau::~Cerveau() {}

void Creature::SetVitA(int vit)
{
    m_vitA = vit;
}
void Creature::SetVitB(int vit)
{
    m_vitB = vit;
}
void Creature::SetVitC(int vit)
{
    m_vitC = vit;
}
void Creature::SetVitD(int vit)
{
    m_vitD = vit;
}

int Creature::getVitA() const
{
    return m_vitA;
}

int Creature::getVitB() const
{
    return m_vitB;
}

int Creature::getVitC() const
{
    return m_vitC;
}

int Creature::getVitD() const
{
    return m_vitD;
}

void Creature::setVie(int vie)
{
    m_vie = vie;
}

void Creature::recevoirPasserTour()
{
    m_skip = true;
}

void Creature::setSkipFalse()
{
    m_skip = false;
}

bool Creature::getSkip() const
{
    return m_skip;
}
