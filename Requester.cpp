#include <iostream>
#include "Requester.hpp"
#include "System.hpp"

void Requester::sendRequest(Request& request) {
    System system;
    chronometre.setTE(); // Démarrer le chronomètre
    system.execute(request); // Exécution de la requête
    // La méthode execute doit mettre à jour le statut de la requête
    // à COMPLETED une fois qu'elle est traitée
    receiveResponse(request); // Simule la réception de la réponse
}


void Requester::receiveResponse(Request& request) {
    std::cout << "Request received with ID: " << request.getId() << std::endl;
    if (request.getStatus() == RequestStatus::COMPLETED) {
        chronometre.setTR(); // Arrêter le chronomètre
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
            chronometre.getTR() - chronometre.getTE()
        ).count();
        std::cout << "Process Time: " << duration << " ms" << std::endl;
    } else {
        // Gérer les cas où la requête n'est pas complétée
        std::cout << "requête pas traitée correctement." << std::endl;
    }
}