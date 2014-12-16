#ifndef SCIENTISTREPOSITORY_H
#define SCIENTISTREPOSITORY_H

#include <list>
#include "Scientist.h"
#include <stdexcept>
#include <string>
#include <QtSql>

// Handles all the things that pertain to persistence
// uses a file that is located in the build root directory
// for persistent storage
class ScientistRepository {
public:
    ScientistRepository();
    ~ScientistRepository();
    //Adds a scientist to the database
    void add(Scientist);
    void remove(std::string id);
    void editScientist(Scientist oldScientist, Scientist newScientist);
    //Gets a new connection to the database file
    QSqlDatabase getDatabaseConnection();
    // Returns all scientists that match the search term
    std::vector<Scientist> search(std::string searchTerm);
    // Returns a list ordered by column and modifier
    std::vector<Scientist> list(std::string col,std::string mod);
private:
    //The database connection that is used to retrieve data and persist data
    QSqlDatabase scientistDB;
    // The filename of the file that is used to persist data
    QString filename;
    // Executes a query and loads all the results into a list which is returned
    std::vector<Scientist> getList(QString sQuery);
};

#endif // SCIENTISTREPOSITORY_H
