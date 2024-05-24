#include "ConcreteComponent.hpp"

ConcreteComponent::ConcreteComponent(std::chrono::milliseconds procTime)
    : nextComponent(nullptr), processingTime(procTime) {}

Response ConcreteComponent::processRequest(const Request& request) {
    // Logique de traitement spécifique au composant
    // ...
    // Simuler le temps de traitement pour le moment 
    std::this_thread::sleep_for(processingTime);
    // on passe au composant suivant de mon systeme 
    for (auto& component : outputPorts) {
        component->processRequest(request);
    }

    // Retourner une réponse si c'est le dernier composant
    return Response(request.getId(), "Processed by ConcreteComponent");
}

// Méthodes pour gérer les ports d'entrée et de sortie
void ConcreteComponent::addInputPort(Component* component){
    inputPorts.push_back(component);
}

void ConcreteComponent::addOutputPort(Component* component){
    outputPorts.push_back(component);
}

// Méthode pour définir le composant suivant via les ports de sortie
void ConcreteComponent::setNextComponent(Component* next) {
    if (!outputPorts.empty()) {
        // Remplacez le dernier port de sortie par le nouveau composant
        outputPorts.back() = next;
    } else {
            // Ajoutez le nouveau composant si aucun port de sortie n'est défini
        addOutputPort(next);
    }
    nextComponent = next; // Gardez une référence directe au composant suivant
}