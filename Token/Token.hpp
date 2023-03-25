#ifndef TOKEN
#define TOKEN

#include <string>

/**
 * Token name enumator
*/
enum token_name{
    TN_INT,
    TN_ADD,
    TN_SUB,
    //TN_DIV,
    TN_MUL
};

/**-----------------------------*/
/**
 * +++++++++++++++++++++++++++++
 * ---------Token Class---------
 * +++++++++++++++++++++++++++++
 * A token is a sequence of characters with an identified meaning.
 * Tokens are created from the Lexer and are the basic
 * components of an Abstract Syntax Tree. 
 * 
 * For example, the text "123+456" 
 * excluding the quotation marks has three tokens:
 *  - Integer token 123
 *  - Plus token +
 *  - Integer token 456
 * 
*/
/**-----------------------------*/
class Token{
    private:
        token_name tn;
        std::string value;
    public:
        Token(const token_name& tn, const std::string& value);

        token_name getTokenName();
        std::string getTokenValue();

        bool operator==(Token t);
        void print();
};

#endif // End of TOKEN