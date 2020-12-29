#include "forTxt.h"
#include "stream.h"
#include <opencv2/opencv.hpp>

std::string datafold = "/home/yujr/Tools/data/";

std::vector< Eigen::Matrix<double,4,4> > vTra;
std::vector<double> vTime;
std::vector<std::string> vName;

int main(int argc, char const *argv[])
{
    Txt::readTra(datafold+"groundtruth.txt", vTime, vTra, vName);

    for (auto &&name : vName)
    {
        cv::Mat img = cv::imread(datafold+"/contourICP/"+name, CV_LOAD_IMAGE_UNCHANGED);
        cv::imshow("img", img);
        cv::waitKey(30);
    }
    
    
    
    
    
    
    return 0;
}
