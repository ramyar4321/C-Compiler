#include <iostream>
#include <string>
#include "Test/TestLexer.hpp"

int main() 
{

    /*std::string text;

    while(true){
        // Read input from the console.
        std::cout << "> ";
        std::getline(std::cin, text);

        std::cout << text << std::endl;

        // Stop reading input from the console
        // if text is "terminate"
        if(text == "terminate"){
            break;
        }


    }*/

    // Tests
    TestLexer tl;
    tl.testTokenizer();



  return 0;
}