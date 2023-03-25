#include "Parser.hpp"
#include <iostream>

/**
 * Constructor for the Parser class
*/
Parser::Parser(std::vector<Token> tokens):
                tokens(tokens),
                token_id(0),
                cur_token(tokens[0])
{}

/**
 * Initiate the Parsing of the tokens by
 * calling the Expr method.
 * 
 * @return std::unique_ptr<ASTNode> The root node of the AST
 * 
*/
std::unique_ptr<ASTNode> Parser::initParser(){
    std::unique_ptr<ASTNode> root = this->Expr();

    return std::move(root);
}

/**
 * This method increments the token_id
 * as long as it is within bounds of the token
 * vector length. The sets cur_token to the 
 * token at index token_id in the vector of tokens.
*/
void Parser::advance(){
    if( this->token_id < tokens.size()-1){
        this->token_id++;
        this->cur_token = this->tokens[this->token_id];
    }
}

/**
 * This method will implement the Expr rule
 * from the Grammer rules.
 * 
 * @return std::unique_ptr<ASTNode> A smart pointer pointing
 *                                  to a Binary Operation Node
 * 
*/
std::unique_ptr<ASTNode> Parser::Expr(){
    std::unique_ptr<ASTNode> lhs = this->Term();
    std::unique_ptr<ASTNode> rhs;

    std::string cur_token_value;

    while( this->cur_token.getTokenName() == TN_ADD ||
            this->cur_token.getTokenName() == TN_SUB){

        cur_token_value = this->cur_token.getTokenValue();
        this->advance();
        rhs = this->Term();
        lhs = std::make_unique<BinOpNode>(cur_token_value, std::move(lhs), std::move(rhs));
    }

    return std::move(lhs);
}

/**
 * This method will implement the Term rule
 * from the Grammer rules.
 * 
 * @return std::unique_ptr<ASTNode> A smart pointer pointing
 *                                  to a Binary Operation Node.
*/
std::unique_ptr<ASTNode> Parser::Term(){

    std::unique_ptr<ASTNode> lhs = this->Factor();
    std::unique_ptr<ASTNode> rhs;

    std::string cur_token_value;

    while (this->cur_token.getTokenName() == TN_MUL){
        cur_token_value = this->cur_token.getTokenValue();
        this->advance();
        rhs = this->Factor();
        lhs = std::make_unique<BinOpNode>(cur_token_value, std::move(lhs), std::move(rhs));
    }

    return std::move(lhs);
}

/**
 * This methode will implement the Factor rule
 * from the Grammer rules.
 * 
 @return std::unique_ptr<ASTNode> A smart pointer pointing
                                  to an Integer Node.
*/
std::unique_ptr<ASTNode> Parser::Factor(){
    Token cur_token = this->tokens[token_id];
    std::unique_ptr<ASTNode> int_node = std::make_unique<IntegerNode>(cur_token);

    this->advance();

    return std::move(int_node);
}
