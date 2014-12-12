#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addcomputerdialog.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentComputers = service.getComputersOrderedBy("ID", "ASC");
    //currentLinks = service.getLinksOrderedBy("ID", "ASC");

    setTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setTable () {
    QString selectedTable = ui->display_table_combo->currentText();
    if(selectedTable == "Scientists") {
        hideAllTables();
        hideAllSortCombos();
        ui->scientist_table->show();
        ui->sort_combo_scientist->show();
        setTableScientist();
    }
    else if(selectedTable == "Computers") {
        hideAllTables();
        hideAllSortCombos();
        ui->computer_table->show();
        ui->sort_combo_computer->show();
        setTableComputer();
    }
}
void MainWindow::hideAllTables() {
    ui->scientist_table->hide();
    ui->computer_table->hide();
}
void MainWindow::hideAllSortCombos() {
    ui->sort_combo_computer->hide();
    ui->sort_combo_scientist->hide();
}

void MainWindow::setTableScientist() {

    currentlyDisplayedScientists.clear();
    ui->scientist_table->clearContents();
    std::string orderSelection = ui->sort_combo_order->currentText().toStdString();
    int sortIndex = ui->sort_combo_scientist->currentIndex() + 1;
    std::string sortingIndex = QString::number(sortIndex).toStdString();
    std::string searchSelection = ui->search_text->text().toStdString();

    currentScientists = service.getScientistsOrderedBy(sortingIndex, orderSelection);
    ui->scientist_table->setRowCount(currentScientists.size());
    for(unsigned int i = 0; i < currentScientists.size(); i++) {
        Scientist currentScientist = currentScientists[i];
        if(currentScientist.contains(searchSelection)) {

            QString scientistId = QString::fromStdString(currentScientist.id);
            QString scientistName = QString::fromStdString(currentScientist.name);
            QString scientistDob = QString::fromStdString(currentScientist.dateOfBirth);
            QString scientistDod = QString::fromStdString(currentScientist.dateOfDeath);
            QString scientistGender = QString::fromStdString(currentScientist.gender);
            int currentIndex = currentlyDisplayedScientists.size();
            ui->scientist_table->setItem(currentIndex,0, new QTableWidgetItem(scientistId));
            ui->scientist_table->setItem(currentIndex,1, new QTableWidgetItem(scientistName));
            ui->scientist_table->setItem(currentIndex,2, new QTableWidgetItem(scientistDob));
            ui->scientist_table->setItem(currentIndex,3, new QTableWidgetItem(scientistDod));
            ui->scientist_table->setItem(currentIndex,4, new QTableWidgetItem(scientistGender));

            currentlyDisplayedScientists.push_back(currentScientist);
        }
    }

}

void MainWindow::setTableComputer() {
    currentlyDisplayedComputers.clear();
    ui->computer_table->clearContents();
    std::string orderSelection = ui->sort_combo_order->currentText().toStdString();
    int sortIndex = ui->sort_combo_computer->currentIndex() + 1;
    std::string sortingIndex = QString::number(sortIndex).toStdString();
    std::string searchSelection = ui->search_text->text().toStdString();
    currentComputers = service.getComputersOrderedBy(sortingIndex, orderSelection);

    for(unsigned int i = 0; i < currentComputers.size(); i++) {
        Computer currentComputer = currentComputers[i];
        if(currentComputer.contains(searchSelection)) {
            ui->computer_table->setRowCount(currentlyDisplayedComputers.size() + 1);
            QString computerId = QString::fromStdString(currentComputer.id);
            QString computerName = QString::fromStdString(currentComputer.name);
            QString computerDob = QString::fromStdString(currentComputer.dateOfBuild);
            QString computerDod = QString::fromStdString(currentComputer.type);
            QString computerGender = QString::fromStdString(currentComputer.built);
            int currentIndex = currentlyDisplayedComputers.size();
            ui->computer_table->setItem(currentIndex,0, new QTableWidgetItem(computerId));
            ui->computer_table->setItem(currentIndex,1, new QTableWidgetItem(computerName));
            ui->computer_table->setItem(currentIndex,2, new QTableWidgetItem(computerDob));
            ui->computer_table->setItem(currentIndex,3, new QTableWidgetItem(computerDod));
            ui->computer_table->setItem(currentIndex,4, new QTableWidgetItem(computerGender));

            currentlyDisplayedComputers.push_back(currentComputer);


        }
    }

}

void MainWindow::on_sort_combo_scientist_currentTextChanged(const QString &arg1)
{
    setTable();
}

void MainWindow::on_sort_combo_order_currentTextChanged(const QString &arg1)
{
    setTable();
}

void MainWindow::on_search_text_textChanged(const QString &arg1)
{
#if 0
    if(ui->search_text->text() != "") {
        ui->sort_combo_order->setCurrentIndex(0);
        ui->sort_combo_scientist->setCurrentIndex(0);
        ui->sort_combo_computer->setCurrentIndex(0);
        ui->sort_combo_computer->setEnabled(false);
        ui->sort_combo_scientist->setEnabled(false);
        ui->sort_combo_order->setEnabled(false);
    }
    else {
        ui->sort_combo_computer->setEnabled(true);
        ui->sort_combo_scientist->setEnabled(true);
        ui->sort_combo_order->setEnabled(true);
    }
#endif
    setTable();

}

void MainWindow::on_add_button_clicked()
{
    addComputerDialog add;
    add.exec();
    service.addComputer(add.getComputer());
    setTable();
}

void MainWindow::on_display_table_combo_currentTextChanged(const QString &arg1)
{
    setTable();
}

void MainWindow::on_sort_combo_computer_currentIndexChanged(int index)
{
    setTable();
}
