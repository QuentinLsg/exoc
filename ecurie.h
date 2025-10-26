
#ifndef ECURIE_H
#define ECURIE_H

#include "structures.h"

// Fonctions de gestion des écuries
int ajouterEcurie(Ecurie ecuries[], int *nbEcuries, Ecurie nouvelleEcurie);
int supprimerEcurie(Ecurie ecuries[], int *nbEcuries, char nom[]);
int modifierEcurie(Ecurie ecuries[], int nbEcuries, char nom[], Ecurie ecurieModifiee);
Ecurie* rechercherEcurie(Ecurie ecuries[], int nbEcuries, char nom[]);
void afficherEcuries(Ecurie ecuries[], int nbEcuries);
void afficherEcurie(Ecurie ecurie);
int validerEcurie(Ecurie ecurie);

// Fonctions utilitaires
void saisirEcurie(Ecurie *ecurie);
int ecurieExiste(Ecurie ecuries[], int nbEcuries, char nom[]);
void calculerPointsEcurie(Ecurie *ecurie, Pilote pilotes[], int nbPilotes);

#endif // ECURIE_H
