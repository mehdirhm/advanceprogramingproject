
#include "./dfa.hpp"
#include "edge.hpp"
#include<iostream>


DFA::DFA(){

}


bool DFA::checkInput(QString input){

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
        while(counter_for_input<input.length()){
    //std::cout<<final->getEdges().length()<<std::endl;
            std::cout<<currentNode->getNameNode().toUtf8().constData()<<std::endl;
            std::cout<<"i is:"<<i<<std::endl;
            for(Edge * edge : currentNode->getEdges()){

                std::cout<<"value of edge:"<<edge->GetEdgeValue().toUtf8().constData()<<std::endl;


          if(edge->GetEdgeValue()==input[i]){



                  currentNode=edge->getDestNode();


//                    break;



            }

            }
            i++;

            counter_for_input++;

       }








        for(Node * node : final){
            if(currentNode==node){
                std::cout<<"accept"<<std::endl;
                return true;
            }






        }

        return false;







//        if(currentNode!=final){
//            std::cout<<"reject"<<std::endl;
//            return false;
//        }


    }


