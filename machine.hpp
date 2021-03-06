#ifndef MACHINE_H
#define MACHINE_H

#include "node.hpp"
#include <vector>
#include <QList>

namespace AM {
    class Machine
    {
        protected:
        QList<Node*> nodes;
        Node* currentNode;
        Node* startNode=nullptr;
        QList <Node *> final;
    public:

        Machine();

        Machine( Node* ,QList<Node*>  );
        virtual ~Machine(){
            delete currentNode;
            delete startNode;
//            delete final;
            nodes.clear();

        };

        void setStartNode( Node * );

        void  setCurrentNode( Node* );
       void setFinalNode(Node *);



        void addNode(Node *);


    };
}

#endif // MACHINE_H
