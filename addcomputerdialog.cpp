#include "addcomputerdialog.h"
#include "ui_addcomputerdialog.h"

addComputerDialog::addComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addComputerDialog) {
    ui->setupUi(this);
    successful = false;
    newComputer.built = "";
    newComputer.dateOfBuild = "";
    newComputer.name = "";
    newComputer.type = "";
    ui->InvalidInput->setEnabled(true);
    ui->InvalidInput->hide();
}

addComputerDialog::~addComputerDialog() {
    delete ui;
}

Computer addComputerDialog::getComputer() {
    return newComputer;
}

bool addComputerDialog::success() {
    return successful;
}

void addComputerDialog::on_C_add_ok_clicked() {
    if(ui->RadioWasBuilt->isChecked()) {
        newComputer.built = "yes";
        newComputer.dateOfBuild = ui->InputBuiltYear->text().toStdString();
    }
    else {
        newComputer.built = "no";
        newComputer.dateOfBuild = "----";
    }
    if(ui->TypeDropDown->currentText() == "Other...") {
        newComputer.type = ui->InputComputerType->text().toStdString();
    }
    else {
        newComputer.type = ui->TypeDropDown->currentText().toStdString();
    }
    newComputer.name = ui->InputComputerName->text().toStdString();
    if(correctInput()) {
        successful = true;
        close();
    }
}

void addComputerDialog::on_RadioWasBuilt_toggled(bool checked) {
    if(checked) {
        ui->InputBuiltYear->setEnabled(true);
    }
    else {
        ui->InputBuiltYear->setEnabled(false);
    }
}

void addComputerDialog::on_Cancel_clicked() {
    close();
}

void addComputerDialog::on_TypeDropDown_currentIndexChanged(const QString &arg1) {
    if(ui->TypeDropDown->currentText().toStdString() == "Other...") {
        ui->InputComputerType->setEnabled(true);
    }
    else {
        ui->InputComputerType->setEnabled(false);
    }
}

bool addComputerDialog::correctInput() {
    if(newComputer.name == "") {
        ui->InvalidInput->show();
        return false;
    }
    if(newComputer.type == "") {
        ui->InvalidInput->show();
        return false;
    }
    if(newComputer.built == "yes") {
        if(!util::validYear(newComputer.dateOfBuild)) {
            ui->InvalidInput->show();
            return false;
        }
    }
    ui->InvalidInput->hide();
    return true;
}
