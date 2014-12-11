#include "services.h"

Services::Services() {
}

Services::~Services() {
}

void Services::addScientist(Scientist scientist) {
    scientistRepository.add(scientist);
}

void Services::addComputer(Computer computer) {
    computerRepository.add(computer);
}

void Services::addLink(Link link) {
    linkRepository.add(link);
}

std::list<Scientist> Services::getScientistsOrderedBy(std::string col, std::string mod) {
    return scientistRepository.list(col,mod);
}

std::list<Computer> Services::getComputersOrderedBy(std::string col, std::string mod) {
    return computerRepository.list(col,mod);
}

std::list<Scientist> Services::scientistSearch(std::string searchTerm) {
    return scientistRepository.search(searchTerm);
}

std::list<Computer> Services::computerSearch(std::string searchTerm) {
    return computerRepository.search(searchTerm);
}

std::list<Scientist> Services::scientistLink(std::string computer_id) {
    return linkRepository.getScientists(computer_id);
}

std::list<Computer> Services::computerLink(std::string scientist_id) {
    return linkRepository.getComputers(scientist_id);
}
