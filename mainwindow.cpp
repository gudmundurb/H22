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
        ui->scientist_table->show();
        setTableScientist();
    }
    else if(selectedTable == "Computers") {
        setTableComputer();
    }
}
void MainWindow::hideAllTables() {
    ui->scientist_table->hide();
    ui->computer_table->hide();
}

void MainWindow::setTableScientist() {
    ui->sort_combo->clear();
    currentlyDisplayedScientists.clear();
    ui->scientist_table->clearContents();
    std::string orderSelection = ui->sort_combo_order->currentText().toStdString();
    int sortIndex = ui->sort_combo->currentIndex() + 1;
    std::string sortingIndex = QString::number(sortIndex).toStdString();
    std::string searchSelection = ui->search_text->text().toStdString();

    currentScientists = service.getScientistsOrderedBy(sortingIndex, orderSelection);
    ui->scientist_table->setRowCount(currentScientists.size());
    ui->countof->setText(QString::number(ui->scientist_table->rowCount()));
    for(unsigned int i = 0; i < currentScientists.size(); i++) {
        Scientist currentScientist = currentScientists[i];
        if(currentScientist.contains(searchSelection)) {

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

            currentlyDisplayedScientists.push_back(currentScientist);
        }
    }

}

void MainWindow::setTableComputer() {
    currentlyDisplayedComputers.clear();
    ui->computer_table->clearContents();
    std::string orderSelection = ui->sort_combo_order->currentText().toStdString();
    int sortIndex = ui->sort_combo->currentIndex() + 1;
    std::string sortingIndex = QString::number(sortIndex).toStdString();
    std::string searchSelection = ui->search_text->text().toStdString();

    currentComputers = service.getComputersOrderedBy(sortingIndex, orderSelection);
    ui->computer_table->setRowCount(currentComputers.size());

    for(unsigned int i = 0; i < currentComputers.size(); i++) {
        Computer currentComputer = currentComputers[i];
        if(currentComputer.contains(searchSelection)) {

            ui->countof->setText(QString::number(currentlyDisplayedComputers.size()));
            QString computerId = QString::fromStdString(currentComputer.id);
            QString computerName = QString::fromStdString(currentComputer.name);
            QString computerDob = QString::fromStdString(currentComputer.dateOfBuild);
            QString computerDod = QString::fromStdString(currentComputer.type);
            QString computerGender = QString::fromStdString(currentComputer.built);

            ui->computer_table->setItem(i,0, new QTableWidgetItem(computerId));
            ui->computer_table->setItem(i,1, new QTableWidgetItem(computerName));
            ui->computer_table->setItem(i,2, new QTableWidgetItem(computerDob));
            ui->computer_table->setItem(i,3, new QTableWidgetItem(computerDod));
            ui->computer_table->setItem(i,4, new QTableWidgetItem(computerGender));

            currentlyDisplayedComputers.push_back(currentComputer);
        }
    }

}

void MainWindow::on_sort_combo_currentTextChanged(const QString &arg1)
{
    setTable();
}

void MainWindow::on_sort_combo_order_currentTextChanged(const QString &arg1)
{
    setTable();
}

void MainWindow::on_search_text_textChanged(const QString &arg1)
{
    ui->sort_combo_order->setCurrentIndex(0);
    ui->sort_combo->setCurrentIndex(0);
    setTable();
}

void MainWindow::on_add_button_clicked()
{
    addComputerDialog add;
    add.exec();
    service.addComputer(add.getComputer());
}
