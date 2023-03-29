#ifndef AST_NODE
#define AST_NODE

//#include "../Interpreter/Interpreter.hpp"
#include <vector>
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

// Forward declaration
class Interpreter;

class ASTNode{
    public:

        virtual void accept(Interpreter& i) = 0;

};

#endif // End of AST_NODE