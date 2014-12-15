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
    void removeScientist(std::string s_id);
    void removeComputer(std::string c_id);
    void remove(std::string s_id, std::string c_id);
     //Gets a new connection to the database file
    QSqlDatabase getDatabaseConnection();
    //Returns a list of scientists connected to a certain computer ID
    std::vector<Scientist> getScientists(std::string computer_id);
    //Returns a list of computers connected to a certain scientist ID
    std::vector<Computer> getComputers(std::string scientist_id);
private:
    //The database connection that is used to retrieve data and persist data
    QSqlDatabase linkDB;
    // The filename of the database that is used to persist data
    QString filename;
    // Executes a query and loads all the results into a list which is returned
    std::vector<Link> getList(QString sQuery);
};

#endif // LINKREPOSITORY_H
