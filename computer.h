#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

class Computer {
public:
    Computer();
    Computer(std::string name, std::string dateOfBuild, std::string type, std::string built);
    std::string id;
    std::string name;
    std::string dateOfBuild;
    std::string type;
    std::string built;
    bool contains(std::string str);
    std::string toString();
};

#endif // COMPUTER_H
