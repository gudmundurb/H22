#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>
#include "utilities.h"

// DTO for scientists
class Scientist {
public:
    Scientist();
    std::string id;
    std::string name;
    std::string dateOfBirth;
    std::string dateOfDeath;
    std::string gender;
    bool contains(std::string str);
    std::string toString();
    std::string s_imagefilepath;
};

#endif // SCIENTIST_H
