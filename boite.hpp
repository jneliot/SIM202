#ifndef BOITE_HPP
#define BOITE_HPP

#include <iostream>
#include "utilitaires.hpp"
#include "particule.hpp"
#include "parametres.hpp"

using namespace std;

//===================================================================
//                       classe Boîte
// représenté par ses niveau,centre, centre de masse, masse, particules (ptr), boîte fille (ptr), boîte soeur (ptr)
//===================================================================
class Boite
{
    public:
    int nv=1; //niveau (=> taille)
    Pfloat centre = {0,0}; //centre de la boite
    Pfloat centre_masse = {0,0}; //centre de masse de la boite
    int masse = 0; 
    Particule* particule = 0;
    Boite* filles[4] = {0,0,0,0};
    Boite* soeur = 0;

    //Constructeurs
    Boite(double x, double y, int niveau);

    //Fonctions membres
    inline bool vide(); //Vérifie si la boite est vide ou non
    inline void subdiviser(); //Subdiviser en 4 une boîte quand les particules sont plusieurs dans celle-ci
    inline void ajouter_particule(Particule* particule); //Ajouter une particule à la boîte + subdivision si nécessaire
    inline bool contient(Particule* particule); //Vérifier si une particule est dans la boîte ou non
    inline void maj_centre_masse(Particule* particule); //Mettre à jour les masse et centre de masse après ajout d'une particule dans une boîte fille
};


//===================================================================
//                       Constructeurs
Boite::Boite(double x, double y, int niveau) 
{
    nv = niveau;

    centre.first = x;
    centre.second = y;
}


//===================================================================
//                       Fonctions membres

inline bool Boite::vide(){
    if((*this).particule == 0){return 1;}
    return 0;
}

inline void Boite::subdiviser() {
    int idx = 0;
    double taille = coor_max/(2^(this->nv));
    for (int dx : {-taille, taille}) {
        for (int dy : {-taille, taille}) {
            double x = centre[0] + dx;
            double y = centre[1] + dy;
            this->filles[idx] = new Boite(x, y, this->nv + 1);
            if (idx > 0) {
                this->filles[idx-1]->soeur = this->filles[idx];
            idx++;
            }
        }
    }
}

inline bool Boite::contient(Particule* particule) 
{
    double taille = coor_max/(2^(this->nv));
    return std::abs(particule->position[0] - centre[0]) <= taille &&
           std::abs(particule->position[1] - centre[1]) <= taille &&
            std::abs(particule->position[2] - centre[2]) <= taille;
}

inline void Boite::maj_centre_masse(Particule* particule)
{
    masse += particule->masse;
    centre_masse.first += particule->position.first * particule->masse/masse;
    centre_masse.second += particule->position.second * particule->masse/masse;
}

inline void Boite::ajouter_particule(Particule* particule) 
{
    if (!this->particule) //Si la particule à ajouter est seule
    {
        this->particule = particule;
        centre_masse[0] = particule->position[0];
        centre_masse[1] = particule->position[1];
        centre_masse[2] = particule->position[2];
        masse = particule->masse;
    } 
    else  //Si elle n'est pas seule, il faut la mettre dans une boîte fille
    {
        if(!this->filles[0]) //Subdiviser si cela n'a pas été déjà fait
        {
            subdiviser();
        }
        for (auto& boite:filles) 
        {
            if (boite->contient(particule)) 
            {
                boite->ajouter_particule(particule);
                maj_centre_masse(particule);
                break;
            }
        }
    }
}
//===================================================================
//                       Fonctions externes

#endif