#include "linkrepository.h"

LinkRepository::LinkRepository() {
    filename = "scicomp.sqlite";
    linkDB = QSqlDatabase::addDatabase("QSQLITE", "LinksConnection");
    linkDB.setDatabaseName(filename);
}

LinkRepository::~LinkRepository() {
    if(linkDB.isOpen()) {
        linkDB.close(); //Closes the linkDB connection in LinksConnection.
    }
    linkDB = QSqlDatabase();
    linkDB.removeDatabase("LinksConnection"); //Closes the "LinksConnection" itself.
}

void LinkRepository::add(Link link) {
    linkDB = getDatabaseConnection();
    QSqlQuery query(linkDB);
    if(linkDB.isOpen()) {
        QString setKeys = "PRAGMA foreign_keys = on"; // Checks for foreign key consistency
        query.prepare(setKeys);
        query.exec(setKeys);
    }
    else {
        throw std::runtime_error("Failed to open " + filename.toStdString() + " when trying to run PRAGMA command in linkDB.");
    }
    query.prepare("INSERT INTO Links (C_ID, S_ID)VALUES(:C_ID, :S_ID)");
    query.bindValue(":C_ID", QString::fromStdString(link.c_ID));
    query.bindValue(":S_ID", QString::fromStdString(link.s_ID));
    query.exec();
    linkDB.close();
}

std::list<Link> LinkRepository::getList(QString sQuery) {
    std::list<Link> newList = std::list<Link>();
    linkDB = getDatabaseConnection();
    if(linkDB.isOpen()) {
        QSqlQuery query(linkDB);
        query.exec(sQuery);
        while(query.next()) {
            Link c = Link();
            c.c_ID = query.value("c_ID").toString().toStdString();
            c.s_ID = query.value("s_ID").toString().toStdString();
            newList.push_back(c);
        }
        linkDB.close();
    }
    else {
        throw std::runtime_error("Failed to open " + filename.toStdString() + " when trying to retrieve list from linkDB");
    }
    return newList;
}

QSqlDatabase LinkRepository::getDatabaseConnection() {
    QString connectionName = "LinksConnection";
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

std::list<Scientist> LinkRepository::getScientists(std::string computer_id) {
    std::list<Scientist> newList = std::list<Scientist>();
    QString q = "SELECT s.ID, s.Name, s.Dob, s.Dod, s.Gender FROM Scientists s ";
    q +=        "INNER JOIN Links l ";
    q +=        "ON l.s_id = s.id ";
    q +=        "INNER JOIN Computers c ";
    q +=        "ON l.c_id = c.id ";
    q +=        "WHERE c.id = :computerID ";
    q +=        "ORDER BY s.ID ASC";
    linkDB = getDatabaseConnection();
    QSqlQuery query(linkDB);
    query.prepare(q);
    query.bindValue(":computerID", QString::fromStdString(computer_id));
    query.exec();
    while(query.next()) {
        Scientist s = Scientist();
        s.id          = query.value("ID").toString().toStdString();
        s.name        = query.value("Name").toString().toStdString();
        s.dateOfBirth = query.value("Dob").toString().toStdString();
        s.dateOfDeath = query.value("Dod").toString().toStdString();
        s.gender      = query.value("Gender").toString().toStdString();
        newList.push_back(s);
    }
    linkDB.close();
    return newList;
}

std::list<Computer> LinkRepository::getComputers(std::string scientist_id) {
    std::list<Computer> newList = std::list<Computer>();
    QString q =   "SELECT c.ID, c.Computer, c.BuiltYear, c.Type, c.WasBuilt FROM Computers c ";
    q +=          "INNER JOIN Links l ";
    q +=          "ON l.c_id = c.id ";
    q +=          "INNER JOIN Scientists s ";
    q +=          "ON l.s_id = s.id ";
    q +=          "WHERE s.id = :scientistID ";
    q +=          "ORDER BY c.ID ASC";
    linkDB = getDatabaseConnection();
    QSqlQuery query(linkDB);
    query.prepare(q);
    query.bindValue(":scientistID", QString::fromStdString(scientist_id));
    query.exec();
    while(query.next()) {
        Computer c = Computer();
        c.id =          query.value("ID").toString().toStdString();
        c.name =        query.value("Computer").toString().toStdString();
        c.dateOfBuild = query.value("BuiltYear").toString().toStdString();
        c.type =        query.value("Type").toString().toStdString();
        c.built =       query.value("WasBuilt").toString().toStdString();
        newList.push_back(c);
    }
    linkDB.close();
    return newList;
}
