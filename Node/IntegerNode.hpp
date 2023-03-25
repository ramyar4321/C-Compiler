#ifndef INTEGER_NODE
#define INTEGER_NODE

#include "../Token/Token.hpp"
#include "ASTNode.hpp"

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

        void traverse();
};

#endif // End of INTEGER_NODE