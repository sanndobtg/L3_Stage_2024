#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <string>

// Énumération pour représenter le statut de la requête
enum class RequestStatus {
    PENDING,     // En attente d'exécution
    IN_PROGRESS, // En cours d'exécution
    COMPLETED,   // Terminée
    FAILED       // Une étape s'est mal passée
};

class Request {
private:
    long long int id;
    std::string data; // Données de la requête
    std::string type; // Type de la tâche à effectuer
    RequestStatus status; // Statut de la requête

public:
    Request(long long int id, const std::string& data, const std::string& type);

    long long int getId() const;
    std::string getData() const;
    std::string getType() const;
    RequestStatus getStatus() const;
    void setStatus(RequestStatus newStatus);
};

#endif // REQUEST_HPP