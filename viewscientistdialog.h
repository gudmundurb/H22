#ifndef VIEWSCIENTISTDIALOG_H
#define VIEWSCIENTISTDIALOG_H

#include <QDialog>
#include "scientist.h"
#include "computer.h"
#include "editscientist.h"
#include "services.h"

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
private slots:
    void on_Edit_button_clicked();

private:
    std::vector<Computer> connectedComputers;
    Scientist scientist;
    void setTable();
    void displayScientist();
    Ui::ViewScientistDialog *ui;
    Services service;
};

#endif // VIEWSCIENTISTDIALOG_H
