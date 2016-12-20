#include <iostream>
#include <stdlib.h>
#include "image_text_reader.h"

int main(int argc , char** argv){

    
    if(argc == 0){
        std::cout << "usage: imagenames.\n";
        exit(1);
    }

    for(unsigned int i =1 ; i < argc ; i++){
        read_text_from(argv[i]);
    }
    return 0;
}
