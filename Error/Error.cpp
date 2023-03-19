#include "Error.hpp"
#include <iostream>

Error& Error::getInstance(){
    static Error e_instance;

    return e_instance;
}

bool Error::setFlag(){
    this->error_flag = true;

    return this->error_flag;
}

bool Error::resetFlag(){
    this->error_flag = false;

    return this->error_flag;
}

bool Error::getFlag(){
    return this->error_flag;
}

void Error::printErrorMsg(std::string& error_msg){
    std::cout << error_msg << std::endl;
}

