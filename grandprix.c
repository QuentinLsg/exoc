#include "grandprix.h"
#include "pilote.h"
#include "ecurie.h"

// Ajouter un Grand Prix
int ajouterGrandPrix(GrandPrix grandsPrix[], int *nbGrandsPrix, GrandPrix nouveauGP) {
    if (*nbGrandsPrix >= MAX_GRANDS_PRIX) {
        printf("Erreur : Nombre maximum de Grands Prix atteint.\n");
        return 0;
    }
    
    if (grandPrixExiste(grandsPrix, *nbGrandsPrix, nouveauGP.nomCircuit)) {
        printf("Erreur : Ce Grand Prix existe déjà.\n");
        return 0;
    }
    
    if (!validerGrandPrix(nouveauGP)) {
        return 0;
    }
    
    grandsPrix[*nbGrandsPrix] = nouveauGP;
    (*nbGrandsPrix)++;
    printf("Grand Prix ajouté avec succès.\n");
    return 1;
}

// Supprimer un Grand Prix (suppression logique)
int supprimerGrandPrix(GrandPrix grandsPrix[], int *nbGrandsPrix, char nomCircuit[]) {
    for (int i = 0; i < *nbGrandsPrix; i++) {
        if (strcmp(grandsPrix[i].nomCircuit, nomCircuit) == 0) {
            grandsPrix[i].actif = 0;
            printf("Grand Prix supprimé avec succès.\n");
            return 1;
        }
    }
    printf("Erreur : Grand Prix non trouvé.\n");
    return 0;
}

// Modifier un Grand Prix
int modifierGrandPrix(GrandPrix grandsPrix[], int nbGrandsPrix, char nomCircuit[], GrandPrix gpModifie) {
    for (int i = 0; i < nbGrandsPrix; i++) {
        if (strcmp(grandsPrix[i].nomCircuit, nomCircuit) == 0) {
            grandsPrix[i] = gpModifie;
            printf("Grand Prix modifié avec succès.\n");
            return 1;
        }
    }
    printf("Erreur : Grand Prix non trouvé.\n");
    return 0;
}

// Rechercher un Grand Prix
GrandPrix* rechercherGrandPrix(GrandPrix grandsPrix[], int nbGrandsPrix, char nomCircuit[]) {
    for (int i = 0; i < nbGrandsPrix; i++) {
        if (strcmp(grandsPrix[i].nomCircuit, nomCircuit) == 0 && grandsPrix[i].actif) {
            return &grandsPrix[i];
        }
    }
    return NULL;
}

// Afficher tous les Grands Prix
void afficherGrandsPrix(GrandPrix grandsPrix[], int nbGrandsPrix) {
    printf("\n=== CALENDRIER DES GRANDS PRIX ===\n");
    printf("%-25s %-15s %-8s %-12s %-8s %-8s\n", 
           "Circuit", "Pays", "Tours", "Date", "Heure", "Résultats");
    printf("--------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < nbGrandsPrix; i++) {
        if (grandsPrix[i].actif) {
            afficherGrandPrix(grandsPrix[i]);
        }
    }
    printf("\n");
}

// Afficher un Grand Prix
void afficherGrandPrix(GrandPrix gp) {
    printf("%-25s %-15s %-8d %02d/%02d/%04d %02d:%02d %-8d\n",
           gp.nomCircuit, gp.pays, gp.nombreTours,
           gp.date.jour, gp.date.mois, gp.date.annee,
           gp.horaire.heure, gp.horaire.minute,
           gp.nombreResultats);
}

// Valider un Grand Prix
int validerGrandPrix(GrandPrix gp) {
    if (strlen(gp.nomCircuit) == 0) {
        printf("Erreur : Nom du circuit obligatoire.\n");
        return 0;
    }
    
    if (strlen(gp.pays) == 0) {
        printf("Erreur : Pays organisateur obligatoire.\n");
        return 0;
    }
    
    if (gp.nombreTours < 10 || gp.nombreTours > 100) {
        printf("Erreur : Nombre de tours doit être entre 10 et 100.\n");
        return 0;
    }
    
    if (!validerDate(gp.date)) {
        printf("Erreur : Date invalide.\n");
        return 0;
    }
    
    if (!validerHeure(gp.horaire)) {
        printf("Erreur : Horaire invalide.\n");
        return 0;
    }
    
    if (gp.nombreResultats < 0 || gp.nombreResultats > 20) {
        printf("Erreur : Nombre de résultats invalide.\n");
        return 0;
    }
    
    return 1;
}

// Ajouter un résultat à un Grand Prix
int ajouterResultat(GrandPrix *gp, ResultatCourse resultat) {
    if (gp->nombreResultats >= MAX_RESULTATS_PAR_COURSE) {
        printf("Erreur : Nombre maximum de résultats atteint.\n");
        return 0;
    }
    
    // Vérifier que la position n'est pas déjà prise
    for (int i = 0; i < gp->nombreResultats; i++) {
        if (gp->resultats[i].position == resultat.position) {
            printf("Erreur : Position %d déjà occupée.\n", resultat.position);
            return 0;
        }
    }
    
    gp->resultats[gp->nombreResultats] = resultat;
    gp->nombreResultats++;
    printf("Résultat ajouté avec succès.\n");
    return 1;
}

// Supprimer un résultat d'un Grand Prix
int supprimerResultat(GrandPrix *gp, int position) {
    for (int i = 0; i < gp->nombreResultats; i++) {
        if (gp->resultats[i].position == position) {
            // Décaler les éléments suivants
            for (int j = i; j < gp->nombreResultats - 1; j++) {
                gp->resultats[j] = gp->resultats[j + 1];
            }
            gp->nombreResultats--;
            printf("Résultat supprimé avec succès.\n");
            return 1;
        }
    }
    printf("Erreur : Résultat non trouvé.\n");
    return 0;
}

// Afficher les résultats d'un Grand Prix
void afficherResultats(GrandPrix gp) {
    printf("\n=== RÉSULTATS - %s ===\n", gp.nomCircuit);
    printf("%-3s %-15s %-15s %-15s %-12s %-8s\n", 
           "Pos", "Nom", "Prénom", "Nationalité", "Temps", "Points");
    printf("--------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < gp.nombreResultats; i++) {
        printf("%-3d %-15s %-15s %-15s %-12s %-8d\n",
               gp.resultats[i].position,
               gp.resultats[i].nomPilote,
               gp.resultats[i].prenomPilote,
               gp.resultats[i].nationalite,
               gp.resultats[i].tempsRealise,
               gp.resultats[i].pointsObtenus);
    }
    printf("\n");
}

// Saisir un résultat
void saisirResultat(ResultatCourse *resultat) {
    printf("Nom du pilote : ");
    scanf("%s", resultat->nomPilote);
    
    printf("Prénom du pilote : ");
    scanf("%s", resultat->prenomPilote);
    
    printf("Nationalité : ");
    scanf("%s", resultat->nationalite);
    
    printf("Position (1-20) : ");
    scanf("%d", &resultat->position);
    
    printf("Temps réalisé (format H:MM:SS.sss) : ");
    scanf("%s", resultat->tempsRealise);
    
    resultat->pointsObtenus = obtenirPointsPosition(resultat->position);
}

// Valider un résultat
int validerResultat(ResultatCourse resultat, Pilote pilotes[], int nbPilotes) {
    if (resultat.position < 1 || resultat.position > 20) {
        printf("Erreur : Position doit être entre 1 et 20.\n");
        return 0;
    }
    
    // Vérifier que le pilote existe
    int piloteTrouve = 0;
    for (int i = 0; i < nbPilotes; i++) {
        if (strcmp(pilotes[i].nom, resultat.nomPilote) == 0 && 
            strcmp(pilotes[i].prenom, resultat.prenomPilote) == 0 && 
            pilotes[i].actif) {
            piloteTrouve = 1;
            break;
        }
    }
    
    if (!piloteTrouve) {
        printf("Erreur : Pilote '%s %s' non trouvé.\n", resultat.prenomPilote, resultat.nomPilote);
        return 0;
    }
    
    return 1;
}

// Saisir un Grand Prix
void saisirGrandPrix(GrandPrix *gp) {
    printf("Nom du circuit : ");
    scanf("%s", gp->nomCircuit);
    
    printf("Pays organisateur : ");
    scanf("%s", gp->pays);
    
    printf("Nombre de tours (10-100) : ");
    scanf("%d", &gp->nombreTours);
    
    printf("Jour : ");
    scanf("%d", &gp->date.jour);
    
    printf("Mois : ");
    scanf("%d", &gp->date.mois);
    
    printf("Année : ");
    scanf("%d", &gp->date.annee);
    
    printf("Heure (0-23) : ");
    scanf("%d", &gp->horaire.heure);
    
    printf("Minutes (0-59) : ");
    scanf("%d", &gp->horaire.minute);
    
    gp->nombreResultats = 0;
    gp->actif = 1;
}

// Vérifier si un Grand Prix existe
int grandPrixExiste(GrandPrix grandsPrix[], int nbGrandsPrix, char nomCircuit[]) {
    for (int i = 0; i < nbGrandsPrix; i++) {
        if (strcmp(grandsPrix[i].nomCircuit, nomCircuit) == 0 && grandsPrix[i].actif) {
            return 1;
        }
    }
    return 0;
}

// Mettre à jour les points des pilotes après un Grand Prix
void mettreAJourPointsPilotes(GrandPrix gp, Pilote pilotes[], int nbPilotes) {
    for (int i = 0; i < gp.nombreResultats; i++) {
        for (int j = 0; j < nbPilotes; j++) {
            if (strcmp(pilotes[j].nom, gp.resultats[i].nomPilote) == 0 && 
                strcmp(pilotes[j].prenom, gp.resultats[i].prenomPilote) == 0 && 
                pilotes[j].actif) {
                pilotes[j].points += gp.resultats[i].pointsObtenus;
                printf("Points mis à jour pour %s %s : +%d points\n", 
                       pilotes[j].prenom, pilotes[j].nom, gp.resultats[i].pointsObtenus);
                break;
            }
        }
    }
}
