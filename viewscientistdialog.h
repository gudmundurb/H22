#ifndef VIEWSCIENTISTDIALOG_H
#define VIEWSCIENTISTDIALOG_H

#include "scientist.h"
#include "computer.h"
#include "editscientist.h"
#include <QDialog>
#include <QDebug>
#include <QDate>
#include <QMenu>
#include <QPixmap>

namespace Ui {
class ViewScientistDialog;
}

class ViewScientistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewScientistDialog(QWidget *parent = 0);
    ~ViewScientistDialog();
    void setConnectedComputers(std::vector<Computer> input);
    void setScientist(Scientist input);
    void setup();
    bool wantRemove();
    std::vector<std::string> getRemoveIds();

private slots:
    void on_actionUnlink_computer_triggered();

    void on_computer_table_customContextMenuRequested(const QPoint &pos);

private:
    Scientist scientist;
    std::vector<Computer> connectedComputers;
    bool wantsToRemoveLinks;
    std::vector<std::string> idsToRemove;
    void setTable();
    void displayScientist();
    void displayPicture();
    Ui::ViewScientistDialog *ui;
};

#endif // VIEWSCIENTISTDIALOG_H
