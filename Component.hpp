#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Request.hpp"
#include "Response.hpp"
#include <vector>

class Component {
public:
    virtual ~Component() = default;
    virtual Response processRequest(const Request& request) = 0;

    // Méthodes pour gérer les ports d'entrée et de sortie
    virtual void addInputPort(Component* component) = 0;
    virtual void addOutputPort(Component* component) = 0;
};

#endif // COMPONENT_HPP