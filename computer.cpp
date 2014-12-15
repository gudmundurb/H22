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
    if(str == "") {
        return true;
    }

    std::string searchStringToLower = util::stringToLower(str);

    if(util::stringToLower(this->toString()).find(searchStringToLower) != std::string::npos) {
        return true;
    }
    else {
        return false;
    }
}

std::string Computer::toString() {
    return id + " " + name + " " + dateOfBuild + " " + type + " " + built;
}
