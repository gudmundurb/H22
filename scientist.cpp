#include "scientist.h"

Scientist::Scientist() {
    id = "";
    name = "";
    dateOfBirth = "";
    dateOfDeath = "";
    gender = "";
    s_imagefilepath = "";
}

bool Scientist::contains(std::string str) {
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

std::string Scientist::toString() {
    return id + " " + name + " " + dateOfBirth + " " + dateOfDeath + " " + gender;
}
