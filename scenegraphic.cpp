#include "scenegraphic.h"
#include"node.hpp"
#include<iostream>
#include <QLineEdit>
#include<string>

scenegraphic::scenegraphic(QWidget* parent):QGraphicsView (parent) {
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-400, -400, 800, 800);
    setScene(scene);
    this->scene = scene;
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
}

scenegraphic::~scenegraphic(){
}


Node * scenegraphic::isInAnyCircle(QPointF point){
    std::cout << "Silam " <<  point.x()  << " " <<  point.y() << std::endl;
    const QList<QGraphicsItem *> items = scene->items();
    for (QGraphicsItem *item : items) {
        if( Node * node = qgraphicsitem_cast<Node*>(item) ){
            qreal xc = node->get_X() + RAD/2;
            qreal yc= node->get_Y() + RAD/2;
            qreal xp = point.x();
            qreal yp = point.y();
            std::cout << "***: " << sqrt(pow(xc-xp,2)+pow(yc-yp,2)) << std::endl;
            if(sqrt(pow(xc-xp,2)+pow(yc-yp,2)) <= RAD/2 ){
                return node;
            }

        }
    }
    return nullptr;

}

Node * scenegraphic::isInAnyNode(QPointF point ){
    const QList<QGraphicsItem *> items = scene->items();
    for (QGraphicsItem *item : items) {
        if( Node * node = qgraphicsitem_cast<Node*>(item) ){
            qreal xc = node->get_X() + RAD/2;
            qreal yc= node->get_Y() + RAD/2;
            qreal xp = point.x();
            qreal yp = point.y();
            std::cout << "***: " << sqrt(pow(xc-xp,2)+pow(yc-yp,2)) << std::endl;
            if(sqrt(pow(xc-xp,2)+pow(yc-yp,2)) < RAD ){
                return node;
            }

        }
    }
    return nullptr;
}

void scenegraphic::mousePressEvent(QMouseEvent *event){
    QPointF scenePt = mapToScene(event->pos());
    std::cout << "x-p:" << scenePt.x() << "y-p:" <<scenePt.y()<<std::endl;

    if(scenegraphic::isNodeButtonActived()){
        QPointF scenePt = mapToScene(event->pos());
        std::cout<<scenePt.x()<<std::endl<<scenePt.y()<<std::endl;
        if(event->buttons() & Qt::LeftButton){
            Node *node=new Node();
            //set x and y to node object
            node->set_X(scenePt.x() - RAD/2);
            node->set_Y(scenePt.y() - RAD/2);
            if ( !isInAnyNode( node->getCenterPoint() ) )
            scene->addItem(node);
        }
    }

    if ( scenegraphic::isEdgeButtonActived() ){
        std::cout<<"silam gholam$$$$$$$$$"<<std::endl;
        if ( Node* node = isInAnyCircle( scenePt ) ){
            std::cout<<"silam gholam"<<std::endl;
            isPressedAnyCircle = node;

            this->firstPoint.setX( node->get_X() );
            this->firstPoint.setY( node->get_Y() );
        }
    }

    const QList<QGraphicsItem *> items = scene->items();
    for (QGraphicsItem *item : items) {

        if (Node * node = qgraphicsitem_cast<Node *>(item))
            std::cout << "x-:" << node->get_X() << "y:" << node->get_Y() << std::endl;

    }
    // drag and drop
    if(scenegraphic::GetDragAndDrop()){
     if ( Node* node = isInAnyCircle( scenePt ) ){

          selectedNode=node;
          selectedNode->set_X(scenePt.x());
          selectedNode->set_Y(scenePt.y());
          scene->update();
       }

    }

    if(isDrag){
        selectedNode->set_X(scenePt.x());
        selectedNode->set_Y(scenePt.y());
//        setDragAndDropDeactive();
        isDrag=false;
        selectedNode=nullptr;

    }
    ///////////////////////////*///////////////


}

void scenegraphic::mouseReleaseEvent(QMouseEvent *event){
    QPointF scenePt = mapToScene(event->pos());
    std::cout << "x-r:" << scenePt.x()<< " y-r:" <<scenePt.y()<<std::endl;
    //check select node
    const QList<QGraphicsItem *> items = scene->items();
    for (QGraphicsItem *item : items) {
        if (Node * node = qgraphicsitem_cast<Node *>(item))
            std::cout << "x:" << node->get_X() << "y:" << node->get_Y() << std::endl;
    }



    if ( scenegraphic::isEdgeButtonActived() ){
      if ( Node* sourceNode = isPressedAnyCircle ){
          if ( Node * destNode = isInAnyCircle( scenePt ) ){

              QPen pen;
              secondPoint.setX( destNode->get_X() + RAD/2 );
              secondPoint.setY( destNode->get_Y() + RAD/2 );
              scene->addItem( new Edge( sourceNode ,destNode ));
              li=new QLineEdit;
              scene->addWidget(li);
              li->resize(120,20);
              li->move(firstPoint.x()+50,firstPoint.y());
              li->setFocus();
         connect(li,SIGNAL(returnPressed()),this,SLOT(customSlot()));




//              scene->addLine(firstPoint.x()+ RAD/2,firstPoint.y()+ RAD/2,secondPoint.x(),secondPoint.y());
                scene->update();
//                delete li;

          }
          isPressedAnyCircle = nullptr;
      }

    }

//     QGraphicsItem *foundItem = itemAt(event->pos());
//     if(foundItem && currentDraggedItem &&
//            foundItem != currentDraggedItem)
//         {
//            std::cout<<"helpppppdddwdp"<<std::endl;
//            scene->update();
//         }






}

QGraphicsScene* scenegraphic::getScene() {
    return  scene;
}

QPainter* scenegraphic::GetPaint(QPainter *painter){
    return painter;
}

void scenegraphic::mouseMoveEvent(QMouseEvent *event){

    if(GetDragAndDrop()){
        setNodeButtonDeactive();
        setEdgeButtonDeactive();

        if(selectedNode){
            QPointF scenePt = mapToScene( event->pos() );
           auto p=  mapToGlobal( QCursor::pos());
            isDrag=true;
           selectedNode->set_X(scenePt.x());
           selectedNode->set_Y(scenePt.y());

           scene->update();
        }



    }


}


//Active deActive Button
void scenegraphic::setNodeButtonActive(){
    scenegraphic::nodeButtonActived = true;
}

void scenegraphic::setNodeButtonDeactive(){
    scenegraphic::nodeButtonActived = false;
}

bool scenegraphic::isNodeButtonActived(){
    return scenegraphic::nodeButtonActived;
}

bool scenegraphic::nodeButtonActived = false;

void scenegraphic::setEdgeButtonActive(){
    scenegraphic::edgeButtonActived = true;
}

void scenegraphic::setEdgeButtonDeactive(){
    scenegraphic::edgeButtonActived = false;
}

bool scenegraphic::isEdgeButtonActived(){
    return scenegraphic::edgeButtonActived;
}

bool scenegraphic::edgeButtonActived = false;

bool scenegraphic::dragAndDrop=false;

bool scenegraphic::GetDragAndDrop(){
    return scenegraphic::dragAndDrop;
}
void scenegraphic::DragAndDropActived(){
    scenegraphic::dragAndDrop=true;
}


void scenegraphic::setDragAndDropDeactive(){
    scenegraphic::dragAndDrop=false;
}


void scenegraphic::customSlot()
{
 QString st=li->text();

 std::string utf8_text = st.toUtf8().constData();

   std::cout<<utf8_text<<std::endl;
    li->setVisible(false);


}

