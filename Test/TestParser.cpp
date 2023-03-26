#include "TestParser.hpp"
#include "../Lexer/Lexer.hpp"
#include "../Parser/Parser.hpp"
#include <memory>
#include <string>
#include <iostream>

/**
 * Test if the Parser correctly forms 
 * an Abstract Syntax Tree.
 * 
 * The text example that will used 
 * to parse will be the following:
 * "123+456*789"
 * excluding the quotation marks.
 * 
 * The AST that will be formed is the following:
 *          +
 *        /   \
 *       123   *
 *            /  \
 *          456  789
*/
bool TestParser::testParser(){

    bool testPassed = true;

    std::string text = "123+456*789";

    Lexer lexer = Lexer(text);
    std::vector<Token> tokens = lexer.tokenize();

    Parser parser = Parser(tokens);
    std::unique_ptr<ASTNode> root = parser.initParser();

    std::vector<std::string> actual_results;
    root.get()->traverse(actual_results);

    std::vector<std::string> expected_results = {"123", "+", "456", "*", "789"};

    if(actual_results.size() == expected_results.size()){

        if( actual_results[0] == expected_results[0] &&
            actual_results[1] == expected_results[1] &&
            actual_results[2] == expected_results[2] &&
            actual_results[3] == expected_results[3] &&
            actual_results[4] == expected_results[4]){
                std::cout << "Parser test passed!" << std::endl;
            } else{
                std::cout << "Parser test failed! AST incorrectly built." << std::endl;
            }
    } else{
        std::cout << "Parser test failed! Expected result size not equal to actual result size." << std::endl;
        testPassed = false;
    }

    return testPassed;
}
