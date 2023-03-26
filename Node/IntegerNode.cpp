#include "IntegerNode.hpp"

IntegerNode::IntegerNode(Token t):
                            t(t)
{}

/**
 * Method used when traversing the Abstract Syntax Tree.
 * Once this node is reached, this node's token value will 
 * be added to the accumulator.
 * 
 * @param node_value_acc  A vector that accumulates AST node value
 *                        as the tree is being traversed.
 * 
*/
void IntegerNode::traverse(std::vector<std::string>& node_value_acc){
    node_value_acc.push_back(this->t.getTokenValue());
}