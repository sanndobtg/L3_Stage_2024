#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Request.hpp"
#include "Response.hpp"

// Interface de base pour les composants
class Component {
public:
    virtual ~Component() = default;
    virtual Response processRequest(const Request& request) = 0;
    virtual void setNextComponent(Component* next) = 0;
};

#endif // COMPONENT_HPP