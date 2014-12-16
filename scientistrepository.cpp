#include "scientistrepository.h"

ScientistRepository::ScientistRepository() {
    filename = "scicomp.sqlite";
    scientistDB = QSqlDatabase::addDatabase("QSQLITE", "ScientistConnection");
    scientistDB.setDatabaseName(filename);
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
    query.prepare("INSERT INTO Scientists (Name, Dob, Dod, Gender, ScientistImagePath)VALUES(:name, :dob, :dod, :gender, :scientistImagePath)");
    query.bindValue(":name",   QString::fromStdString(scientist.name));
    query.bindValue(":dob",    QString::fromStdString(scientist.dateOfBirth));
    query.bindValue(":dod",    QString::fromStdString(scientist.dateOfDeath));
    query.bindValue(":gender", QString::fromStdString(scientist.gender));
    query.bindValue(":scientistImagePath",   QString::fromStdString(scientist.s_imagefilepath));
    query.exec();
    scientistDB.close();
}

void ScientistRepository::remove(std::string id) {
    scientistDB = getDatabaseConnection();
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
            Scientist s = Scientist();
            s.id =              query.value("ID").toString().toStdString();
            s.name =            query.value("Name").toString().toStdString();
            s.dateOfBirth =     query.value("Dob").toString().toStdString();
            s.dateOfDeath =     query.value("Dod").toString().toStdString();
            s.gender =          query.value("Gender").toString().toStdString();
            s.s_imagefilepath = query.value("ScientistImagePath").toString().toStdString();
            newList.push_back(s);
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

void ScientistRepository::editScientist(Scientist oldScientist, Scientist newScientist) {
    scientistDB = getDatabaseConnection();
    QSqlQuery query(scientistDB);
    QString q =    "UPDATE Scientists ";
    q +=           "SET Name='" +  QString::fromStdString(newScientist.name) + "', ";
    q +=           "Dob='" +       QString::fromStdString(newScientist.dateOfBirth) + "', ";
    q +=           "Dod='" +       QString::fromStdString(newScientist.dateOfDeath) + "', ";
    q +=           "Gender='" +    QString::fromStdString(newScientist.gender) + "', ";
    q +=           "ScientistImagePath='" + QString::fromStdString(newScientist.s_imagefilepath) + "' ";
    q +=           "WHERE ID=" +   QString::fromStdString(oldScientist.id);
    query.exec(q);
}
