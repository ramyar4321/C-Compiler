#ifndef BINARY_OPERATOR_NODE
#define BINARY_OPERATOR_NODE

#include <memory>
#include <string>
#include "IntegerNode.hpp"

/**
 * +++++++++++++++++++++++++++++
 * ----Binary Operator Node-----
 * +++++++++++++++++++++++++++++
 * 
 * This class represents mathematical
 * operations such as addition between
 * a left-hand side Integer Node
 * and a right-hand side Integer Node. 
 * 
*/
class BinOpNode: public ASTNode{
    private:
        std::string op;
        std::unique_ptr<ASTNode> LHS, RHS;

    public:
        BinOpNode(std::string op, std::unique_ptr<ASTNode>LHS, std::unique_ptr<ASTNode> RHS); 

        void traverse();
};

#endif // End of BINARY_OPERATOR_NODE