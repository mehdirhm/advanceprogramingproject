#include "node.hpp"
#include"edge.hpp"
#include"scenegraphic.h"
#include "mainwindow.h"
#include<QPainter>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#define RAD 35


Node::Node( qreal x, qreal y )
    : QGraphicsItem ( nullptr )
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    center.setX( x );
    center.setY( y );
}

QRectF Node::boundingRect() const {
    QRectF rect( center.x() -RAD/2 ,center.y() - RAD/2 ,RAD ,RAD );
    return rect;
}

QPainterPath Node::shape() const
{
    QPainterPath path;
    path.addEllipse( center ,RAD/2 ,RAD/2 );
    return path;
}

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    painter->setRenderHint(QPainter::Antialiasing, true);
//    painter->setPen(QPen(Qt::black, 3, Qt::DashDotLine ,Qt::RoundCap));
    painter->setBrush(QBrush(Qt::green, Qt::SolidPattern));
    painter->drawEllipse( boundingRect() );
    painter->setBrush(QBrush() );

}

void Node::addEdge(Edge *edge)
{
    edgeList << edge;
    edge->adjust();
}

QList < Edge* > Node::getEdges(){
    return edgeList;
}

QVariant Node::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        for (Edge *edge : qAsConst(edgeList))
            edge->adjust();
        break;
    default:
        break;
    };
    return QGraphicsItem::itemChange(change, value);
}

void Node::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}


void Node::set_X(qreal x){
    center.setX( x );
}

void Node::set_Y(qreal y){
    center.setY( y );
}

qreal Node::get_X(void){
    return center.x();
}
qreal Node::get_Y(void){
    return center.y();
}

void Node::setCenterPoint(QPointF point ){
    this->center = point;
}

QPointF Node::getCenterPoint(){
    return this->center;
}
