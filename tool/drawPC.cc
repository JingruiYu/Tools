#include <opencv2/opencv.hpp>
#include "forTxt.h"
#include "stream.h"
#include "pclDraw.h"


std::string datafold = "/home/yujr/Tools/data/";

std::vector< Eigen::Matrix<float,4,4> > vTra;
std::vector<cv::Vec3d> v3Tra;
std::vector<double> vTime;
std::vector<std::string> vName;

int main(int argc, char const *argv[])
{
    cv::Vec3d KFtra = cv::Vec3d(0,0,0);

    Txt::readTra(datafold+"groundtruth.txt", vTime, v3Tra, vTra, vName);

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

        bool isKF = false, dPC = true;

        if (i == 0)
        {
            KFtra = v3Tra[i];
            isKF = true;
        }
        else
        {
            double dTx = KFtra[0] - v3Tra[i][0];
            double dTy = KFtra[1] - v3Tra[i][1];
            double dTz = fabs(KFtra[2] - v3Tra[i][2]);
            
            double dis = sqrt(dTx*dTx + dTy*dTy);

            if (dis > 1.5 || dTz > 0.3)
            {
                KFtra = v3Tra[i];
                isKF = true;

                if (i < 60)
                {
                    dPC = false;
                }
                

                if (i > 90 && i < 170)
                {
                    dPC = false;
                }
                
                if (i > 500 && i < 560)
                {
                    dPC = false;
                }

                if (i > 640 && i < 690)
                {
                    dPC = false;
                }

                if (i > 1000 && i < 1120)
                {
                    dPC = false;
                }
                
            }
            
        }
        
        

        if (isKF)
        {
            if (dPC)
            {
                pcl::transformPointCloud(*EdgeCloud, *EdgeCloud, vTra[i]);
                pcl::transformPointCloud(*FreeCloud, *FreeCloud, vTra[i]);

                pcD->DrawPointCloud(EdgeCloud,"Edge_"+vName[i]);
                pcD->DrawPointCloud(FreeCloud,"Free_"+vName[i]);
            }
            
            pcD->DrawInTwb_ptr_(vTra[i],0.2,0,0,100,vName[i]);
        }
        else
        {
            pcD->DrawInTwb_ptr_(vTra[i],0.1,100,0,0,vName[i]);
        }     
        
    }   
    
    std::cin.get();
    
    
    
    
    
    return 0;
}
