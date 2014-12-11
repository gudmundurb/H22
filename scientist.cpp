#include "scientist.h"

Scientist::Scientist() {
    id = "";
    name = "";
    dateOfBirth = "";
    dateOfDeath = "";
    gender = "";
}

bool Scientist::contains(std::string str) {
    return this->toString().find(str) != std::string::npos;
}

std::string Scientist::toString() {
    return id + " " + name + " " + dateOfBirth + " " + dateOfDeath + " " + gender;
}
