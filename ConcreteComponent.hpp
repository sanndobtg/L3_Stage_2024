#ifndef CONCRETECOMPONENT_HPP
#define CONCRETECOMPONENT_HPP

#include "Component.hpp"
#include <chrono>
#include <thread>
#include <vector>

class ConcreteComponent : public Component {
private:
    Component* nextComponent; // Pointeur vers le composant suivant
    std::chrono::milliseconds processingTime; // Temps de traitement
    std::vector<Component*> inputPorts; // Ports d'entrée
    std::vector<Component*> outputPorts; // Ports de sortie

public:
    ConcreteComponent(std::chrono::milliseconds procTime);
    virtual ~ConcreteComponent() {}

    // Méthode pour traiter la requête
    Response processRequest(const Request& request) override;

    
    virtual void addInputPort(Component* component) override;

    virtual void addOutputPort(Component* component) override ;

    // Méthode pour définir le composant suivant via les ports de sortie
    virtual void setNextComponent(Component* next);
};

#endif // CONCRETECOMPONENT_HPP