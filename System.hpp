#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "Request.hpp"
#include "Response.hpp"
#include "Component.hpp"
#include "ConcreteComponent.hpp"

// Classe System qui contient et gère les composants
class System {
private:
    ConcreteComponent* componentA;
    ConcreteComponent* componentB;
    ConcreteComponent* componentC;
    Component* entryComponent; // Point d'entrée du système

public:
    System();
     ~System(); // Ajoutez un destructeur pour nettoyer la mémoire
    void setupComponents(); // Nouvelle méthode pour configurer les composants
    Response execute(Request& request);
};

#endif // SYSTEM_HPP