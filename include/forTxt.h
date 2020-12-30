#pragma once

#include <iostream>
#include <vector>
#include <Eigen/Dense>
#include <fstream>

class Txt
{
private:
    /* data */
public:
    Txt(/* args */);
    ~Txt();

public:
    static bool readTra(const std::string& fileAdd, std::vector<double> &vTime, std::vector< Eigen::Matrix<float,4,4> > &vTra, std::vector<std::string> &vImgName);
    static bool readImg2vec(const std::string& fileAdd, std::vector< std::string >&vName);
};




