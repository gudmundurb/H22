#ifndef SERVICES_H
#define SERVICES_H

#include "computerrepository.h"
#include "ScientistRepository.h"
#include "linkrepository.h"

class Services {
public:
    Services();
    ~Services();
    //Add functions
    void addScientist(Scientist scientist);
    void addComputer (Computer computer);
    void addLink(Link link);
    //Search functions
    std::list<Scientist> scientistSearch(std::string searchTerm);
    std::list<Computer> computerSearch(std::string searchTerm);
    //List functions
    std::list<Scientist> getScientistsOrderedBy(std::string,std::string);
    std::list<Computer> getComputersOrderedBy(std::string col,std::string mod);
    //Link functions
    std::list<Scientist> scientistLink(std::string c_id);
    std::list<Computer> computerLink(std::string s_id);
private:
    ScientistRepository scientistRepository;
    ComputerRepository computerRepository;
    LinkRepository linkRepository;
};

#endif // SERVICES_H
