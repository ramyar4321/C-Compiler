#include "TestParser.hpp"
#include "../Lexer/Lexer.hpp"
#include "../Parser/Parser.hpp"
#include <memory>
#include <string>
#include <iostream>

/**
 * Test if the Parser correctly forms 
 * an Abstract Syntax Tree.
*/
bool TestParser::testParser(){

    bool testPassed = true;

    std::string text = "123+456*789";

    Lexer lexer = Lexer(text);
    std::vector<Token> tokens = lexer.tokenize();

    Parser parser = Parser(tokens);
    std::unique_ptr<ASTNode> root = parser.initParser();

    root.get()->traverse();

    return testPassed;
}
