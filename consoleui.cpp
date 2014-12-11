#include "consoleui.h"
#include "menus.h"

ConsoleUI::ConsoleUI() {
}

ConsoleUI::~ConsoleUI() {
}

int ConsoleUI::start() {
    bool response = true;
    while(response) {
        response = respondToMessage();
    }
    return 0;
}

void ConsoleUI::printFormatted(std::string a, std::string b, std::string c, std::string d, std::string e) {
    std::cout << std::left
              << std::setw(5)  << a
              << std::setw(25) << b
              << std::setw(8)  << c
              << std::setw(20) << d
              << std::setw(8)  << e
              << std::endl;
}

void ConsoleUI::printLine() {
    for(int i = 0; i < 68; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

void ConsoleUI::noResults() {
    std::cout << std::endl << "No results." << std::endl;
}

void ConsoleUI::waitForPrompt() {
    std::cout << "\nPress enter to continue...";
    std::cin.get();
}

bool ConsoleUI::respondToMessage() {
    char userRequest;
    std::cout << MAIN_MENU << std::endl;
    std::cin >> userRequest;
    std::cin.ignore(1000, '\n');
    switch(userRequest) {
        case '1': {addScientist(); break;}
        case '2': {addComputer(); break;}
        case '3': {addLink(); break;}
        case '4': {listScientist(); break;}
        case '5': {listComputer(); break;}
        case '6': {searchScientist(); break;}
        case '7': {searchComputer(); break;}
        case '8': {searchLink(); break;}
        case '0': {return false; break;}
        default : {
            std::cout << userRequest << " is not a valid command." << std::endl;
            waitForPrompt();
        }
    }
    return true;
}

void ConsoleUI::addScientist() {
    Scientist additionalScientist = Scientist();
    bool valid;
    std::cout << "Name: ";
    std::getline(std::cin, additionalScientist.name);
    std::cout << "Year of birth: ";
    std::cin >> additionalScientist.dateOfBirth;
    std::cout << "Year of death (0 if alive): ";
    std::cin >> additionalScientist.dateOfDeath;
    if(additionalScientist.dateOfDeath == "0") {
        additionalScientist.dateOfDeath = "----";
    }
    std::cout << "Gender (M/F): ";
    std::cin >> additionalScientist.gender;
    std::cin.ignore();
    //Years must be valid
    //Use aliases to shorten the bool evaluation
    std::string b = additionalScientist.dateOfBirth;
    std::string d = additionalScientist.dateOfDeath;
    //Birthyear must be a valid year, death year must be "----" OR (larger than birth year AND valid year)
    valid = ( util::validYear(b) ) && ( ( d == "----") || ( ( b < d ) && util::validYear(d) ) );
    if(valid) {
        Service.addScientist(additionalScientist);
    }
    else {
        std::cout << "Invalid input of year. \nYears must be in range 1000-2015 and death must not happen before birth." << std::endl;
        waitForPrompt();
    }
}

void ConsoleUI::addComputer() {
    Computer additionalComputer = Computer();
    std::cout << "Name: ";
    std::getline(std::cin, additionalComputer.name);
    std::cout << "Was the Computer built (yes/no)? ";
    std::cin >> additionalComputer.built;
    //Build date is not needed for computers not built
    if(additionalComputer.built == "yes") {
        std::cout << "Build date: ";
        std::cin >> additionalComputer.dateOfBuild;
    }
    else {
        additionalComputer.dateOfBuild = "----";
    }
    std::cout << "Type: ";
    std::cin >> additionalComputer.type;
    std::cin.ignore();
    //Years must be in the range 1000-2015 except if the computer was not built then dateOfBuild is "----"
    if(util::validYear(additionalComputer.dateOfBuild) || (additionalComputer.dateOfBuild == "----")) {
        Service.addComputer(additionalComputer);
    }
    else {
        std::cout << "Year must be in the range 1000 - 2015 or 0." << std::endl;
        waitForPrompt();
    }
}

void ConsoleUI::addLink() {
    Link additionalLink = Link();
    std::list<Computer> c = Service.getComputersOrderedBy("ID", "ASC");
    printComputers(c);
    std::cout << "Please choose a computer ID: ";
    std::cin >> additionalLink.c_ID;
    std::list<Scientist> s = Service.getScientistsOrderedBy("ID","ASC");
    printScientists(s);
    std::cout << "Please choose a scientist ID: ";
    std::cin >> additionalLink.s_ID;
    Service.addLink(additionalLink);
}

void ConsoleUI::listScientist() {
    char filter;
    std::string order;
    bool cont;
    std::list<Scientist> l;
    do {
        cont = false;
        std::cout << FILTER_MENU_SCIENTIST << std::endl;
        std::cin >> filter;
        std::cin.ignore(1000, '\n');
        std::cout << ASC_DESC_MENU;
        std::cin >> order;
        std::cin.ignore();
        order = (order == "1") ? order = "ASC" : order = "DESC";
        switch(filter) {
            case '1': {l = Service.getScientistsOrderedBy("ID",order); break;}
            case '2': {l = Service.getScientistsOrderedBy("Name",order); break;}
            case '3': {l = Service.getScientistsOrderedBy("Gender",order); break;}
            case '4': {l = Service.getScientistsOrderedBy("Dob",order); break;}
            case '5': {l = Service.getScientistsOrderedBy("Dod",order); break;}
            default : {std::cout << "Invalid input, please try another command\n"; cont = true;}
        }
    } while(cont);
    if(l.size() > 0) {
        printScientists(l);
    }
    else {
        noResults();
    }
    waitForPrompt();
}

void ConsoleUI::listComputer() {
    char filter;
    std::string order;
    bool cont;
    std::list<Computer> l;
    do {
        cont = false;
        std::cout << FILTER_MENU_COMPUTERS << std::endl;
        std::cin >> filter;
        std::cin.ignore(1000, '\n');
        std::cout << ASC_DESC_MENU;
        std::cin >> order;
        std::cin.ignore();
        order = (order == "1") ? order = "ASC" : order = "DESC";
        switch(filter) {
            case '1': {l = Service.getComputersOrderedBy("ID",order); break;}
            case '2': {l = Service.getComputersOrderedBy("Computer",order); break;}
            case '3': {l = Service.getComputersOrderedBy("BuiltYear",order); break;}
            case '4': {l = Service.getComputersOrderedBy("Type",order); break;}
            case '5': {l = Service.getComputersOrderedBy("WasBuilt",order); break;}
            default : {std::cout << "Invalid input, please try another command\n"; cont = true;}
        }
    } while(cont);
    if(l.size() > 0) {
        printComputers(l);
    }
    else {
        noResults();
    }
    waitForPrompt();
}

void ConsoleUI::searchScientist() {
    std::string searchTerm = "";
    std::cout << "Enter the search term: ";
    std::getline(std::cin,searchTerm);
    std::list<Scientist> searchResult = Service.scientistSearch(searchTerm);
    if(searchResult.size() > 0) {
        std::cout << "\nScientist(s) with name containing: " << searchTerm << std::endl;
        printScientists(searchResult);
    }
    else {
        noResults();
    }
    waitForPrompt();
}

void ConsoleUI::searchComputer() {
    std::string searchTerm = "";
    std::cout << "Enter the search term: ";
    std::getline(std::cin,searchTerm);
    std::list<Computer> searchResult = Service.computerSearch(searchTerm);
    if(searchResult.size() > 0) {
        std::cout << "\nComputer(s) with name containing: " << searchTerm << std::endl;
        printComputers(searchResult);
    }
    else {
        noResults();
    }
    waitForPrompt();
}

void ConsoleUI::searchLink() {
    char sortOption;
    bool cont;
    do {
        cont = false;
        std::cout << FILTER_MENU_LINKS << std::endl;
        std::cin >> sortOption;
        std::cin.ignore(1000, '\n');
        switch(sortOption) {
            case '1': {searchScientistLinks(); break;}
            case '2': {searchComputerLinks(); break;}
            default : {
                std::cout << "Invalid input, please try another command\n";
                cont = true;
            }
        }
        waitForPrompt();
    } while(cont);
}

void ConsoleUI::searchScientistLinks() {
    std::string ID;
    std::list<Scientist> s = Service.getScientistsOrderedBy("ID","ASC");
    printScientists(s);
    std::cout << "Please choose a scientist ID: ";
    std::cin >> ID;
    std::cin.ignore();
    std::list<Computer> c = Service.computerLink(ID);
    if(c.size() > 0) {
        std::cout << "\nComputer(s) connected to scientist ID " << ID << ":\n";
        printComputers(c);
    }
    else {
        noResults();
    }
}

void ConsoleUI::searchComputerLinks() {
    std::string ID;
    std::list<Computer> c = Service.getComputersOrderedBy("ID", "ASC");
    printComputers(c);
    std::cout << "Please choose a computer ID: ";
    std::cin >> ID;
    std::cin.ignore();
    std::list<Scientist> s = Service.scientistLink(ID);
    if(s.size() > 0) {
        std::cout << "\nScientist(s) connected to computer ID " << ID << ":\n";
        printScientists(s);
    }
    else {
        noResults();
    }
}

void ConsoleUI::printScientists(std::list<Scientist> printOut) {
    std::cout << std::endl;
    printFormatted("ID", "Name", "Birth", "Death", "Gender");
    printLine();
    for(std::list<Scientist>::iterator iter = printOut.begin(); iter != printOut.end(); iter ++) {
        printFormatted(iter->id, iter->name, iter->dateOfBirth, iter->dateOfDeath, iter->gender);
    }
}

void ConsoleUI::printComputers(std::list<Computer> printOut) {
    std::cout << std::endl;
    printFormatted("ID", "Name", "Date", "Type", "Built?");
    printLine();
    for(std::list<Computer>::iterator iter = printOut.begin(); iter != printOut.end(); iter ++) {
        printFormatted(iter->id, iter->name, iter->dateOfBuild, iter->type, iter->built);
    }
}
