#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "services.h"
#include "scientist.h"
#include "computer.h"
#include "link.h"
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_sort_combo_scientist_currentTextChanged(const QString &arg1);

    void on_sort_combo_order_currentTextChanged(const QString &arg1);

    void on_search_text_textChanged(const QString &arg1);

    void on_add_button_clicked();

    void on_display_table_combo_currentTextChanged(const QString &arg1);

    void on_sort_combo_computer_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    Services service;
    std::vector<Scientist> currentScientists;
    std::vector<Computer> currentComputers;
    std::vector<Link> currentLinks;
    std::vector<Scientist> currentlyDisplayedScientists;
    std::vector<Computer> currentlyDisplayedComputers;
    std::vector<Link> currentlyDislayedLinks;
    void setTableScientist();
    void setTableComputer();
    void setTable ();
    void hideAllTables();
    void hideAllSortCombos();
};

#endif // MAINWINDOW_H
