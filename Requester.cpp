#include <iostream>
#include "Requester.hpp"
#include "System.hpp"

void Requester::sendRequest(Request& request) {
    chronometre.setTE(); 
    system.execute(request); 
    // La méthode execute doit mettre à jour le statut de la requête
    // à COMPLETED une fois qu'elle est traitée
    receiveResponse(request); // Simule la réception de la réponse
}



void Requester::receiveResponse(Request& request) {
    std::cout << "Request received with ID: " << request.getId() << std::endl;
    if (request.getStatus() == RequestStatus::COMPLETED) {
        chronometre.setTR(); 
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
            chronometre.getTR() - chronometre.getTE()
        ).count();
        std::cout << "Process Time: " << duration << " ms" << std::endl;
    } else {
       
        std::cout << "Requête pas traitée correctement." << std::endl;
    }
}