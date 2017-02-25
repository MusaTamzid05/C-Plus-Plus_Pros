#include "windows.h"


void Windows::show_image(const cv::Mat& image , const std::string& window_name = "Window"){

    while(char(cv::waitKey(1)) != 'q'){

        cv::imshow("Window" , image);
    }
}


void Windows::show_all(){


    while(char(cv::waitKey(1)) != 'q'){


        for(auto image : images){
            cv::imshow(image.first, image.second);
        }
        
    }


}


void Windows::add(const std::string& window_name , const cv::Mat image){
    images[window_name] = image;
}
