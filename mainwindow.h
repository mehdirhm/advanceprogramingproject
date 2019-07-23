#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include<QPainter>
#include<QPaintEvent>
#include<QLineEdit>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:


    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void handleInput();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

//    void on_pushButton_4_clicked();

//    void on_pushButton_5_clicked();

//    void on_pushButton_6_clicked();

    void on_actionGet_Input_triggered();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene * scene;
    QLineEdit *li;
    QString input;
};

#endif // MAINWINDOW_H
