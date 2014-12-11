#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "services.h"
#include "utilities.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>

// Display layer for the console application
class ConsoleUI {
public:
    ConsoleUI();
    ~ConsoleUI();
    int start();
private:
    Services Service;
    void printFormatted(std::string a, std::string b, std::string c, std::string d, std::string e);
    void printLine();
    void waitForPrompt();
    void noResults();
    bool respondToMessage();
    //Add functions.
    void addScientist();
    void addComputer();
    void addLink();
    //Display functions
    void listScientist();
    void listComputer();
    //Search functions
    void searchScientist();
    void searchComputer();
    void searchLink();
    void searchScientistLinks();
    void searchComputerLinks();
    //Print functions
    void printScientists(std::list<Scientist> printOut);
    void printComputers(std::list<Computer> printOut);
};

#endif // CONSOLEUI_H
