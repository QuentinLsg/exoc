#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "pilote.h"
#include "ecurie.h"
#include "grandprix.h"
#include "classement.h"
#include "initialisation.h"

// Variables globales pour stocker les données
Pilote pilotes[MAX_PILOTES];
Ecurie ecuries[MAX_ECURIES];
GrandPrix grandsPrix[MAX_GRANDS_PRIX];
int nbPilotes = 0;
int nbEcuries = 0;
int nbGrandsPrix = 0;

// Fonction pour afficher le menu principal
void afficherMenu() {
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                    🏁 FIA - FORMULE 1 🏁                     ║\n");
    printf("║              Système de Gestion de Championnat              ║\n");
    printf("╠══════════════════════════════════════════════════════════════╣\n");
    printf("║ 1. Gestion des Pilotes                                      ║\n");
    printf("║ 2. Gestion des Écuries                                       ║\n");
    printf("║ 3. Gestion des Grands Prix                                   ║\n");
    printf("║ 4. Classements                                               ║\n");
    printf("║ 5. Mettre à jour les points                                  ║\n");
    printf("║ 6. Afficher toutes les données                              ║\n");
    printf("║ 0. Quitter                                                   ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n");
    printf("Votre choix : ");
}

// Fonction pour le menu des pilotes
void menuPilotes() {
    int choix;
    char nom[50], prenom[50];
    Pilote nouveauPilote;
    
    do {
        printf("\n=== GESTION DES PILOTES ===\n");
        printf("1. Ajouter un pilote\n");
        printf("2. Supprimer un pilote\n");
        printf("3. Modifier un pilote\n");
        printf("4. Afficher tous les pilotes\n");
        printf("5. Rechercher un pilote\n");
        printf("0. Retour au menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        
        switch(choix) {
            case 1:
                printf("\n--- Ajout d'un pilote ---\n");
                saisirPilote(&nouveauPilote);
                if (validerPilote(nouveauPilote, ecuries, nbEcuries)) {
                    ajouterPilote(pilotes, &nbPilotes, nouveauPilote);
                }
                break;
            case 2:
                printf("\n--- Suppression d'un pilote ---\n");
                printf("Nom : ");
                scanf("%s", nom);
                printf("Prénom : ");
                scanf("%s", prenom);
                supprimerPilote(pilotes, &nbPilotes, nom, prenom);
                break;
            case 3:
                printf("\n--- Modification d'un pilote ---\n");
                printf("Nom du pilote à modifier : ");
                scanf("%s", nom);
                printf("Prénom : ");
                scanf("%s", prenom);
                printf("Nouvelles informations :\n");
                saisirPilote(&nouveauPilote);
                if (validerPilote(nouveauPilote, ecuries, nbEcuries)) {
                    modifierPilote(pilotes, nbPilotes, nom, prenom, nouveauPilote);
                }
                break;
            case 4:
                afficherPilotes(pilotes, nbPilotes);
                break;
            case 5:
                printf("\n--- Recherche d'un pilote ---\n");
                printf("Nom : ");
                scanf("%s", nom);
                printf("Prénom : ");
                scanf("%s", prenom);
                Pilote *pilote = rechercherPilote(pilotes, nbPilotes, nom, prenom);
                if (pilote) {
                    printf("Pilote trouvé :\n");
                    afficherPilote(*pilote);
                } else {
                    printf("Pilote non trouvé.\n");
                }
                break;
        }
    } while(choix != 0);
}

// Fonction pour le menu des écuries
void menuEcuries() {
    int choix;
    char nom[50];
    Ecurie nouvelleEcurie;
    
    do {
        printf("\n=== GESTION DES ÉCURIES ===\n");
        printf("1. Ajouter une écurie\n");
        printf("2. Supprimer une écurie\n");
        printf("3. Modifier une écurie\n");
        printf("4. Afficher toutes les écuries\n");
        printf("5. Rechercher une écurie\n");
        printf("6. Calculer les points d'une écurie\n");
        printf("0. Retour au menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        
        switch(choix) {
            case 1:
                printf("\n--- Ajout d'une écurie ---\n");
                saisirEcurie(&nouvelleEcurie);
                if (validerEcurie(nouvelleEcurie)) {
                    ajouterEcurie(ecuries, &nbEcuries, nouvelleEcurie);
                }
                break;
            case 2:
                printf("\n--- Suppression d'une écurie ---\n");
                printf("Nom de l'écurie : ");
                scanf("%s", nom);
                supprimerEcurie(ecuries, &nbEcuries, nom);
                break;
            case 3:
                printf("\n--- Modification d'une écurie ---\n");
                printf("Nom de l'écurie à modifier : ");
                scanf("%s", nom);
                printf("Nouvelles informations :\n");
                saisirEcurie(&nouvelleEcurie);
                if (validerEcurie(nouvelleEcurie)) {
                    modifierEcurie(ecuries, nbEcuries, nom, nouvelleEcurie);
                }
                break;
            case 4:
                afficherEcuries(ecuries, nbEcuries);
                break;
            case 5:
                printf("\n--- Recherche d'une écurie ---\n");
                printf("Nom : ");
                scanf("%s", nom);
                Ecurie *ecurie = rechercherEcurie(ecuries, nbEcuries, nom);
                if (ecurie) {
                    printf("Écurie trouvée :\n");
                    afficherEcurie(*ecurie);
                } else {
                    printf("Écurie non trouvée.\n");
                }
                break;
            case 6:
                printf("\n--- Calcul des points d'une écurie ---\n");
                printf("Nom de l'écurie : ");
                scanf("%s", nom);
                Ecurie *ecurieCalc = rechercherEcurie(ecuries, nbEcuries, nom);
                if (ecurieCalc) {
                    calculerPointsEcurie(ecurieCalc, pilotes, nbPilotes);
                } else {
                    printf("Écurie non trouvée.\n");
                }
                break;
        }
    } while(choix != 0);
}

// Fonction pour le menu des Grands Prix
void menuGrandsPrix() {
    int choix;
    char nomCircuit[50];
    GrandPrix nouveauGP;
    ResultatCourse nouveauResultat;
    
    do {
        printf("\n=== GESTION DES GRANDS PRIX ===\n");
        printf("1. Ajouter un Grand Prix\n");
        printf("2. Supprimer un Grand Prix\n");
        printf("3. Modifier un Grand Prix\n");
        printf("4. Afficher tous les Grands Prix\n");
        printf("5. Rechercher un Grand Prix\n");
        printf("6. Ajouter un résultat\n");
        printf("7. Afficher les résultats d'un Grand Prix\n");
        printf("0. Retour au menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        
        switch(choix) {
            case 1:
                printf("\n--- Ajout d'un Grand Prix ---\n");
                saisirGrandPrix(&nouveauGP);
                if (validerGrandPrix(nouveauGP)) {
                    ajouterGrandPrix(grandsPrix, &nbGrandsPrix, nouveauGP);
                }
                break;
            case 2:
                printf("\n--- Suppression d'un Grand Prix ---\n");
                printf("Nom du circuit : ");
                scanf("%s", nomCircuit);
                supprimerGrandPrix(grandsPrix, &nbGrandsPrix, nomCircuit);
                break;
            case 3:
                printf("\n--- Modification d'un Grand Prix ---\n");
                printf("Nom du circuit à modifier : ");
                scanf("%s", nomCircuit);
                printf("Nouvelles informations :\n");
                saisirGrandPrix(&nouveauGP);
                if (validerGrandPrix(nouveauGP)) {
                    modifierGrandPrix(grandsPrix, nbGrandsPrix, nomCircuit, nouveauGP);
                }
                break;
            case 4:
                afficherGrandsPrix(grandsPrix, nbGrandsPrix);
                break;
            case 5:
                printf("\n--- Recherche d'un Grand Prix ---\n");
                printf("Nom du circuit : ");
                scanf("%s", nomCircuit);
                GrandPrix *gp = rechercherGrandPrix(grandsPrix, nbGrandsPrix, nomCircuit);
                if (gp) {
                    printf("Grand Prix trouvé :\n");
                    afficherGrandPrix(*gp);
                } else {
                    printf("Grand Prix non trouvé.\n");
                }
                break;
            case 6:
                printf("\n--- Ajout d'un résultat ---\n");
                printf("Nom du circuit : ");
                scanf("%s", nomCircuit);
                GrandPrix *gpResultat = rechercherGrandPrix(grandsPrix, nbGrandsPrix, nomCircuit);
                if (gpResultat) {
                    saisirResultat(&nouveauResultat);
                    if (validerResultat(nouveauResultat, pilotes, nbPilotes)) {
                        ajouterResultat(gpResultat, nouveauResultat);
                    }
                } else {
                    printf("Grand Prix non trouvé.\n");
                }
                break;
            case 7:
                printf("\n--- Résultats d'un Grand Prix ---\n");
                printf("Nom du circuit : ");
                scanf("%s", nomCircuit);
                GrandPrix *gpAffichage = rechercherGrandPrix(grandsPrix, nbGrandsPrix, nomCircuit);
                if (gpAffichage) {
                    afficherResultats(*gpAffichage);
                } else {
                    printf("Grand Prix non trouvé.\n");
                }
                break;
        }
    } while(choix != 0);
}

// Fonction pour le menu des classements
void menuClassements() {
    int choix;
    
    do {
        printf("\n=== CLASSEMENTS ===\n");
        printf("1. Classement des pilotes\n");
        printf("2. Classement des écuries\n");
        printf("3. Classement d'une course\n");
        printf("0. Retour au menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        
        switch(choix) {
            case 1:
                printf("\n--- Classement des pilotes ---\n");
                trierPilotesParPoints(pilotes, nbPilotes);
                afficherClassementPilotes(pilotes, nbPilotes);
                break;
            case 2:
                printf("\n--- Classement des écuries ---\n");
                // Mettre à jour les points des écuries avant le classement
                for (int i = 0; i < nbEcuries; i++) {
                    calculerPointsEcurie(&ecuries[i], pilotes, nbPilotes);
                }
                trierEcuriesParPoints(ecuries, nbEcuries);
                afficherClassementEcuries(ecuries, nbEcuries);
                break;
            case 3:
                printf("\n--- Classement d'une course ---\n");
                char nomCircuit[50];
                printf("Nom du circuit : ");
                scanf("%s", nomCircuit);
                GrandPrix *gp = rechercherGrandPrix(grandsPrix, nbGrandsPrix, nomCircuit);
                if (gp) {
                    afficherClassementCourse(*gp);
                } else {
                    printf("Grand Prix non trouvé.\n");
                }
                break;
        }
    } while(choix != 0);
}

// Fonction pour mettre à jour les points
void mettreAJourPoints() {
    printf("\n=== MISE À JOUR DES POINTS ===\n");
    
    // Mettre à jour les points des pilotes à partir des résultats des courses
    for (int i = 0; i < nbGrandsPrix; i++) {
        if (grandsPrix[i].actif) {
            mettreAJourPointsPilotes(grandsPrix[i], pilotes, nbPilotes);
        }
    }
    
    // Mettre à jour les points des écuries
    for (int i = 0; i < nbEcuries; i++) {
        if (ecuries[i].actif) {
            calculerPointsEcurie(&ecuries[i], pilotes, nbPilotes);
        }
    }
    
    printf("Points mis à jour avec succès !\n");
}

// Fonction pour afficher toutes les données
void afficherToutesDonnees() {
    printf("\n=== RÉCAPITULATIF COMPLET ===\n");
    
    printf("\n📊 STATISTIQUES :\n");
    printf("- %d écuries actives\n", nbEcuries);
    printf("- %d pilotes actifs\n", nbPilotes);
    printf("- %d Grands Prix\n", nbGrandsPrix);
    
    afficherEcuries(ecuries, nbEcuries);
    afficherPilotes(pilotes, nbPilotes);
    afficherGrandsPrix(grandsPrix, nbGrandsPrix);
    
    printf("\n🏆 CLASSEMENTS ACTUELS :\n");
    trierPilotesParPoints(pilotes, nbPilotes);
    afficherClassementPilotes(pilotes, nbPilotes);
    
    for (int i = 0; i < nbEcuries; i++) {
        calculerPointsEcurie(&ecuries[i], pilotes, nbPilotes);
    }
    trierEcuriesParPoints(ecuries, nbEcuries);
    afficherClassementEcuries(ecuries, nbEcuries);
}

// Fonction principale
int main() {
    int choix;
    
    printf("🏁 Bienvenue dans le système de gestion FIA Formule 1 ! 🏁\n");
    
    // Initialiser les données de test
    initialiserDonneesTest(pilotes, &nbPilotes, ecuries, &nbEcuries, grandsPrix, &nbGrandsPrix);
    
    // Mettre à jour les points initiaux
    mettreAJourPoints();
    
    do {
        afficherMenu();
        scanf("%d", &choix);
        
        switch(choix) {
            case 1:
                menuPilotes();
                break;
            case 2:
                menuEcuries();
                break;
            case 3:
                menuGrandsPrix();
                break;
            case 4:
                menuClassements();
                break;
            case 5:
                mettreAJourPoints();
                break;
            case 6:
                afficherToutesDonnees();
                break;
            case 0:
                printf("\n🏁 Merci d'avoir utilisé le système FIA Formule 1 ! Au revoir ! 🏁\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    } while(choix != 0);
    
    return 0;
}
