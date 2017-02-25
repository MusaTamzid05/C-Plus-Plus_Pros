#ifndef LIGHT_REMOVER
#define LIGHT_REMOVER

#include <string>
#include <opencv2/opencv.hpp>


class LightRemover{

    public:
        LightRemover(const std::string& pattern_file);
        bool convertTo32(cv::Mat& src_image , cv::Mat& dst_image);

        void remove_light_from(cv::Mat& src , cv::Mat& dst);
        void convert_to_nornal(cv::Mat& img);

    private:

        bool load_pattern(const std::string& file_name);

        cv::Mat pattern , pattern32;

};



#endif
