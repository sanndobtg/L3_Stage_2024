#include "ConcreteComponent.hpp"

ConcreteComponent::ConcreteComponent(std::chrono::milliseconds procTime) : nextComponent(nullptr), processingTime(procTime) {}

Response ConcreteComponent::processRequest(const Request& request) {
    // Logique de traitement spécifique au composant
    // ...    
    // Simuler le temps de traitement
    std::this_thread::sleep_for(processingTime);
    // Passer la requête au composant suivant si nécessaire
    if (nextComponent) {
        return nextComponent->processRequest(request);
    }

    // Retourner une réponse si c'est le dernier composant
    return Response(request.getId(), "Processed by ConcreteComponent");
}

void ConcreteComponent::setNextComponent(Component* next) {
    nextComponent = next;
}