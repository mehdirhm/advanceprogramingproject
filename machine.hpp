#ifndef MACHINE_H
#define MACHINE_H

#include "node.hpp"
#include <vector>
#include <QList>

namespace AM {
    class Machine
    {
    private:
        QList<Node*> nodes;
        Node* currentNode;
        Node* startNode;
        QList<Node*> finalNodes;
    public:
        Machine( Node* ,QList<Node*> ,QList<Node*> );
        virtual ~Machine(){
            delete currentNode;
            delete startNode;
        };

        Node* getStartNode( void );
        QList<Node*>  getFinalNodes( void );
        void  setCurrentNode( Node* );

        const QList<Node *> getNodes( void );
    };
}

#endif // MACHINE_H
