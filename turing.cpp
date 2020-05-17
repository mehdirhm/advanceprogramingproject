#include "turing.hpp"
#include "edge.hpp"
#include <iostream>
Turing::Turing()
{

}



bool Turing::CheckInput(QString input){
    rightHalf[0]=input[0];
    leftHalf[0]=input[0];
    for (int i=1;i<input.length();i++) {
       rightHalf[i]=input[i];

    }



    for (Node * node : nodes){

        if(node->getIsStart()){
            startNode=node;



        }
    }


currentNode=startNode;
bool i=false;

do{


    for(Edge * edge : currentNode->getEdges()){


if(Head>=0){

  if(edge->GetEdgeValue()[0]==rightHalf[0]){
      i=true;

//if(edge->GetEdgeValue()[1]=="#"){
//    rightHalf[Head]=edge->GetEdgeValue()[1]

//}
      rightHalf[Head]=edge->GetEdgeValue()[1];

      if(edge->GetEdgeValue()[2]=='R'){

          Head++;
      }
      if(edge->GetEdgeValue()[2]=='L'){

          Head--;
      }


          prevNode=currentNode;
          currentNode=edge->getDestNode();


//


    }

  else {
      prevNode=currentNode;
  }

}

else {
Head=0;
if(edge->GetEdgeValue()[0]==leftHalf[0]){

leftHalf[Head]=edge->GetEdgeValue()[1];
if(edge->GetEdgeValue()[2]=='R'){

    Head++;
}
if(edge->GetEdgeValue()[2]=='L'){

    Head--;
}


    prevNode=currentNode;
    currentNode=edge->getDestNode();





//


}

else {
prevNode=currentNode;
}

}



    }

    if(i==false){
        return false;
    }


    if(currentNode->getIsFinal()){
        std::cout<<"Accept"<<std::endl;
        return true;
    }












return false;







}

        while(prevNode!=currentNode);
}




