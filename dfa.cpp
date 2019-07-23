
#include "./dfa.hpp"
#include "edge.hpp"


DFA::DFA(){

}


void DFA::checkInput(QString input){
    int counter_for_input=0;
    int i=0;
    while (counter_for_input==input.length()){

        for (Node * node : nodes){
            if(node->getIsStart()){
                for(Edge * edge : node->getEdges()){
                    if(edge->GetEdgeValue()==input[i]){


                    }
                }
            }
        }
    }

}
