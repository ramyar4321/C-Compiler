#ifndef EVALUATOR
#define EVALUATOR

#include "Interpreter.hpp"

/**
 * +++++++++++++++++++++++++++++++++
 * ----------Evaluator--------------
 * +++++++++++++++++++++++++++++++++
 * 
 * This class is used to produce 
 * a value by evaluating the Abstract
 * Syntax Tree nodes.
 * 
*/
class Evaluator: public Interpreter{

    private:
        std::stack<int> nodes;

    public:
        void visit_BinOpNode(BinOpNode& node);
        void visit_IntegerNode(IntegerNode& node);

        int result();
};

#endif // End of EVALUATOR