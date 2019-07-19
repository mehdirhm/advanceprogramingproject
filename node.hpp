#ifndef node_H
#define node_H
#define RAD 40


#include <vector>
#include <string>
#include<QList>
#include<QGraphicsView>
#include<QGraphicsItem>
class Edge;
class scenegraphic;

class Node: public QGraphicsItem
{
private:
    std::string name;


    QList<Edge * > Edges;
    scenegraphic *sc;

    QPointF center;
    float x;
    float y;
protected:

    // overriding mouse events
    //     void mousePressEvent(QGraphicsSceneMouseEvent *event);

    //     void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
public:
    Node();

    void set_X(float x);
    void set_Y(float y);
    float  get_X(void);
    float  get_Y(void);
    void setCenterPoint( QPointF );
    QPointF getCenterPoint( void );

    void addEdge(Edge *edge);

    QRectF boundingRect() const;
    void AddEdge(Edge *);
    QList<Edge *> edges() const;
    QList< std::multimap<std::string,Node>> GetEdges();
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    //virtual void draw( QPainter );
    //     Node(scenegraphic *);
};






















#endif // node_H
