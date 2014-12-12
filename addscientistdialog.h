#ifndef ADDSCIENTISTDIALOG_H
#define ADDSCIENTISTDIALOG_H

#include <QWidget>

namespace Ui {
class addScientistDialog;
}

class addScientistDialog : public QWidget
{
    Q_OBJECT

public:
    explicit addScientistDialog(QWidget *parent = 0);
    ~addScientistDialog();

private:
    Ui::addScientistDialog *ui;
};

#endif // ADDSCIENTISTDIALOG_H
