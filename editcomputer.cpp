#include "editcomputer.h"
#include "ui_editcomputer.h"

EditComputerDialog::EditComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editComputer) {
    ui->setupUi(this);
    successful = false;
    ui->InvalidInput->hide();
}

EditComputerDialog::~EditComputerDialog() {
    delete ui;
}

Computer EditComputerDialog::getComputer() {
    return newComputer;
}

bool EditComputerDialog::success() {
    return successful;
}

void EditComputerDialog::on_C_add_ok_clicked() {
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

void EditComputerDialog::on_RadioWasBuilt_toggled(bool checked) {
    if(checked) {
        ui->InputBuiltYear->setEnabled(true);
    }
    else {
        ui->InputBuiltYear->setEnabled(false);
    }
}

void EditComputerDialog::on_Cancel_clicked() {
    close();
}

void EditComputerDialog::on_TypeDropDown_currentIndexChanged(const QString &arg1) {
    if(ui->TypeDropDown->currentText().toStdString() == "Other...") {
        ui->InputComputerType->setEnabled(true);
    }
    else {
        ui->InputComputerType->setEnabled(false);
    }
}

bool EditComputerDialog::correctInput() {
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

void EditComputerDialog::startingInput(Computer oldComputer){
    ui->InputComputerName->setText(QString::fromStdString(oldComputer.name));
    if(oldComputer.built == "yes"){
        ui->RadioWasBuilt->toggle();
        ui->InputBuiltYear->setText(QString::fromStdString(oldComputer.dateOfBuild));
    }
    if(oldComputer.type == "Mechanical") {
        ui->TypeDropDown->setCurrentIndex(0);
    }
    else if(oldComputer.type == "Vacuum") {
        ui->TypeDropDown->setCurrentIndex(1);
    }
    else if(oldComputer.type == "Transistors") {
        ui->TypeDropDown->setCurrentIndex(2);
    }
    else if(oldComputer.type == "Digital") {
        ui->TypeDropDown->setCurrentIndex(3);
    }
    else{
        ui->TypeDropDown->setCurrentIndex(4);
        ui->InputComputerType->setEnabled(true);
        ui->InputComputerType->setText(QString::fromStdString(oldComputer.type));
    }
    if(oldComputer.c_imagefilepath != "") {
        ui->C_input_imagepath->setText(QString::fromStdString(oldComputer.c_imagefilepath));
        QPixmap pixmap(QString::fromStdString(oldComputer.c_imagefilepath));
        ui->ComputerImageLabel->setPixmap(pixmap);
        ui->ComputerImageLabel->setScaledContents(true);
    }
    newComputer = oldComputer;
}

void EditComputerDialog::on_browseImagePath_clicked() {
    QString filename = QFileDialog::getOpenFileName(
                                this,
                                "Browse for image",
                                 "",
                                 "Image files (*.png *.jpg *.jpeg)"
                                 );
    ui->C_input_imagepath->setText(filename);
    QPixmap pixmap(filename);
    ui->ComputerImageLabel->setPixmap(pixmap);
    ui->ComputerImageLabel->setScaledContents(true);
}
