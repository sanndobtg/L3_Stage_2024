#include "IdGenerator.hpp"

IdGenerator::IdGenerator() : nextId(0) {}

long long int IdGenerator::generateNextId() {
    return nextId++;
}