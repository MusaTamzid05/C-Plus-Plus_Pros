#include "util.h"
#include <fstream>
#include <cstdlib>
#include <iostream>


namespace Util {


    std::string read(const std::string& file_name) {

        std::string text;
        std::string line;


        std::ifstream file(file_name);

        if(!file.is_open()) {

            std::cerr << "Could not open " << file_name << "\n";
            return "";

        }

        while(std::getline(file , line)) 
            text += line + "\n";



        file.close();
        return text;

    }
};
