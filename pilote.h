#ifndef PILOTE_H
#define PILOTE_H

#include "structures.h"

// Fonctions de gestion des pilotes
int ajouterPilote(Pilote pilotes[], int *nbPilotes, Pilote nouveauPilote);
int supprimerPilote(Pilote pilotes[], int *nbPilotes, char nom[], char prenom[]);
int modifierPilote(Pilote pilotes[], int nbPilotes, char nom[], char prenom[], Pilote piloteModifie);
Pilote* rechercherPilote(Pilote pilotes[], int nbPilotes, char nom[], char prenom[]);
void afficherPilotes(Pilote pilotes[], int nbPilotes);
void afficherPilote(Pilote pilote);
int validerPilote(Pilote pilote, Ecurie ecuries[], int nbEcuries);

// Fonctions utilitaires
void saisirPilote(Pilote *pilote);
int piloteExiste(Pilote pilotes[], int nbPilotes, char nom[], char prenom[]);
int numeroPiloteUnique(Pilote pilotes[], int nbPilotes, int numero);

#endif // PILOTE_H
