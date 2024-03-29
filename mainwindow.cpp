#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setTable();
    setLinkTableComputer();
    setLinkTableScientist();
    ui->scientist_table->setColumnWidth(0,35);
    ui->computer_table->setColumnWidth(0,35);
    ui->scientist_table->setColumnWidth(1,200);
    ui->computer_table->setColumnWidth(1,200);
    ui->scientist_table->setColumnWidth(2,100);
    ui->computer_table->setColumnWidth(2,100);
    ui->scientist_table->setColumnWidth(3,150);
    ui->computer_table->setColumnWidth(3,150);
    this->statusBar()->setSizeGripEnabled(false);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setTable () {
    QString selectedTable = ui->display_table_combo->currentText();
    if(selectedTable == "Scientists") {
        hideAllSortCombos();
        hideAllTables();
        ui->scientist_table->show();
        ui->scientist_table->setEnabled(true);
        ui->sort_combo_scientist->show();
        ui->sort_combo_scientist->setEnabled(true);
        setTableScientist();
    }
    else if(selectedTable == "Computers") {
        hideAllSortCombos();
        hideAllTables();
        ui->computer_table->show();
        ui->computer_table->setEnabled(true);
        ui->sort_combo_computer->show();
        ui->sort_combo_computer->setEnabled(true);
        setTableComputer();
    }
}

void MainWindow::hideAllTables() {
    ui->scientist_table->hide();
    ui->scientist_table->setEnabled(false);
    ui->computer_table->hide();
    ui->computer_table->setEnabled(false);
}

void MainWindow::hideAllSortCombos() {
    ui->sort_combo_computer->hide();
    ui->sort_combo_computer->setEnabled(false);
    ui->sort_combo_scientist->hide();
    ui->sort_combo_computer->setEnabled(false);
}

void MainWindow::setTableScientist() {
    currentlyDisplayedScientists.clear();
    ui->scientist_table->clearContents();

    std::string orderSelection = ui->sort_combo_order->currentText().toStdString();
    int sortIndex = ui->sort_combo_scientist->currentIndex() + 1;
    std::string sortingIndex = QString::number(sortIndex).toStdString();
    std::string searchSelection = ui->search_text->text().toStdString();

    currentScientists = service.getScientistsOrderedBy(sortingIndex, orderSelection);

    for(unsigned int i = 0; i < currentScientists.size(); i++) {
        Scientist currentScientist = currentScientists[i];

        if(currentScientist.contains(searchSelection)) {
            ui->scientist_table->setRowCount(currentlyDisplayedScientists.size() + 1);

            QString scientistId =       QString::fromStdString(currentScientist.id);
            QString scientistName =     QString::fromStdString(currentScientist.name);
            QString scientistDob =      QString::fromStdString(currentScientist.dateOfBirth);
            QString scientistDod =      QString::fromStdString(currentScientist.dateOfDeath);
            QString scientistGender =   QString::fromStdString(currentScientist.gender);

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

    std::string searchSelection = ui->search_link_scientist->text().toStdString();

    currentScientists = service.getScientistsOrderedBy("ID", "ASC");

    for(unsigned int i = 0; i < currentScientists.size(); i++) {
        Scientist currentScientist = currentScientists[i];

        if(currentScientist.contains(searchSelection)) {
            ui->scientist_table_link->setRowCount(currentlyDisplayedScientists.size() + 1);

            QString scientistId =   QString::fromStdString(currentScientist.id);
            QString scientistName = QString::fromStdString(currentScientist.name);

            int currentIndex = currentlyDisplayedScientists.size();

            ui->scientist_table_link->setItem(currentIndex,0, new QTableWidgetItem(scientistId));
            ui->scientist_table_link->setItem(currentIndex,1, new QTableWidgetItem(scientistName));
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

            QString computerId =      QString::fromStdString(currentComputer.id);
            QString computerName =    QString::fromStdString(currentComputer.name);
            QString computerDob =     QString::fromStdString(currentComputer.dateOfBuild);
            QString computerType =    QString::fromStdString(currentComputer.type);
            QString computerBuilt =   QString::fromStdString(currentComputer.built);

            int currentIndex = currentlyDisplayedComputers.size();

            ui->computer_table->setItem(currentIndex,0, new QTableWidgetItem(computerId));
            ui->computer_table->setItem(currentIndex,1, new QTableWidgetItem(computerName));
            ui->computer_table->setItem(currentIndex,2, new QTableWidgetItem(computerDob));
            ui->computer_table->setItem(currentIndex,3, new QTableWidgetItem(computerType));
            ui->computer_table->setItem(currentIndex,4, new QTableWidgetItem(computerBuilt));
            currentlyDisplayedComputers.push_back(currentComputer);
        }
    }
}

void MainWindow::setLinkTableComputer() {
    currentlyDisplayedComputers.clear();
    ui->computer_table_link->clearContents();

    std::string searchSelection = ui->search_link_computer->text().toStdString();

    currentComputers = service.getComputersOrderedBy("ID", "ASC");

    for(unsigned int i = 0; i < currentComputers.size(); i++) {
        Computer currentComputer = currentComputers[i];

        if(currentComputer.contains(searchSelection)) {
            ui->computer_table_link->setRowCount(currentlyDisplayedComputers.size() + 1);

            QString computerId =    QString::fromStdString(currentComputer.id);
            QString computerName =  QString::fromStdString(currentComputer.name);

            int currentIndex = currentlyDisplayedComputers.size();

            ui->computer_table_link->setItem(currentIndex,0, new QTableWidgetItem(computerId));
            ui->computer_table_link->setItem(currentIndex,1, new QTableWidgetItem(computerName));
            currentlyDisplayedComputers.push_back(currentComputer);
        }
    }
}

void MainWindow::on_sort_combo_scientist_currentTextChanged(const QString &arg1) {
    setTable();
}

void MainWindow::on_sort_combo_order_currentTextChanged(const QString &arg1) {
    setTable();
}

void MainWindow::on_search_text_textChanged(const QString &arg1) {
    setTable();
}

void MainWindow::on_add_button_clicked() {
    QString selectedTable = ui->display_table_combo->currentText();
    if(selectedTable == "Scientists") {
        AddScientistDialog add;
        add.exec();
        if(add.success()) {
            service.addScientist(add.getScientist());
            ui->statusBar->showMessage("Scientist added to database.", 2500);
        }
    }
    else if(selectedTable == "Computers") {
        AddComputerDialog add;
        add.exec();
        if(add.success()) {
            service.addComputer(add.getComputer());
            ui->statusBar->showMessage("Computer added to database.", 2500);
        }
    }
    setTable();
}

void MainWindow::on_display_table_combo_currentTextChanged(const QString &arg1) {
    setTable();
}

void MainWindow::on_sort_combo_computer_currentIndexChanged(int index) {
    setTable();
}

void MainWindow::on_tabWidget_currentChanged(int index) {
    if(index == 0) {
        setTable();
    }
    else if(index == 1) {
        setLinkTableComputer();
        setLinkTableScientist();
    }
}

void MainWindow::on_scientist_table_link_clicked(const QModelIndex &index) {
    int row = ui->scientist_table_link->currentRow();
    QString currentID = ui->scientist_table_link->item(row, 0)->text();
    ui->link_scientist_selected->setText(currentID);
}

void MainWindow::on_computer_table_link_clicked(const QModelIndex &index) {
    int row = ui->computer_table_link->currentRow();
    QString currentID = ui->computer_table_link->item(row, 0)->text();
    ui->link_computer_selected->setText(currentID);
}

void MainWindow::on_link_button_clicked() {
    std::string selSciID = ui->link_scientist_selected->text().toStdString();
    std::string selComID = ui->link_computer_selected->text().toStdString();
    if((selComID != "") && (selSciID != "")) {
        Link newLink = Link(selSciID,selComID);
        service.addLink(newLink);
        ui->statusBar->showMessage("Scientist with ID: " + QString::fromStdString(selSciID)
                                   + " and computer with ID: " + QString::fromStdString(selComID)
                                   + " have been linked.", 4000);
        if(currentlyDisplayedComputers.size() != 1) {
            ui->link_computer_selected->clear();
        }
        if(currentlyDisplayedScientists.size() != 1) {
            ui->link_scientist_selected->clear();
        }
    }
}

void MainWindow::on_scientist_table_customContextMenuRequested(const QPoint &pos) {
    QMenu menu;
    menu.addAction(ui->actionView_Scientist);
    menu.addAction(ui->actionEdit_Scientist);
    menu.addAction(ui->actionRemove_scientist);
    menu.exec(QCursor::pos());
}

void MainWindow::on_actionAdd_a_scientist_triggered() {
    AddScientistDialog addSci;
    addSci.exec();
}

void MainWindow::on_actionRemove_scientist_triggered() {
    int row = ui->scientist_table->currentRow();
    std::string id = ui->scientist_table->item(row, 0)->text().toStdString();
    int reply = QMessageBox::question(this, "Removing Scientist",
                                      "Do you really want to remove scientist with ID: " +
                                      QString::fromStdString(id),
                                      QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        service.removeScientist(id);
        ui->statusBar->showMessage("Scientist with ID: " +
                                   QString::fromStdString(id) +
                                   " has been removed.", 2500);
    }
    setTable();
}

void MainWindow::on_computer_table_customContextMenuRequested(const QPoint &pos) {
    QMenu menu;
    menu.addAction(ui->actionView_Computer);
    menu.addAction(ui->actionEdit_computer);
    menu.addAction(ui->actionRemove_Computer);
    menu.exec(QCursor::pos());
}

void MainWindow::on_actionRemove_Computer_triggered() {
    int row = ui->computer_table->currentRow();
    std::string id = ui->computer_table->item(row, 0)->text().toStdString();
    int reply = QMessageBox::question(this, "Removing computer",
                                      "Do you really want to remove computer with ID: " +
                                      QString::fromStdString(id),
                                      QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes) {
        service.removeComputer(id);
        ui->statusBar->showMessage("Computer with ID: " +
                                   QString::fromStdString(id) +
                                   " has been removed.", 2000);
    }
    setTable();
}

void MainWindow::on_search_link_scientist_textChanged(const QString &arg1) {
    setLinkTableScientist();
    if(currentlyDisplayedScientists.size() == 1) {
        QString onlyID = ui->scientist_table_link->item(0, 0)->text();
        ui->link_scientist_selected->setText(onlyID);
    }
    else {
        ui->link_scientist_selected->clear();
    }
}

void MainWindow::on_search_link_computer_textChanged(const QString &arg1) {
    setLinkTableComputer();
    if(currentlyDisplayedComputers.size() == 1) {
        QString onlyID = ui->computer_table_link->item(0, 0)->text();
        ui->link_computer_selected->setText(onlyID);
    }
    else {
        ui->link_computer_selected->clear();
    }
}

void MainWindow::on_actionView_Scientist_triggered() {
    int row = ui->scientist_table->currentRow();
    std::string scientistId = ui->scientist_table->item(row, 0)->text().toStdString();
    Scientist tempScientist;
    for(unsigned int i = 0; i < currentlyDisplayedScientists.size(); i++) {
        if(currentlyDisplayedScientists[i].id == scientistId) {
            tempScientist = currentlyDisplayedScientists[i];
            break;
        }
    }
    std::vector<Computer> tempComputers = service.computerLink(tempScientist.id);
    ViewScientistDialog viewDialog;
    viewDialog.setConnectedComputers(tempComputers);
    viewDialog.setScientist(tempScientist);
    viewDialog.setup();
    viewDialog.exec();
    if(viewDialog.wantRemove()) {
        std::vector<std::string> removeIds = viewDialog.getRemoveIds();
        for(unsigned int i = 0; i < removeIds.size(); i++) {
            service.removeLink(scientistId, removeIds[i]);
        }
    }
}

void MainWindow::on_actionView_Computer_triggered() {
    int row = ui->computer_table->currentRow();
    std::string computerId = ui->computer_table->item(row, 0)->text().toStdString();
    Computer tempComputer;
    for(unsigned int i = 0; i < currentlyDisplayedComputers.size(); i++) {
        if(currentlyDisplayedComputers[i].id == computerId) {
            tempComputer = currentlyDisplayedComputers[i];
            break;
        }
    }
    std::vector<Scientist> tempScientists = service.scientistLink(tempComputer.id);
    ViewComputerDialog viewDialog;
    viewDialog.setConnectedScientists(tempScientists);
    viewDialog.setComputer(tempComputer);
    viewDialog.setup();
    viewDialog.exec();
    if(viewDialog.wantRemove()) {
        std::vector<std::string> removeIds = viewDialog.getRemoveIds();
        for(unsigned int i = 0; i < removeIds.size(); i++) {
            service.removeLink(removeIds[i], computerId);
        }
    }
}

void MainWindow::on_actionEdit_Scientist_triggered() {
    int row = ui->scientist_table->currentRow();
    std::string scientistId = ui->scientist_table->item(row, 0)->text().toStdString();
    Scientist tempScientist;
    for(unsigned int i = 0; i < currentlyDisplayedScientists.size(); i++) {
        if(currentlyDisplayedScientists[i].id == scientistId) {
            tempScientist = currentlyDisplayedScientists[i];
            break;
        }
    }
    EditScientistDialog dialog;
    dialog.startingInput(tempScientist);
    dialog.exec();
    if(dialog.success()) {
        service.updateScientist(tempScientist, dialog.getScientist());
        ui->statusBar->showMessage("Scientist was updated.", 4500);
    }
    setTable();
}

void MainWindow::on_actionEdit_computer_triggered() {
    int row = ui->computer_table->currentRow();
    std::string computerId = ui->computer_table->item(row, 0)->text().toStdString();
    Computer tempComputer;
    for(unsigned int i = 0; i < currentlyDisplayedComputers.size(); i++) {
        if(currentlyDisplayedComputers[i].id == computerId) {
            tempComputer = currentlyDisplayedComputers[i];
            break;
        }
    }
    EditComputerDialog dialog;
    dialog.startingInput(tempComputer);
    dialog.exec();
    if(dialog.success()) {
        service.updateComputer(tempComputer, dialog.getComputer());
        ui->statusBar->showMessage("Computer was updated.", 4500);
    }
    setTable();
}

void MainWindow::on_scientist_table_doubleClicked(const QModelIndex &index) {
    ui->actionView_Scientist->trigger();
}

void MainWindow::on_computer_table_doubleClicked(const QModelIndex &index) {
    ui->actionView_Computer->trigger();
}
