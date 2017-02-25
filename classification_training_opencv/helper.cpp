#include "helper.h"



void load_image(const std::string filename , cv::Mat& img){

    img = cv::imread(filename , 0);

    if(img.empty()){

        std::cerr << "Could not load " <<  filename << ".\n";
        exit(1);
    }


}

void noice_removal(const cv::Mat& image,cv::Mat& new_image){

    medianBlur(image , new_image,3);
}






void removeLight(cv::Mat& img , cv::Mat& pattern ,cv::Mat& result){

    cv::Mat aux;

    // method 1 means we are gone use division
    // need to convert the image to 32bit in order to make division.
    cv::Mat img32 , pattern32;

    img.convertTo(img32 , CV_32F);
    pattern.convertTo(pattern32 , CV_32F);

    if(img32.empty() || pattern32.empty())
        std::cerr << "one of the image is empty.\n";


    std::cout << "trying to calculate.\n";
    aux = 1 -  ( img32 / pattern32 );
    std::cout << "data calculated.\n";

    // now we need to convert the the image back to 8 bit.
    // to do that we first need to scale it.

    aux = aux * 255;
    aux.convertTo(aux , CV_8U);


    aux = pattern - img;

    result = aux.clone();
}


void calculatePattern(const cv::Mat& image , cv::Mat& result){

    cv::blur( image , result ,  cv::Size(image.cols/ 3 , image.cols / 3) );
}


void binarize_image(const cv::Mat& image , cv::Mat& result , bool dark_background){

    cv::Mat thr;

    if( dark_background == true)
        cv::threshold(image , thr , 30 , 255 , cv::THRESH_BINARY);
    else
        cv::threshold(image , thr , 140 , 255 , cv::THRESH_BINARY_INV);

    result = thr.clone();

}




void connected_components(cv::Mat& image){

    cv::Mat labels;
    int num_objects = cv::connectedComponents(image, labels);

    if(num_objects < 2){

        std::cout << "No objects deteced.\n";
        return;
    }else{

        std::cout << "Number of objects detected: " << num_objects - 1 << "\n";
    }


    cv::Mat output = cv::Mat::zeros(image.rows , image.cols , CV_8UC3);
    cv::RNG rng(0xFFFFFFFF);

    for(int i = 1  ; i < num_objects ; i++){
        cv::Mat mask = labels == i;
        output.setTo(randomColor( rng  ) , mask );
    }


}


static cv::Scalar randomColor(cv::RNG& rng){
    
    int icolor = (unsigned) rng;
    return cv::Scalar( icolor&255 ,(icolor > 8)&255 , (icolor>>16)&255 );
}
