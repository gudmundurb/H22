#ifndef COMPUTERREPOSITORY_H
#define COMPUTERREPOSITORY_H

#include <list>
#include "Computer.h"
#include <stdexcept>
#include <string>
#include <QtSql>

// Handles all the things that pertain to persistence
// uses a file that is located in the build root directory
// for persistent storage
class ComputerRepository {
public:
    ComputerRepository();
    ~ComputerRepository();
    void add(Computer);
    void remove(std::string id);
    //Gets a new connection to the database file
    QSqlDatabase getDatabaseConnection();
    // Returns all computers that match the search term
    std::vector<Computer> search(std::string searchTerm);
    // Returns a list ordered by column and modifier
    std::vector<Computer> list(std::string col,std::string mod);

    void editComputer(Computer oldComputer, Computer newComputer);
private:
    //The database connection that is used to retrieve data and persist data
    QSqlDatabase computerDB;
    // The filename of the database that is used to persist data
    QString filename;
    // Executes a query and loads all the results into a list which is returned
    std::vector<Computer> getList(QString sQuery);
};

#endif // COMPUTERREPOSITORY_H
