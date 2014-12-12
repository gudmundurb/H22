#ifndef ADDCOMPUTERDIALOG_H
#define ADDCOMPUTERDIALOG_H

#include <QDialog>
#include <services.h>

namespace Ui {
class addComputerDialog;
}

class addComputerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addComputerDialog(QWidget *parent = 0);
    ~addComputerDialog();

private slots:


    void on_C_add_ok_clicked();

private:
    Ui::addComputerDialog *ui;
    Services service;
};

#endif // ADDCOMPUTERDIALOG_H