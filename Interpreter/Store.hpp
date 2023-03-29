#ifndef STORE
#define STORE

#include "Interpreter.hpp"

/**
 * ++++++++++++++++++++++++++++++
 * ---------Traverse-------------
 * ++++++++++++++++++++++++++++++
 * 
 * Store the nodes of the Abstract 
 * Syntax Tree into a stack.
 * 
 * This class is mainly used to test
 * the Parser.
 * 
*/

class Store: public Interpreter{

    private:
        std::stack<std::string> nodes;

    public:
        void visit_BinOpNode(BinOpNode& node) override;
        void visit_IntegerNode(IntegerNode& node) override;

        std::stack<std::string> getNodes();

};

#endif // End of STORE