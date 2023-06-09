#ifndef INTERPRETER
#define INTERPRETER

#include <stack>
#include <string>

/**
 * ++++++++++++++++++++++++++++++++++
 * ----------Interpreter-------------
 * ++++++++++++++++++++++++++++++++++
 * 
 * The interpreter traverses the 
 * Abstract Syntax Tree and produces
 * an output. 
 * 
 * To do this, the Visitor Pattern will
 * be used and this interpreter class
 * will be C++ interface. 
 * 
*/

// Forward declarations
class BinOpNode;
class IntegerNode;

class Interpreter{

    public:
        virtual void visit_BinOpNode(BinOpNode& node) = 0;
        virtual void visit_IntegerNode(IntegerNode& node) = 0;

};

#endif // End of INTERPRETER