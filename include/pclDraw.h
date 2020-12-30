#pragma once

#include <pcl/filters/voxel_grid.h>
#include <pcl/io/ply_io.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/point_types.h>
#include <pcl/point_types_conversion.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pclomp/ndt_omp.h>
#include <pcl/io/pcd_io.h>
#include <pcl/registration/icp.h>

#include <opencv2/opencv.hpp>
#include <Eigen/Dense>
#include <string>

class pclDraw
{
private:
    pcl::visualization::PCLVisualizer::Ptr Twb_ptr_;
    double vehicle_length, vehicle_width, rear_axle_to_center, pixel2meter;

public:
    pclDraw();
    ~pclDraw();

    void DrawInTwb_ptr_(const Eigen::Matrix<float,4,4> &T, double r, double g, double b, std::string name);
    void DrawPointCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr Cloud, const std::string cloudName);
    void ConvertImg2Cloud(cv::Mat& img, pcl::PointCloud<pcl::PointXYZ>::Ptr EdgeCloud, pcl::PointCloud<pcl::PointXYZ>::Ptr FreeCloud);
};
