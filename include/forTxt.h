#pragma once

#include <iostream>
#include <vector>
#include <Eigen/Dense>

bool readAlignedTra(const std::string& fileAdd, std::vector< Eigen::Matrix<double,4,4> > &vTra);