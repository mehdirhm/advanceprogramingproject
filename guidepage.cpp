#include "guidepage.h"
#include "ui_guidepage.h"

GuidePage::GuidePage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GuidePage)
{
    ui->setupUi(this);
}

GuidePage::~GuidePage()
{
    delete ui;
}
