//Fichier de classes/fonctions utiles dans l'implémentation des classes/fonctions importantes
#ifndef UTILITAIRES_HPP
#define UTILITAIRES_HPP

#include <utility>
#include <math.h>


//---------------------------------------------------------------------------
//     classe Pfloat ( pair<float,float>)
//---------------------------------------------------------------------------
typedef pair<float,float> Pfloat;

double distance(double* a, double* b) {
    return sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]));
}

#endif