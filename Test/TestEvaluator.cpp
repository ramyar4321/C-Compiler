#include "TestEvaluator.hpp"
#include <string>
#include "../Lexer/Lexer.hpp"
#include "../Parser/Parser.hpp"
#include "../Interpreter/Evaluator.hpp"
#include <iostream>

/**
 * This method is responsible for testing
 * the Evaluator class.
 * 
 * The test example that will be considered 
 * will be the following text, excluding the 
 * quotation marks:
 *      "1+2*3"
 * 
 * The Abstract Syntax Tree is the following
 *          +
 *        /   \
 *        1    *
 *            /  \
 *            2   3
 * 
 * The AST should be evaluated to the value 7.
 * 
*/
bool TestEvaluator::testEvaluator(){
    bool testPassed = true;

    std::string text = "123+456*789";

    int actual_result;
    int expected_result = 7;

    Lexer lexer = Lexer(text);
    std::vector<Token> tokens = lexer.tokenize();

    Parser parser = Parser(tokens);
    std::unique_ptr<ASTNode> root = parser.initParser();

    Evaluator eval;
    root.get()->accept(eval);

    actual_result = eval.result();

    if (expected_result != actual_result){
        std::cout << "Evaluator test failed!" << std::endl;
        std::cout << actual_result << std::endl;
        testPassed = false;
        return testPassed;
    }

    std::cout << "Evaluator test passed!" << std::endl;
    return testPassed;

}
