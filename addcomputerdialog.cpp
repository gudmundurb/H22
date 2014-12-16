#include "addcomputerdialog.h"
#include "ui_addcomputerdialog.h"

AddComputerDialog::AddComputerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addComputerDialog) {
    ui->setupUi(this);
    successful = false;
    newComputer.built = "";
    newComputer.dateOfBuild = "";
    newComputer.name = "";
    newComputer.type = "";
    ui->InvalidInput->hide();
}

AddComputerDialog::~AddComputerDialog() {
    delete ui;
}

Computer AddComputerDialog::getComputer() {
    return newComputer;
}

bool AddComputerDialog::success() {
    return successful;
}

void AddComputerDialog::on_C_add_ok_clicked() {
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

void AddComputerDialog::on_RadioWasBuilt_toggled(bool checked) {
    if(checked) {
        ui->InputBuiltYear->setEnabled(true);
    }
    else {
        ui->InputBuiltYear->setEnabled(false);
    }
}

void AddComputerDialog::on_Cancel_clicked() {
    close();
}

void AddComputerDialog::on_TypeDropDown_currentIndexChanged(const QString &arg1) {
    if(ui->TypeDropDown->currentText().toStdString() == "Other...") {
        ui->InputComputerType->setEnabled(true);
    }
    else {
        ui->InputComputerType->setEnabled(false);
    }
}

bool AddComputerDialog::correctInput() {
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

void AddComputerDialog::on_browseImagePath_clicked() {
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

