#include "Request.hpp"

Request::Request(long long int id, const std::string& data, const std::string& type)
    : id(id), data(data), type(type), status(RequestStatus::PENDING) {}

long long int Request::getId() const {
    return id;
}

std::string Request::getData() const {
    return data;
}

std::string Request::getType() const {
    return type;
}

RequestStatus Request::getStatus() const {
    return status;
}

void Request::setStatus(RequestStatus newStatus) {
    status = newStatus;
}