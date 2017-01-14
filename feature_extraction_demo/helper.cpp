#include "helper.h"
#include <iostream>

void remove_noise(cv::Mat& original_image , cv::Mat& new_image){

    cv::medianBlur( original_image , new_image, 3);
    
}


void calculate_light_pattern(cv::Mat& image , cv::Mat& pattern){

    cv::Mat temp = image.clone();


    cv::blur(temp , pattern , cv::Size(temp.cols / 3 , temp.cols / 3));

}


void remove_light(cv::Mat& img , cv::Mat& pattern , cv::Mat& new_image){

    cv::Mat aux;
    cv::Mat temp = img.clone();


    cv::Mat img32 , pattern32;

    temp.convertTo(img32 , CV_32F);
    pattern.convertTo(pattern32 , CV_32F);



    aux = 1 - (img32/ pattern32);
    aux = aux * 255;

    aux.convertTo(aux , CV_8U);
    new_image = aux.clone();

    
}


void threshold_image(cv::Mat& image , cv::Mat& new_image){

    
    cv::Mat temp = image.clone();

    if(temp.empty())
        std::cerr << "temp is not empty.\n";


    cv::threshold(temp , new_image , 30 , 255 , cv::THRESH_BINARY);
}


void find_contours(cv::Mat& image){

    std::vector<std::vector<cv::Point>> contours; 
    cv::Mat temp;

    temp = image.clone();

    if(temp.empty())
        std::cerr << "steve empty.\n";

    cv::findContours( image , contours , cv::RETR_EXTERNAL , cv::CHAIN_APPROX_SIMPLE  );

    
    if(contours.size() == 0){
        std::cerr << "No contours detected.\n";
        return ;
    }

    cv::Mat output = cv::Mat::zeros( image.rows , image.cols , CV_8UC3);

    for(unsigned int i = 0 ; i < contours.size() ; i++){
        cv::drawContours(output , contours , -1 , cv::Scalar::all(255) );
    }

    cv::imshow("contours" , output);


}
