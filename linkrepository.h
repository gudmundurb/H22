#ifndef LINKREPOSITORY_H
#define LINKREPOSITORY_H

#include "link.h"
#include <QtSql>
#include <stdexcept>
#include <string>
#include <list>
#include "scientist.h"
#include "computer.h"

// Handles all the things that pertain to persistence
// uses a file that is located in the build root directory
// for persistent storage
class LinkRepository {
public:
    LinkRepository();
    ~LinkRepository();
    void add(Link);
     //Gets a new connection to the database file
    QSqlDatabase getDatabaseConnection();
    //Returns a list of scientists connected to a certain computer ID
    std::list<Scientist> getScientists(std::string computer_id);
    //Returns a list of computers connected to a certain scientist ID
    std::list<Computer> getComputers(std::string scientist_id);
private:
    //The database connection that is used to retrieve data and persist data
    QSqlDatabase linkDB;
    // The filename of the database that is used to persist data
    QString filename;
    // Executes a query and loads all the results into a list which is returned
    std::list<Link> getList(QString sQuery);
};

#endif // LINKREPOSITORY_H
