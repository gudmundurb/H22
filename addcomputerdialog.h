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
    Computer getComputer();
private slots:


    void on_C_add_ok_clicked();

    void on_RadioWasBuilt_toggled(bool checked);

    void on_InputComputerName_textChanged(const QString &arg1);

    void on_InputBuiltYear_textChanged(const QString &arg1);
    void on_InputComputerType_textChanged(const QString &arg1);
    void on_Cancel_clicked();
    void on_TypeDropDown_currentIndexChanged(const QString &arg1);

private:
    Ui::addComputerDialog *ui;
    Computer newComputer;
};

#endif // ADDCOMPUTERDIALOG_H
