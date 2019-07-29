#ifndef EDGE_H
#define EDGE_H

#include"node.hpp"
#include<QList>
#include <QGraphicsItem>
#include<QGraphicsView>
#include<QString>

class Edge:public QGraphicsItem
{
private:
    Node* sourceNode;
    Node* destNode;
    QPointF sourcePoint;
    QPointF destPoint;
    qreal arrowSize;
    QString edgeValue;
    bool isDup;
      bool likeEdge ;
        unsigned int checkForSameEdgeCounter;


protected:
      QPainterPath shape() const override;
//      enum Type { Line ,SameLine ,Ellipse ,SameEllipse };
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
public:
    Edge( Node* ,Node* );
    ~Edge(){
        delete sourceNode;
        delete destNode;

    }

    void checkForSameEdge( QPainter* );

    Node* getSourceNode() const;
    Node* getDestNode() const;
    void setSourceNode( Node* );
    void setDestNode( Node* );
    void addText( QString);
    void adjust();
    QString GetEdgeValue();
    void handleCheckDupLine();
    void setTrueDup();
    bool GetDupBool();
   QPointF CenterOfLine(void)const ;
   QPointF getSourcePoint(){

       return sourcePoint;
   };

   QPointF getDestPoint(){

       return destPoint;
   };

};




#endif // EDGE_H
