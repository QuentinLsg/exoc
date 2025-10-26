#ifndef CLASSEMENT_H
#define CLASSEMENT_H

#include "structures.h"

// Fonctions de classement des pilotes
void trierPilotesParPoints(Pilote pilotes[], int nbPilotes);
void afficherClassementPilotes(Pilote pilotes[], int nbPilotes);

// Fonctions de classement des écuries
void trierEcuriesParPoints(Ecurie ecuries[], int nbEcuries);
void afficherClassementEcuries(Ecurie ecuries[], int nbEcuries);

// Fonctions de classement d'une course
void trierResultatsParPosition(ResultatCourse resultats[], int nbResultats);
void afficherClassementCourse(GrandPrix gp);

// Fonctions utilitaires
void echangerPilotes(Pilote *a, Pilote *b);
void echangerEcuries(Ecurie *a, Ecurie *b);
void echangerResultats(ResultatCourse *a, ResultatCourse *b);

#endif // CLASSEMENT_H
