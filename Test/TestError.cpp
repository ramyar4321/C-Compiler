#include "TestError.hpp"
#include "../Error/Error.hpp"
#include "../Lexer/Lexer.hpp"
#include <iostream>

/**
 * This method tests the Error class.
 * 
 * When an error is encountered, the error
 * flag must be set.
 * 
 * @return testPassed True if the test passed, false otherwise.
*/
bool TestError::testError(){

    bool testPassed = true;

    // Prior to Lexerical analysis, the
    // error flag must be set to false.
    if(Error::getInstance().getFlag()){
        testPassed = false;
        std::cout << "Error test failed! Error flag is true without any errors." << std::endl;
    }

    std::string text = "2324@1221";
    Lexer lexer = Lexer(text);
    lexer.tokenize();

    if(!Error::getInstance().getFlag()){
        testPassed = false;
        std::cout << "Error test failed! Error failed to be set." << std::endl;
    }

    if(testPassed){
        std::cout << "Error test passed!" << std::endl;
    }

    return testPassed;
}