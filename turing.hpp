#ifndef TURING_H
#define TURING_H


#include "./machine.hpp"
#include <vector>

class Turing : public AM::Machine
{
private:
    std::vector <QString> rightHalf;
    std::vector <QString> leftHalf;

    int Head=0;
    Node * final=nullptr;







public:


    bool CheckInput(QString);
    Turing();

};





#endif
