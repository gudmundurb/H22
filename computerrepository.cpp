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
    query.prepare("INSERT INTO Computers (Computer, BuiltYear, Type, WasBuilt, ComputerImagePath )VALUES(:name, :dateOfBuild, :type, :built, :computerimagepath)");
    query.bindValue(":name",        QString::fromStdString(computer.name));
    query.bindValue(":dateOfBuild", QString::fromStdString(computer.dateOfBuild));
    query.bindValue(":type",        QString::fromStdString(computer.type));
    query.bindValue(":built",       QString::fromStdString(computer.built));
    query.bindValue(":ComputerImagePath",   QString::fromStdString(computer.c_imagefilepath));
    query.exec();
    computerDB.close();
}

void ComputerRepository::remove(std::string id) {
    computerDB = getDatabaseConnection();
    QString q = "DELETE FROM Computers WHERE ID = " + QString::fromStdString(id);
    QSqlQuery query(computerDB);
    query.exec(q);
}

std::vector<Computer> ComputerRepository::list(std::string col, std::string mod) {
    std::vector<Computer> outList = std::vector<Computer>();
    QString query = "SELECT * FROM Computers ORDER BY " + QString::fromStdString(col)
            + " " + QString::fromStdString(mod);
    outList = getList(query);
    return outList;
}

std::vector<Computer> ComputerRepository::getList(QString sQuery) {
    std::vector<Computer> newList = std::vector<Computer>();
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
            c.c_imagefilepath = query.value("ComputerImagePath").toString().toStdString();
            newList.push_back(c);
        }
        computerDB.close();
    }
    else {
        throw std::runtime_error("Failed to open " + filename.toStdString() + " when trying to retrieve list from computerDB");
    }
    return newList;
}

std::vector<Computer> ComputerRepository::search(std::string searchTerm) {
    QString search = QString::fromStdString(searchTerm);
    QString query = "SELECT * FROM Computers WHERE Computer LIKE '%" + search + "%'";
    std::vector<Computer> newList = getList(query);
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
