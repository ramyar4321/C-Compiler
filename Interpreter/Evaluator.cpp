#include "Evaluator.hpp"
#include "../Node/BinOpNode.hpp"
#include "../Error/Error.hpp"

/**
 * Evaluate the Binary Operator Node and push
 * the value onto the stack. 
 * 
*/
void Evaluator::visit_BinOpNode(BinOpNode& node){

    int lhs;
    int rhs;   

    std::string op = node.getOp();   

    if( op.compare("+")){
        rhs = this->nodes.top();
        this->nodes.pop();
        lhs = this->nodes.top();
        this->nodes.pop();
        this->nodes.push(lhs+rhs);
    } else if (op.compare("-")){
        rhs = this->nodes.top();
        this->nodes.pop();
        lhs = this->nodes.top();
        this->nodes.pop();
        this->nodes.push(lhs-rhs);
    } else if (op.compare("*")){
        rhs = this->nodes.top();
        this->nodes.pop();
        lhs = this->nodes.top();
        this->nodes.pop();
        this->nodes.push(lhs*rhs);
    } else {

        // Error: unidentified Node reached
        Error::getInstance().setFlag();

        std::string err_msg = "Unidentified Node ";
        err_msg += op;
        Error::getInstance().printErrorMsg(err_msg);

    }
}

/**
 * 
 * Push the Integer onto the stack.
 * 
*/
void Evaluator::visit_IntegerNode(IntegerNode& node){

    this->nodes.push(std::stoi(node.getToken().getTokenValue()));
}

/**
 * 
 * Return the result of the evaluation.
 * 
*/
int Evaluator::result(){

    int res;
    if(!this->nodes.empty()){
        res = 0;
    } else{
        res = this->nodes.top();
    }

    return res;
}