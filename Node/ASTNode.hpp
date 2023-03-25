#ifndef AST_NODE
#define AST_NODE

#include <string>
/**
 * ++++++++++++++++++++++++++++++
 * -----------AST Node-----------
 * ++++++++++++++++++++++++++++++
 * 
 * The purpose of this class is to serve
 * as a base class for nodes of the 
 * abstract syntax tree. 
 * 
*/
class ASTNode{
    public:
        virtual ~ASTNode() = 0;

        virtual void traverse() = 0;

};

#endif // End of AST_NODE