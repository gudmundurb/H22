#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include "utilities.h"

class Computer {
public:
    Computer();
    Computer(std::string name, std::string dateOfBuild, std::string type, std::string built, std::string c_imagefilepath);
    std::string id;
    std::string name;
    std::string dateOfBuild;
    std::string type;
    std::string built;
    bool contains(std::string str);
    std::string toString();
    std::string c_imagefilepath;
};

#endif // COMPUTER_H
