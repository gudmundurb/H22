#ifndef VIEWCOMPUTERDIALOG_H
#define VIEWCOMPUTERDIALOG_H

#include <QDialog>
#include "scientist.h"
#include "computer.h"
#include <QDate>
#include <QMenu>

namespace Ui {
class ViewComputerDialog;
}

class ViewComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewComputerDialog(QWidget *parent = 0);
    ~ViewComputerDialog();
    void setConnectedScientists(std::vector<Scientist> input);
    void setComputer(Computer input);
    void setup();
    bool wantRemove();
    std::vector<std::string> getRemoveIds();
private slots:
    void on_scientist_table_customContextMenuRequested(const QPoint &pos);

    void on_actionUnlink_scientist_triggered();

private:
    std::vector<Scientist> connectedScientists;
    Computer computer;
    bool wantsToRemoveLinks;
    std::vector<std::string> idsToRemove;
    void setTable();
    void displayComputer();
    void displayPicture();
    Ui::ViewComputerDialog *ui;
};

#endif // VIEWCOMPUTERDIALOG_H
