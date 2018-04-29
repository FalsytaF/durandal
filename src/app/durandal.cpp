#include "durandal.h"
#include "ui_durandal.h"

Durandal::Durandal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Durandal)
{
    ui->setupUi(this);
}

Durandal::~Durandal()
{
    delete ui;
}
