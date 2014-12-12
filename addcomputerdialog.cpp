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
    if(ui->RadioWasBuilt){
        newComputer.dateOfBuild = ui->InputBuiltYear;
    }
    else{
        newComputer.dateOfBuild = "0";
    }
    if(ui->TypeDropDown->currentText().toStdString() == "Other..."){

    }
    else{
        newComputer.type = ui->TypeDropDown->currentText().toStdString();
    }
    Services.addComputer(newComputer);
}
