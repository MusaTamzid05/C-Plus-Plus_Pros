#include "video.h"
#include "helper.h"

Video::Video():vid(0){

}


void Video::run(){

    cv::Mat frame;
    running = true;

    while(vid.isOpened()){

        vid >> frame;

        handle_input();

        if(!running)
            break;

        cvtColor( frame , frame , CV_BGR2GRAY );
        cv::Mat temp = frame.clone();
        cv::Mat without_noise;;
        remove_noise(temp , without_noise);

        cv::Mat pattern;
        
        calculate_light_pattern(temp , pattern);
        cv::Mat light_remove_image;
        remove_light( without_noise , pattern , light_remove_image);

        cv::Mat threshold_;
        threshold_image(light_remove_image , threshold_);
        find_contours(threshold_);
        cv::imshow("test" , frame);
        cv::imshow("noise remove" , without_noise);
        cv::imshow("light remove" , light_remove_image);
        cv::imshow("threshold image" , threshold_);

    }

}

void Video::handle_input(){

    char key = cv::waitKey(20);


    if(key == 'q')
        running = false;


}
