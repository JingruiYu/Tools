#include<iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char const *argv[])
{
    cv::String foldstr = "/media/yujr/cache/SYNTHIA/new york/SYNTHIA-SEQS-02-FALL/SYNTHIA-SEQS-02-FALL/RGB/Stereo_Left";
    std::vector<cv::String> imagePathList;
    cv::glob(foldstr,imagePathList,true);


    std::cout << "imagePathList.size: " << imagePathList.size() << std::endl;
    return 0;
}
