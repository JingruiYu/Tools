#include <opencv2/opencv.hpp>
#include "forTxt.h"
#include "stream.h"
#include "pclDraw.h"


std::string datafold = "/home/yujr/Tools/data/";

std::vector< Eigen::Matrix<float,4,4> > vTra;
std::vector<double> vTime;
std::vector<std::string> vName;

int main(int argc, char const *argv[])
{
    Txt::readTra(datafold+"groundtruth.txt", vTime, vTra, vName);

    pclDraw* pcD = new pclDraw();

    for (size_t i = 0; i < vTra.size(); i++)
    {
        cv::Mat img = cv::imread(datafold+"/edgePng/"+vName[i], CV_LOAD_IMAGE_UNCHANGED);
        cv::imshow("img", img);
        cv::waitKey(30);
        
        pcl::PointCloud<pcl::PointXYZ>::Ptr EdgeCloud(new pcl::PointCloud<pcl::PointXYZ>);
        pcl::PointCloud<pcl::PointXYZ>::Ptr FreeCloud(new pcl::PointCloud<pcl::PointXYZ>);
        pcl::PointCloud<pcl::PointXYZ>::Ptr EdgeCloud_alig(new pcl::PointCloud<pcl::PointXYZ>);
        pcl::PointCloud<pcl::PointXYZ>::Ptr FreeCloud_alig(new pcl::PointCloud<pcl::PointXYZ>);

        pcD->ConvertImg2Cloud(img, EdgeCloud, FreeCloud);

        pcl::transformPointCloud(*EdgeCloud, *EdgeCloud, vTra[i]);
        pcl::transformPointCloud(*FreeCloud, *FreeCloud, vTra[i]);

        pcD->DrawPointCloud(EdgeCloud,"Edge_"+vName[i]);
        pcD->DrawPointCloud(FreeCloud,"Free_"+vName[i]);

        pcD->DrawInTwb_ptr_(vTra[i],100,0,0,vName[i]);
    }   
    
    std::cin.get();
    
    
    
    
    
    return 0;
}
