#include <iostream>
#include <vector>
#include "Request.hpp"
#include "Response.hpp"
#include "IdGenerator.hpp"
#include "System.hpp"
#include "Requester.hpp"

int main() {
    // Création d'un générateur d'ID pour les requêtes
    IdGenerator idGen;

    // Création d'un vecteur pour stocker les requêtes
    std::vector<Request> requests;

    // Création et ajout de quelques requêtes dans le vecteur
    requests.emplace_back(idGen.generateNextId(), "Donnée 1", "TypeA");
    requests.emplace_back(idGen.generateNextId(), "Donnée 2", "TypeB");
    requests.emplace_back(idGen.generateNextId(), "Donnée 3", "TypeC");

    // Création du système complexe
    System system;

    // Création de l'objet Requester avec une référence vers le système
    Requester requester(system);

    // Envoi de chaque requête via l'objet Requester
    for (auto& req : requests) {
        requester.sendRequest(req);
    }
    
    return 0;
}