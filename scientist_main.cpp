#include "scientist_main.h"
#include "ui_scientist_main.h"

Scientist_main::Scientist_main(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Scientist_main)
{
    ui->setupUi(this);
}

Scientist_main::~Scientist_main()
{
    delete ui;
}


void Scientist_main::on_scientistDisplay_activated(const QModelIndex &index)
{

}
