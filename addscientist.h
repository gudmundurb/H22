#ifndef ADDSCIENTIST_H
#define ADDSCIENTIST_H

#include <QWidget>
#include "scientist.h"
namespace Ui {
class AddScientist;
}

class AddScientist : public QWidget
{
    Q_OBJECT

public:
    explicit AddScientist(QWidget *parent = 0);
    ~AddScientist();
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
    Ui::AddScientist *ui;
    Scientist newScientist;
};

#endif // ADDSCIENTIST_H
