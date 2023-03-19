#ifndef ERROR
#define ERROR

#include <string>

/**
 * This class is used to generate an error meesage
 * and set an error flag when an error is encountered
 * from the text.
 * 
 * Since the erro flag is used globally by the program,
 * this class will use the Singleton Design pattern
 * for it implementation.
 * 
*/
class Error{

    public:
        Error(const Error&) = delete;
        void operator=(const Error&) = delete;

        static Error& getInstance();

        bool setFlag();
        bool resetFlag();

        bool getFlag();

        void printErrorMsg(std::string& error_msg);

    private:

        Error(){}

        bool error_flag = false;
};

#endif // End of ERROR