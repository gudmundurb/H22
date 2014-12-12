#ifndef ADDSCIENTIST_H
#define ADDSCIENTIST_H

#include <QWidget>

namespace Ui {
class AddScientist;
}

class AddScientist : public QWidget
{
    Q_OBJECT

public:
    explicit AddScientist(QWidget *parent = 0);
    ~AddScientist();

private:
    Ui::AddScientist *ui;
};

#endif // ADDSCIENTIST_H
