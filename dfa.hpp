#ifndef DFA_H
#define DFA_H

#include "./node.hpp"
#include "./machine.hpp"
#include<QList>

class DFA : public AM::Machine
{
private:


public:
    DFA();
    bool checkInput(QString );



};

#endif // DFA_H
