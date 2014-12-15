#ifndef VIEWSCIENTISTDIALOG_H
#define VIEWSCIENTISTDIALOG_H

#include <QDialog>
#include "scientist.h"
#include "computer.h"

namespace Ui {
class ViewScientistDialog;
}

class ViewScientistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewScientistDialog(QWidget *parent = 0);
    ~ViewScientistDialog();
    void setConnectedComputers(const std::vector<Computer> &input);
    void setScientist(const Scientist &input);
    void setup();
private:
    std::vector<Computer> connectedComputers;
    Scientist scientist;
    void setTable();
    void displayScientist();
    Ui::ViewScientistDialog *ui;
};

#endif // VIEWSCIENTISTDIALOG_H
