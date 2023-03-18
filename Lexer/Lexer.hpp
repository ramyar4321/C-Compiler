#include <vector>
#include <string>
#include "../Token/Token.hpp"

/**-----------------------------*/
/**
 * +++++++++++++++++++++++++++++
 * ---------Lexer Class---------
 * +++++++++++++++++++++++++++++
 * 
 * The Lexer class creates a vector of tokens 
 * from the text. 
*/
class Lexer{

    private:

        // Input from the user to be broken down 
        // into tokens.
        std::string text;
        // Current position of the character of 
        // the text that is being analyzed
        int cur_pos;
        // Current character that is being analyzed by the Lexer
        char cur_char;
        // Boolean value that is set to true 
        // when the Lexer has reached the end of the text
        bool eot;

    public:
        Lexer(std::string& text);
        std::vector<Token> tokenize();
        void advance();
        Token makeIntegerToken();
        

};