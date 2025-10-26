#include "structures.h"

// Fonction pour obtenir les points selon la position
int obtenirPointsPosition(int position) {
    switch(position) {
        case 1: return POINTS_POSITION_1;
        case 2: return POINTS_POSITION_2;
        case 3: return POINTS_POSITION_3;
        case 4: return POINTS_POSITION_4;
        case 5: return POINTS_POSITION_5;
        case 6: return POINTS_POSITION_6;
        case 7: return POINTS_POSITION_7;
        case 8: return POINTS_POSITION_8;
        case 9: return POINTS_POSITION_9;
        case 10: return POINTS_POSITION_10;
        default: return 0;
    }
}

// Fonction de validation des dates
int validerDate(Date date) {
    if (date.annee < 1900 || date.annee > 2100) return 0;
    if (date.mois < 1 || date.mois > 12) return 0;
    
    int joursParMois[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Gestion des années bissextiles
    if (date.mois == 2 && ((date.annee % 4 == 0 && date.annee % 100 != 0) || (date.annee % 400 == 0))) {
        joursParMois[1] = 29;
    }
    
    if (date.jour < 1 || date.jour > joursParMois[date.mois - 1]) return 0;
    
    return 1;
}

// Fonction de validation des heures
int validerHeure(Heure heure) {
    return (heure.heure >= 0 && heure.heure <= 23 && heure.minute >= 0 && heure.minute <= 59);
}
