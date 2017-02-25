#ifndef HELPER_H
#define HELPER_H 

#include <opencv2/opencv.hpp>
#include <stdlib.h>

void noice_removal(const cv::Mat& image,cv::Mat& new_image);
void removeLight(cv::Mat& image , cv::Mat& pattern , cv::Mat& result);
void load_image(const std::string filename , cv::Mat& img);
void calculatePattern(const cv::Mat& image , cv::Mat& result);
void binarize_image(const cv::Mat& image , cv::Mat& result , bool dark_backgroud);
void connected_components(cv::Mat& image);
static cv::Scalar randomColor(cv::RNG& rng);


#endif
