#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"machine.hpp"
#include"dfa.hpp"
#include<QMouseEvent>
#include<QLineEdit>

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
//    scenegraphic::setFinalButtonDeactive();
//    scenegraphic::setInitialButtonDeactive();
}

void MainWindow::on_pushButton_3_clicked()
{
    scenegraphic::setSelectButtonActive();
    scenegraphic::setEdgeButtonDeactive();
    scenegraphic::setNodeButtonDeactive();
//    scenegraphic::setFinalButtonDeactive();
//    scenegraphic::setInitialButtonDeactive();
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
void MainWindow::handleInput(){





}

void MainWindow::on_actionGet_Input_triggered()
{


    scenegraphic::setEdgeButtonDeactive();
    scenegraphic::setNodeButtonDeactive();
    scenegraphic::setFinalButtonDeactive();
    scenegraphic::setSelectButtonDeactive();
    scenegraphic::setInitialButtonDeactive();
    scenegraphic::setFinalButtonDeactive();
    scenegraphic::setGetInputActive();



}

void MainWindow::on_pushButton_6_clicked()
{
    scenegraphic::setEdgeButtonDeactive();
    scenegraphic::setNodeButtonDeactive();
    scenegraphic::setFinalButtonDeactive();
    scenegraphic::setSelectButtonDeactive();
    scenegraphic::setInitialButtonActive();


}
