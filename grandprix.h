#ifndef GRANDPRIX_H
#define GRANDPRIX_H

#include "structures.h"

// Fonctions de gestion des Grands Prix
int ajouterGrandPrix(GrandPrix grandsPrix[], int *nbGrandsPrix, GrandPrix nouveauGP);
int supprimerGrandPrix(GrandPrix grandsPrix[], int *nbGrandsPrix, char nomCircuit[]);
int modifierGrandPrix(GrandPrix grandsPrix[], int nbGrandsPrix, char nomCircuit[], GrandPrix gpModifie);
GrandPrix* rechercherGrandPrix(GrandPrix grandsPrix[], int nbGrandsPrix, char nomCircuit[]);
void afficherGrandsPrix(GrandPrix grandsPrix[], int nbGrandsPrix);
void afficherGrandPrix(GrandPrix gp);
int validerGrandPrix(GrandPrix gp);

// Fonctions de gestion des résultats
int ajouterResultat(GrandPrix *gp, ResultatCourse resultat);
int supprimerResultat(GrandPrix *gp, int position);
void afficherResultats(GrandPrix gp);
void saisirResultat(ResultatCourse *resultat);
int validerResultat(ResultatCourse resultat, Pilote pilotes[], int nbPilotes);

// Fonctions utilitaires
void saisirGrandPrix(GrandPrix *gp);
int grandPrixExiste(GrandPrix grandsPrix[], int nbGrandsPrix, char nomCircuit[]);
void mettreAJourPointsPilotes(GrandPrix gp, Pilote pilotes[], int nbPilotes);

#endif // GRANDPRIX_H
