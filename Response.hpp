#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include <string>

class Response {
private:
    long long int id; 
    std::string data;

public:
    Response(long long int id, const std::string& data); 
    long long int getId() const; 
    std::string getData() const;
};

#endif // RESPONSE_HPP