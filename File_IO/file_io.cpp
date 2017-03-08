#include "file_io.h"

#include <iostream>
#include <fstream>

namespace IO{


    std::string read_file(const std::string& filename){
        
        std::string line;
        std::string text = "";

        std::ifstream file(filename);

        if(file.is_open()){

            try{

                while(std::getline(file , line)){
                    text += line + "\n";
                }


            }catch(std::exception& e){
                std::cerr << e.what() << "\n";
            }


            file.close();


        }else{

            std::cerr << "Could open " << filename << "\n";
        }

        return text;
    }



    void write_file(const std::string& filename , const std::string& text , bool append){
        
        std::ofstream output_file;



        if(append)
            output_file.open(filename , std::ios::out | std::ios::app);
        else
            output_file.open(filename);


        output_file << text;
        output_file.close();

    }



};
