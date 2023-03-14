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
    TN_DIV,
    TN_MUL
};

/**-----------------------------*/
/**
 * This class is used to create lexical token objects.
 * A lexical token is a sequence of characters with an identified meaning. 
 * Tokens form the basic units that make up the ABstract Syntax Tree.
 * 
*/
/**-----------------------------*/
class Token{
    private:
        token_name tn;
        std::string value;
    public:
        Token(const token_name& tn, const std::string& value);
};

#endif // End of TOKEN