#include "forTxt.h"

int main(int argc, char const *argv[])
{
    std::string fileAdd = "string";
    std::vector< Eigen::Matrix<double,4,4> > vTra;
    readAlignedTra(fileAdd, vTra);
    
    return 0;
}
