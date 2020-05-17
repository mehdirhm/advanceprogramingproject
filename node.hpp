#ifndef node_H
#define node_H
#define RAD 40


#include <vector>
#include <string>
#include<QList>
#include<QGraphicsView>
#include <QGraphicsItem>


class Edge;
class scenegraphic;

class Node: public QGraphicsItem
{
private:
    bool isStart=false;
    bool isFinal=false;
    QString s;


    QList<Edge * > edgeList;
    QPointF center;
static int counter;

public:
void setNameNode(QString name){
    s=name;

}
int getLenth(){
    return edgeList.length();
}

QString getNameNode(){
    return s;
}

void setIsStart(){

    isStart=true;



}
void setIsFinal(){

    isFinal=true;

}

bool getIsFinal(){

    return isFinal;
}

bool getIsStart(){

    return isStart;
}

    Node( qreal ,qreal );
    ~Node(){
        edgeList.clear();
    }


    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    void set_X(qreal x);
    void set_Y(qreal y);
    qreal  get_X(void);
    qreal  get_Y(void);
    void setCenterPoint( QPointF );
    QPointF getCenterPoint( void );
 static void AddCounter();

 static  int getCounter();
    void addEdge(Edge *edge);

    QList< Edge* > getEdges();
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};






















#endif // node_H
