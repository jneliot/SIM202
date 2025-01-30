#ifndef BOITE_HPP
#define BOITE_HPP

#include <iostream>
#include "utilitaires.hpp"
#include "particule.hpp"


using namespace std;

//===================================================================
//                       classe Boîte
// représenté par ses niveau,centre, centre de masse, masse, particules (ptr), boîte fille (ptr), boîte sur (ptr)
//===================================================================
class Boite
{
    public:
    int nv=1; //niveau (=> taille)
    Pfloat centre = {0,0}; //centre de la boite
    Pfloat centre_masse = {0,0}; //centre de masse de la boite
    int masse = 0; 
    Particule* part = 0;
    Boite* fille = 0;
    Boite* soeur = 0;

    //Constructeurs
    Boite(Boite mere);

    //Fonctions membres
    inline bool vide(); //Vérifie si la boite est vide ou non
    inline void update(Pfloat force, float dt); //mise à jour de la particule pour passer à l'itération suivante

};


//===================================================================
//                       Constructeurs
Boite::Boite(Boite mere)
{

}


//===================================================================
//                       Fonctions membres

inline bool Boite::vide(){
    if((*this).part == 0){return 1;}
    return 0;
}


//===================================================================
//                       Fonctions externes

#endif