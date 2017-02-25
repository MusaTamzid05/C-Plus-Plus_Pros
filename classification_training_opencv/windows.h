#ifndef WINDOWS_H
#define WINDOWS_H

#include <map>
#include <opencv2/opencv.hpp>
#include <string>


class Windows{

    public:
        Windows(){}
        void show_all();
        static void show_image(const cv::Mat& image , const std::string& window_name);
        void add(const std::string& window_name , const cv::Mat image);

    private:

        std::map<std::string , cv::Mat> images;
};

#endif
