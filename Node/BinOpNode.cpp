#include "BinOpNode.hpp"

BinOpNode::BinOpNode(std::string op, std::unique_ptr<ASTNode>LHS, 
                              std::unique_ptr<ASTNode> RHS):
                              op(op), LHS(std::move(LHS)), RHS(std::move(RHS))

{}


/**
 * Method used when traversing the Abstract Syntax Tree.
 * Once this node is reached, this node's op will 
 * be added to the accumulator.
 * 
 * @param node_value_acc  A vector that accumulates AST node value
 *                        as the tree is being traversed.
 * 
*/
void BinOpNode::traverse(std::vector<std::string>& node_value_acc){
    this->LHS->traverse(node_value_acc);
    node_value_acc.push_back(this->op);
    this->RHS->traverse(node_value_acc);
}