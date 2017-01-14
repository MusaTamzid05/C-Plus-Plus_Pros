#ifndef HELPER_H
#define HELPER_H

#include <opencv2/opencv.hpp>

void remove_noise(cv::Mat& original_image , cv::Mat& new_image);
void calculate_light_pattern(cv::Mat& image , cv::Mat& pattern);
void remove_light(cv::Mat& img , cv::Mat& pattern , cv::Mat& new_image);
void threshold_image(cv::Mat& image , cv::Mat& new_image);
void find_contours(cv::Mat& image);

#endif
