#ifndef ADDSCIENTISTDIALOG_H
#define ADDSCIENTISTDIALOG_H

#include <QWidget>
#include "scientist.h"
namespace Ui {
class AddScientistDialog;
}

class AddScientistDialog : public QWidget
{
    Q_OBJECT

public:
    explicit AddScientistDialog(QWidget *parent = 0);
    ~AddScientistDialog();
    Scientist getScientist();
private slots:
    void on_InputScientistName_textChanged(const QString &arg1);

    void on_InputBirthYear_textChanged(const QString &arg1);

    void on_InputDeathYear_textChanged(const QString &arg1);

    void on_ScientistGender_currentIndexChanged(const QString &arg1);

    void on_RadioStillAlive_toggled(bool checked);

    void on_Cancel_clicked();

    void on_S_add_ok_clicked();

private:
    Ui::AddScientistDialog *ui;
    Scientist newScientist;
};

#endif // ADDSCIENTISTDIALOG_H
