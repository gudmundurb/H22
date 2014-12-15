#include "scientistrepository.h"

ScientistRepository::ScientistRepository() {
    filename = "scicomp.sqlite";
    scientistDB = QSqlDatabase::addDatabase("QSQLITE", "ScientistConnection");
    scientistDB.setDatabaseName(filename);
    scientistDB.open();
}

ScientistRepository::~ScientistRepository() {
    if(scientistDB.isOpen()) {
        scientistDB.close();
    }
    scientistDB = QSqlDatabase(); //Closes the scientistDB connection in ScientistConnection.
    scientistDB.removeDatabase("ScientistConnection"); //Closes the connection itself.
}

void ScientistRepository::add(Scientist scientist) {
    scientistDB = getDatabaseConnection();
    QSqlQuery query(scientistDB);
    query.prepare("INSERT INTO Scientists (Name, Dob, Dod, Gender)VALUES(:name, :dob, :dod, :gender)");
    query.bindValue(":name",   QString::fromStdString(scientist.name));
    query.bindValue(":dob",    QString::fromStdString(scientist.dateOfBirth));
    query.bindValue(":dod",    QString::fromStdString(scientist.dateOfDeath));
    query.bindValue(":gender", QString::fromStdString(scientist.gender));
    query.exec();
    scientistDB.close();
}

void ScientistRepository::remove(std::string id)
{
    //scientistDB = getDatabaseConnection();
    QString q = "DELETE FROM Scientists WHERE ID = " + QString::fromStdString(id);
    QSqlQuery query(scientistDB);
    query.exec(q);
}

std::vector<Scientist> ScientistRepository::list(std::string col, std::string mod) {
    std::vector<Scientist> outList = std::vector<Scientist>();
    QString query = "SELECT * FROM Scientists ORDER BY " + QString::fromStdString(col)
            + " " + QString::fromStdString(mod);
    outList = getList(query);
    return outList;
}

std::vector<Scientist> ScientistRepository::getList(QString sQuery) {
    std::vector<Scientist> newList = std::vector<Scientist>();
    scientistDB = getDatabaseConnection();
    if(scientistDB.isOpen()) {
        QSqlQuery query(scientistDB);
        query.exec(sQuery);
        while(query.next()) {
            Scientist c = Scientist();
            c.id =          query.value("ID").toString().toStdString();
            c.name =        query.value("Name").toString().toStdString();
            c.dateOfBirth = query.value("Dob").toString().toStdString();
            c.dateOfDeath = query.value("Dod").toString().toStdString();
            c.gender =      query.value("Gender").toString().toStdString();
            newList.push_back(c);
        }
        scientistDB.close();
    }
    else {
        throw std::runtime_error("Failed to open " + filename.toStdString() + " when trying to retrieve list from scientistDB");
    }
    return newList;
}

std::vector<Scientist> ScientistRepository::search(std::string searchTerm) {
    QString search = QString::fromStdString(searchTerm);
    QString query = "SELECT * FROM Scientists WHERE Name LIKE '%" + search + "%'";
    std::vector<Scientist> newList = getList(query);
    return newList;
}

QSqlDatabase ScientistRepository::getDatabaseConnection() {
    QString connectionName = "ScientistConnection";
    QSqlDatabase db;
    if(QSqlDatabase::contains(connectionName)) {
        db = QSqlDatabase::database(connectionName);
        db.open();
    }
    else {
        db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
        db.setDatabaseName(filename);
        db.open();
    }
    return db;
}
