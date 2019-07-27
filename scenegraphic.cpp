#include "scenegraphic.h"
#include"node.hpp"
#include<iostream>
#include <machine.hpp>
#include<QScopedPointer>
#include"mainwindow.h"
#include"dfa.hpp"

bool scenegraphic::edgeButtonActived    = false;
bool scenegraphic::nodeButtonActived    = false;
bool scenegraphic::selectButtonActived  = false;
bool scenegraphic::initialButtonActived = false;
bool scenegraphic::finalButtonActived   = false;
bool scenegraphic::calculate=false;
DFA * scenegraphic::dfa=nullptr;


scenegraphic::scenegraphic(QWidget* parent):QGraphicsView (parent)
  , isPressedAnyCircle(nullptr),tempLine( nullptr ) {



    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-400, -400, 800, 800);
    setScene(scene);
    this->scene = scene;
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    scale(qreal(1), qreal(1));
    setMinimumSize(400, 400);


}

Node * scenegraphic::isInAnyCircle(QPointF point){
    const QList<QGraphicsItem *> items = scene->items();
    for (QGraphicsItem *item : items) {
        if( Node * node = qgraphicsitem_cast<Node*>(item) ){
            qreal xc = node->get_X();
            qreal yc = node->get_Y();
            qreal xp = point.x();
            qreal yp = point.y();
            if(sqrt(pow(xc-xp,2)+pow(yc-yp,2)) <= RAD/2 ){
                return node;
            }

        }
    }
    return nullptr;

}

Node* scenegraphic::isInAnyNode(QPointF point ){
    const QList<QGraphicsItem *> items = scene->items();
    for (QGraphicsItem *item : items) {
        if( Node* node = qgraphicsitem_cast<Node*>(item) ){
            qreal xc = node->get_X() ;
            qreal yc= node->get_Y() ;
            qreal xp = point.x();
            qreal yp = point.y();
            if(sqrt(pow(xc - xp,2)+pow(yc - yp,2)) < RAD ){
                return node;
            }

        }
    }
    return nullptr;
}

void scenegraphic::mousePressEvent(QMouseEvent *event){


    QPointF scenePt = mapToScene(event->pos());

    if ( scenegraphic::isNodeButtonActived()  ){

        QPointF scenePt = mapToScene(event->pos());
        if(event->buttons() & Qt::LeftButton){
         Node * node=new Node( scenePt.x() ,scenePt.y() );




            if ( !isInAnyNode( node->getCenterPoint() ) ){
            scene->addItem( node );
            if(GetIsDfa()){
                dfa=new DFA;
                dfa->addNode(node);





            }
//            machine->addNode(node);
//            dfa->addNode(startNode);
            nodes<<node;
            Node::AddCounter();



            scene->update();
//            std::cout<<node->getCounter()<<std::endl;


            }

        }


    }
    if ( scenegraphic::isEdgeButtonActived()  ){


            if ( Node* node = isInAnyCircle( scenePt ) ){
                isPressedAnyCircle = node;
            }




    }
    if ( scenegraphic::isSelectButtonActived()){
        if ( Node* node = isInAnyCircle( scenePt ) ){
            isPressedAnyCircle = node;
        }
    }


    scene->update();

    if(scenegraphic::isInitialButtonActived()){
        if ( Node* node = isInAnyCircle( scenePt ) ){
            startNode = node;
//            machine->setStartNode(startNode);
            startNode->setIsStart();
            if(GetIsDfa()){
                 dfa->setStartNode(startNode);
            }

            startNode->setSelected(true);
//            const QList<QGraphicsItem *> items = scene->items();
//            for (QGraphicsItem *item : items){
//                if(item->isSelected()){
//                    item->setFlag(QGraphicsItem::ItemIsSelectable,true);
//                }
//            }



        }

    }


    if(scenegraphic::finalButtonActived){
        if ( Node* node = isInAnyCircle( scenePt ) ){
            finalNode = node;
//            machine->setStartNode(startNode);
            finalNode->setIsFinal();
            if(GetIsDfa()){
                 dfa->setFinalNode(finalNode);
            }

            finalNode->setSelected(true);
//            const QList<QGraphicsItem *> items = scene->items();
//            for (QGraphicsItem *item : items){
//                if(item->isSelected()){
//                    item->setFlag(QGraphicsItem::ItemIsSelectable,true);
//                }
//            }



        }

    }

    if(isGetinput()){
        line=new QLineEdit;
        line->setVisible(true);

        connect(line,SIGNAL(returnPressed()),this,SLOT(handleInput()));

    }


    if(IsCal()){

//        dfa->checkInput(MainWindow::GetInputCheck());
    }
}

void scenegraphic::mouseReleaseEvent(QMouseEvent *event){
    QPointF scenePt = mapToScene(event->pos());

    if ( scenegraphic::isEdgeButtonActived() ){

            if ( Node* sourceNode = isPressedAnyCircle ){
                if ( Node * destNode = isInAnyCircle( scenePt ) ){
                    ed = new Edge( sourceNode ,destNode );
                     ed->adjust();
                    scene->addItem( ed );
                    edgeListView<<ed;
      //                sourceNode->addEdge(ed);

                    li=new QLineEdit;

                                 scene->addWidget(li);
                                 scenegraphic::setEdgeButtonDeactive();
                                 li->resize(120,20);
                                 QLine line(ed->getSourcePoint().x()+RAD/2,ed->getSourcePoint().y()+RAD/2,ed->getDestPoint().x()+RAD/2,ed->getDestPoint().y()+RAD/2);

//                                 QLine line(sourceNode->getCenterPoint().x()+RAD/2,sourceNode->getCenterPoint().y()+RAD/2 ,destNode->getCenterPoint().x()+RAD/2,destNode->getCenterPoint().y()+RAD/2);
                                 li->move(line.center());
                                li->setFocus();


                            connect(li,SIGNAL(returnPressed()),this,SLOT(customSlot()));



                }
                //Line which draw onTime
                scene->removeItem( tempLine );
                tempLine = nullptr;
                isPressedAnyCircle = nullptr;
            }




    }

    if ( scenegraphic::isSelectButtonActived() ){
        if ( isPressedAnyCircle ){
       isPressedAnyCircle->setCenterPoint( scenePt );
       QList <Edge*> edgelist = isPressedAnyCircle->getEdges();
       for ( Edge* edge : qAsConst(edgelist) ){
           edge->adjust();
       }
        }
       isPressedAnyCircle = nullptr;
    }

    scene->update();
}

void scenegraphic::mouseMoveEvent(QMouseEvent *event){
    QPointF scenePt = mapToScene( event->pos() );
    if ( scenegraphic::isSelectButtonActived() ){
        if ( isPressedAnyCircle ){
            isPressedAnyCircle->setCenterPoint( scenePt );
            QList <Edge*> edgelist = isPressedAnyCircle->getEdges();
            for ( Edge* edge : qAsConst(edgelist) ){
                edge->adjust();

            }
            for ( Edge* edgeView : qAsConst( edgeListView ) ){
                edgeView->adjust();
            }
        }
        scene->update();
    }

    if( scenegraphic::isEdgeButtonActived() ){


            if ( isPressedAnyCircle ){
                scene->removeItem( tempLine );
                tempLine = new QGraphicsLineItem( QLineF( isPressedAnyCircle->getCenterPoint() ,scenePt ) );
                scene->addItem( tempLine );
            }



    }

    scene-> update();

}





void scenegraphic::wheelEvent(QWheelEvent *event)
{
    MeasureViewScene(pow((double)2, -event->delta() / 220.0));
}


void scenegraphic::MeasureViewScene(qreal scaleMeasure)
{
    qreal measure = transform().scale(scaleMeasure, scaleMeasure).mapRect(QRectF(0, 0, 1, 1)).width();
    if (measure < 0.09 || measure > 100)
        return;

    scale(scaleMeasure, scaleMeasure);
}

void scenegraphic::zoomIn()
{
    MeasureViewScene(qreal(1.4));
}

void scenegraphic::zoomOut()
{
    MeasureViewScene(1 / qreal(1.4));
}

QGraphicsScene* scenegraphic::getScene() {
    return  scene;
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

void scenegraphic::setEdgeButtonActive(){
    scenegraphic::edgeButtonActived = true;
}

void scenegraphic::setEdgeButtonDeactive(){
    scenegraphic::edgeButtonActived = false;
}

bool scenegraphic::isEdgeButtonActived(){
    return scenegraphic::edgeButtonActived;
}

void scenegraphic::setSelectButtonActive(){
    scenegraphic::selectButtonActived = true;
}

void scenegraphic::setSelectButtonDeactive(){
    scenegraphic::selectButtonActived = false;
}

bool scenegraphic::isSelectButtonActived(){
    return scenegraphic::selectButtonActived;
}

void scenegraphic::setFinalButtonActive(){
    scenegraphic::finalButtonActived = true;
}

void scenegraphic::setFinalButtonDeactive(){
    scenegraphic::finalButtonActived = false;
}

bool scenegraphic::isFinalButtonActived(){
    return scenegraphic::finalButtonActived;
}

void scenegraphic::setInitialButtonActive(){
    scenegraphic::initialButtonActived = true;
}

void scenegraphic::setInitialButtonDeactive(){
    scenegraphic::initialButtonActived = false;
}

bool scenegraphic::isInitialButtonActived(){
    return scenegraphic::initialButtonActived;
}

bool scenegraphic::Getinput;
bool scenegraphic::isGetinput(){
    return Getinput;
}

void scenegraphic::setGetInputActive(){
    scenegraphic::Getinput=true;
}

void scenegraphic::setGetInputDeactive(){
    scenegraphic::Getinput=false;
}

void scenegraphic::setCalActive(){
    scenegraphic::calculate=true;

}
void scenegraphic::setCalDeactive(){
    scenegraphic::calculate=false;
}

bool scenegraphic::IsCal(){
    return scenegraphic::calculate;
}
void scenegraphic::customSlot()
{
 QString  st=li->text();

// std::string utf8_text = st.toUtf8().constData();
// std::string const_text = st.toUtf8().constData();
// QByteArray ba = st.toLocal8Bit();
//  const char *c_str2 = ba.data();

//while(st.isEmpty()){
//    checkEmptyLine=true;
//}



    li->setVisible(false);
    scenegraphic::setEdgeButtonActive();

ed->addText(st);



scene->update();



//    path.addText(firstPoint.x()+100,firstPoint.y(),font,tr(c_str2));



//  scene->addPath(path);


//  scene->update();




//    scene->update();




}
