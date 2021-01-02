#include "pclDraw.h"


pclDraw::pclDraw(): Twb_ptr_(new pcl::visualization::PCLVisualizer("Twb_viewer")), 
    vehicle_length(4.63), vehicle_width(1.901), rear_axle_to_center(1.393), pixel2meter(0.03984)
{
    int v1(0);
    Twb_ptr_->createViewPort(0.0, 0.0, 1.0, 1.0, v1);
    Twb_ptr_->createViewPortCamera(v1);
    Twb_ptr_->setBackgroundColor(0, 0, 0, v1);
    Twb_ptr_->addCube(-(vehicle_length / 2 - rear_axle_to_center),
                        vehicle_length / 2 + rear_axle_to_center,
                        -vehicle_width / 2, vehicle_width / 2, 0.0, 0.2, 128.0,
                        69.0, 0.0, "vehicle", v1);
    Twb_ptr_->addCoordinateSystem(1.0, 0.0, 0.0, 0.3, "vehicle_frame", v1);
    Twb_ptr_->addCoordinateSystem(1.0, 0.0, 0.0, 0.0, "map_frame", v1);
}

pclDraw::~pclDraw()
{
}

void pclDraw::DrawInTwb_ptr_(const Eigen::Matrix<float,4,4> &T, double rsize, double r, double g, double b, std::string name)
{
    Eigen::Affine3f Draw_pose;
    Draw_pose.matrix() = T;
    pcl::PointXYZ Tpoint;
    Tpoint.x = Draw_pose.translation()[0];
    Tpoint.y = Draw_pose.translation()[1];
    Tpoint.z = Draw_pose.translation()[2];

    Twb_ptr_->updateShapePose("vehicle", Draw_pose);
    Twb_ptr_->updateCoordinateSystemPose("vehicle_frame", Draw_pose);
    Twb_ptr_->addSphere(Tpoint, rsize, r, g, b, name);
    Twb_ptr_->spinOnce();
}

void pclDraw::DrawPointCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr Cloud, const std::string cloudName)
{
    Twb_ptr_->addPointCloud<pcl::PointXYZ>(Cloud,cloudName,0);
}

void pclDraw::ConvertImg2Cloud(cv::Mat& img, pcl::PointCloud<pcl::PointXYZ>::Ptr EdgeCloud, pcl::PointCloud<pcl::PointXYZ>::Ptr FreeCloud)
{
    for (int r = 0; r < img.rows; r++)
    {
        for (int c = 0; c < img.cols; c++)
        {
            int label = -1;
            if (img.at<uchar>(r,c) == 0)
                continue;
            else if (img.at<uchar>(r,c) < 129)
                label = 0;
            else
                label = 1;
            
            pcl::PointXYZ point;
            point.x = (img.rows / 2 - r) * pixel2meter + rear_axle_to_center;
            point.y = (img.cols / 2 - c) * pixel2meter;
            point.z = 0.0;

            if (label == 1)
            {
                FreeCloud->points.push_back(point);
            }
            else
            {
                EdgeCloud->points.push_back(point);
            }
        }
    }

    FreeCloud->width = FreeCloud->points.size();
    FreeCloud->height = 1;
    FreeCloud->is_dense = true;

    EdgeCloud->width = EdgeCloud->points.size();
    EdgeCloud->height = 1;
    EdgeCloud->is_dense = true;
}