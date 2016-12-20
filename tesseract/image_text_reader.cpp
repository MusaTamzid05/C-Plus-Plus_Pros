#include "image_text_reader.h"
#include <iostream>

#include <time.h>


int random(int from , int to){

    srand(time(nullptr));
    return (rand() % to) + from;
}

void read_text_from(const std::string& image_name){

    std::cout << "trying to read " << image_name << "\n";
    std::string exts[]= {"png" , "jpeg"};
    bool found = false;
    for(auto ext : exts){

        if(image_name.find(ext) != std::string::npos){
            found = true;
            break;
        }
    }

    if(found){
        std::cout << image_name << " is supported.\n";
        std::string save_filename = std::to_string(random(1,1000));

        std::string command = "tesseract " + image_name + " " + save_filename;

        system(command.c_str());
        std::cout << "the text of image " << image_name << "is saved to " << save_filename << "\n";
        return;
    }

    std::cout << image_name << " is not supported.\n";


}
