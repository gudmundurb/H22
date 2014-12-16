#ifndef EDITSCIENTIST_H
#define EDITSCIENTIST_H

#include <QDialog>
#include "scientist.h"
#include <cctype>

namespace Ui {
class EditScientist;
}

class EditScientist : public QDialog
{
    Q_OBJECT

public:
    explicit EditScientist(QWidget *parent = 0);
    ~EditScientist();
    Scientist getScientist();
    bool correctInput();
    bool success();
    void startingInput();
    Scientist oldScientist;
private slots:
    void on_RadioStillAlive_toggled(bool checked);

    void on_Cancel_clicked();

    void on_S_add_ok_clicked();

private:
    Ui::EditScientist *ui;
    Scientist newScientist;
    bool succesful;
};

#endif // EDITSCIENTIST_H
