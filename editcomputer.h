#ifndef EDITCOMPUTER_H
#define EDITCOMPUTER_H

#include "computer.h"
#include <QDialog>
#include <QPixmap>
#include <QFileDialog>

namespace Ui {
class editComputer;
}

class EditComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditComputerDialog(QWidget *parent = 0);
    ~EditComputerDialog();
    Computer getComputer();
    bool success();
    bool correctInput();
    void startingInput(Computer oldComputer);

private slots:
    void on_C_add_ok_clicked();

    void on_RadioWasBuilt_toggled(bool checked);

    void on_Cancel_clicked();

    void on_TypeDropDown_currentIndexChanged(const QString &arg1);

    void on_browseImagePath_clicked();

private:
    bool successful;
    Ui::editComputer *ui;
    Computer oldComputer;
    Computer newComputer;
};

#endif // EDITCOMPUTER_H
