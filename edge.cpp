#include "./edge.hpp"
#define M_PI 3.14
#include <math.h>
#include <iostream>
#include <QTextItem>
Edge::Edge( Node* sourceNode ,Node* destNode ):QGraphicsItem ( nullptr ),arrowSize(20){
    this->sourceNode = sourceNode;
    this->destNode = destNode;
    sourcePoint = sourceNode->getCenterPoint();
    destPoint = destNode->getCenterPoint();
    sourceNode->addEdge( this );
    destNode->addEdge( this );
//    setFlag(ItemIsMovable);
//    setFlag(ItemSendsGeometryChanges);
//    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);
}


void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if (!sourceNode || !destNode )
        return;

    QLineF line(sourcePoint, destPoint);
    if (qFuzzyCompare(line.length(), qreal(0.))){
        //edge to itself
    }
QLineF lin(sourceNode->getCenterPoint(),destNode->getCenterPoint());
update();

    // Draw the line itself
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    painter->drawLine(line);





painter->drawText(lin.center(),str);

 update();

    // Draw the arrows
    double angle = std::atan2(-line.dy(), line.dx());

    QPointF sourceArrowP1 = sourcePoint + QPointF(sin(angle + M_PI / 3) * arrowSize,
                                                  cos(angle + M_PI / 3) * arrowSize);
    QPointF sourceArrowP2 = sourcePoint + QPointF(sin(angle + M_PI - M_PI / 3) * arrowSize,
                                                  cos(angle + M_PI - M_PI / 3) * arrowSize);
    QPointF destArrowP1 = destPoint + QPointF(sin(angle - M_PI / 3) * arrowSize,
                                              cos(angle - M_PI / 3) * arrowSize);
    QPointF destArrowP2 = destPoint + QPointF(sin(angle - M_PI + M_PI / 3 ) * arrowSize,
                                              cos(angle - M_PI + M_PI / 3) * arrowSize);

    painter->setBrush(Qt::red);
    painter->drawLine(sourceArrowP1 , line.p1() );
    painter->drawLine(sourceArrowP2 , line.p1() );
    painter->drawPolygon(QPolygonF() << line.p2() << destArrowP1 << destArrowP2);

}

QRectF Edge::boundingRect() const
{
    if (!sourceNode || !destNode)
        return QRectF();

//    qreal penWidth = 1;
//    qreal extra = (penWidth + arrowSize) / 2.0;

  /*!important*/  return QRectF(sourcePoint, QSizeF(destPoint.x() - sourcePoint.x(),
                                      destPoint.y() - sourcePoint.y()))
        .normalized();
//        .adjusted(-extra, -extra, extra, extra);

}

void Edge::adjust()
{
    if (!sourceNode || !destNode)
        return;

    QLineF line( sourceNode->getCenterPoint() ,destNode->getCenterPoint() );
    qreal length = line.length();

    prepareGeometryChange();

        QPointF edgeOffset((line.dx() * 10) / length, (line.dy() * 10) / length);
        sourcePoint = line.p1() + edgeOffset;
        destPoint = line.p2() - edgeOffset;
        update();
}


Node* Edge::getSourceNode() const
{
    return sourceNode;
}

Node* Edge::getDestNode() const
{
    return destNode;
}

void Edge::setSourceNode( Node* node ) {
    sourceNode = node;
}

void Edge::setDestNode( Node* node ) {
    destNode = node;
}
void Edge:: addText( QString s){
    str=s;


};

void Edge::addInput(QString  s){
inputs<<s;
////
////
}

