#include "Eigen_CV_G2O_Convert.h"

#include "math.h"

Eigen::Matrix<double,4,4> Eigen_CV_G2O_Convert::xytz2EigenM4(double x, double y, double tz)
{
    Eigen::Matrix<double,4,4> M;

    M << cos(tz),-sin(tz),  0,  x,
         sin(tz), cos(tz),  0,  y,
         0      ,       0,  1,  0,
         0      ,       0,  0,  1;

    return M;
}