#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "Component.hpp"
#include "Request.hpp"
#include "Response.hpp"

class System {
private:
    Component* componentA; 
    Component* componentB; 
    Component* componentC; 
    Component* entryComponent;

public:
    System(); 
    ~System(); 

    // Méthode pour initialiser et connecter les composants
    void configure(); 
    
    // Méthode pour exécuter une requête à travers les composants
    Response execute(Request& request); 
};

#endif // SYSTEM_HPP