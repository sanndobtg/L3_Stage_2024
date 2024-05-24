#include "Response.hpp"

Response::Response(long long int id, const std::string& data)
    : id(id), data(data) {}

long long int Response::getId() const { 
    return id;
}

std::string Response::getData() const {
    return data;
}