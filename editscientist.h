#ifndef EDITSCIENTIST_H
#define EDITSCIENTIST_H

#include "scientist.h"
#include <QDialog>
#include <QFileDialog>
#include <QPixmap>

namespace Ui {
class EditScientist;
}

class EditScientistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditScientistDialog(QWidget *parent = 0);
    ~EditScientistDialog();
    Scientist getScientist();
    bool correctInput();
    bool success();
    void startingInput(Scientist oldScientist);

private slots:
    void on_RadioStillAlive_toggled(bool checked);

    void on_Cancel_clicked();

    void on_S_add_ok_clicked();

    void on_browseImagePath_clicked();

private:
    Scientist oldScientist;
    Ui::EditScientist *ui;
    Scientist newScientist;
    bool succesful;
};

#endif // EDITSCIENTIST_H
