#ifndef VIEWCOMPUTERDIALOG_H
#define VIEWCOMPUTERDIALOG_H

#include <QDialog>
#include "scientist.h"
#include "computer.h"
#include <QDate>

namespace Ui {
class ViewComputerDialog;
}

class ViewComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewComputerDialog(QWidget *parent = 0);
    ~ViewComputerDialog();
    void setConnectedScientists(const std::vector<Scientist> &input);
    void setComputer(const Computer &input);
    void setup();
private:
    std::vector<Scientist> connectedScientists;
    Computer computer;
    void setTable();
    void displayComputer();
    Ui::ViewComputerDialog *ui;
};

#endif // VIEWCOMPUTERDIALOG_H
