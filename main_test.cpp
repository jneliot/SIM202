#include "boite.hpp"
#include "utilitaires.hpp"
#include "particule.hpp"

//Paramètres généraux
int N = 15; //Nombre de particules
int coor_max = 1024; //Coordonnées max -> on étudie une grille [-coor_max;+coor_max]^2 (2^n <=> n niveaux)
float eps = 0.01; //Paramètre d'adoucissement
float dt = 0.001; //Pas de discrétisation du temps
