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



void addComputerDialog::on_C_add_ok_clicked()
{
    Computer newComputer;
    newComputer.name =  ui->InputComputerName->text().toStdString();
    bool checked = false;
    ui->RadioWasBuilt->toggled(checked);
    if(checked){
        newComputer.dateOfBuild = ui->InputBuiltYear->text().toStdString();
    }
    else{
        newComputer.dateOfBuild = "0";
    }
    if(ui->TypeDropDown->currentText().toStdString() == "Other..."){

    }
    else{
        newComputer.type = ui->TypeDropDown->currentText().toStdString();
    }
    service.addComputer(newComputer);
}
