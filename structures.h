#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure Date
typedef struct {
    int jour;    // 1 ≤ jour ≤ 31
    int mois;    // 1 ≤ mois ≤ 12
    int annee;   // 1900 ≤ annee ≤ 2100
} Date;

// Structure Heure
typedef struct {
    int heure;   // 0 ≤ heure ≤ 23
    int minute;  // 0 ≤ minute ≤ 59
} Heure;

// Structure Pilote
typedef struct {
    char nom[50];        // Nom de famille
    char prenom[50];      // Prénom
    char nationalite[50]; // Pays de représentation
    char ecurie[50];      // Nom de l'écurie
    int points;           // Points accumulés
    int numero;           // Numéro de voiture (1-99)
    int age;              // Âge du pilote
    int actif;            // Statut (0 ou 1)
} Pilote;

// Structure Ecurie
typedef struct {
    char nom[50];         // Dénomination officielle
    char pays[50];        // Pays du siège social
    int points;           // Somme des points des 2 pilotes
    int anneeCreation;    // Année de création
    char directeur[50];   // Nom du directeur d'écurie
    int actif;            // Statut (0 ou 1)
} Ecurie;

// Structure ResultatCourse
typedef struct {
    char nomPilote[50];      // Nom du pilote
    char prenomPilote[50];   // Prénom du pilote
    char nationalite[50];    // Nationalité du pilote
    int position;            // Position finale (1-20)
    char tempsRealise[20];   // Temps total de course
    int pointsObtenus;       // Points FIA selon position
} ResultatCourse;

// Structure GrandPrix
typedef struct {
    char nomCircuit[50];                    // Nom officiel du circuit
    char pays[50];                          // Pays organisateur
    int nombreTours;                        // Nombre de tours (10-100)
    Date date;                              // Date de la course
    Heure horaire;                          // Horaire de départ
    ResultatCourse resultats[20];           // Tableau des résultats
    int nombreResultats;                    // Compteur des résultats
    int actif;                              // Statut (0 ou 1)
} GrandPrix;

// Constantes pour le système de points FIA
#define POINTS_POSITION_1 25
#define POINTS_POSITION_2 18
#define POINTS_POSITION_3 15
#define POINTS_POSITION_4 12
#define POINTS_POSITION_5 10
#define POINTS_POSITION_6 8
#define POINTS_POSITION_7 6
#define POINTS_POSITION_8 4
#define POINTS_POSITION_9 2
#define POINTS_POSITION_10 1

// Limites
#define MAX_PILOTES 50
#define MAX_ECURIES 20
#define MAX_GRANDS_PRIX 30
#define MAX_RESULTATS_PAR_COURSE 20

// Fonction pour obtenir les points selon la position
int obtenirPointsPosition(int position);

// Fonction de validation des dates
int validerDate(Date date);

// Fonction de validation des heures
int validerHeure(Heure heure);

#endif // STRUCTURES_H
