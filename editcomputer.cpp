#include "editcomputer.h"
#include "ui_editcomputer.h"

editComputer::editComputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editComputer) {
    ui->setupUi(this);
    successful = false;
    if(oldComputer.built == "yes"){
        newComputer.built = oldComputer.built;
        newComputer.dateOfBuild = oldComputer.dateOfBuild;
    }
    else{
        ui->RadioWasBuilt->toggle();
    }
    newComputer.name = oldComputer.name;
    newComputer.type = oldComputer.type;
    ui->InvalidInput->hide();
}

editComputer::~editComputer() {
    delete ui;
}

Computer editComputer::getComputer() {
    return newComputer;
}

bool editComputer::success() {
    return successful;
}

void editComputer::on_C_add_ok_clicked() {
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
    newComputer.c_imagefilepath = ui->C_input_imagepath->text().toStdString();
    if(correctInput()) {
        successful = true;
        close();
    }
}

void editComputer::on_RadioWasBuilt_toggled(bool checked) {
    if(checked) {
        ui->InputBuiltYear->setEnabled(true);
    }
    else {
        ui->InputBuiltYear->setEnabled(false);
    }
}

void editComputer::on_Cancel_clicked() {
    close();
}

void editComputer::on_TypeDropDown_currentIndexChanged(const QString &arg1) {
    if(ui->TypeDropDown->currentText().toStdString() == "Other...") {
        ui->InputComputerType->setEnabled(true);
    }
    else {
        ui->InputComputerType->setEnabled(false);
    }
}

bool editComputer::correctInput() {
    if(newComputer.name == "") {
        ui->InvalidInput->setText("Invalid name.");
        ui->InvalidInput->show();
        return false;
    }
    if(newComputer.type == "") {
        ui->InvalidInput->setText("Invalid type.");
        ui->InvalidInput->show();
        return false;
    }
    if(newComputer.built == "yes") {
        if(!util::validYear(newComputer.dateOfBuild)) {
            ui->InvalidInput->setText("Invalid build year.");
            ui->InvalidInput->show();
            return false;
        }
    }
    ui->InvalidInput->hide();
    return true;
}

void editComputer::startingInput(Computer oldComputer){
    ui->InputComputerName->setText(QString::fromStdString(oldComputer.name));
    ui->InputComputerType->setText(QString::fromStdString(oldComputer.type));
    if(oldComputer.built != "no"){
        ui->RadioWasBuilt->toggle();
        ui->InputBuiltYear->setText(QString::fromStdString(oldComputer.dateOfBuild));
    }
    if(oldComputer.type == "Mechanical") {
        ui->TypeDropDown->setCurrentIndex(1);
    }
    else if(oldComputer.type == "Vacuum") {
        ui->TypeDropDown->setCurrentIndex(2);
    }
    else if(oldComputer.type == "Transistors") {
        ui->TypeDropDown->setCurrentIndex(3);
    }
    else if(oldComputer.type == "Digital") {
        ui->TypeDropDown->setCurrentIndex(4);
    }
    else{
        ui->TypeDropDown->setCurrentIndex(5);
        ui->InputComputerType->setEnabled(true);
        ui->InputComputerType->setText(QString::fromStdString(oldComputer.type));
    }
    newComputer = oldComputer;
}
