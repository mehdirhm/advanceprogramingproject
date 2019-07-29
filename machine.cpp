#include "node.hpp"
#include "machine.hpp"
#include <vector>
#include <QList>

AM::Machine::Machine( Node* sNode ,QList<Node*> Nodes ){
    startNode = sNode;
    setCurrentNode( sNode );

    this->nodes = nodes;
}
AM::Machine::Machine(){

}



void AM::Machine::setStartNode( Node * node ){
    startNode=node;
}



void AM::Machine::setCurrentNode( Node* node){
    currentNode = node;
}


void AM::Machine::setFinalNode(Node * node){
    final << node;

}

void AM::Machine:: addNode(Node * node){
    nodes<<node;



}





