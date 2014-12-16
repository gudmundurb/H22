#include "viewcomputerdialog.h"
#include "ui_viewcomputerdialog.h"

ViewComputerDialog::ViewComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewComputerDialog)
{
    ui->setupUi(this);
}

ViewComputerDialog::~ViewComputerDialog() {
    delete ui;
}

void ViewComputerDialog::setConnectedScientists(std::vector<Scientist> input) {
    connectedScientists = input;
}

void ViewComputerDialog::setComputer(Computer input) {
    computer = input;
}

void ViewComputerDialog::setup() {
    setTable();
    displayComputer();
    ui->scientist_table->setColumnWidth(0,35);
    ui->scientist_table->setColumnWidth(1,200);
}

bool ViewComputerDialog::wantRemove() {
    return wantsToRemoveLinks;
}

std::vector<std::string> ViewComputerDialog::getRemoveIds() {
    return idsToRemove;
}

void ViewComputerDialog::setTable() {
    ui->scientist_table->setRowCount(connectedScientists.size());
    for(unsigned int i = 0; i < connectedScientists.size(); i++) {
        Scientist currentScientist = connectedScientists.at(i);
        QString scientistId = QString::fromStdString(currentScientist.id);
        QString scientistName = QString::fromStdString(currentScientist.name);
        QString scientistDob = QString::fromStdString(currentScientist.dateOfBirth);
        QString scientistDod = QString::fromStdString(currentScientist.dateOfDeath);
        QString scientistGen = QString::fromStdString(currentScientist.gender);
        ui->scientist_table->setItem(i,0, new QTableWidgetItem(scientistId));
        ui->scientist_table->setItem(i,1, new QTableWidgetItem(scientistName));
        ui->scientist_table->setItem(i,2, new QTableWidgetItem(scientistDob));
        ui->scientist_table->setItem(i,3, new QTableWidgetItem(scientistDod));
        ui->scientist_table->setItem(i,4, new QTableWidgetItem(scientistGen));
    }
}

void ViewComputerDialog::displayComputer() {
    ui->computer_name->setText(QString::fromStdString(computer.name));
    ui->built_year->setText(QString::fromStdString(computer.dateOfBuild));
    ui->was_built->setText(QString::fromStdString(computer.built));
    ui->type->setText(QString::fromStdString(computer.type));
    int thisYear = QDate::currentDate().year();
    if(computer.built == "yes") {
        QString age = QString::number(thisYear - QString::fromStdString(computer.dateOfBuild).toInt());
        ui->aged->setText("Age: " + age);
    }
    else {
        ui->aged->setText("");
    }
}

void ViewComputerDialog::on_scientist_table_customContextMenuRequested(const QPoint &pos) {
    QMenu menu;
    menu.addAction(ui->actionUnlink_scientist);
    menu.exec(QCursor::pos());
}

void ViewComputerDialog::on_actionUnlink_scientist_triggered() {
    int currentRow = ui->scientist_table->currentRow();
    std::string scientistId = ui->scientist_table->item(currentRow, 0)->text().toStdString();
    ui->scientist_table->setRowHidden(currentRow, true);
    idsToRemove.push_back(scientistId);
    wantsToRemoveLinks = true;
}
