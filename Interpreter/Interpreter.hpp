#ifndef INTERPRETER
#define INTERPRETER

#include <stack>
#include <string>

//#include "../Node/BinOpNode.hpp"
//#include "../Node/IntegerNode.hpp"

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
class BinOpNode;
class IntegerNode;

class Interpreter{

    public:
        virtual void visit_BinOpNode(BinOpNode& node) = 0;
        virtual void visit_IntegerNode(IntegerNode& node) = 0;

        virtual std::stack<std::string> getNodes()=0;
};

#endif // End of INTERPRETER