#include "editscientist.h"
#include "ui_editscientist.h"

EditScientist::EditScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditScientist)
{
    ui->setupUi(this);
    newScientist.dateOfBirth = oldScientist.dateOfBirth;
    if(oldScientist.dateOfDeath != "----"){
        newScientist.dateOfDeath = oldScientist.dateOfDeath;
    }
    else{
        ui->RadioStillAlive->toggle();
    }
    newScientist.name = oldScientist.name;
    newScientist.gender = oldScientist.gender;
    startingInput();
    succesful = false;
    ui->InvalidInput->hide();
}

EditScientist::~EditScientist() {
    delete ui;
}

Scientist EditScientist::getScientist() {
    return newScientist;
}

bool EditScientist::success() {
    return succesful;
}

void EditScientist::on_RadioStillAlive_toggled(bool checked) {
    if(checked) {
        ui->InputDeathYear->setEnabled(false);
    }
    else {
        ui->InputDeathYear->setEnabled(true);
    }
}

void EditScientist::on_Cancel_clicked() {
    close();
}

void EditScientist::on_S_add_ok_clicked() {
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

bool EditScientist::correctInput(){
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

void EditScientist::startingInput(){
    ui->InputScientistName->setText(QString::fromStdString(oldScientist.name));
    ui->InputBirthYear->setText(QString::fromStdString(oldScientist.dateOfBirth));
    if(oldScientist.dateOfDeath != "----"){
        ui->InputDeathYear->setText(QString::fromStdString(oldScientist.dateOfDeath));
    }
    if(oldScientist.gender == "F") {
        ui->ScientistGender->setCurrentIndex(2);
    }
}
