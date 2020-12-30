#pragma once
#include <Eigen/Dense>

class Eigen_CV_G2O_Convert
{    
private:
    /* data */
public:
    Eigen_CV_G2O_Convert(/* args */) {}
    ~Eigen_CV_G2O_Convert() {}

public:
    static Eigen::Matrix<float,4,4> xytz2EigenM4(double x, double y, double tz);

};
