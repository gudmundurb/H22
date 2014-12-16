#include "viewscientistdialog.h"
#include "ui_viewscientistdialog.h"
#include <QDebug>
#include <QDate>
#include <QMenu>

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

bool ViewScientistDialog::wantRemove() {
    return wantsToRemoveLinks;
}

std::vector<std::string> ViewScientistDialog::getRemoveIds() {
    return idsToRemove;
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
    int thisYear = QDate::currentDate().year();
    if(scientist.dateOfDeath != "----") {
        QString age = QString::number(QString::fromStdString(scientist.dateOfDeath).toInt() - QString::fromStdString(scientist.dateOfBirth).toInt());
        ui->aged->setText("Age: " + age);
    }
    else {
        QString age = QString::number(thisYear - QString::fromStdString(scientist.dateOfBirth).toInt());
        ui->aged->setText("Age: " + age);
    }
}

void ViewScientistDialog::on_actionUnlink_computer_triggered() {
    int currentRow = ui->computer_table->currentRow();
    std::string computerId = ui->computer_table->item(currentRow, 0)->text().toStdString();
    ui->computer_table->setRowHidden(currentRow, true);
    idsToRemove.push_back(computerId);
    wantsToRemoveLinks = true;
}

void ViewScientistDialog::on_computer_table_customContextMenuRequested(const QPoint &pos) {
    QMenu menu;
    menu.addAction(ui->actionUnlink_computer);
    menu.exec(QCursor::pos());
}
