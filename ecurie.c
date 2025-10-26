#include "ecurie.h"
#include "pilote.h"

// Ajouter une écurie
int ajouterEcurie(Ecurie ecuries[], int *nbEcuries, Ecurie nouvelleEcurie) {
    if (*nbEcuries >= MAX_ECURIES) {
        printf("Erreur : Nombre maximum d'écuries atteint.\n");
        return 0;
    }
    
    if (ecurieExiste(ecuries, *nbEcuries, nouvelleEcurie.nom)) {
        printf("Erreur : Cette écurie existe déjà.\n");
        return 0;
    }
    
    if (!validerEcurie(nouvelleEcurie)) {
        return 0;
    }
    
    ecuries[*nbEcuries] = nouvelleEcurie;
    (*nbEcuries)++;
    printf("Écurie ajoutée avec succès.\n");
    return 1;
}

// Supprimer une écurie (suppression logique)
int supprimerEcurie(Ecurie ecuries[], int *nbEcuries, char nom[]) {
    for (int i = 0; i < *nbEcuries; i++) {
        if (strcmp(ecuries[i].nom, nom) == 0) {
            ecuries[i].actif = 0;
            printf("Écurie supprimée avec succès.\n");
            return 1;
        }
    }
    printf("Erreur : Écurie non trouvée.\n");
    return 0;
}

// Modifier une écurie
int modifierEcurie(Ecurie ecuries[], int nbEcuries, char nom[], Ecurie ecurieModifiee) {
    for (int i = 0; i < nbEcuries; i++) {
        if (strcmp(ecuries[i].nom, nom) == 0) {
            ecuries[i] = ecurieModifiee;
            printf("Écurie modifiée avec succès.\n");
            return 1;
        }
    }
    printf("Erreur : Écurie non trouvée.\n");
    return 0;
}

// Rechercher une écurie
Ecurie* rechercherEcurie(Ecurie ecuries[], int nbEcuries, char nom[]) {
    for (int i = 0; i < nbEcuries; i++) {
        if (strcmp(ecuries[i].nom, nom) == 0 && ecuries[i].actif) {
            return &ecuries[i];
        }
    }
    return NULL;
}

// Afficher toutes les écuries
void afficherEcuries(Ecurie ecuries[], int nbEcuries) {
    printf("\n=== LISTE DES ÉCURIES ===\n");
    printf("%-25s %-15s %-8s %-8s %-20s\n", 
           "Nom", "Pays", "Points", "Année", "Directeur");
    printf("--------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < nbEcuries; i++) {
        if (ecuries[i].actif) {
            afficherEcurie(ecuries[i]);
        }
    }
    printf("\n");
}

// Afficher une écurie
void afficherEcurie(Ecurie ecurie) {
    printf("%-25s %-15s %-8d %-8d %-20s\n",
           ecurie.nom, ecurie.pays, ecurie.points, 
           ecurie.anneeCreation, ecurie.directeur);
}

// Valider une écurie
int validerEcurie(Ecurie ecurie) {
    if (strlen(ecurie.nom) == 0) {
        printf("Erreur : Nom de l'écurie obligatoire.\n");
        return 0;
    }
    
    if (strlen(ecurie.pays) == 0) {
        printf("Erreur : Pays obligatoire.\n");
        return 0;
    }
    
    if (strlen(ecurie.directeur) == 0) {
        printf("Erreur : Directeur obligatoire.\n");
        return 0;
    }
    
    if (ecurie.anneeCreation < 1900 || ecurie.anneeCreation > 2024) {
        printf("Erreur : Année de création invalide.\n");
        return 0;
    }
    
    if (ecurie.points < 0) {
        printf("Erreur : Points ne peuvent pas être négatifs.\n");
        return 0;
    }
    
    return 1;
}

// Saisir une écurie
void saisirEcurie(Ecurie *ecurie) {
    printf("Nom de l'écurie : ");
    scanf("%s", ecurie->nom);
    
    printf("Pays : ");
    scanf("%s", ecurie->pays);
    
    printf("Année de création : ");
    scanf("%d", &ecurie->anneeCreation);
    
    printf("Directeur : ");
    scanf("%s", ecurie->directeur);
    
    ecurie->points = 0;
    ecurie->actif = 1;
}

// Vérifier si une écurie existe
int ecurieExiste(Ecurie ecuries[], int nbEcuries, char nom[]) {
    for (int i = 0; i < nbEcuries; i++) {
        if (strcmp(ecuries[i].nom, nom) == 0 && ecuries[i].actif) {
            return 1;
        }
    }
    return 0;
}

// Calculer les points d'une écurie basés sur ses pilotes
void calculerPointsEcurie(Ecurie *ecurie, Pilote pilotes[], int nbPilotes) {
    int totalPoints = 0;
    int nbPilotesEcurie = 0;
    
    for (int i = 0; i < nbPilotes; i++) {
        if (strcmp(pilotes[i].ecurie, ecurie->nom) == 0 && pilotes[i].actif) {
            totalPoints += pilotes[i].points;
            nbPilotesEcurie++;
        }
    }
    
    ecurie->points = totalPoints;
    printf("Points de l'écurie %s mis à jour : %d points (%d pilotes)\n", 
           ecurie->nom, totalPoints, nbPilotesEcurie);
}
