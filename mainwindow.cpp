#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"machine.hpp"
#include"dfa.hpp"
#include<QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    scenegraphic::setNodeButtonActive();
    scenegraphic::setEdgeButtonDeactive();
    scenegraphic::setDragAndDropDeactive();
}

void MainWindow::on_pushButton_2_clicked()
{
    scenegraphic::setEdgeButtonActive();
    scenegraphic::setNodeButtonDeactive();
    scenegraphic::setDragAndDropDeactive();
}

void MainWindow::on_pushButton_3_clicked()
{
    scenegraphic::DragAndDropActived();
}


