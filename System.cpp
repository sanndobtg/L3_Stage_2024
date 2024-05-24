#include "System.hpp"

System::System() : componentA(nullptr), componentB(nullptr), componentC(nullptr), entryComponent(nullptr) {
    setupComponents();
}

System::~System() {
    delete componentA;
    delete componentB;
    delete componentC;
}

void System::setupComponents() {
    // Créez des composants avec des temps de traitement différents
    componentA = new ConcreteComponent(std::chrono::milliseconds(100));
    componentB = new ConcreteComponent(std::chrono::milliseconds(150));
    componentC = new ConcreteComponent(std::chrono::milliseconds(200));

    // Connectez les composants
    componentA->setNextComponent(componentB);
    componentB->setNextComponent(componentC);

    // Définissez le point d'entrée du système
    entryComponent = componentA;
}

Response System::execute(Request& request) {
   if (entryComponent) {
        Response response = entryComponent->processRequest(request);
        // Après le traitement, mettre à jour le statut de la requête
        request.setStatus(RequestStatus::COMPLETED);
        return response;
    }
    // Retourner une réponse d'erreur si aucun composant d'entrée n'est défini
    return Response(request.getId(), "No entry component defined");
}