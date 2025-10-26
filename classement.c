#include "classement.h"
#include "pilote.h"
#include "ecurie.h"
#include "grandprix.h"

// Trier les pilotes par points (tri par sélection)
void trierPilotesParPoints(Pilote pilotes[], int nbPilotes) {
    for (int i = 0; i < nbPilotes - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < nbPilotes; j++) {
            if (pilotes[j].actif && pilotes[j].points > pilotes[maxIndex].points) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            echangerPilotes(&pilotes[i], &pilotes[maxIndex]);
        }
    }
}

// Afficher le classement des pilotes
void afficherClassementPilotes(Pilote pilotes[], int nbPilotes) {
    printf("\n=== CHAMPIONNAT DES PILOTES ===\n");
    printf("%-3s %-15s %-15s %-15s %-20s %-8s %-6s %-4s\n", 
           "Pos", "Nom", "Prénom", "Nationalité", "Écurie", "Points", "N°", "Âge");
    printf("--------------------------------------------------------------------------------\n");
    
    int position = 1;
    for (int i = 0; i < nbPilotes; i++) {
        if (pilotes[i].actif) {
            printf("%-3d %-15s %-15s %-15s %-20s %-8d %-6d %-4d\n",
                   position++,
                   pilotes[i].nom, pilotes[i].prenom, pilotes[i].nationalite,
                   pilotes[i].ecurie, pilotes[i].points, pilotes[i].numero, pilotes[i].age);
        }
    }
    printf("\n");
}

// Trier les écuries par points (tri par sélection)
void trierEcuriesParPoints(Ecurie ecuries[], int nbEcuries) {
    for (int i = 0; i < nbEcuries - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < nbEcuries; j++) {
            if (ecuries[j].actif && ecuries[j].points > ecuries[maxIndex].points) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            echangerEcuries(&ecuries[i], &ecuries[maxIndex]);
        }
    }
}

// Afficher le classement des écuries
void afficherClassementEcuries(Ecurie ecuries[], int nbEcuries) {
    printf("\n=== CHAMPIONNAT DES CONSTRUCTEURS ===\n");
    printf("%-3s %-25s %-15s %-8s %-8s %-20s\n", 
           "Pos", "Écurie", "Pays", "Points", "Année", "Directeur");
    printf("--------------------------------------------------------------------------------\n");
    
    int position = 1;
    for (int i = 0; i < nbEcuries; i++) {
        if (ecuries[i].actif) {
            printf("%-3d %-25s %-15s %-8d %-8d %-20s\n",
                   position++,
                   ecuries[i].nom, ecuries[i].pays, ecuries[i].points,
                   ecuries[i].anneeCreation, ecuries[i].directeur);
        }
    }
    printf("\n");
}

// Trier les résultats par position (tri par sélection)
void trierResultatsParPosition(ResultatCourse resultats[], int nbResultats) {
    for (int i = 0; i < nbResultats - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < nbResultats; j++) {
            if (resultats[j].position < resultats[minIndex].position) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            echangerResultats(&resultats[i], &resultats[minIndex]);
        }
    }
}

// Afficher le classement d'une course
void afficherClassementCourse(GrandPrix gp) {
    printf("\n=== CLASSEMENT - %s ===\n", gp.nomCircuit);
    printf("%-3s %-15s %-15s %-15s %-12s %-8s\n", 
           "Pos", "Nom", "Prénom", "Nationalité", "Temps", "Points");
    printf("--------------------------------------------------------------------------------\n");
    
    // Créer une copie des résultats pour le tri
    ResultatCourse resultatsTries[MAX_RESULTATS_PAR_COURSE];
    for (int i = 0; i < gp.nombreResultats; i++) {
        resultatsTries[i] = gp.resultats[i];
    }
    
    // Trier par position
    trierResultatsParPosition(resultatsTries, gp.nombreResultats);
    
    // Afficher les résultats triés
    for (int i = 0; i < gp.nombreResultats; i++) {
        printf("%-3d %-15s %-15s %-15s %-12s %-8d\n",
               resultatsTries[i].position,
               resultatsTries[i].nomPilote,
               resultatsTries[i].prenomPilote,
               resultatsTries[i].nationalite,
               resultatsTries[i].tempsRealise,
               resultatsTries[i].pointsObtenus);
    }
    printf("\n");
}

// Échanger deux pilotes
void echangerPilotes(Pilote *a, Pilote *b) {
    Pilote temp = *a;
    *a = *b;
    *b = temp;
}

// Échanger deux écuries
void echangerEcuries(Ecurie *a, Ecurie *b) {
    Ecurie temp = *a;
    *a = *b;
    *b = temp;
}

// Échanger deux résultats
void echangerResultats(ResultatCourse *a, ResultatCourse *b) {
    ResultatCourse temp = *a;
    *a = *b;
    *b = temp;
}
