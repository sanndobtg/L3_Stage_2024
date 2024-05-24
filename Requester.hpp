#ifndef REQUESTER_HPP
#define REQUESTER_HPP

#include "Request.hpp"
#include "Response.hpp"
#include "Chronometre.hpp"

class Requester {
private:
    Chronometre chronometre;

public:
    void sendRequest(Request& request);
    void receiveResponse(Request& request);
};

#endif // REQUESTER_HPP