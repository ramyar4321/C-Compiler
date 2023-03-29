#include "IntegerNode.hpp"

IntegerNode::IntegerNode(Token t):
                            t(t)
{}

/**
 * Return the token corresponding 
 * to this Interger Node.
 * 
*/
Token IntegerNode::getToken(){
    return this->t;
}

/**
 * This method is used in the Visitor
 * Pattern to invoke the Interpreter
 * on this Integer Node.
 * 
*/
void IntegerNode::accept(Interpreter& i){
    i.visit_IntegerNode(*this);
}