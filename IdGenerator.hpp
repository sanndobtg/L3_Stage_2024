#ifndef IDGENERATOR_HPP
#define IDGENERATOR_HPP

#include <atomic>

class IdGenerator {
private:
    std::atomic<long long int> nextId;

public:
    IdGenerator();
    long long int generateNextId();
};

#endif // IDGENERATOR_HPP