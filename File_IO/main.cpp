#include "file_io.h"
#include <string>
#include <iostream>

int main(int argc , char** argv){

    std::string text = IO::read_file("data.xml");
    IO::write_file("data3.xml" , text );

    IO::write_file("data3.xml" , text , true ); // append mode

    return 0;

}
