#include "System.hpp"
#include "ConcreteComponent.hpp"
#include "Request.hpp"
#include "Response.hpp"

System::System() : componentA(nullptr), componentB(nullptr), componentC(nullptr), entryComponent(nullptr) {
    configure();
}

System::~System() {
    delete componentA;
    delete componentB;
    delete componentC;
}

void System::configure() {
    // Créez des composants
    componentA = new ConcreteComponent(std::chrono::milliseconds(100));
    componentB = new ConcreteComponent(std::chrono::milliseconds(150));
    componentC = new ConcreteComponent(std::chrono::milliseconds(200));

    // Connectez les composants via les ports
    componentA->addOutputPort(componentB);
    componentB->addInputPort(componentA);
    componentB->addOutputPort(componentC);
    componentC->addInputPort(componentB);

    // Définissez le point d'entrée du système
    entryComponent = componentA;
}

Response System::execute(Request& request) {
    if (entryComponent) {
       Response response = entryComponent->processRequest(request);
        // mise à jour le statut de la requête
        request.setStatus(RequestStatus::COMPLETED);
        return response;
    }
    return Response(request.getId(), "No entry component defined");
}