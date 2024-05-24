#include <thread>
#include "System.hpp"


Response System::execute( Request& request) {
    // Simuler un traitement en mettant à jour le statut de la requête
    request.setStatus(RequestStatus::COMPLETED);

    // Simuler un temps de traitement (optionnel)
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // Retourner une réponse avec les données de la requête
    return Response(request.getId(), "Response Data");
}