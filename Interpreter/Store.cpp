#include "Store.hpp"
#include "../Node/BinOpNode.hpp"
#include "../Node/IntegerNode.hpp"

/**
 * Store a Binary Node Operator
 * by pushing the string operator
 * value onto the stack.
 * 
 * @param node A given Binary Node Operator
 * 
*/
void Store::visit_BinOpNode(BinOpNode& node) {

    this->nodes.push(node.getOp());
}

/**
 * Store a Integer Node
 * by pushing the Integer
 * value onto the stack
 * 
*/
void Store::visit_IntegerNode(IntegerNode& node){
    this->nodes.push(node.getToken().getTokenValue());
}

std::stack<std::string> Store::getNodes(){
    return this->nodes;
}