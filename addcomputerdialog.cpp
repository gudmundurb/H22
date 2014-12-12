#include "addcomputerdialog.h"
#include "ui_addcomputerdialog.h"

addComputerDialog::addComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addComputerDialog)
{
    ui->setupUi(this);
}

addComputerDialog::~addComputerDialog()
{
    delete ui;
}
Computer addComputerDialog::getComputer() {
    return newComputer;
}

void addComputerDialog::on_C_add_ok_clicked()
{
    if(newComputer.built != "yes"){
        newComputer.built = "no";
        newComputer.dateOfBuild = "----";
    }
    close();
}

void addComputerDialog::on_RadioWasBuilt_toggled(bool checked)
{
    if(checked) {
        newComputer.built = "yes";
        ui->InputBuiltYear->setEnabled(true);
    }
    else {
        ui->InputBuiltYear->setEnabled(false);
    }
}

void addComputerDialog::on_InputComputerName_textChanged(const QString &arg1)
{
    newComputer.name =  ui->InputComputerName->text().toStdString();
}

void addComputerDialog::on_InputBuiltYear_textChanged(const QString &arg1)
{
    newComputer.dateOfBuild = ui->InputBuiltYear->text().toStdString();
}

void addComputerDialog::on_Cancel_clicked()
{
    close();
}


void addComputerDialog::on_TypeDropDown_currentIndexChanged(const QString &arg1)
{
    if(ui->TypeDropDown->currentText().toStdString() == "Other..."){
        ui->InputComputerType->setEnabled(true);
    }
    else{
        ui->InputComputerType->setEnabled(false);
        newComputer.type = ui->TypeDropDown->currentText().toStdString();
    }
}

void addComputerDialog::on_InputComputerType_textChanged(const QString &arg1)
{
    newComputer.type = ui->InputComputerType->text().toStdString();
}
