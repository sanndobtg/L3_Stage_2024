#ifndef CONCRETECOMPONENT_HPP
#define CONCRETECOMPONENT_HPP

#include <chrono>
#include <thread>
#include "Component.hpp"

// Un composant concret qui traite les requêtes d'une certaine manière
class ConcreteComponent : public Component {
private:
    Component* nextComponent; // Pointeur vers le composant suivant
     std::chrono::milliseconds processingTime; // Temps de traitement simulé

public:
    ConcreteComponent(std::chrono::milliseconds procTime);
    virtual Response processRequest(const Request& request) override;
    virtual void setNextComponent(Component* next) override;
};

#endif // CONCRETECOMPONENT_HPP