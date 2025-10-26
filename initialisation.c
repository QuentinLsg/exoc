#include "initialisation.h"
#include "pilote.h"
#include "ecurie.h"
#include "grandprix.h"
#include "classement.h"

// Fonction principale d'initialisation des données de test
void initialiserDonneesTest(Pilote pilotes[], int *nbPilotes, 
                           Ecurie ecuries[], int *nbEcuries, 
                           GrandPrix grandsPrix[], int *nbGrandsPrix) {
    printf("Initialisation des données de test...\n");
    
    // Initialiser les écuries
    initialiserEcuries(ecuries, nbEcuries);
    
    // Initialiser les pilotes
    initialiserPilotes(pilotes, nbPilotes);
    
    // Initialiser les Grands Prix
    initialiserGrandsPrix(grandsPrix, nbGrandsPrix);
    
    printf("Données de test initialisées avec succès !\n");
    printf("- %d écuries\n", *nbEcuries);
    printf("- %d pilotes\n", *nbPilotes);
    printf("- %d Grands Prix\n", *nbGrandsPrix);
}

// Initialiser les écuries
void initialiserEcuries(Ecurie ecuries[], int *nbEcuries) {
    Ecurie ecuriesTest[5] = {
        {"Red Bull Racing", "Autriche", 0, 2005, "Christian Horner", 1},
        {"Scuderia Ferrari", "Italie", 0, 1950, "Frédéric Vasseur", 1},
        {"Mercedes-AMG", "Allemagne", 0, 2010, "Toto Wolff", 1},
        {"McLaren Racing", "Royaume-Uni", 0, 1966, "Andrea Stella", 1},
        {"Aston Martin", "Royaume-Uni", 0, 2021, "Mike Krack", 1}
    };
    
    for (int i = 0; i < 5; i++) {
        ecuries[i] = ecuriesTest[i];
    }
    *nbEcuries = 5;
}

// Initialiser les pilotes
void initialiserPilotes(Pilote pilotes[], int *nbPilotes) {
    Pilote pilotesTest[10] = {
        {"Verstappen", "Max", "Pays-Bas", "Red Bull Racing", 0, 1, 27, 1},
        {"Perez", "Sergio", "Mexique", "Red Bull Racing", 0, 11, 34, 1},
        {"Leclerc", "Charles", "Monaco", "Scuderia Ferrari", 0, 16, 27, 1},
        {"Sainz", "Carlos", "Espagne", "Scuderia Ferrari", 0, 55, 30, 1},
        {"Hamilton", "Lewis", "Royaume-Uni", "Mercedes-AMG", 0, 44, 39, 1},
        {"Russell", "George", "Royaume-Uni", "Mercedes-AMG", 0, 63, 26, 1},
        {"Norris", "Lando", "Royaume-Uni", "McLaren Racing", 0, 4, 25, 1},
        {"Piastri", "Oscar", "Australie", "McLaren Racing", 0, 81, 23, 1},
        {"Alonso", "Fernando", "Espagne", "Aston Martin", 0, 14, 43, 1},
        {"Stroll", "Lance", "Canada", "Aston Martin", 0, 18, 26, 1}
    };
    
    for (int i = 0; i < 10; i++) {
        pilotes[i] = pilotesTest[i];
    }
    *nbPilotes = 10;
}

// Initialiser les Grands Prix
void initialiserGrandsPrix(GrandPrix grandsPrix[], int *nbGrandsPrix) {
    // Grand Prix 1 - Monaco
    GrandPrix gp1;
    strcpy(gp1.nomCircuit, "Circuit de Monaco");
    strcpy(gp1.pays, "Monaco");
    gp1.nombreTours = 78;
    gp1.date = (Date){26, 5, 2024};
    gp1.horaire = (Heure){15, 0};
    gp1.nombreResultats = 10;
    gp1.actif = 1;
    
    // Résultats du Grand Prix de Monaco
    ResultatCourse resultatsMonaco[10] = {
        {"Verstappen", "Max", "Pays-Bas", 1, "1:44:12.456", 25},
        {"Leclerc", "Charles", "Monaco", 2, "1:44:18.234", 18},
        {"Hamilton", "Lewis", "Royaume-Uni", 3, "1:44:25.678", 15},
        {"Norris", "Lando", "Royaume-Uni", 4, "1:44:32.123", 12},
        {"Sainz", "Carlos", "Espagne", 5, "1:44:39.456", 10},
        {"Russell", "George", "Royaume-Uni", 6, "1:44:45.789", 8},
        {"Perez", "Sergio", "Mexique", 7, "1:44:52.234", 6},
        {"Alonso", "Fernando", "Espagne", 8, "1:44:58.567", 4},
        {"Piastri", "Oscar", "Australie", 9, "1:45:04.890", 2},
        {"Stroll", "Lance", "Canada", 10, "1:45:11.123", 1}
    };
    
    // Copier les résultats dans la structure GrandPrix
    for (int i = 0; i < 10; i++) {
        gp1.resultats[i] = resultatsMonaco[i];
    }
    
    // Grand Prix 2 - Silverstone
    GrandPrix gp2;
    strcpy(gp2.nomCircuit, "Silverstone Circuit");
    strcpy(gp2.pays, "Royaume-Uni");
    gp2.nombreTours = 52;
    gp2.date = (Date){7, 7, 2024};
    gp2.horaire = (Heure){15, 0};
    gp2.nombreResultats = 10;
    gp2.actif = 1;
    
    // Résultats du Grand Prix de Silverstone
    ResultatCourse resultatsSilverstone[10] = {
        {"Hamilton", "Lewis", "Royaume-Uni", 1, "1:24:35.123", 25},
        {"Norris", "Lando", "Royaume-Uni", 2, "1:24:42.456", 18},
        {"Verstappen", "Max", "Pays-Bas", 3, "1:24:48.789", 15},
        {"Russell", "George", "Royaume-Uni", 4, "1:24:55.234", 12},
        {"Leclerc", "Charles", "Monaco", 5, "1:25:01.567", 10},
        {"Sainz", "Carlos", "Espagne", 6, "1:25:07.890", 8},
        {"Piastri", "Oscar", "Australie", 7, "1:25:14.123", 6},
        {"Alonso", "Fernando", "Espagne", 8, "1:25:20.456", 4},
        {"Perez", "Sergio", "Mexique", 9, "1:25:26.789", 2},
        {"Stroll", "Lance", "Canada", 10, "1:25:33.012", 1}
    };
    
    // Copier les résultats dans la structure GrandPrix
    for (int i = 0; i < 10; i++) {
        gp2.resultats[i] = resultatsSilverstone[i];
    }
    
    // Grand Prix 3 - Monza
    GrandPrix gp3;
    strcpy(gp3.nomCircuit, "Autodromo Nazionale Monza");
    strcpy(gp3.pays, "Italie");
    gp3.nombreTours = 53;
    gp3.date = (Date){1, 9, 2024};
    gp3.horaire = (Heure){15, 0};
    gp3.nombreResultats = 10;
    gp3.actif = 1;
    
    // Résultats du Grand Prix de Monza
    ResultatCourse resultatsMonza[10] = {
        {"Leclerc", "Charles", "Monaco", 1, "1:20:15.234", 25},
        {"Sainz", "Carlos", "Espagne", 2, "1:20:22.567", 18},
        {"Verstappen", "Max", "Pays-Bas", 3, "1:20:28.890", 15},
        {"Hamilton", "Lewis", "Royaume-Uni", 4, "1:20:35.123", 12},
        {"Norris", "Lando", "Royaume-Uni", 5, "1:20:41.456", 10},
        {"Russell", "George", "Royaume-Uni", 6, "1:20:47.789", 8},
        {"Perez", "Sergio", "Mexique", 7, "1:20:54.012", 6},
        {"Piastri", "Oscar", "Australie", 8, "1:21:00.345", 4},
        {"Alonso", "Fernando", "Espagne", 9, "1:21:06.678", 2},
        {"Stroll", "Lance", "Canada", 10, "1:21:12.901", 1}
    };
    
    // Copier les résultats dans la structure GrandPrix
    for (int i = 0; i < 10; i++) {
        gp3.resultats[i] = resultatsMonza[i];
    }
    
    // Ajouter les Grands Prix au tableau
    grandsPrix[0] = gp1;
    grandsPrix[1] = gp2;
    grandsPrix[2] = gp3;
    *nbGrandsPrix = 3;
}
