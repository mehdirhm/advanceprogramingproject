#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include<QPainter>
#include<QPaintEvent>
#include<QLineEdit>
#include"dfa.hpp"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:


    static QString GetInputCheck(){
        return InputForCheck;
    }
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void handleInput();

private slots:
    void HandleInputCheck();

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

//    void on_pushButton_4_clicked();

//    void on_pushButton_5_clicked();

//    void on_pushButton_6_clicked();

    void on_actionGet_Input_triggered();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

private:
    static QString InputForCheck;
    Ui::MainWindow *ui;
    QGraphicsScene * scene;
    QLineEdit *li;
    QLineEdit *line=nullptr;
    QString input;

};

#endif // MAINWINDOW_H
