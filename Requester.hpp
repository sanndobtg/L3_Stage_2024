#ifndef REQUESTER_HPP
#define REQUESTER_HPP

#include "Request.hpp"
#include "Response.hpp"
#include "Chronometre.hpp"
#include "System.hpp"

class Requester {
private:
    System& system; // Référence vers le système complexe
    Chronometre chronometre;

public:
    Requester(System& sys) : system(sys) {}

    void sendRequest(Request& request);
    void receiveResponse(Request& request);
};

#endif // REQUESTER_HPP