#include "./edge.hpp"
#include <iostream>
Edge::Edge( Node* sourceNode ,Node* destNode ):QGraphicsLineItem ( nullptr ){
    this->sourceNode = sourceNode;
    this->destNode = destNode;
//    setFlag(ItemIsMovable);
//    setFlag(ItemSendsGeometryChanges);
//    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);
    QLineF line( sourceNode->getCenterPoint() ,destNode->getCenterPoint() );
    setLine( line );
    sourceNode->addEdge(this);
    destNode->addEdge(this);
}


void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    painter->setRenderHint(QPainter::Antialiasing, true);
//    painter->setPen(QPen(Qt::black, 3, Qt::DashLine ,Qt::RoundCap));
    painter->setBrush(QBrush(Qt::green, Qt::SolidPattern));
    painter->drawLine( sourceNode->getCenterPoint().x()+RAD/2,sourceNode->getCenterPoint().y()+RAD/2 ,destNode->getCenterPoint().x()+RAD/2,destNode->getCenterPoint().y()+RAD/2 );
    update();
}

void Edge::addInput(QString * s){
inputs<<s;
////

}

