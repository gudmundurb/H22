#ifndef ADDSCIENTISTDIALOG_H
#define ADDSCIENTISTDIALOG_H

#include "scientist.h"
#include <QDialog>
#include <QPixmap>
#include <QFileDialog>
#include <QDebug>

namespace Ui {
class AddScientistDialog;
}

class AddScientistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddScientistDialog(QWidget *parent = 0);
    ~AddScientistDialog();
    Scientist getScientist();
    bool correctInput();
    bool success();

private slots:
    void on_RadioStillAlive_toggled(bool checked);

    void on_Cancel_clicked();

    void on_S_add_ok_clicked();

    void on_browseImagePath_clicked();

private:
    Ui::AddScientistDialog *ui;
    Scientist newScientist;
    bool succesful;
};

#endif // ADDSCIENTISTDIALOG_H
