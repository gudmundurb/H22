#ifndef ADDSCIENTISTDIALOG_H
#define ADDSCIENTISTDIALOG_H

#include <QWidget>
#include "scientist.h"

namespace Ui {
class addScientistDialog;
}

class addScientistDialog : public QWidget
{
    Q_OBJECT

public:
    explicit addScientistDialog(QWidget *parent = 0);
    ~addScientistDialog();
    Scientist getScientist();

private:
    Ui::addScientistDialog *ui;
    Scientist newScientist;
};

#endif // ADDSCIENTISTDIALOG_H
