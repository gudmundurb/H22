#include "addscientistdialog.h"
#include "ui_addscientistdialog.h"

AddScientistDialog::AddScientistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScientistDialog)
{
    ui->setupUi(this);
    newScientist.dateOfBirth = "";
    newScientist.dateOfDeath = "";
    newScientist.name = "";
    newScientist.gender = "";
    succesful = false;
    ui->InvalidInput->setEnabled(true);
    ui->InvalidInput->hide();
}

AddScientistDialog::~AddScientistDialog() {
    delete ui;
}

Scientist AddScientistDialog::getScientist() {
    return newScientist;
}

bool AddScientistDialog::success() {
    return succesful;
}

void AddScientistDialog::on_RadioStillAlive_toggled(bool checked) {
    if(checked) {
        ui->InputDeathYear->setEnabled(false);
    }
    else {
        ui->InputDeathYear->setEnabled(true);
    }
}

void AddScientistDialog::on_Cancel_clicked() {
    close();
}

void AddScientistDialog::on_S_add_ok_clicked() {
    newScientist.name = ui->InputScientistName->text().toStdString();
    newScientist.dateOfBirth = ui->InputBirthYear->text().toStdString();
    if(ui->RadioStillAlive->isChecked()) {
        newScientist.dateOfDeath = "----";
    }
    else {
        newScientist.dateOfDeath = ui->InputDeathYear->text().toStdString();
    }
    if(ui->ScientistGender->currentText() == "Male") {
        newScientist.gender = "M";
    }
    else {
        newScientist.gender = "F";
    }
    if(correctInput()) {
        succesful = true;
        close();
    }
    else {
        ui->InvalidInput->show();
    }
}

bool AddScientistDialog::correctInput(){
    if(newScientist.name == "") {
        ui->InvalidInput->setText("Invalid name.");
        ui->InvalidInput->show();
        return false;
    }
    if(!util::validYear(newScientist.dateOfBirth)) {
        ui->InvalidInput->setText("Invalid birth year.");
        ui->InvalidInput->show();
        return false;
    }
    if(!(ui->RadioStillAlive->isChecked())) {
        if(!util::validYear(newScientist.dateOfDeath)) {
            ui->InvalidInput->setText("Invalid death year.");
            ui->InvalidInput->show();
            return false;
        }
    }
    ui->InvalidInput->hide();
    return true;
}
