
#include "./dfa.hpp"
#include "edge.hpp"
#include<iostream>


DFA::DFA(){

}


void DFA::checkInput(QString input){
    int counter_for_input=0;
    int i=0;

    for (Node * node : nodes){

        if(node->getIsStart()){
            startNode=node;



        }
    }

//    while (counter_for_input<input.length()){
//        std::cout<<"slmmmmmm"<<std::endl;
//        currentNode=startNode;
currentNode=startNode;
//std::cout<<startNode->getNameNode().toUtf8().constData()<<std::endl;
//std::cout<<final->getNameNode().toUtf8().constData()<<std::endl;
 std::cout<<input.toUtf8().constData()<<std::endl;
        while(counter_for_input<5){
    //std::cout<<final->getEdges().length()<<std::endl;
            for(Edge * edge : currentNode->getEdges()){


          if(edge->GetEdgeValue()==input.at(i)){


              std::cout<<edge->GetEdgeValue().toUtf8().constData()<<std::endl;

                  currentNode=edge->getDestNode();

                    std::cout<<currentNode->getNameNode().toUtf8().constData()<<std::endl;
                    break;



                }
                i++;
            }

            counter_for_input++;

       }

        if(currentNode==final){
            std::cout<<"accept"<<std::endl;
        }
        if(currentNode!=final){
            std::cout<<"reject"<<std::endl;
        }


    }


