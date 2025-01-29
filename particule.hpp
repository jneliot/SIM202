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
};

class Monde : public vector<Particule>
{
    Monde(const initializer_list<Particule>);
};


#endif