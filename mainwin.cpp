#include "mainwin.h"
#include "ui_mainwin.h"
#include <mainwindow.h>

MainWin::MainWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWin)
{
    ui->setupUi(this);
}

MainWin::~MainWin()
{
    delete ui;
}

void MainWin::on_pushButton_clicked()
{
    MainWindow * main=new MainWindow;
    hide();
    main->show();
}
