#include "Chronometre.hpp"

void Chronometre::setTE() {
    TE = std::chrono::system_clock::now();
}

void Chronometre::setTR() {
    TR = std::chrono::system_clock::now();
}

std::chrono::time_point<std::chrono::system_clock> Chronometre::getTE() const {
    return TE;
}

std::chrono::time_point<std::chrono::system_clock> Chronometre::getTR() const {
    return TR;
}