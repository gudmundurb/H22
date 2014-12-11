#include "computerrepository.h"

ComputerRepository::ComputerRepository() {
    filename = "scicomp.sqlite";
    computerDB = QSqlDatabase::addDatabase("QSQLITE", "ComputerConnection");
    computerDB.setDatabaseName(filename);
}

ComputerRepository::~ComputerRepository() {
    if(computerDB.isOpen()) {
        computerDB.close();  //Closes the connection in ComputerConnection.
    }
    computerDB = QSqlDatabase();
    computerDB.removeDatabase("ComputerConnection"); //Closes the connection itself.
}

void ComputerRepository::add(Computer computer) {
    computerDB = getDatabaseConnection();
    QSqlQuery query(computerDB);
    query.prepare("INSERT INTO Computers (Computer, BuiltYear, Type, WasBuilt)VALUES(:name, :dateOfBuild, :type, :built)");
    query.bindValue(":name",        QString::fromStdString(computer.name));
    query.bindValue(":dateOfBuild", QString::fromStdString(computer.dateOfBuild));
    query.bindValue(":type",        QString::fromStdString(computer.type));
    query.bindValue(":built",       QString::fromStdString(computer.built));
    query.exec();
    computerDB.close();
}

std::list<Computer> ComputerRepository::list(std::string col, std::string mod) {
    std::list<Computer> outList = std::list<Computer>();
    QString query = "SELECT * FROM Computers ORDER BY " + QString::fromStdString(col)
            + " " + QString::fromStdString(mod);
    outList = getList(query);
    return outList;
}

std::list<Computer> ComputerRepository::getList(QString sQuery) {
    std::list<Computer> newList = std::list<Computer>();
    computerDB = getDatabaseConnection();
    if(computerDB.isOpen()) {
        QSqlQuery query(computerDB);
        query.exec(sQuery);
        while(query.next()) {
            Computer c = Computer();
            c.id =          query.value("ID").toString().toStdString();
            c.name =        query.value("Computer").toString().toStdString();
            c.dateOfBuild = query.value("BuiltYear").toString().toStdString();
            c.type =        query.value("Type").toString().toStdString();
            c.built =       query.value("WasBuilt").toString().toStdString();
            newList.push_back(c);
        }
        computerDB.close();
    }
    else {
        throw std::runtime_error("Failed to open " + filename.toStdString() + " when trying to retrieve list from computerDB");
    }
    return newList;
}

std::list<Computer> ComputerRepository::search(std::string searchTerm) {
    QString search = QString::fromStdString(searchTerm);
    QString query = "SELECT * FROM Computers WHERE Computer LIKE '%" + search + "%'";
    std::list<Computer> newList = getList(query);
    return newList;
}

QSqlDatabase ComputerRepository::getDatabaseConnection() {
    QString connectionName = "ComputerConnection";
    QSqlDatabase db;
    if(QSqlDatabase::contains(connectionName)) {
        db = QSqlDatabase::database(connectionName);
    }
    else {
        db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
        db.setDatabaseName(filename);
        db.open();
    }
    return db;
}
