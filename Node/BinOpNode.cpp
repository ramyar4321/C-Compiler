#include "BinOpNode.hpp"
#include "../Interpreter/Interpreter.hpp"

BinOpNode::BinOpNode(std::string op, std::unique_ptr<ASTNode>LHS, 
                              std::unique_ptr<ASTNode> RHS):
                              op(op), LHS(std::move(LHS)), RHS(std::move(RHS))

{}

/**
 * Return the string that represents the
 * operation of this node.
 * 
*/
std::string BinOpNode::getOp(){
    return this->op;
}

/**
 * This method is used in Visitor Pattern
 * to invoke the interpreter on this Binary
 * Operation Node. 
 * 
 * Furthermore, the accept methods for the child 
 * nodes are also called. 
*/
void BinOpNode::accept(Interpreter& i){
    this->LHS.get()->accept(i);
    this->RHS.get()->accept(i);
    i.visit_BinOpNode(*this);
}