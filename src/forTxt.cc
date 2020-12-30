#include "forTxt.h"
#include "Eigen_CV_G2O_Convert.h"
#include "stream.h"

Txt::Txt(/* args */)
{
}

Txt::~Txt()
{
}

bool Txt::readTra(const std::string& fileAdd, std::vector<double> &vTime, std::vector< Eigen::Matrix<float,4,4> > &vTra, std::vector<std::string> &vImgName)
{
    std::ifstream f;
    f.open(fileAdd.c_str());

    if (!f.is_open())
    {
        redcout(fileAdd + std::string(" is empty!"));
        return false;
    }
    
    while(!f.eof())
    {
        std::string s;
        std::getline(f,s);
        if(!s.empty())
        {
            std::stringstream ss;
            ss << s;
            double t;
            double x,y,theta;
            std::string image;
            ss >> t;
            vTime.push_back(t);
            ss>>x>>y>>theta;
            vTra.push_back(Eigen_CV_G2O_Convert::xytz2EigenM4(x,y,theta)); //TODO
            ss >> image;
            vImgName.push_back(image+".jpg.png");
        }
    }

    greencout(fileAdd + std::string(" has read !"));
    return true;
}

bool Txt::readImg2vec(const std::string& fileAdd, std::vector< std::string >&vName)
{
    vName.push_back("first");
    vName.push_back("second");
    std::cout << "readImg2vec" << std::endl;
    return true;
}