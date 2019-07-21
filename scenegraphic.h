#ifndef scenegraphic_H
#define scenegraphic_H

#define RAD 40
#include <QObject>
#include <QWidget>
#include<QGraphicsView>
#include<QPainter>
#include<iostream>
#include <math.h>
#include "node.hpp"
#include "edge.hpp"
#include<QLineEdit>

class scenegraphic:public QGraphicsView
{
    Q_OBJECT

public:
    scenegraphic(QWidget *parent = 0);
    ~scenegraphic(){
        delete li;
        delete tempLine;
        delete scene;
        delete painter;
        delete isPressedAnyCircle;
        delete ed;
    }
    QGraphicsScene* getScene();

    static void setNodeButtonActive();
    static void setNodeButtonDeactive();
    static bool isNodeButtonActived();

    static void setEdgeButtonActive();
    static void setEdgeButtonDeactive();
    static bool isEdgeButtonActived();

    static void setInitialButtonActive();
    static void setInitialButtonDeactive();
    static bool isInitialButtonActived();

    static void setSelectButtonActive();
    static void setSelectButtonDeactive();
    static bool isSelectButtonActived();

    static void setFinalButtonActive();
    static void setFinalButtonDeactive();
    static bool isFinalButtonActived();

    Node* isInAnyCircle(QPointF);
    Node* isInAnyNode( QPointF);

protected:
    void mouseReleaseEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private slots:
    void customSlot();
private:
    static bool edgeButtonActived;
    static bool nodeButtonActived;
    static bool selectButtonActived;
    static bool finalButtonActived;
    static bool initialButtonActived;
    QLineEdit *li;
    QGraphicsLineItem* tempLine;
    QGraphicsScene* scene;
    QPainter* painter;
    Node *isPressedAnyCircle;
    Edge* ed;

};

#endif
