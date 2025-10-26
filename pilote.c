#include "pilote.h"
#include "ecurie.h"

// Ajouter un pilote
int ajouterPilote(Pilote pilotes[], int *nbPilotes, Pilote nouveauPilote) {
    if (*nbPilotes >= MAX_PILOTES) {
        printf("Erreur : Nombre maximum de pilotes atteint.\n");
        return 0;
    }
    
    if (piloteExiste(pilotes, *nbPilotes, nouveauPilote.nom, nouveauPilote.prenom)) {
        printf("Erreur : Ce pilote existe déjà.\n");
        return 0;
    }
    
    if (!numeroPiloteUnique(pilotes, *nbPilotes, nouveauPilote.numero)) {
        printf("Erreur : Ce numéro de pilote est déjà utilisé.\n");
        return 0;
    }
    
    pilotes[*nbPilotes] = nouveauPilote;
    (*nbPilotes)++;
    printf("Pilote ajouté avec succès.\n");
    return 1;
}

// Supprimer un pilote (suppression logique)
int supprimerPilote(Pilote pilotes[], int *nbPilotes, char nom[], char prenom[]) {
    for (int i = 0; i < *nbPilotes; i++) {
        if (strcmp(pilotes[i].nom, nom) == 0 && strcmp(pilotes[i].prenom, prenom) == 0) {
            pilotes[i].actif = 0;
            printf("Pilote supprimé avec succès.\n");
            return 1;
        }
    }
    printf("Erreur : Pilote non trouvé.\n");
    return 0;
}

// Modifier un pilote
int modifierPilote(Pilote pilotes[], int nbPilotes, char nom[], char prenom[], Pilote piloteModifie) {
    for (int i = 0; i < nbPilotes; i++) {
        if (strcmp(pilotes[i].nom, nom) == 0 && strcmp(pilotes[i].prenom, prenom) == 0) {
            pilotes[i] = piloteModifie;
            printf("Pilote modifié avec succès.\n");
            return 1;
        }
    }
    printf("Erreur : Pilote non trouvé.\n");
    return 0;
}

// Rechercher un pilote
Pilote* rechercherPilote(Pilote pilotes[], int nbPilotes, char nom[], char prenom[]) {
    for (int i = 0; i < nbPilotes; i++) {
        if (strcmp(pilotes[i].nom, nom) == 0 && strcmp(pilotes[i].prenom, prenom) == 0 && pilotes[i].actif) {
            return &pilotes[i];
        }
    }
    return NULL;
}

// Afficher tous les pilotes
void afficherPilotes(Pilote pilotes[], int nbPilotes) {
    printf("\n=== LISTE DES PILOTES ===\n");
    printf("%-15s %-15s %-15s %-20s %-6s %-6s %-4s\n", 
           "Nom", "Prénom", "Nationalité", "Écurie", "Points", "N°", "Âge");
    printf("--------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < nbPilotes; i++) {
        if (pilotes[i].actif) {
            afficherPilote(pilotes[i]);
        }
    }
    printf("\n");
}

// Afficher un pilote
void afficherPilote(Pilote pilote) {
    printf("%-15s %-15s %-15s %-20s %-6d %-6d %-4d\n",
           pilote.nom, pilote.prenom, pilote.nationalite, 
           pilote.ecurie, pilote.points, pilote.numero, pilote.age);
}

// Valider un pilote
int validerPilote(Pilote pilote, Ecurie ecuries[], int nbEcuries) {
    if (strlen(pilote.nom) == 0 || strlen(pilote.prenom) == 0) {
        printf("Erreur : Nom et prénom obligatoires.\n");
        return 0;
    }
    
    if (pilote.age < 18 || pilote.age > 50) {
        printf("Erreur : Âge doit être entre 18 et 50 ans.\n");
        return 0;
    }
    
    if (pilote.numero < 1 || pilote.numero > 99) {
        printf("Erreur : Numéro doit être entre 1 et 99.\n");
        return 0;
    }
    
    if (pilote.points < 0) {
        printf("Erreur : Points ne peuvent pas être négatifs.\n");
        return 0;
    }
    
    // Vérifier que l'écurie existe
    int ecurieTrouvee = 0;
    for (int i = 0; i < nbEcuries; i++) {
        if (strcmp(ecuries[i].nom, pilote.ecurie) == 0 && ecuries[i].actif) {
            ecurieTrouvee = 1;
            break;
        }
    }
    
    if (!ecurieTrouvee) {
        printf("Erreur : Écurie '%s' n'existe pas.\n", pilote.ecurie);
        return 0;
    }
    
    return 1;
}

// Saisir un pilote
void saisirPilote(Pilote *pilote) {
    printf("Nom : ");
    scanf("%s", pilote->nom);
    
    printf("Prénom : ");
    scanf("%s", pilote->prenom);
    
    printf("Nationalité : ");
    scanf("%s", pilote->nationalite);
    
    printf("Écurie : ");
    scanf("%s", pilote->ecurie);
    
    printf("Numéro de voiture (1-99) : ");
    scanf("%d", &pilote->numero);
    
    printf("Âge (18-50) : ");
    scanf("%d", &pilote->age);
    
    pilote->points = 0;
    pilote->actif = 1;
}

// Vérifier si un pilote existe
int piloteExiste(Pilote pilotes[], int nbPilotes, char nom[], char prenom[]) {
    for (int i = 0; i < nbPilotes; i++) {
        if (strcmp(pilotes[i].nom, nom) == 0 && strcmp(pilotes[i].prenom, prenom) == 0 && pilotes[i].actif) {
            return 1;
        }
    }
    return 0;
}

// Vérifier l'unicité du numéro de pilote
int numeroPiloteUnique(Pilote pilotes[], int nbPilotes, int numero) {
    for (int i = 0; i < nbPilotes; i++) {
        if (pilotes[i].numero == numero && pilotes[i].actif) {
            return 0;
        }
    }
    return 1;
}
