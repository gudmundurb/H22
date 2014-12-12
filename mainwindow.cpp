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

    setTableScientist();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setTable () {
    QString selectedTable = ui->display_table_combo->currentText();
    if(selectedTable == "Scientists") {
        setTableScientist();
    }
    else if(selectedTable == "Computers") {
        //setTableComputers();
    }
}

void MainWindow::setTableScientist() {
    currentlyDisplayedScientists.clear();
    std::string sortSelection = ui->sort_combo_scientist->currentText().toStdString();
    std::string orderSelection = ui->sort_combo_order->currentText().toStdString();
    int sortIndex = ui->sort_combo_scientist->currentIndex() + 1;
    std::string selectionIndex = QString::number(sortIndex).toStdString();
    std::string searchSelection = ui->search_text->text().toStdString();

    ui->countof->setText(QString::fromStdString(searchSelection));
    currentScientists = service.getScientistsOrderedBy(selectionIndex, orderSelection);
    ui->scientist_table->setRowCount(currentScientists.size());
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
    setTable();
}

void MainWindow::on_add_button_clicked()
{
    addComputerDialog add;
    add.exec();
}
