#include "./edge.hpp"
#define M_PI 3.14
#include <math.h>
#include <iostream>
#include <QTextItem>
Edge::Edge( Node* sourceNode ,Node* destNode ):QGraphicsItem ( nullptr ),arrowSize(10){
    this->sourceNode = sourceNode;
    this->destNode = destNode;
    sourcePoint = sourceNode->getCenterPoint();
    destPoint = destNode->getCenterPoint();
   sourceNode->addEdge( this );
//    destNode->addEdge( this );
//    setFlag(ItemIsMovable);
//    setFlag(ItemSendsGeometryChanges);
//    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);
}


void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{





if ( sourceNode == destNode ){
    QPointF edgeCenter = sourcePoint - QPointF( 0 ,RAD/2 );
    painter->drawEllipse( edgeCenter ,RAD/2 ,RAD/2 );
    QPointF d(0,+25);
    painter->drawText(edgeCenter-d,edgeValue);
    QPointF arrowPoint = edgeCenter + QPointF( RAD/2*cos( M_PI/6 ) ,RAD/2*sin( M_PI/6));
    painter->setPen( QPen(Qt::blue));

    QPointF firstArrow = edgeCenter + QPointF( (RAD/2 - 5) *cos(M_PI/18) ,(RAD/2 - 5) *sin(M_PI/18) );
    QPointF secondArrow = edgeCenter + QPointF( (RAD/2 +5) *cos(M_PI/18) ,(RAD/2 + 5) *sin(M_PI/18) );
    painter->setBrush( QBrush(Qt::red));
    painter->drawPolygon( QPolygonF() << firstArrow << secondArrow << arrowPoint );
    return;
}


    QLineF line(sourcePoint, destPoint);

QLineF lin(sourceNode->getCenterPoint(),destNode->getCenterPoint());
update();

    // Draw the line itself
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    painter->drawLine(line);





painter->drawText(lin.center(),edgeValue);

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

//    painter->drawRect( boundingRect() );
    painter->setBrush(Qt::red);
    painter->drawPolygon(QPolygonF() << line.p2() << destArrowP1 << destArrowP2);

}

QRectF Edge::boundingRect() const
{
    qreal penWidth = 1;
    qreal extra = (penWidth + arrowSize) / 2.0;
    if ( sourceNode == destNode ){
        return QRectF( sourcePoint.x() - RAD/2 ,sourcePoint.y() - RAD ,RAD ,RAD )
               .adjusted( -extra, -extra, extra, extra);
    }

  /*!important*/  return QRectF(sourcePoint, QSizeF(destPoint.x() - sourcePoint.x(),
                                      destPoint.y() - sourcePoint.y()))
        .normalized()
      .adjusted(-extra, -extra, extra, extra);

}

void Edge::adjust()
{
    //adjust to sourcePoint and destPoint
    if ( sourceNode == destNode ){
        sourcePoint = destPoint = sourceNode->getCenterPoint();
        return;
    }

    QLineF line( sourceNode->getCenterPoint() ,destNode->getCenterPoint() );
    qreal length = line.length();

    prepareGeometryChange();

        QPointF edgeOffset((line.dx() * 10) / length, (line.dy() * 10) / length);
        sourcePoint = line.p1() + 2*edgeOffset;
        destPoint   = line.p2() - 2*edgeOffset;
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


    edgeValue=s;



};


QString Edge::GetEdgeValue(){
    return edgeValue;
}



