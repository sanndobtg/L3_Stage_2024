#ifndef CHRONOMETRE_HPP
#define CHRONOMETRE_HPP

#include <chrono>

class Chronometre {
private:
    std::chrono::time_point<std::chrono::system_clock> TE;
    std::chrono::time_point<std::chrono::system_clock> TR;

public:
    void setTE();
    void setTR();
    std::chrono::time_point<std::chrono::system_clock> getTE() const;
    std::chrono::time_point<std::chrono::system_clock> getTR() const;
};

#endif // CHRONOMETRE_HPP