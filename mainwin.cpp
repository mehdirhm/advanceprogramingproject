#include "mainwin.h"
#include "ui_mainwin.h"
#include <mainwindow.h>
#include "scenegraphic.h"
#include"guidepage.h"
#include "aboutme.h"

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
    scenegraphic::SetISDfa();
    main->show();
}

void MainWin::on_pushButton_2_clicked()
{
    MainWindow * main=new MainWindow;
    hide();
    scenegraphic::SetIsTuring();
    main->show();

}

void MainWin::on_pushButton_6_clicked()
{
   close();
}

void MainWin::on_pushButton_3_clicked()
{
    GuidePage *Guide=new GuidePage;
    hide();
    Guide->show();

}

void MainWin::on_pushButton_4_clicked()
{
     aboutme * about=new aboutme;
     hide();
     about->show();

}
