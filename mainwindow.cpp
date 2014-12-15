#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addcomputerdialog.h"
#include "addscientistdialog.h"
#include <QMenu>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setTable();
    setLinkTableComputer();
    setLinkTableScientist();
    ui->scientist_table->setColumnWidth(1,200);
    ui->computer_table->setColumnWidth(1,200);
    ui->scientist_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->scientist_table_link->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->computer_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->computer_table_link->setEditTriggers(QAbstractItemView::NoEditTriggers);
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
void MainWindow::setLinkTableScientist() {

    currentlyDisplayedScientists.clear();
    ui->scientist_table_link->clearContents();
    /*std::string orderSelection = ui->sort_combo_order->currentText().toStdString();
    int sortIndex = ui->sort_combo_scientist->currentIndex() + 1;
    std::string sortingIndex = QString::number(sortIndex).toStdString();
    std::string searchSelection = ui->search_text->text().toStdString();

    currentScientists = service.getScientistsOrderedBy(sortingIndex, orderSelection);*/
    currentScientists = service.getScientistsOrderedBy("1", "ASC");
    ui->scientist_table_link->setRowCount(currentScientists.size());
    for(unsigned int i = 0; i < currentScientists.size(); i++) {
        Scientist currentScientist = currentScientists[i];
        //if(currentScientist.contains(searchSelection)) {
            QString scientistId = QString::fromStdString(currentScientist.id);
            QString scientistName = QString::fromStdString(currentScientist.name);
            int currentIndex = currentlyDisplayedScientists.size();
            ui->scientist_table_link->setItem(currentIndex,0, new QTableWidgetItem(scientistId));
            ui->scientist_table_link->setItem(currentIndex,1, new QTableWidgetItem(scientistName));

            currentlyDisplayedScientists.push_back(currentScientist);
        //}
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

void MainWindow::setLinkTableComputer() {
    currentlyDisplayedComputers.clear();
    ui->computer_table_link->clearContents();
    /*std::string orderSelection = ui->sort_combo_order->currentText().toStdString();
    int sortIndex = ui->sort_combo_computer->currentIndex() + 1;
    std::string sortingIndex = QString::number(sortIndex).toStdString();
    std::string searchSelection = ui->search_text->text().toStdString();
    currentComputers = service.getComputersOrderedBy(sortingIndex, orderSelection);*/
    currentComputers = service.getComputersOrderedBy("1", "ASC");
    for(unsigned int i = 0; i < currentComputers.size(); i++) {
        Computer currentComputer = currentComputers[i];
        //if(currentComputer.contains(searchSelection)) {
            ui->computer_table_link->setRowCount(currentlyDisplayedComputers.size() + 1);
            QString computerId = QString::fromStdString(currentComputer.id);
            QString computerName = QString::fromStdString(currentComputer.name);
            int currentIndex = currentlyDisplayedComputers.size();
            ui->computer_table_link->setItem(currentIndex,0, new QTableWidgetItem(computerId));
            ui->computer_table_link->setItem(currentIndex,1, new QTableWidgetItem(computerName));
            currentlyDisplayedComputers.push_back(currentComputer);
        //}
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
    QString selectedTable = ui->display_table_combo->currentText();
    if(selectedTable == "Scientists") {
        AddScientistDialog addSci;
        addSci.exec();
        /*if(addSci.success) {
            service.addScientist(addSci.getScientist());
        }*/
    }
    else if(selectedTable == "Computers") {
        addComputerDialog addComp;
        addComp.exec();
        if(addComp.success()) {
            service.addComputer(addComp.getComputer());
        }
    }
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

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(index == 0) {
        setTable();
    }
    else if(index == 1) {
        setLinkTableComputer();
        setLinkTableScientist();
    }
}

void MainWindow::on_scientist_table_link_clicked(const QModelIndex &index)
{
    int row = ui->scientist_table_link->currentRow();
    QString currentID = ui->scientist_table_link->item(row, 0)->text();
    ui->link_scientist_selected->setText(currentID);
}

void MainWindow::on_computer_table_link_clicked(const QModelIndex &index)
{
    int row = ui->computer_table_link->currentRow();
    QString currentID = ui->computer_table_link->item(row, 0)->text();
    ui->link_computer_selected->setText(currentID);
}

void MainWindow::on_link_button_clicked()
{
    std::string selSciID = ui->link_scientist_selected->text().toStdString();
    std::string selComID = ui->link_computer_selected->text().toStdString();
    if((selComID != "") && (selSciID != "")) {
        Link newLink = Link(selSciID,selComID);
        service.addLink(newLink);
        ui->link_computer_selected->clear();
        ui->link_scientist_selected->clear();
    }
}

void MainWindow::on_scientist_table_customContextMenuRequested(const QPoint &pos)
{
    QMenu menu;
    menu.addAction(ui->actionRemove_scientist);
    menu.exec(QCursor::pos());
}

void MainWindow::on_actionAdd_a_scientist_triggered()
{
    AddScientistDialog addSci;
    addSci.exec();
}

void MainWindow::on_actionRemove_scientist_triggered()
{
    int row = ui->scientist_table->currentRow();
    std::string id = ui->scientist_table->item(row, 0)->text().toStdString();
    service.removeScientist(id);
    setTable();
}

void MainWindow::on_computer_table_customContextMenuRequested(const QPoint &pos)
{
    QMenu menu;
    menu.addAction(ui->actionRemove_Computer);
    menu.exec(QCursor::pos());
}

void MainWindow::on_actionRemove_Computer_triggered()
{
    int row = ui->computer_table->currentRow();
    std::string id = ui->computer_table->item(row, 0)->text().toStdString();
    int reply = QMessageBox::question(this, "Removing computer",
                                      "Do you really want to remove computer with ID:" +
                                      QString::fromStdString(id),
                                      QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        service.removeComputer(id);
        ui->statusBar->showMessage("Computer with ID:" +
                                   QString::fromStdString(id) +
                                   " has been removed.", 2000);
    }

    setTable();
}
