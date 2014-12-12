#include "addscientist.h"
#include "ui_addscientist.h"

AddScientist::AddScientist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddScientist)
{
    ui->setupUi(this);
}

AddScientist::~AddScientist()
{
    delete ui;
}

Scientist AddScientist::getScientist(){
    return newScientist;
}


void AddScientist::on_InputScientistName_textChanged(const QString &arg1)
{
    newScientist.name = ui->InputScientistName->text().toStdString();
}

void AddScientist::on_InputBirthYear_textChanged(const QString &arg1)
{
    newScientist.dateOfBirth = ui->InputBirthYear->text().toStdString();
}

void AddScientist::on_InputDeathYear_textChanged(const QString &arg1)
{
    newScientist.dateOfDeath = ui->InputDeathYear->text().toStdString();
}
void AddScientist::on_ScientistGender_currentIndexChanged(const QString &arg1)
{
    if(ui->ScientistGender->currentText().toStdString() == "Male"){
        newScientist.gender = "M";
    }
    else{
        newScientist.gender = "F";
    }
}



void AddScientist::on_RadioStillAlive_toggled(bool checked)
{
    if(checked){
        ui->InputDeathYear->setEnabled(false);
        newScientist.dateOfDeath = "0";
    }
    else{
        ui->InputDeathYear->setEnabled(true);
    }
}

void AddScientist::on_Cancel_clicked()
{
    close();
}

void AddScientist::on_S_add_ok_clicked()
{
    close();
}
