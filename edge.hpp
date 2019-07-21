#ifndef EDGE_H
#define EDGE_H

#include"node.hpp"
#include<QList>
#include <QGraphicsItem>
#include<QGraphicsView>

class Edge:public QGraphicsItem
{
private:
    Node* sourceNode;
    Node* destNode;
    QPointF sourcePoint;
    QPointF destPoint;
    qreal arrowSize;
   QString str;
    QList <QString>inputs;

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
public:
    Edge( Node* ,Node* );
    ~Edge(){
        delete sourceNode;
        delete destNode;

    }

    Node* getSourceNode() const;
    Node* getDestNode() const;
    void setSourceNode( Node* );
    void setDestNode( Node* );
    void addInput(QString );
   void addText( QString);
    void adjust();
};




#endif // EDGE_H
