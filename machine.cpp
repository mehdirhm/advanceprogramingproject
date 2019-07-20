#include "node.hpp"
#include "machine.hpp"
#include <vector>
#include <QList>

AM::Machine::Machine( Node* sNode ,QList<Node*> fNodes ,QList<Node*> nodes){
    startNode = sNode;
    setCurrentNode( sNode );
    this->finalNodes = fNodes;
    this->nodes = nodes;
}



Node* AM::Machine::getStartNode( void ){
    return startNode;
}

QList<Node*> AM::Machine::getFinalNodes( void ){
    return nodes;
}

void AM::Machine::setCurrentNode( Node* node){
    currentNode = node;
}






