#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include "windows.h"
#include "helper.h"
#include "filesystem.h"
#include "light_remover.h"


const int MIN_AREA  = 500;


std::vector<std::vector<float>>  ExtractFeatures( cv::Mat img , std::vector<int>* left = nullptr , std::vector<int>* top = nullptr );
bool readFolderAndExtractFeatures(std::string filder , int label , int num_for_test , std::vector<float>& trainingData , std::vector<int>& responseData , std::vector<float>& testData , 
        std::vector<float>& testResponseData);


void trainAndTest(); // it also saves the training data

cv::Mat processImage(cv::Mat& input);


int main(int argc , char** argv){

    
    trainAndTest();
    

    return 0;
}


std::vector<std::vector<float>> ExtractFeatures( cv::Mat img , std::vector<int>* left , std::vector<int>* top ){

    std::vector< std::vector<float>> output;
    std::vector<std::vector<cv::Point>> contours;
    cv::Mat input = img.clone();
    cvtColor(input , input , CV_BGR2GRAY);
    std::vector<cv::Vec4i> hierarchy;
    

    cv::findContours( input , contours , hierarchy ,cv::RETR_CCOMP   , cv::CHAIN_APPROX_SIMPLE );


    if( contours.size() == 0 )
        return output;


    for( unsigned int i = 0 ; i < contours.size() ; i++ ){
        cv::Mat mask = cv::Mat::zeros( img.rows , img.cols , CV_8UC1 );
        cv::drawContours( mask , contours , i , cv::Scalar(1) , cv::FILLED , cv::LINE_8 , hierarchy , 1 );


        cv::Scalar area_s = cv::sum(mask);
        float area = area_s[0];

        if( area > MIN_AREA ){
            
            cv::RotatedRect r = cv::minAreaRect( contours[i] );
            float weight = r.size.width;
            float height = r.size.height;
            float ar = ( weight < height ) ? height / weight: weight / height;

            std::vector<float> row;
            row.push_back(area);
            row.push_back(ar);
            output.push_back(row);

            if( left != nullptr ){
                left->push_back( (int)r.center.x );
            }

            if( top != nullptr ){
                top->push_back((int)r.center.y);
            }
        }
    }

    return output;

}



bool readFolderAndExtractFeatures(std::string folder, int label , int num_for_test , std::vector<float>& trainingData , std::vector<int>& responseData , std::vector<float>& testData , 
        std::vector<float>& testResponseData){

    LightRemover light_remover("data/pattern.pgm");
    FileSystem fs(folder);
    std::vector<std::string> image_files;


    fs.get_files(image_files);

    if( image_files.empty() ){

        std::cerr << "No files where found in " << folder << "\n";
        return false;
    }

    std::cout << "image files found  in " << folder << "\n";
    std::cout << "total images : " << image_files.size() << "\n";

    int img_index = 0;

    for(auto image_file : image_files){

        std::cout << img_index + 1 << "/" << image_files.size() << "\n";
        cv::Mat frame = cv::imread(image_file );
   

        if(frame.empty()){
            std::cerr << "Could not load " << image_file << "\n";
            exit(1);
        }

        std::cout << "processing " << image_file << "\n";

        cv::Mat noice_removed;
        noice_removal( frame , noice_removed );
        std::cout << "Removed noice from " << image_file << "\n";

        cv::Mat light_remove;

        std::cout << "trying to remove light from the image!!!!\n";
        light_remover.remove_light_from(frame , light_remove);
        std::cout << "removed light from the image.\n";
        
        std::vector<std::vector<float>> features = ExtractFeatures(light_remove);
        
        for(unsigned int i = 0 ; i <features.size() ; i++){

            if( img_index >= num_for_test ){

                trainingData.push_back( features[i][0] );
                trainingData.push_back( features[i][1] );
                responseData.push_back(label);
            }else{
                testData.push_back(features[i][0]);
                testData.push_back(features[i][1]);
                testResponseData.push_back((float)label);
            }
        }

        img_index++;

    }

    return true;
}



cv::Mat processImage(cv::Mat&  input){

    if(input.empty()){

        std::cout << "input image is empty.\n";
        exit(2);
    }
    std::cout << "image is not empty.\n";

    cv::Mat image = input.clone();
    cv::Mat result;
    removeLight( image , light_pattern , result );



    return cv::Mat();

}



void trainAndTest(){

    std::vector<float> trainingData;
    std::vector<int>  responseData;
    std::vector<float> testData;
    std::vector<float> testResponseData;

    int num_for_test = 20;

    readFolderAndExtractFeatures("data/nut" , 0 , num_for_test , trainingData, responseData , testData , testResponseData);
    readFolderAndExtractFeatures("data/ring" , 1 , num_for_test , trainingData , responseData , testData , testResponseData);
    readFolderAndExtractFeatures("data/screw" , 2 , num_for_test , trainingData , responseData , testData , testResponseData);

    // hare we save all the data.
    std::cout << "total traning_data: " << trainingData.size() << "\n";
    cv::Mat training_data_mat(trainingData.size() /2 , 2 , CV_32FC1 , &trainingData[0]);
    cv::imwrite("training_data.png" ,training_data_mat );
    std::cout << "training data saved!\n";

    std::cout << "total response data:" << responseData.size() << "\n";
    cv::Mat response_mat(responseData.size() , 1 , CV_32SC1  , &responseData[0]);
    cv::imwrite("training_response_data.png" , response_mat);
    std::cout << "training response data are saved.\n";


    std::cout << "total test data : " << testData.size() << "\n";
    cv::Mat test_data_mat(testData.size() / 2 , 2 , CV_32FC1 , &testData[0]);
    cv::imwrite("test_data.png" , test_data_mat);
    std::cout << "test data saved.\n";

    std::cout << "total test response:" << testResponseData.size() << "\n";
    cv::Mat test_response_mat(testResponseData.size() , 1 , CV_32SC1 , &testResponseData[0]);
    std::cout << "test response data saved.\n";


}
