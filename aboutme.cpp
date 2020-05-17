#include "aboutme.h"
#include "ui_aboutme.h"

aboutme::aboutme(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::aboutme)
{
    ui->setupUi(this);
}

aboutme::~aboutme()
{
    delete ui;
}
