#include "TestLexer.hpp"
#include "../Lexer/Lexer.hpp"
#include <iostream>

bool TestLexer::testTokenizer(){

    bool testPassed = true;

    std::string text = "123+456";

    Lexer lexer = Lexer(text);
    std::vector<Token> actual_results = lexer.tokenize();

    std::vector<Token> expected_results = {Token(TN_INT, "123"),
                                         Token(TN_ADD, "+"),
                                         Token(TN_INT, "456")};

    std::cout << actual_results.size() << std::endl;
    std::cout << expected_results.size() << std::endl;

    for( int i =0; i < actual_results.size(); i++){
        actual_results[i].print();
    }
    
    std::cout << "--------------" << std::endl;

    for( int j =0; j < expected_results.size(); j++){
        expected_results[j].print();
    }

    if (actual_results.size() == expected_results.size()){
        if ( actual_results[0] == expected_results[0] &&
             actual_results[1] == expected_results[1] &&
             actual_results[2] == expected_results[2]){
                std::cout << "Tokenizer test passed!" << std::endl;
            } else{
                testPassed = false;
                std::cout << "Tokenizer test failed! List of tokens not properly returned." << std::endl;
            }
    } else {
        testPassed = false;
        std::cout << "Tokenizer test failed! Sizes not equal! " << std::endl;
    }

    return testPassed;
}