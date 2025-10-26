#ifndef INITIALISATION_H
#define INITIALISATION_H

#include "structures.h"

// Fonction d'initialisation des données de test
void initialiserDonneesTest(Pilote pilotes[], int *nbPilotes, 
                           Ecurie ecuries[], int *nbEcuries, 
                           GrandPrix grandsPrix[], int *nbGrandsPrix);

// Fonctions d'initialisation spécifiques
void initialiserEcuries(Ecurie ecuries[], int *nbEcuries);
void initialiserPilotes(Pilote pilotes[], int *nbPilotes);
void initialiserGrandsPrix(GrandPrix grandsPrix[], int *nbGrandsPrix);

#endif // INITIALISATION_H
