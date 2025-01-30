#ifndef PARTICULE_HPP
#define PARTICULE_HPP

#include <iostream>
#include "utilitaires.hpp"
#include <vector>

using namespace std;

//===================================================================
//                       classe Particule
// représentant une particule avec ses position, vitesse et force subie
//===================================================================
class Particule
{
    public:
    Pfloat position = {0,0};
    Pfloat vitesse = {0,0};
    Pfloat force = {0,0};

    //Constructeurs
    Particule(Pfloat pos, Pfloat vit, Pfloat force);

    //Fonctions membres
    inline void update(Pfloat force, float dt); //mise à jour de la particule pour passer à l'itération suivante

};


//===================================================================
//                       classe Monde
// représentant une liste de toutes les particules simulées
//===================================================================
class Monde : public vector<Particule>
{
    Monde(const initializer_list<Particule>);
};


#endif