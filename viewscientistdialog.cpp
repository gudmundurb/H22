#include "viewscientistdialog.h"
#include "ui_viewscientistdialog.h"
#include <QDebug>
ViewScientistDialog::ViewScientistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewScientistDialog)
{
    ui->setupUi(this);
}

ViewScientistDialog::~ViewScientistDialog() {
    delete ui;
}

void ViewScientistDialog::setConnectedComputers(const std::vector<Computer> &input) {
    connectedComputers = input;
}

void ViewScientistDialog::setScientist(const Scientist &input) {
    scientist = input;
}

void ViewScientistDialog::setup() {
    setTable();
    displayScientist();
    ui->computer_table->setColumnWidth(0, 35);
    ui->computer_table->setColumnWidth(1, 200);
    ui->computer_table->setColumnWidth(3, 150);
}

void ViewScientistDialog::setTable() {
    ui->computer_table->setRowCount(connectedComputers.size());
    for(unsigned int i = 0; i < connectedComputers.size(); i++) {
        Computer currentComputer = connectedComputers.at(i);
        QString computerId =       QString::fromStdString(currentComputer.id);
        QString computerName =     QString::fromStdString(currentComputer.name);
        QString computerDob =      QString::fromStdString(currentComputer.dateOfBuild);
        QString computerType =     QString::fromStdString(currentComputer.type);
        QString computerBuilt =    QString::fromStdString(currentComputer.built);
        ui->computer_table->setItem(i,0, new QTableWidgetItem(computerId));
        ui->computer_table->setItem(i,1, new QTableWidgetItem(computerName));
        ui->computer_table->setItem(i,2, new QTableWidgetItem(computerDob));
        ui->computer_table->setItem(i,3, new QTableWidgetItem(computerType));
        ui->computer_table->setItem(i,4, new QTableWidgetItem(computerBuilt));
    }
}

void ViewScientistDialog::displayScientist() {
    ui->scientist_name->setText(QString::fromStdString(scientist.name));
    ui->born_year->setText(QString::fromStdString(scientist.dateOfBirth));
    ui->dead_year->setText(QString::fromStdString(scientist.dateOfDeath));
    if(scientist.gender == "M") {
        ui->gender->setText("Male");
    }
    else {
        ui->gender->setText("Female");
    }

    QString age = QString::number(QString::fromStdString(scientist.dateOfDeath).toInt() - QString::fromStdString(scientist.dateOfBirth).toInt());
    ui->aged->setText("Age: " + age);
}
