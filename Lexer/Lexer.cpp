#include "Lexer.hpp"
#include "../Error/Error.hpp"
#include <ctype.h>

/**
 * Constructor for the Lexer class.
*/
Lexer::Lexer(std::string& text):
                text(text),
                cur_pos(0),
                cur_char(text[0]),
                eot(false)
{}



/**
 * This method breaks the text into tokens
 * and returns a vector of tokens.
 * 
*/
std::vector<Token> Lexer::tokenize(){

    std::vector<Token> tokens;
    
    // Traverse the text.
    while(!eot){
        // Ignore spaces and terminating characters.
        if ( this->cur_char == ' '  ||
             this->cur_char == '\t' ||
             this->cur_char == '\n' ||
             this->cur_char == '\0'){
            this->advance();
        }
        else if( this->cur_char == '+'){
            tokens.push_back(Token(TN_ADD, "+"));
            this->advance();
        } else if( this->cur_char == '-'){
            tokens.push_back(Token(TN_SUB, "-"));
            this->advance();
        } else if( this->cur_char == '*'){
            tokens.push_back(Token(TN_MUL, "*"));
            this->advance();
        } else if(isdigit(this->cur_char)){
            tokens.push_back(makeIntegerToken());
        } else{
            // Error: unidentified symbol reached
            Error::getInstance().setFlag();


            std::string err_msg = "Unidentified symbol ";
            err_msg += cur_char;
            Error::getInstance().printErrorMsg(err_msg);
            this->advance();

        }

    }

    return tokens;

}

/**
 * This method increments cur_pos and sets the cur_char
 * to the cur_pos of the text, as long as cur_pos is
 * less than the length of the text.
 * 
 * eot is set to true when the end of the text is reached.
 *  
*/
void Lexer::advance(){
    if (this->cur_pos < this->text.size()){
        this->cur_pos++;
        this->cur_char = this->text[this->cur_pos];
    } else {
        eot = true;
    }
}

/**
 * This method is a helper function for the tokenize method.
 * This method creates an integer token and returns it.
*/
Token Lexer::makeIntegerToken(){

    std::string integer_token;

    while( isdigit(cur_char)){

        integer_token += this->cur_char;
        this->advance();
    }

    return Token(TN_INT, integer_token);
}