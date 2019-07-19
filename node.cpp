#include "node.hpp"
#include"edge.hpp"
#include"scenegraphic.h"
#include "mainwindow.h"
#include<QPainter>
#define RAD 40


Node::Node()
    : QGraphicsItem ()
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
//    setCacheMode(DeviceCoordinateCache);
//    setZValue(-1);
}

void Node::AddEdge(Edge *edge){
    Edges<<edge;
}

QList<Edge *> Node::edges() const
{
    return Edges;
}


void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    QRectF rect = boundingRect();
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(QPen(Qt::black, 3, Qt::DashDotLine ,Qt::RoundCap));
    painter->setBrush(QBrush(Qt::green, Qt::SolidPattern));
    painter->drawEllipse(rect);
    this->x = center.x() + RAD / 2;
    this->y = center.y() + RAD / 2;
}

QRectF Node::boundingRect() const
{
    return QRectF(center.x() ,center.y() ,RAD ,RAD );
}

void Node::set_X(float x){
    center.setX( x );
}
void Node::set_Y(float y){
    center.setY( y );
}
float Node::get_X(void){
    return center.x();
}
float Node::get_Y(void){
    return center.y();
}

void Node::addEdge(Edge *edge)
{
    Edges << edge;

}

void Node::setCenterPoint(QPointF point ){
    this->center = point;
}

QPointF Node::getCenterPoint(){
    return this->center;
}



//QVariant Node::itemChange(GraphicsItemChange change, const QVariant &value)
//{


//}
