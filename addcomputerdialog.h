#ifndef ADDCOMPUTERDIALOG_H
#define ADDCOMPUTERDIALOG_H

#include <QDialog>
#include "services.h"
#include <QFileDialog>
#include <QDebug>
#include <QPixmap>

namespace Ui {
class addComputerDialog;
}

class AddComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddComputerDialog(QWidget *parent = 0);
    ~AddComputerDialog();
    Computer getComputer();
    bool success();
    bool correctInput();
    //void setComputer(Computer c);

private slots:
    void on_C_add_ok_clicked();
    void on_RadioWasBuilt_toggled(bool checked);
    void on_Cancel_clicked();
    void on_TypeDropDown_currentIndexChanged(const QString &arg1);
    void on_browseImagePath_clicked();

private:
    bool successful;
    Ui::addComputerDialog *ui;
    Computer newComputer;
};

#endif // ADDCOMPUTERDIALOG_H
