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
#include <QLineEdit>

class scenegraphic:public QGraphicsView
{
    Q_OBJECT

public:

    void ManageInput();
    QPainter* GetPaint(QPainter *p );
    scenegraphic(QWidget *parent = 0);
    virtual ~scenegraphic();
    QGraphicsScene* getScene();

    static void setNodeButtonActive();
    static void setNodeButtonDeactive();
    static bool isNodeButtonActived();

    static void setEdgeButtonActive();
    static void setEdgeButtonDeactive();
    static bool isEdgeButtonActived();

    static bool GetDragAndDrop();

    static void setDragAndDropDeactive();

    static void DragAndDropActived();
    Node * isInAnyCircle(QPointF);
    Node* isInAnyNode( QPointF);

protected:
    void mouseReleaseEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);


private slots:
    void customSlot();
private:
     QLineEdit * li;
    static bool edgeButtonActived;
    static bool nodeButtonActived;
    static bool dragAndDrop;
    bool isDrag=false;
    QGraphicsScene* scene;
    QPointF firstPoint;
    QPointF secondPoint;
    QPainter pa;
    Node *isPressedAnyCircle;
   QGraphicsItem* currentDraggedItem ;
   Node * selectedNode=nullptr;

};

#endif
