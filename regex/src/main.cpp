#include <string>
#include <iostream>
#include "regular_exp.h"


int main(int argc , char** argv) {

    std::string words[] = { "test.cpp" , "test.rb" , "test2.cpp" };

    Util::Regex regex("^.*cpp$");


    for(auto word : words) {

        if(regex.is_match(word)) 
            std::cout << "cpp file found.\n";
        else
            std::cout << "Not  a cpp file.\n";
    }
    return 0;
}
