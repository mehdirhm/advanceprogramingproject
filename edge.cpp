#include "./edge.hpp"
#define M_PI 3.14
#include <math.h>
#include <iostream>
#include <QTextItem>
Edge::Edge( Node* sourceNode ,Node* destNode ):QGraphicsItem ( nullptr ),arrowSize(10),isDup(false),likeEdge(false){
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



QPointF Edge::CenterOfLine(void)const {

    QLineF lina( sourceNode->getCenterPoint() ,destNode->getCenterPoint() );
    QLineF normalizeLina = lina.normalVector();
    normalizeLina.setLength( RAD );

    QLineF linb( destNode->getCenterPoint() ,sourceNode->getCenterPoint() );
    QLineF normalizeLineb = linb.normalVector();
    normalizeLineb.setLength(RAD );
    normalizeLineb.setAngle( normalizeLineb.angle() + 180 );

    QLineF center( normalizeLina.p2() ,normalizeLineb.p2() );

    return center.center();

}


void Edge::setTrueDup(){
    isDup=true;
}

bool Edge::GetDupBool(){
    return isDup;
}
void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{




    QList<Edge*> sourceEdges = sourceNode->getEdges();
    for ( Edge* edge : qAsConst(sourceEdges) ){

        QList<Edge*> destEdges = edge->getDestNode()->getEdges();
        for ( Edge* destEdge : qAsConst(destEdges) ){
            if ( destEdge->destNode == edge->sourceNode ) {
                destEdge->setTrueDup();
                edge->setTrueDup();
            }
        }

        ////checking for prevent repet edge
        if ( edge->destNode == this->destNode && edge != this ){
                if ( sourceNode == destNode ){
                    QLineF lin(sourceNode->getCenterPoint(),destNode->getCenterPoint());
                    painter->drawText(lin.center(),edgeValue);

                     update();
                }
                else {
                    QLineF line( sourcePoint ,destPoint );

                    painter->drawText( line.center() ,edgeValue);
                }
                likeEdge = true;

        }
    }


// checking duplicate edge and like edge for prevent repet
    if ( !likeEdge ){
        if ( sourceNode != destNode ){
            if ( GetDupBool() ) {

                QLineF line(CenterOfLine(), destPoint);
                painter->drawPath( shape() );
                painter->drawText( CenterOfLine() ,edgeValue );


                painter->setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));


                double angle = std::atan2(-line.dy(), line.dx());

                QPointF secoundArrowP1 = destPoint + QPointF(sin(angle - M_PI / 3) * arrowSize,
                                                          cos(angle - M_PI / 3) * arrowSize);
                QPointF secoundArrowP2 = destPoint + QPointF(sin(angle - M_PI + M_PI / 3) * arrowSize,
                                                          cos(angle - M_PI + M_PI / 3) * arrowSize);

                painter->drawLine(secoundArrowP1 , line.p2() );
                painter->drawLine(secoundArrowP2 , line.p2() );

                QList<Edge*> destEdges = this->destNode->getEdges();
                for ( Edge* edgeItem : qAsConst(destEdges) ){
                    edgeItem->update();
                }



            }
            else{
                QLineF line(sourcePoint, destPoint);



                painter->drawLine( sourcePoint ,destPoint );

                painter->setPen(QPen(Qt::red, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

                double angle = std::atan2(-line.dy(), line.dx());

                QPointF secoundArrowP1 = destPoint + QPointF(sin(angle - M_PI / 3) * arrowSize,
                                                          cos(angle - M_PI / 3) * arrowSize);
                QPointF secoundArrowP2 = destPoint + QPointF(sin(angle - M_PI + M_PI / 3) * arrowSize,
                                                          cos(angle - M_PI + M_PI / 3) * arrowSize);

                painter->drawLine(secoundArrowP1 , line.p2() );
                painter->drawLine(secoundArrowP2 , line.p2() );

                painter->setPen( QPen() );
                QLineF lin(sourceNode->getCenterPoint(),destNode->getCenterPoint());

                painter->drawText(lin.center(),edgeValue);

            } ;

        }

        if ( sourceNode == destNode )
        {
            QPointF edgeOfCenter = sourcePoint - QPointF( 0 ,RAD/2 );
            painter->drawEllipse( edgeOfCenter ,RAD/2 ,RAD/2 );
            QPointF d(0,+30);
            painter->drawText(edgeOfCenter-d,edgeValue);
            QPointF arrowPoint = edgeOfCenter + QPointF( RAD/2*cos( M_PI/6 ) ,RAD/2*sin( M_PI/6));
            painter->setPen( QPen(Qt::red));

            QPointF firstArrow = edgeOfCenter + QPointF( (RAD/2 - 5) *cos(M_PI/18) ,(RAD/2 - 5) *sin(M_PI/18) );
            QPointF secondArrow = edgeOfCenter + QPointF( (RAD/2 +5) *cos(M_PI/18) ,(RAD/2 + 5) *sin(M_PI/18) );
            painter->setBrush( QBrush(Qt::red));
            painter->drawPolygon( QPolygonF() << firstArrow << secondArrow << arrowPoint );
            return;
        }
    }






}

QPainterPath Edge::shape() const{
    QPainterPath path;
    path.moveTo( sourcePoint );
    QLineF line( sourcePoint ,destPoint );
    path.cubicTo( line.center() ,CenterOfLine() , destPoint );
    return path;
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
update();
    prepareGeometryChange();

        QPointF edgeOffset((line.dx() * 10) / length, (line.dy() * 10) / length);
        sourcePoint = line.p1() + 2*edgeOffset;
        update();
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



