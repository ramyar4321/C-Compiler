#ifndef INTEGER_NODE
#define INTEGER_NODE

#include "../Token/Token.hpp"
#include "ASTNode.hpp"
#include "../Interpreter/Interpreter.hpp"

/**
 * +++++++++++++++++++++++++++++
 * --------Integer Node---------
 * +++++++++++++++++++++++++++++
 * 
 * This class represents the Integer 
 * Node in an Abstract Syntax Tree.
 * An Integer Node contains 
 * an Integer Token.
 * 
*/
class IntegerNode : public ASTNode{
    private:
        Token t;
    public:
        IntegerNode(Token t);

        Token getToken();

        void accept(Interpreter& i) override;
};

#endif // End of INTEGER_NODE