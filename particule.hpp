#ifndef PARTICULE_HPP
#define PARTICULE_HPP

#include <iostream>
#include <vector>
#include "parametres.hpp"
#include "utilitaires.hpp"

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
    Pfloat F = {0,0};
    float masse = 0;

    //Constructeurs
    Particule(Pfloat pos, Pfloat vit, Pfloat force, float masse);

    //Fonctions membres
    inline void update(); //Mise à jour de la particule pour passer à l'itération suivante
    inline Pfloat force(); //Détermihation de la force totale appliquée à la particule

};

//===================================================================
//                       Constructeurs
inline Particule::Particule(Pfloat pos, Pfloat vit, Pfloat force, float m)
{
    position = pos;
    vitesse = vit;
    F = force;
    masse = m;
}


//===================================================================
//                       Fonctions membres
inline Pfloat Particule::force()
{

}

inline void Particule::update()
{
    (*this).vitesse += dt*(*this).F/(*this).masse; //Attention, on travaille sur des float (dt,v) et des doublets (F, position)
    (*this).position += dt*(*this).vitesse;

    (*this).F = (*this).force();
}

//===================================================================
//                       classe Monde
// représentant une liste de toutes les particules simulées
//===================================================================
class Monde : public vector<Particule>
{
    Monde(const initializer_list<Particule>);

    //Fonctions membres
    inline void init(Pfloat pos, Pfloat vit, Pfloat Force); //Initialisation du monde: des forces et des v^1/2 de chaque particule
};

//===================================================================
//                       Fonctions membres

inline void Monde::init(Pfloat pos, Pfloat vit, Pfloat Force)
{
    for(auto part:(*this))
    {
        part.F = part.force(); //Déterminer la force appliquée à la particule F^0
        part.vitesse += dt*part.F/(2*part.masse); //v^1/2
    }
}

#endif