#include "TestParser.hpp"
#include "../Lexer/Lexer.hpp"
#include "../Parser/Parser.hpp"
#include "../Interpreter/Interpreter.hpp"
#include "../Interpreter/Store.hpp"
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

    Store interp;
    root.get()->accept(interp);

    std::stack<std::string> actual_results = interp.getNodes();

    std::stack<std::string> expected_results;
    expected_results.push("123");
    expected_results.push("456");
    expected_results.push("789");
    expected_results.push("*");
    expected_results.push("+");

    if(actual_results.size() == expected_results.size()){

        while(!expected_results.empty()){
            if( expected_results.top() != actual_results.top()){
                std::cout << "Parser test failed! AST incorrectly built." << std::endl;
                testPassed = false;
                return testPassed;
            }
            expected_results.pop();
            actual_results.pop();
        }
    } else{
        std::cout << "Parser test failed! Expected result size not equal to actual result size." << std::endl;
        testPassed = false;
        return testPassed;
    }

    std::cout << "Parser test passed!" << std::endl;

    return testPassed;
}
