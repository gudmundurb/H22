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
    bool checked = false;
    ui->RadioWasBuilt->toggled(checked);
    if(!checked){
        newComputer.dateOfBuild = "0";
    }
    if(ui->TypeDropDown->currentText().toStdString() == "Other..."){

    }
    else{
        newComputer.type = ui->TypeDropDown->currentText().toStdString();
    }
    service.addComputer(newComputer);
}




void addComputerDialog::on_RadioWasBuilt_toggled(bool checked)
{
    if(checked){

        newComputer.built = "yes";
        ui->InputBuiltYear->setEnabled(true);
    }
    else{
        newComputer.built = "no";
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
