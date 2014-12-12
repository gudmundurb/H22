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
};

#endif // MAINWINDOW_H
