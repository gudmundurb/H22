#include "computer.h"

Computer::Computer() {
    id = "";
    name = "";
    dateOfBuild = "";
    type = "";
    built = "";
}
Computer::Computer(std::string name, std::string dateOfBuild, std::string type, std::string built) {
    this->id = "";
    this->name = name;
    this->dateOfBuild = dateOfBuild;
    this->type = type;
    this->built = built;
}

bool Computer::contains(std::string str) {
    return this->toString().find(str) != std::string::npos;
}

std::string Computer::toString() {
    return id + " " + name + " " + dateOfBuild + " " + type + " " + built;
}
