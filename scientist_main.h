#ifndef SCIENTIST_MAIN_H
#define SCIENTIST_MAIN_H

#include <QWidget>

namespace Ui {
class Scientist_main;
}

class Scientist_main : public QWidget
{
    Q_OBJECT

public:
    explicit Scientist_main(QWidget *parent = 0);
    ~Scientist_main();

private slots:
    void on_scientistDisplay_activated(const QModelIndex &index);

private:
    Ui::Scientist_main *ui;
};

#endif // SCIENTIST_MAIN_H
