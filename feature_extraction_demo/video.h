#ifndef VIDEO_H
#define VIDEO_H

#include <opencv2/opencv.hpp>

class Video{

    public:

        Video();
        void run();
        void handle_input();

    private:

        cv::VideoCapture vid;
        bool running;


};

#endif
