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

    void on_tabWidget_currentChanged(int index);

    void on_scientist_table_link_clicked(const QModelIndex &index);

    void on_computer_table_link_clicked(const QModelIndex &index);

    void on_link_button_clicked();

    void on_scientist_table_customContextMenuRequested(const QPoint &pos);

    void on_actionAdd_a_scientist_triggered();

    void on_actionRemove_scientist_triggered();

    void on_computer_table_customContextMenuRequested(const QPoint &pos);

    void on_actionRemove_Computer_triggered();

    void on_search_link_scientist_textChanged(const QString &arg1);

    void on_search_link_computer_textChanged(const QString &arg1);

    void on_actionView_Scientist_triggered();

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
    void setLinkTableScientist();
    void setLinkTableComputer();
    void setTableComputer();
    void setTable ();
    void hideAllTables();
    void hideAllSortCombos();
};

#endif // MAINWINDOW_H
