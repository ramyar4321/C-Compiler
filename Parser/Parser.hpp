#ifndef PARSER
#define PARSER

#include <vector>
#include <memory>
#include "../Token/Token.hpp"
#include "../Node/ASTNode.hpp"
#include "../Node/BinOpNode.hpp"
#include "../Node/IntegerNode.hpp"

/**-----------------------------*/
/**
 * +++++++++++++++++++++++++++++
 * -------_Parser Class---------
 * +++++++++++++++++++++++++++++
 * 
 * The Parser takes the tokens from the Lexer
 * and generates an Abstract Syntax Tree (AST).
 * The Parser will generate the AST in 
 * accordance with grammer rules defined
 * in GrammerRules.md. 
 * 
 * 
*/
class Parser{

    private:
        std::vector<Token> tokens;
        int token_id;
        Token cur_token;

    public:
        Parser(std::vector<Token> tokens);

        std::unique_ptr<ASTNode> initParser();

        void advance();

        std::unique_ptr<ASTNode> Expr();
        std::unique_ptr<ASTNode> Term();
        std::unique_ptr<ASTNode> Factor();

};
#endif // End of PARSER