#pragma once

#include <iostream>
#include <vector>
#include <Eigen/Dense>
#include <fstream>
#include <opencv2/opencv.hpp>

class Txt
{
private:
    /* data */
public:
    Txt(/* args */);
    ~Txt();

public:
    static bool readTra(const std::string& fileAdd, std::vector<double> &vTime, std::vector<cv::Vec3d> &v3Tra, std::vector< Eigen::Matrix<float,4,4> > &vTra, std::vector<std::string> &vImgName);
    static bool readImg2vec(const std::string& fileAdd, std::vector< std::string >&vName);
};




