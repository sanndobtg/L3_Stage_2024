#include <vector>
#include "Request.hpp"
#include "Requester.hpp"
#include "IdGenerator.hpp"

int main() {
    // Création d'un générateur d'ID pour les requêtes
    IdGenerator idGen;

    // Création d'un vecteur pour stocker les requêtes
    std::vector<Request> requests;

    // Création et ajout de quelques requêtes dans le vecteur
    requests.emplace_back(idGen.generateNextId(), "Donnée 1", "TypeA");
    requests.emplace_back(idGen.generateNextId(), "Donnée 2", "TypeB");
    requests.emplace_back(idGen.generateNextId(), "Donnée 3", "TypeC");

    // Création d'un objet Requester
    Requester requester;

    // Envoi de chaque requête et affichage du temps de traitement
    for (auto& req : requests) {
        requester.sendRequest(req);
    }

    return 0;
}