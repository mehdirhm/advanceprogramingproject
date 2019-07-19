#ifndef EDGE_H
#define EDGE_H

#include"node.hpp"
#include<map>
#include<QList>

class Edge:public QGraphicsLineItem
{



private:
    Node* sourceNode;
    Node* destNode;
    QList  <QString *> inputs;

public:
    Edge( Node* ,Node* );
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
    void addInput(QString *);


};




#endif // EDGE_H
