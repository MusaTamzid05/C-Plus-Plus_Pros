#include "light_remover.h"
#include <stdlib.h>

LightRemover::LightRemover(const std::string& pattern_file){

    if(!load_pattern(pattern_file)){

        std::cerr << "Could not load the pattern file!!";
        exit(1);
    }

    std::cout << "pattern file " << pattern_file << " loaded.\n";
}


bool LightRemover::load_pattern(const std::string& file_name){
    pattern= cv::imread(file_name);
    
    if(pattern.empty())
        return false;



    return convertTo32( pattern, pattern32);


}

bool LightRemover::convertTo32(cv::Mat& src_image , cv::Mat& dst_image){

    src_image.convertTo(dst_image , CV_32F);

    return !dst_image.empty();
}

void LightRemover::convert_to_nornal(cv::Mat& img){

    img = img * 255;
    img.convertTo(img , CV_8U);
}
void LightRemover::remove_light_from(cv::Mat& src , cv::Mat& dst){

    if(src.empty()){
        std::cerr << "source image is empty.Cannot remove light.\n";
        exit(2);
    }

    cv::Mat img32;

    if(!convertTo32(src , img32)){
        std::cerr << "source image conversion failed.Cannot remove noice.\n";
        exit(3);
    }
    cv::Mat aux;
    aux = 1 - ( img32 / pattern32  );
    convert_to_nornal(aux);

    //cv::Mat result = aux -pattern;
    dst = aux.clone();


}
