#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "Request.hpp"
#include "Response.hpp"

class System {
public:
    Response execute(Request& request);
};

#endif // SYSTEM_HPP