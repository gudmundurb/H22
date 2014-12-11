#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>

// DTO for scientists
class Scientist {
public:
    Scientist();
    std::string id;
    std::string name;
    std::string dateOfBirth;
    std::string dateOfDeath;
    std::string gender;
};

#endif // SCIENTIST_H
