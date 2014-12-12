#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentComputers = service.getComputersOrderedBy("ID", "ASC");
    //currentLinks = service.getLinksOrderedBy("ID", "ASC");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTableScientist() {
    QString sortSelection = ui->sort_combo_scientist->currentText();
    currentScientists = service.getScientistsOrderedBy("ID", "ASC");
    ui->scientist_table->setRowCount(currentScientists.size());
    for(unsigned int i = 0; i < currentScientists.size(); i++) {
        Scientist currentScientist = currentScientists[i];
        QString scientistId = QString::fromStdString(currentScientist.id);
        QString scientistName = QString::fromStdString(currentScientist.name);
        QString scientistDob = QString::fromStdString(currentScientist.dateOfBirth);
        QString scientistDod = QString::fromStdString(currentScientist.dateOfDeath);
        QString scientistGender = QString::fromStdString(currentScientist.gender);

        ui->scientist_table->setItem(i,0, new QTableWidgetItem(scientistId));
        ui->scientist_table->setItem(i,1, new QTableWidgetItem(scientistName));
        ui->scientist_table->setItem(i,2, new QTableWidgetItem(scientistDob));
        ui->scientist_table->setItem(i,3, new QTableWidgetItem(scientistDod));
        ui->scientist_table->setItem(i,4, new QTableWidgetItem(scientistGender));
    }
    ui->countof->setText(QString::number(currentScientists.size()));
}
