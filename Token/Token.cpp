#include "Token.hpp"
#include <iostream>

Token::Token(const token_name& tn, const std::string& value):
                tn(tn),
                value(value)
{}

/**
 * Overload of equality operator.
 * 
 * This token is equal to another token if and only
 * if their token names are equal and their values 
 * are equal.
*/
bool Token::operator==(Token t){

    bool areEqual = false;

    if(this->tn == t.tn && this->value == t.value){
        areEqual = true;
    } 

    return areEqual;
}

/**
 * Print the token to console.
*/
void Token::print(){
    std::cout << "[" << this->tn << " , " << this->value << "]" << std::endl;
}