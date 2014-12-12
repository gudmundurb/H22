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

std::vector<Scientist> Services::getScientistsOrderedBy(std::string col, std::string mod) {
    return scientistRepository.list(col,mod);
}

std::vector<Computer> Services::getComputersOrderedBy(std::string col, std::string mod) {
    return computerRepository.list(col,mod);
}

std::vector<Scientist> Services::scientistSearch(std::string searchTerm) {
    return scientistRepository.search(searchTerm);
}

std::vector<Computer> Services::computerSearch(std::string searchTerm) {
    return computerRepository.search(searchTerm);
}

std::vector<Scientist> Services::scientistLink(std::string computer_id) {
    return linkRepository.getScientists(computer_id);
}

std::vector<Computer> Services::computerLink(std::string scientist_id) {
    return linkRepository.getComputers(scientist_id);
}
