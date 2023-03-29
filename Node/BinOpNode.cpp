#include "BinOpNode.hpp"
#include "../Interpreter/Interpreter.hpp"

BinOpNode::BinOpNode(std::string op, std::unique_ptr<ASTNode>LHS, 
                              std::unique_ptr<ASTNode> RHS):
                              op(op), LHS(std::move(LHS)), RHS(std::move(RHS))

{}


std::string BinOpNode::getOp(){
    return this->op;
}


void BinOpNode::accept(Interpreter& i){
    this->LHS.get()->accept(i);
    this->RHS.get()->accept(i);
    i.visit_BinOpNode(*this);
}