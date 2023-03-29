#include "IntegerNode.hpp"

IntegerNode::IntegerNode(Token t):
                            t(t)
{}

/**
 * Return this token.
 * 
*/
Token IntegerNode::getToken(){
    return this->t;
}


void IntegerNode::accept(Interpreter& i){
    i.visit_IntegerNode(*this);
}