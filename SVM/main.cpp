#include <opencv2/core/core.hpp>
#include <opencv2/ml/ml.hpp>
#include <iostream>


int main(int argc , char** argv){

    int train_data_row = 10, train_data_col = 2;
    int num_labels_row = 10 , num_labels_col = 1; 

    float training_data[train_data_row][train_data_col] = { {5.0,1.0} , { 3.0 , 2.1} , {1.0 , 3.0} , {2.0 , 4.0} , {4.0,7.0}, {10.2 , 11.1 } , {15.3 , 13.4} , {13.4 , 17.8} , {12.2 , 18.9} , {19.2, 16.6}
    };

    cv::Mat training_data_mat(train_data_row , train_data_col , CV_32FC1 , training_data);

    // first 5 data are 0 , last 5 data are 1 
    int labels[num_labels_row] ={ 0 , 0 , 0 , 0 , 0 , 1 , 1 ,1 ,1 ,1 };

    cv::Mat labels_mat(num_labels_row,  num_labels_col ,  CV_32S , labels);

    cv::Ptr<cv::ml::SVM> svm;



    svm = cv::ml::SVM::create();
    svm->setType(cv::ml::SVM::C_SVC);
    svm->setKernel(cv::ml::SVM::CHI2);
    svm->setTermCriteria(cv::TermCriteria(cv::TermCriteria::MAX_ITER , 100 , 1e-6));



    svm->train(training_data_mat,cv::ml::ROW_SAMPLE, labels_mat);

    float test_data[][2] = { {3.0 , 1.0} };

    cv::Mat test_data_mat(1 , 2 , CV_32FC1 , test_data);
    cv::Mat output;
    svm->predict(test_data_mat , output);

    std::cout << output << "\n";


    float test_data2[][2] = { {15.4 , 13.4} };

    cv::Mat test_data2_mat(1 , 2 , CV_32FC1 , test_data);
    svm->predict(test_data2_mat , output);

    std::cout << output << "\n";

    return 0;
}
