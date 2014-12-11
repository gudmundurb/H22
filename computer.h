#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

class Computer {
public:
    Computer();
    std::string id;
    std::string name;
    std::string dateOfBuild;
    std::string type;
    std::string built;
    bool contains(std::string str);
};

#endif // COMPUTER_H
