#ifndef PARAMETRE_HPP
#define PARAMETRE_HPP

//Paramètres généraux
int N = 15; //Nombre de particules
int coor_max = 1024; //Coordonnées max -> on étudie une grille [-coor_max;+coor_max]^2 (2^n <=> n niveaux)
float eps = 0.1; //Paramètre d'adoucissement
float dt = 0.01; //Pas de discrétisation du temps
int temps_max = 100;

#endif