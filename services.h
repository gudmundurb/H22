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
    //Remove functions
    void removeScientist(std::string s_id);
    void removeComputer(std::string c_id);
    void removeLink(std::string s_id, std::string c_id);
    //Search functions
    std::vector<Scientist> scientistSearch(std::string searchTerm);
    std::vector<Computer> computerSearch(std::string searchTerm);
    //List functions
    std::vector<Scientist> getScientistsOrderedBy(std::string,std::string);
    std::vector<Computer> getComputersOrderedBy(std::string col,std::string mod);
    //Link functions
    std::vector<Scientist> scientistLink(std::string c_id);
    std::vector<Computer> computerLink(std::string s_id);

    void updateScientist(Scientist oldScientist, Scientist newScientist);
private:
    ScientistRepository scientistRepository;
    ComputerRepository computerRepository;
    LinkRepository linkRepository;
};

#endif // SERVICES_H
