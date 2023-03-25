#include "IntegerNode.hpp"
#include <iostream>

IntegerNode::IntegerNode(Token t):
                            t(t)
{}

void IntegerNode::traverse(){
    std::cout << this->t.getTokenValue() << std::endl;
}