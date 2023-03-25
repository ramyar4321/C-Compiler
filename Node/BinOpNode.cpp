#include "BinOpNode.hpp"
#include <iostream>

BinOpNode::BinOpNode(std::string op, std::unique_ptr<ASTNode>LHS, 
                              std::unique_ptr<ASTNode> RHS):
                              op(op), LHS(std::move(LHS)), RHS(std::move(RHS))

{}



void BinOpNode::traverse(){
    this->LHS->traverse();
    std::cout << this->op << std::endl;
    this->RHS->traverse();
}