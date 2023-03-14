#include <iostream>
#include <string>

int main() 
{

    std::string text;

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


    }

  return 0;
}