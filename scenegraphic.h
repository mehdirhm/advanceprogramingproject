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
#include"machine.hpp"
#include <dfa.hpp>


class scenegraphic:public QGraphicsView
{
    Q_OBJECT

public:
    scenegraphic(QWidget *parent = 0);
    ~scenegraphic(){
        delete li;
        delete tempLine;
        delete scene;

        delete isPressedAnyCircle;
        delete ed;
        delete dfa;
        delete finalNode;
        delete startNode;
        delete line;

        nodes.clear();
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

    static void setGetInputActive();
    static void setGetInputDeactive();
    static bool isGetinput();


    static void setCalActive();
    static void setCalDeactive();
    static bool IsCal();




    Node* isInAnyCircle(QPointF);
    Node* isInAnyNode( QPointF);
  QList <Node *> nodes;
  bool GetIsDfa(){
      return DfaMachine;
  }

protected:
    void mouseReleaseEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

       void zoomIn();
       void zoomOut();
       void wheelEvent(QWheelEvent *event) override;
       void MeasureViewScene(qreal scaleMeasure);

private slots:
    void customSlot();
//    void handleInput();
private:
    static bool edgeButtonActived;
    static bool nodeButtonActived;
    static bool selectButtonActived;
    static bool finalButtonActived;
    static bool initialButtonActived;
    static bool SelectStartNode;
    static bool Getinput;

    static bool calculate;
    QLineEdit *li=nullptr;
    QLineEdit *line=nullptr;
    QGraphicsLineItem* tempLine=nullptr;
    QGraphicsScene* scene=nullptr;
//    QPainter* painter=nullptr;
    Node *isPressedAnyCircle=nullptr;
    Edge* ed=nullptr;
    Node *startNode=nullptr;
    Node *finalNode=nullptr;
    bool DfaMachine=true;
    DFA *dfa=nullptr;

//    DFA *dfa;



};

#endif
