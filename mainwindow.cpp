#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"machine.hpp"
#include"dfa.hpp"
#include<QMouseEvent>
#include<QLineEdit>
#include <QLabel>
QString MainWindow::InputForCheck="";
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}
MainWindow::~MainWindow()
{
    delete ui;
    delete  scene;
    delete li;
    delete line;
}

void MainWindow::on_pushButton_clicked()
{
    scenegraphic::setNodeButtonActive();
    scenegraphic::setEdgeButtonDeactive();
    scenegraphic::setSelectButtonDeactive();
    scenegraphic::setFinalButtonDeactive();
    scenegraphic::setInitialButtonDeactive();
}

void MainWindow::on_pushButton_2_clicked()
{
    scenegraphic::setEdgeButtonActive();
    scenegraphic::setNodeButtonDeactive();
    scenegraphic::setSelectButtonDeactive();
     scenegraphic::setCalDeactive();
    scenegraphic::setFinalButtonDeactive();
    scenegraphic::setInitialButtonDeactive();
}

void MainWindow::on_pushButton_3_clicked()
{
    scenegraphic::setSelectButtonActive();
    scenegraphic::setEdgeButtonDeactive();
    scenegraphic::setNodeButtonDeactive();
     scenegraphic::setCalDeactive();
    scenegraphic::setFinalButtonDeactive();
    scenegraphic::setInitialButtonDeactive();
}

//void MainWindow::on_pushButton_4_clicked()
//{
//    scenegraphic::setInitialButtonActive();
//    scenegraphic::setEdgeButtonDeactive();
//    scenegraphic::setSelectButtonDeactive();
//    scenegraphic::setFinalButtonDeactive();
//    scenegraphic::setNodeButtonDeactive();
//}

//void MainWindow::on_pushButton_5_clicked()
//{
//    scenegraphic::setFinalButtonActive();
//    scenegraphic::setEdgeButtonDeactive();
//    scenegraphic::setSelectButtonDeactive();
//    scenegraphic::setFinalButtonDeactive();
//    scenegraphic::setNodeButtonDeactive();
//}

//void MainWindow::on_pushButton_6_clicked()
//{

//}


void MainWindow::on_actionGet_Input_triggered()
{


    scenegraphic::setEdgeButtonDeactive();
    scenegraphic::setNodeButtonDeactive();
    scenegraphic::setFinalButtonDeactive();
    scenegraphic::setSelectButtonDeactive();
    scenegraphic::setInitialButtonDeactive();
    scenegraphic::setFinalButtonDeactive();
    scenegraphic::setGetInputActive();
     scenegraphic::setCalDeactive();



}
// select start Node
void MainWindow::on_pushButton_6_clicked()
{
    scenegraphic::setEdgeButtonDeactive();
    scenegraphic::setNodeButtonDeactive();
    scenegraphic::setFinalButtonDeactive();
    scenegraphic::setSelectButtonDeactive();
    scenegraphic::setInitialButtonActive();
    scenegraphic::setCalDeactive();


}

//cal button

void MainWindow::on_pushButton_7_clicked()
{
    scenegraphic::setEdgeButtonDeactive();
    scenegraphic::setNodeButtonDeactive();
    scenegraphic::setFinalButtonDeactive();
    scenegraphic::setSelectButtonDeactive();
    scenegraphic::setInitialButtonDeactive();
    scenegraphic::setCalActive();
    if(scenegraphic::GetDfaMachine()){
        line=new QLineEdit;

        QPoint start(200,400);
        line->setFixedWidth(500);

    line->setWindowTitle("ورودی مورد نظر به ماشین تورینگ را وارد کنید:");

         line->move(mapFromGlobal(start));
        line->setVisible(true);

    //    connect(li,SIGNAL(returnPressed()),this,SLOT(HandleInputCheck()));
       connect(line,SIGNAL(returnPressed()),this,SLOT(HandleInputCheck()));



    }
    else {
        QLabel * label=new QLabel;
        label->setWindowTitle("خطا");
        label->move(350,400);


        label->setText("ابتدا یک ماشین ترسیم کنید!");
        label->setVisible(true);

    }



}

void MainWindow::HandleInputCheck(){

   QString st=line->text();
    InputForCheck=st;
    line->setVisible(false);
    if(scenegraphic:: GetDfaMachine()->checkInput(InputForCheck)){
        QLabel * lab=new QLabel;
         lab->move(350,400);
          li->setWindowTitle("بررسی ورودی ها:");
        lab->setText("Accept!!!!");
        lab->setVisible(true);
    }
    else {
        QLabel * lab=new QLabel;
        lab->setText("Reject!!!!");
        li->setWindowTitle("بررسی ورودی ها:");
        lab->move(350,400);
        lab->setVisible(true);

    }







}

//select final node

void MainWindow::on_pushButton_5_clicked()
{
    scenegraphic::setEdgeButtonDeactive();
    scenegraphic::setNodeButtonDeactive();
    scenegraphic::setFinalButtonDeactive();
    scenegraphic::setSelectButtonDeactive();
    scenegraphic::setInitialButtonDeactive();
    scenegraphic::setCalDeactive();
    scenegraphic::setFinalButtonActive();




}
