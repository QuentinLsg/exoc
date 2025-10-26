# 🏁 Système de Gestion FIA Formule 1 🏁

## Description
Ce projet implémente un système complet de gestion de championnat de Formule 1 en langage C, développé selon les spécifications du mini-projet XTI101.

## Fonctionnalités

### 📊 Gestion des Données
- **Pilotes** : CRUD complet avec validation des données
- **Écuries** : Gestion des équipes avec calcul automatique des points
- **Grands Prix** : Gestion des courses avec résultats détaillés
- **Classements** : Tri et affichage des classements pilotes et constructeurs

### 🏆 Système de Points FIA
- 1ère place : 25 points
- 2ème place : 18 points
- 3ème place : 15 points
- 4ème place : 12 points
- 5ème place : 10 points
- 6ème place : 8 points
- 7ème place : 6 points
- 8ème place : 4 points
- 9ème place : 2 points
- 10ème place : 1 point

## Architecture Modulaire

### 📁 Structure des Fichiers
```
ExoC/
├── main.c                 # Point d'entrée du programme
├── structures.h/.c        # Structures de données et fonctions utilitaires
├── pilote.h/.c           # Module de gestion des pilotes
├── ecurie.h/.c           # Module de gestion des écuries
├── grandprix.h/.c        # Module de gestion des Grands Prix
├── classement.h/.c       # Module de tri et affichage des classements
├── initialisation.h/.c   # Module d'initialisation des données de test
├── Makefile              # Fichier de compilation
└── README.md             # Ce fichier
```

### 🏗️ Structures de Données
- **Date** : Gestion des dates avec validation
- **Heure** : Gestion des horaires au format 24h
- **Pilote** : Informations complètes des pilotes
- **Ecurie** : Données des équipes
- **ResultatCourse** : Résultats d'une course
- **GrandPrix** : Informations complètes d'un Grand Prix

## Installation et Compilation

### Prérequis Windows
- **MSYS2/MinGW** (recommandé) : https://www.msys2.org/
- **WSL2** (alternative) : `wsl --install`
- **Git Bash** (basique) : Inclus avec Git

### Compilation avec Make (Windows)
```bash
# Compiler le projet
make

# Nettoyer les fichiers de compilation
make clean

# Recompiler complètement
make rebuild

# Compiler et exécuter
make run
```

### Compilation Manuelle (Windows)
```cmd
# Command Prompt
gcc -Wall -Wextra -std=c99 -g -o f1_management.exe main.c structures.c pilote.c ecurie.c grandprix.c classement.c initialisation.c

# Exécution
f1_management.exe
```

### Script Batch (.bat) - Alternative Simple
Créez un fichier `compile.bat` :
```batch
@echo off
echo Compilation du projet F1...
gcc -Wall -Wextra -std=c99 -g -o f1_management.exe main.c structures.c pilote.c ecurie.c grandprix.c classement.c initialisation.c
if %errorlevel% equ 0 (
    echo Compilation reussie !
    f1_management.exe
) else (
    echo Erreur de compilation !
)
pause
```

### Environnements Windows Supportés
- **MSYS2/MinGW** : Environnement Unix-like complet
- **WSL2** : Sous-système Linux sur Windows
- **Git Bash** : Terminal basique avec make
- **Command Prompt** : Compilation directe avec gcc

## Utilisation

### Lancement du Programme (Windows)
```cmd
# Command Prompt
f1_management.exe

# PowerShell
.\f1_management.exe

# MSYS2/Git Bash
./f1_management.exe
```

### Menu Principal
Le programme propose un menu interactif avec les options suivantes :

1. **Gestion des Pilotes**
   - Ajouter un pilote
   - Supprimer un pilote
   - Modifier un pilote
   - Afficher tous les pilotes
   - Rechercher un pilote

2. **Gestion des Écuries**
   - Ajouter une écurie
   - Supprimer une écurie
   - Modifier une écurie
   - Afficher toutes les écuries
   - Rechercher une écurie
   - Calculer les points d'une écurie

3. **Gestion des Grands Prix**
   - Ajouter un Grand Prix
   - Supprimer un Grand Prix
   - Modifier un Grand Prix
   - Afficher tous les Grands Prix
   - Rechercher un Grand Prix
   - Ajouter un résultat
   - Afficher les résultats d'un Grand Prix

4. **Classements**
   - Classement des pilotes
   - Classement des écuries
   - Classement d'une course

5. **Mettre à jour les points**
6. **Afficher toutes les données**

## Données de Test

Le programme inclut des données pré-initialisées pour faciliter les tests :

### Écuries (5)
- Red Bull Racing (Autriche)
- Scuderia Ferrari (Italie)
- Mercedes-AMG (Allemagne)
- McLaren Racing (Royaume-Uni)
- Aston Martin (Royaume-Uni)

### Pilotes (10)
- Max Verstappen (Red Bull Racing)
- Sergio Perez (Red Bull Racing)
- Charles Leclerc (Scuderia Ferrari)
- Carlos Sainz (Scuderia Ferrari)
- Lewis Hamilton (Mercedes-AMG)
- George Russell (Mercedes-AMG)
- Lando Norris (McLaren Racing)
- Oscar Piastri (McLaren Racing)
- Fernando Alonso (Aston Martin)
- Lance Stroll (Aston Martin)

### Grands Prix (3)
- Circuit de Monaco (26/05/2024)
- Silverstone Circuit (07/07/2024)
- Autodromo Nazionale Monza (01/09/2024)

## Validation des Données

Le système inclut une validation complète des données :
- **Dates** : Validation des années bissextiles
- **Heures** : Format 24h avec validation
- **Pilotes** : Âge entre 18 et 50 ans, numéro unique
- **Écuries** : Année de création cohérente
- **Grands Prix** : Nombre de tours entre 10 et 100
- **Résultats** : Positions entre 1 et 20, pilotes existants

## Fonctionnalités Avancées

### Calcul Automatique des Points
- Les points des pilotes sont mis à jour automatiquement après chaque course
- Les points des écuries sont calculés comme la somme des points de leurs pilotes

### Suppression Logique
- Les entités supprimées sont marquées comme inactives (actif = 0)
- Elles n'apparaissent plus dans les affichages mais restent en mémoire

### Tri et Classements
- Tri par sélection pour les classements
- Affichage formaté avec positions
- Classements séparés pour pilotes et écuries

## 🚀 Compilation et Exécution

# Compiler manuellement
gcc -Wall -Wextra -std=c99 -g -o f1_management main.c structures.c pilote.c ecurie.c grandprix.c classement.c initialisation.c
./f1_management
```

## Conformité aux Spécifications

✅ **Architecture modulaire** : Chaque fonctionnalité dans un module dédié  
✅ **Structures de données** : 6 structures principales implémentées  
✅ **Fonctionnalités CRUD** : Création, lecture, mise à jour, suppression  
✅ **Validation des données** : Contrôles complets sur toutes les entrées  
✅ **Données pré-initialisées** : 5 écuries, 10 pilotes, 3 Grands Prix  
✅ **Système de points FIA** : Attribution automatique selon les positions  
✅ **Classements** : Tri et affichage des classements pilotes et constructeurs  
✅ **Gestion des relations** : Liens entre pilotes, écuries et résultats  

## Développement

### Standards de Code
- Norme C99
- Compilation sans erreurs ni avertissements
- Code commenté et bien structuré
- Conventions de nommage respectées

### Tests
Le programme inclut des données de test réalistes permettant de :
- Tester toutes les fonctionnalités
- Démontrer le système rapidement
- Valider les calculs de points
- Vérifier les classements

## Auteur
Projet développé dans le cadre du module XTI101 - Programmation C

## Licence
Projet éducatif - Usage académique uniquement
