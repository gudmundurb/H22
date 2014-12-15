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
    ui->InvalidInput->hide();
}

AddScientistDialog::~AddScientistDialog()
{
    delete ui;
}

Scientist AddScientistDialog::getScientist() {
    return newScientist;
}

bool AddScientistDialog::success() {
    return succesful;
}


void AddScientistDialog::on_InputScientistName_textChanged(const QString &arg1)
{
    newScientist.name = ui->InputScientistName->text().toStdString();
}

void AddScientistDialog::on_InputBirthYear_textChanged(const QString &arg1)
{
    newScientist.dateOfBirth = ui->InputBirthYear->text().toStdString();
}

void AddScientistDialog::on_InputDeathYear_textChanged(const QString &arg1)
{
    newScientist.dateOfDeath = ui->InputDeathYear->text().toStdString();
}
void AddScientistDialog::on_ScientistGender_currentIndexChanged(const QString &arg1)
{
    if(ui->ScientistGender->currentText().toStdString() == "Male"){
        newScientist.gender = "M";
    }
    else{
        newScientist.gender = "F";
    }
}



void AddScientistDialog::on_RadioStillAlive_toggled(bool checked)
{
    if(checked){
        ui->InputDeathYear->setEnabled(false);
        newScientist.dateOfDeath = "0";
    }
    else{
        ui->InputDeathYear->setEnabled(true);
    }
}

void AddScientistDialog::on_Cancel_clicked()
{
    close();
}

void AddScientistDialog::on_S_add_ok_clicked()
{
    if(correctInput()) {
        succesful = true;
        close();
    }
    else{
        ui->InvalidInput->show();
    }
}

bool AddScientistDialog::correctInput(){
    if(newScientist.name == "") {
        return false;
    }
    if(!util::validYear(newScientist.dateOfBirth)) {
            return false;
    }
    if(!(ui->RadioStillAlive->isEnabled())){
        if(!util::validYear(newScientist.dateOfDeath)) {
            return false;
        }
    }

    return true;
}
