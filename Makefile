# Makefile pour Windows (compatible MinGW/MSYS2)
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
TARGET = f1_management.exe
SOURCES = main.c structures.c pilote.c ecurie.c grandprix.c classement.c initialisation.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = structures.h pilote.h ecurie.h grandprix.h classement.h initialisation.h

# Règle par défaut
all: $(TARGET)

# Compilation du programme principal
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Compilation des fichiers objets
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage (compatible Windows)
clean:
	del /Q $(OBJECTS) $(TARGET) 2>nul || true

# Réinstallation complète
rebuild: clean all

# Exécution du programme
run: $(TARGET)
	$(TARGET)

# Affichage de l'aide
help:
	@echo Makefile pour le projet F1 - Version Windows
	@echo Commandes disponibles :
	@echo   make        - Compiler le projet
	@echo   make clean  - Nettoyer les fichiers de compilation
	@echo   make rebuild- Nettoyer et recompiler
	@echo   make run    - Compiler et exécuter le programme
	@echo   make help   - Afficher cette aide

.PHONY: all clean rebuild run help
