
TARGET = program
CXX = g++
CXXFLAGS = -Wall -std=c++14

# Dossiers contenant les fichiers source
SRC_DIR = .

# Dossiers contenant les fichiers objets (.o)
OBJ_DIR = ./obj

# Trouver tous les fichiers source (.cpp) dans SRC_DIR
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Convertir les .cpp en .o
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Lien pour générer l'exécutable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation des fichiers source
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyer les fichiers objets et l'exécutable
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Commande par défaut
all: $(TARGET)

# Empêcher les conflits de noms de fichiers et de commandes
.PHONY: all clean