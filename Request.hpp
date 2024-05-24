#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <string>

// Énumération pour représenter le statut de la requête
enum class RequestStatus {
    PENDING,     
    IN_PROGRESS, 
    COMPLETED,   
    FAILED       
};

class Request {
private:
    long long int id;
    std::string data; 
    std::string type; 
    RequestStatus status; 

public:
    Request(long long int id, const std::string& data, const std::string& type);

    long long int getId() const;
    std::string getData() const;
    std::string getType() const;
    RequestStatus getStatus() const;
    void setStatus(RequestStatus newStatus);
};

#endif // REQUEST_HPP