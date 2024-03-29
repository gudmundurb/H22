#include "addscientistdialog.h"
#include "ui_addscientistdialog.h"

AddScientistDialog::AddScientistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScientistDialog)
{
    ui->setupUi(this);
    succesful = false;
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
    newScientist.s_imagefilepath = ui->C_input_imagepath->text().toStdString();
    if(correctInput()) {
        succesful = true;
        close();
    }
    else {
        ui->InvalidInput->show();
    }
}

bool AddScientistDialog::correctInput() {
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
    if(newScientist.dateOfDeath != "----") {
        if(QString::fromStdString(newScientist.dateOfDeath).toInt() < QString::fromStdString(newScientist.dateOfBirth).toInt()) {
            ui->InvalidInput->setText("Death cannot happen before birth.");
            ui->InvalidInput->show();
            return false;
        }
    }
    ui->InvalidInput->hide();
    return true;
}

void AddScientistDialog::on_browseImagePath_clicked() {
    QString filename = QFileDialog::getOpenFileName(
                                this,
                                "Browse for image",
                                 "",
                                 "Image files (*.png *.jpg *.jpeg)"
                                 );
    ui->C_input_imagepath->setText(filename);
    QPixmap pixmap(filename);
    ui->ScientistImageLabel->setPixmap(pixmap);
    ui->ScientistImageLabel->setScaledContents(true);
}
